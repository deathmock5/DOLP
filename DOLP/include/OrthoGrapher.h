#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Token.h"

/*
	Distributed Orthographic Lexical Parser

	Reads in a .g file, and then creates a .h file for transforming langauge File to Tokens
*/

class OrthoGrapher {
public:
	OrthoGrapher(const char* filename) {
		std::ifstream infile(filename);
		if (infile) {
			std::string line;
			while (std::getline(infile, line))
			{
				std::cout << line << std::endl;
			}
			infile.close();
		}
	}

	void tokenize(const std::string& line) {

	}

	std::string&& getOutput() {
		return std::string();
	}
};