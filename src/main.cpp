#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "structures.h"

using namespace std;

// Memory
vector<word> words;
vector<number> numbers;
vector<function> functions;

// Flags
bool flagClose = false;
bool flagError = false;
bool flagDebug = false;

// Buffers
int pLine; // programme line counter
stringstream ss; // converter
string tempS; // and these buffers
string bufA;
string bufB;
string bufOp;
float tempF;

void flushAll(){
	// clean all the buffers
	ss.clear();
	ss.str("");
	tempS = "";
	bufA = "";
	bufB = "";
	bufOp = "";
	tempF = 0;
}

void resetFlags(){
	flagClose = false;
	flagDebug = false;
	flagError = false;
}

void destroyAll(){
	words.clear();
	numbers.clear();
	functions.clear();
	flushAll();
	resetFlags();
	pLine = 0;
}

void panicMessage(string msg){
	ss << pLine;
	cout << "\033[31m" << msg << "\033[0m" << endl;
	flushAll();
}

void panic(int err){
	flagError = true;
	switch(err){
		case 0:
			panicMessage("Undefined Error!");
			break;
		case 1:
			panicMessage("Script do not have `end'!");
			break;
		case 2:
			panicMessage("Undefined goto!");
			break;
		case 3:
			panicMessage("Undefined object!");
			break;
		case 4:
			panicMessage("Command Not Found!");
			break;
		case 5:
			panicMessage("D-Name!");
			break;
		case 6:
			panicMessage("Missing \"");
			break;
		case 7:
			panicMessage("Too less arguments!");
			break;
		case 8:
			panicMessage("Too many arguments!");
			break;
		case 9:
			panicMessage("Bad command!");
			break;
		default:
			panicMessage("Undefined Error!");
			break;
	}
}

bool startWith(string s, string patt){
	if(s.find_first_of(patt, 0) == 0)
		return true;
	else
		return false;
}

bool endWith(string s, string patt){
	if(s.find_last_of(patt, s.length()) == s.length() - 1)
		return true;
	else
		return false;
}

void addWord(string name, string value){
	vector<word>::iterator iter = words.begin();
	for(;iter != words.end();++iter){
		if(iter->name == name){
			panic(5);
		}
	}
	word w;
	w.name = name;
	w.value = value;
	w.length = name.length();
	words.push_back(w);
}

string readWord(string name){
	vector<word>::iterator iter = words.begin();
	for(;iter != words.end(); ++iter){
		if(iter->name == name){
			return iter->value;
		}
	}
	panic(3); // FIXME: CAUSE SEGFAULT HERE!
}

void writeWord(string name, string value){
	vector<word>::iterator iter = words.begin();
	for(;iter != words.end(); ++iter){
		if(iter->name == name){
			iter->value = value;
			return;
		}
	}
	panic(3);
}

void removeWord(string name){
	vector<word>::iterator iter = words.begin();
	for(;iter != words.end();++iter){
		if(iter->name == name){
			words.erase(iter);
			return;
		}
	}
	panic(3);
}

void addNumber(string name, float value){

}

float readNumber(string name){
	return 0;
}

void removeNumber(string name){

}

int varFinder(string name){
	vector<word>::iterator iw = words.begin();
	vector<number>::iterator in = numbers.begin();
	for(;iw != words.end(); ++iw){
		if(iw->name == name){
			return 1;
		}
	}
	for(;in != numbers.end(); ++in){
		if(in->name == name){
			return 2;
		}
	}
	return 0;
}

string fRead(string f){
	// FIXME: not done yet!
	return 0;
}

void fScan(string f){
	// FIXME: not done yet!
}

void executer(string s){
	if(startWith(s, "bad")){
		panic(0);
	}
	else if(startWith(s, "end")){
		flagClose = true;
	}
	else if(startWith(s, "print")){
		ss << tempS;
		ss >> bufA >> bufB;
		if((startWith("\"", bufB)) &&
				(endWith("\"", bufB))){
			cout << bufB.substr(1, bufB.length() - 2) << endl;
		}else{
			cout << readWord(bufB) << endl;
		}
		flushAll();		
	}
	else if(startWith(s, "create")){
		ss << tempS;
		ss >> bufA >> bufOp >> bufB;
		if((bufOp == "word") && (bufB.length() > 0)){
			addWord(bufB, "");
		}
		else if(bufOp == "number"){
			addNumber(bufB, 0);
		}
		else{
			// FIXME: not a good way
			panic(7);
		}
	}
	else{
		ss << tempS;
		ss >> bufA >> bufOp >> bufB;
		if(bufOp == "="){
			if(varFinder(bufA) == 1){
				if((startWith(bufB, "\"") &&
					(endWith(bufB, "\""))))
					writeWord(bufA, bufB.substr(1, bufB.length() - 2));
				else
					writeWord(bufA, readWord(bufB));
				// FIXME: well
			}
			else if(varFinder(bufA) == 2){
				; // FIXME: well again
			}
			else
				panic(4);
		}
		else{
			panic(9);
		}
	}
}

int main(){
	cout << "Welcome to nextScript console Version 0.1a." << endl;
	cout << "Manual: I haven't got a manual yet!" << endl;
	cout << "You can type commands like Python interactive" << endl;
	cout << "console." << endl;
	cout << "Have fun!" << endl;
retry:
	for(;(!flagClose && !flagError);){
		cout << "> ";
		getline(cin, tempS);
		executer(tempS);
		flushAll();
	}
	if(flagError){
		// Exception processing
		cout << "There's something wrong with your code" << endl;
		cout << "Would you like to Restart(r) or Quit(q)?" << endl;
		cout << "Restart will destroy all the things" << endl;
		tempS = "";
		getline(cin, tempS);
		if(tempS == "r"){
			destroyAll();
			resetFlags();
			flushAll();
			goto retry;
		}
	}else{
		// destroy all
		destroyAll();
		resetFlags();
		flushAll();
	}
	return 0;
}
