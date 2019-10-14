#pragma once


typedef std::pair<const char*, std::string> TokenMatches;
typedef std::pair<uint32_t, TokenMatches> Token;


std::ostream& operator<<(std::ostream& os, const TokenMatches& obj)
{
	os << "{" << obj.first << "," << obj.second << "}";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
	os << obj.first << ":" << obj.second;
	return os;
}