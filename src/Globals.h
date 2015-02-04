// DOCTYPE	: C++ header-g++: Globals.cpp
// Author	: jiangyue
// License	: GPLv2 @ noLicenseFile
// Manual	: N/A
// Encoding	: UTF-8

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


typedef enum {
    /* Process Controlling */
    IF, THEN, ELSE, WHILE, FOR, // Reserved word
    ASSIGN, EQUAL, GREATER, LESS, SPLIT, START_TKN, END_TKN, GREATER_EQUAL,
    LESS_EQUAL, LEFT_PAREN, RIGHT_PAREN,
    /* Type Defination */
    NUMBER, STRING, BOOLEAN, VOID,
    /* Type Identified */
    NUM, ID, COMMENT
} TokenType;


typedef struct {
    TokenType tokenval;
    union {
        char stringval[400];
        int numval;
    } attribute;
} TokenRecord;


// Global files declaration
FILE *code;
FILE *instream;
FILE *outstream;
int line = 1, column = 0;

#endif
