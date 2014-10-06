/*
 * structures.h
 *
 *  Created on: 2014年10月3日
 *      Author: dousha
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

struct word{
	std::string name;    // it's name
	std::string value;   // and it's value
	long length;         // also it's length
};

struct function{
	std::string name;    // it's name
	long line;           // where is it
	int length;          // how long
	std::string carry;   // and returns
};

struct number{
	std::string name;
	float value;
};

struct boolean{
	std::string name;
	bool value;
};

struct command{
	std::string function;
	std::string arg1;
	std::string op;
	std::string arg2;
};

#endif /* STRUCTURES_H_ */
