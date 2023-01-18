#pragma once
#include <string>
#include <vector>
class tokenizer
{
public:
	std::string line;
	std::vector<std::string> tokenize();
	std::vector<std::string> get_line();
	std::string get_next_token();
};

