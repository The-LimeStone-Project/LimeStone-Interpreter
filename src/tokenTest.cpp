// DOCTYPE	: C++-g++: tokenTest.cpp
// Author	: dousha
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

void executer(int code){
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

void solveLine(string expr){
	// FIXME: not completed yet
	if(strncmp(expr.c_str(), "exit", 4) == 0)
		executer(-1);
	else if(expr.empty())
		return;
	else if(strncmp(expr.c_str(), "bad", 3) == 0)
		executer(-99);
	else
		executer(-100);
}

void pushStuffs(string file, string arg){
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
		solveLine(ss.str());
	}
}

int main(){
	string f, dbg;
	cout << "Welcome to use LimeStone!" << endl;
	cout << "Usage: [file name] [options]" << endl;
	cout << "Options:" << endl;
	cout << "--run	Run LimeStone Script." << endl;
	cout << "--dbg	Debugging Mode." << endl;
	cout << "--wtf	I don't know, other developer added this." << endl;
	for(;;){
		fc = false;
		cout << "> ";
		cin >> f >> dbg;
		pushStuffs(f, dbg);
	}
}
