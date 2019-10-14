#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <regex> 
#include "Token.h"

namespace DOLP_Javascript
{
	class Lexer {
	public:
		Lexer(const char* file) : _filename(file) {

		}

		std::vector<Token> parse() {
			std::ifstream t(_filename);
			if (t.is_open()) {
				std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
				for(const auto & p : _data){
					parseRegex(p, str);
				}
			}
			return std::vector<Token>();
		}
	private:

		void parseRegex(const std::pair<std::string, std::string>& p,std::string& data) {
			std::regex r(p.second);
			std::smatch match;
			std::regex_search(data, match, r);
			std::string::const_iterator searchStart(data.cbegin());
			int offset = 0;
			while (std::regex_search(searchStart, data.cend(), match, r)){
				handleMatch(p.first,offset + match.position(), match[0], data);
				searchStart = match.suffix().first;
				offset += match.position() + match.length();
			}
		}

		void handleMatch(const std::string& type, const int& position ,const std::string& content,std::string& data) {
			//Get contents of match, create TokenMatch
			TokenMatches match = { type.c_str(), content };
			
			//Replace contents of string at positions with 0x01
			for (int i = position; i < position + content.length(); i++) {
				data[i] = 0x01;
			}
			Token t(position, match);
			//Add Tokenmatch with index to _tokens
			_tokens.push_back(t);

			std::cout << t << std::endl;
		}

		//TokenType: <tokenBeginSpesifier> <acceptablecharacters>
		//Comment:		<\\>			(\/\/.*\n)
		//Operator:		<+-/%^*>		([\+\-\/%^\*]=|[\+\-\/%^\*]{1,2})
		//String:		<"'>			(['\"].*['\"])k
		//WhiteSpace:	< >				()
		//Number:		<0-9>			([0-9]+)
		//Binary:		<|>				()
		//Punctuation:	<[]{}()<>;,=:>	([\[\]{}\(\)<>;,=:]{1})
		//Symbols		<all that remains>		

		//TODO: Account for \ in Strings.
		std::vector<TokenMatches> _data = {
			{"Comment","(//.*\n)|(\\/\\*[^]*\\*\\/)"},
			{"String","(['].*?[']|[\"].*?[\"])"},
			{"Operator","([=]{3}|[+-]{2}|[!+/%<>^=*-]{1}={1,2}|[+/%=<>^*?-]{1})"},
			{"WhiteSpace","([ \n])"},
			{"Number","([0-9]*)\\.([0-9]+)|([0-9]+)"},
			{"Punctuation","([\\[\\]{}\\(\\)<>;,:\\.]{1})"},
			{"Binary","([&]{2})|([|]{1,2})|([!])"},
			{"Symbols","([a-zA-Z_$]{1}[a-zA-Z0-9_]*)"}
		};
		std::vector<Token> _tokens;
		const std::string _filename;
	};
};