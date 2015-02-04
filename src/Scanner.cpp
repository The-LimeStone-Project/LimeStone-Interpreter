// DOCTYPE	: C++ header-g++: Scanner.cpp
// Author	: jiangyue
// License	: GPLv2 @ noLicenseFile
// Manual	: N/A
// Encoding	: UTF-8

#include "Globals.h"
#include <cstring>
using namespace std;

/////////////////////////////////////////////////
// Main structure of Scanner ////////////////////
/////////////////////////////////////////////////

typedef enum {
    INID, INNUM, INASSIGN, INCOMMENT, ERROR, START, DONE, INSTR
} StateType;


char getNextLetter() {
    // Get the next letter from input stream
    char str[400];
    rewind(code);
    for(int i=1; i<=line; i++) fgets(str, 400, code);
    if(strlen(str) <= column+1) {line++; column=0; fgets(str, 400, code);}
    return str[column++];
}

void ungetNextLetter() {
    // unget the next letter from input stream
    column--;
}

TokenRecord getNextToken() {
    TokenRecord rec;
    StateType CurrState = START;
    char ch = 1;
    do {
        ch = getNextLetter();
        // DFA for Scanner
        switch(CurrState) {
            case START:
                if((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z')) // Reserved a letter
                {rec.tokenval = ID; CurrState = INID; rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;}
                if(ch >= '0' && ch <= '9') // Reserved a number
                {rec.tokenval = NUM; CurrState = INNUM; rec.attribute.numval = rec.attribute.numval * 10 + (ch - '0');}
                if(ch == '=' && getNextLetter() != '=') // Reserver '=', which is reserved.
                {ungetNextLetter(); rec.tokenval = ASSIGN; strcat(rec.attribute.stringval, "="); }
                if(ch == ':' && getNextLetter() == ':') // Reserved "::", which is reserved.
                {rec.tokenval = START_TKN; strcat(rec.attribute.stringval, "::");}
                if(ch == '.')  // Reserved end '.'
                {rec.tokenval = END_TKN; strcat(rec.attribute.stringval, ".");}
                if(ch == ',')  // Reserved comma, split it.
                {rec.tokenval = SPLIT; strcat(rec.attribute.stringval, ",");}
                if(ch == '(') // Reserved '('.
                {rec.tokenval = LEFT_PAREN; strcat(rec.attribute.stringval, "(");}
                if(ch == ')') // Reserved ')'.
                {rec.tokenval = RIGHT_PAREN; strcat(rec.attribute.stringval, ")");}
                if(ch == '=' && getNextLetter() == '=') // Reserved "==", equal?
                {rec.tokenval = EQUAL; strcat(rec.attribute.stringval, "==");}
                if(ch == '>' && getNextLetter() != '=') // Reserved greater.
                {ungetNextLetter(); rec.tokenval = GREATER; strcat(rec.attribute.stringval, ">");}
                if(ch == '<' && getNextLetter() != '=') // Reserved less.
                {ungetNextLetter(); rec.tokenval = LESS; strcat(rec.attribute.stringval, "<");}
                if(ch == '>' && getNextLetter() == '=') // Reserved ">=".
                {rec.tokenval = GREATER_EQUAL; strcat(rec.attribute.stringval, ">=");}
                if(ch == '<' && getNextLetter() == '=') // Reserved "<=".
                {rec.tokenval = LESS_EQUAL; strcat(rec.attribute.stringval, "<=");}
                if(ch == '"') // Reserved string! UNEXPECTED... SABER!
                {rec.tokenval = STRING; CurrState = INSTR; rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;}
                if(ch == '/' && getNextLetter() == '*')
                {rec.tokenval = COMMENT; CurrState = INCOMMENT;}
                break;
            case INID:
                if((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >='0' && ch <='9'))
                    rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;
                else {
                    CurrState = START;
                    ungetNextLetter();
                }
                break;

            case INNUM:
                if(ch >= '0' && ch <= '9') // Continuty number
                    rec.attribute.numval = rec.attribute.numval * 10 + (ch - '0');
                else
                    CurrState = START;
                break;
            case INSTR:
                if(ch == '"') { // Out!
                    rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;
                    CurrState = START;
                } else {
                    rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;
                }
                break;

            case INCOMMENT:
                if(ch == '*' && getNextLetter() == '/') // Out!
                    CurrState = START;
                else
                    rec.attribute.stringval[strlen(rec.attribute.stringval)] = ch;
                break;

            default: // Will never happen.
                {CurrState = ERROR; break;}
        }
    } while(CurrState != START);
    return rec;
}
