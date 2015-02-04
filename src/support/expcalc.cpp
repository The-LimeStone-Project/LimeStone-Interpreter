#include <iostream>

void calcExp(std::string exp) {
	int length = exp.length();

	// First we convert the string to prefix expression.
	
	for(int i=0; i<length; i++) {
		std::cout << exp.at(i) << ' ';
	}

}

int main() {
	calcExp("1+1+1+1");

}
