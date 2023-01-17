#pragma once
#include <string>
#include <vector>
class tokenizer
{
	std::string line;
	std::vector<std::string> tokenize(std::string tokens);
	std::string get_next_token();
};

