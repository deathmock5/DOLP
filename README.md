# DOLP
Distributed Orthographic Lexical Parser

Simply put, the dolp project is a simplified method for inclusion of scripting in other programs.
Think, Cross platform, cross language Just In Time(JIT) Compiler.

Work in progress.

## General usage

```./DOLP langname.l```
	
*.l files contain regex definitons for grammer, similar to the [GNU Bison](https://www.gnu.org/software/bison/) 
and [FLEX](https://github.com/westes/flex)  project.
These files are compiled into a .h file for inclusion into other programs.
	
Now using these .h files are simple just include them once in your main.cpp file, before DOLP.h

## EXAMPLE

```
#include "Javacript.h" //Generated from dolp Javascript.l
#include "Python.h" //Generated from dolp Python.l
#define _DOLP_MAIN_
#include "DOLP.h"

#include <iostream>

int main(int argc, char **argv){
    std::vector<Token> somejsfile = DOLP::parse("somefile.js");
    std::vector<Token> somepythonfile = DOLP::parse("somefile.py");
    //Both now contain A vector of tokens useable with your transformers.
    return EXIT_SUCCESS;
}
```
