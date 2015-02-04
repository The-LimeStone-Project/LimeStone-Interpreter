// DOCTYPE	: C++ header-g++: Globals.cpp
// Author	: jiangyue
// License	: GPLv2 @ noLicenseFile
// Manual	: N/A
// Encoding	: UTF-8

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



// Global files declaration
FILE *code;
FILE *instream;
FILE *outstream;
int line = 1, column = 0;
