// DOCTYPE	: C++-g++: support/LIMESTONE_NUMBER.cpp
// Author	: jiangyue
// License	: Public Domain @ noLicenseFile
// Manual	: N/A
// Encoding	: UTF-8


/* The file is a part of The LimeStone Interpreter.
 *
 * Copyright 2014 The LimeStone Project- Dev team.
 */

#include <iostream>
#include <cstdio>

class LIMESTONE_NUMBER {
private:
    double VALUE;
public:
    // Constructor. INIT The Type Number.
    LIMESTONE_NUMBER(int n = 0) {
        this->VALUE = (double) n;
    }
    
    LIMESTONE_NUMBER(float n = 0.0) {
        this->VALUE = (double) n;
    }
    
    LIMESTONE_NUMBER(double n = 0.0) {
        this->VALUE = n;
    }
    
    // The Adding Function indicated INSIDE
    void addValue(int n = 0) {
        this->VALUE += (double) n;
    }
    void addValue(float n = 0.0) {
        this->VALUE += (double) n;
    }
    void addValue(double n = 0.0) {
        this->VALUE += n;
    }
    
    // The SETTRE
    void setValue(int n = 0) {
        this->VALUE = (double) n;
    }
    void setValue(float n = 0.0) {
        this->VALUE = (double) n;
    }
    void setValue(double n = 0.0) {
        this->VALUE = n;
    }
    
    // END DECL.
    
    // TODO ADD MEMORY SETTRE IN REL. VER 2
};