// DOCTYPE	: C++-g++: Interpreter.cpp
// Author	: jiangyue
// License	: Public Domain @ noLicenseFile
// Manual	: N/A
// Encoding	: UTF-8

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cstring>


// #include "keywords.h"
using namespace std;

vector<pair<string, int> > functions;
vector<pair<string, float> > numbers;
vector<pair<string, string> > strings;
vector<pair<string, int> > gotos;
bool candy, fc = false;
int pLine = 0;
/* The status declare.
 * 0 is the outside, 1 is inside func main, etc...
 */
int currentStat = 0;

int codeLogics[1][5000] = {0};
string File[5000];

void Interpreter_executer(int code){
    switch(code){
        case -1:
            pLine = 0;
            cout << "Programme exited (0)." << endl;
            fc = true;
            return;
        case -99:
            cout << "There's a error occured!" << endl;
            cout << "BadCodeException @ line " << pLine << endl;
            pLine = 0;
            fc = true;
            break;
        default:
            cout << "There's a error occured!" << endl;
            cout << "ExecuterCodeInvaildException @ line " << pLine << endl;
            pLine = 0;
            fc = true;
            break;
    }
}


void Interpreter_solveLine(int pLine){
    // Line Constructure.
    
    
    
    /*
        // FIXME: not completed yet
        if(strncmp(expr.c_str(), "exit", 4) == 0)
            Interpreter_executer(-1);
        else if(expr.empty())
            return;
        else if(strncmp(expr.c_str(), "bad", 3) == 0)
            Interpreter_executer(-99);
        else
            Interpreter_executer(-100);
     */
}

void Interpreter_fileHandler(string file, string arg){
    // Inherited from dousha's joke... :P
    if(arg == "--wtf"){
        cout << "Windows .neT Framework!" << endl;
        cout << "-----------------------------" << endl;
        cout << "Windows .neT Framework is our" << endl;
        cout << "extera project that using    " << endl;
        cout << ".net Framework to execute    " << endl;
        cout << "LimeStone code. We are still " << endl;
        cout << "working on it and it will be " << endl;
        cout << "released in next few         " << endl;
        cout << "development cycles.          " << endl;
        cout << "If you wanna join us and     " << endl;
        cout << "develop LimeStone together,  " << endl;
        cout << "you may send email to        " << endl;
        cout << "lijiahao34@gmail.com and join" << endl;
        cout << "our GitHub Team.             " << endl;
        exit(0);
    }
    ifstream fs(file.c_str(), ios::in);
    char buffer[300];
    stringstream ss;
    if((!fs.is_open()) || (fs.bad())){
        cout << "Bad file!" << endl;
        return;
    }
    while((!fs.eof()) && (!fc)){
        pLine++;
        fs.getline(buffer, 300);
        ss << buffer;
        File[pLine] = ss.str();
        Interpreter_solveLine(pLine);
    }
}
/*
tokens[] Interpreter_readLn(string s) {
	tokens[] tk = new tokens[30];
	
	int top = 0;
	int length = s.length();
	for(i=0; i<lengh; i++) {
		if((s[i] >= "a" && s[i] <= "z") || (s[i] >= "A" && s[i] <= "Z")) {
			
		}
	}
}*/
