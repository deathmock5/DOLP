/* main.cpp */
#include <iostream>
#include "OrthoGrapher.h"

#define _DOLP_MAIN_

int main(int argc, char **argv)
{

	return EXIT_SUCCESS;
}


/*
	Orthographer (ScriptName.y -> ScriptName.h):
		Takes the grammer files and creates headders for C++ to read?
	Translator (File.type -> std::string):
		Loads the file to string, then passes that to Lexical Analizer.
	Lexical (std::string -> std::vector<Token>):
		Use bison or flex created headders to read strings into an array of tokens.
	Parser (std::vector<Token> -> std::map<std::string,uint8_t*>):
		Chunk up the vector into function_name to byte array keypairs. Byte arrays are just data and function calls.
	Transformer:
		C++ Side: ScriptEngine::call("FunctionName",{args});
*/
/*
	General Idea:
	Create defitions for each supported language.
	Use bison? to create headders to tokenize raw string data from files.
	Have C++ side functions to corospond to tokens, as stack actions.
	Map token pairs to function calls. Then "Compile" the input code.
	Functions are turned into a series of integer to function calls.
	C++ methods are exposed as a base set of functions, while language will add extras.
		call function 1; "Push interger literal to the stack"
		call function 1; 
		call function 2; "Function 2 is add() it pops 2 objects off the stack, then adds them and pushes the result."
		call function 3; "Pop a literal off the stack, then pass to std::cout"

	...

	Break everything down to a stack based machine that I can interface with in C++?

*/