#include "DOLP_Javascript.h"
//#include "Python.h" //Generated from dolp Python.l
#define _DOLP_MAIN_
#include "DOLP.h"

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	//std::vector<Token> somejsfile = DOLP::parse("somefile.js");
	//std::vector<Token> somepythonfile = DOLP::parse("somefile.py");
	//Both now contain A vector of tokens useable with your transformers.
	//
	DOLP_Javascript::Lexer script("testfile.js");
	std::vector<Token> tokens = script.parse();

	return EXIT_SUCCESS;
}