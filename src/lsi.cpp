#include <cstdio>
#include <iostream>
#include "Interpreter.cpp"
// #include <cstring>
// #include <string>

// Definations.
#define ALL_DONE 0
#define VERSION 0

using namespace std;

/* The LimeStone Interpreter.
 * Copyright 2014 TLSP Dev Team.
 * You are allowed to edit, change, decompile, recompile the code,
 * and are allowed to re-release the sourse if you note TLSP Dev t
 * -eam while re-releasing.
 *
 * THIS PROJECT IS OPEN-SOURCED AND CAN BE EDIT IF YOU LIKE.
 */

void badParam() {
    cout << "Usage: [options] [file name]" << endl;
    cout << "Options:" << endl;
    cout << "-f	Execute LimeStone Script." << endl;
    cout << "-d	Debugging Mode." << endl;
    cout << "--wtf I don't know, other developer added this." << endl;
}

int main(int argc,char *argv[]) {
    string param;
    
    if(argc < 3) {
        badParam();
        fc = false;
        cout << "> ";
        cin >> param >> argv[2];
        Interpreter_fileHandler(argv[2], "-f");
        exit(0);
    } else {
        // string appname = argv[0];
        param = argv[1];
    }
	cout << "Welcome to the LimeStone Interpreter Version " << VERSION << "!" << endl;
	cout << "Your exec mode is: " << param << "." << endl;

    
	if(param == "-f") {
		cout << "Start executing file!" << endl;
		Interpreter_fileHandler(argv[2], "-f");
        exit(0);
    } else {
        badParam();
        exit(0);
    }

	return ALL_DONE;
}
