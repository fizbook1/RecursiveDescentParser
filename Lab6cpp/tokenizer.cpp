#include "tokenizer.h"
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>

std::vector<std::string> tokenizer::tokenize() {

	int position = 0;
	bool done = false;
	std::vector<std::vector<std::string>> lines;
	std::vector<std::string> tokens;
	std::string text;

	std::ifstream file;
	file.open("text.c@");

	if (!file) {
		std::cerr << "ERROR: File couldn't be opened, likely currently used by another program.";
		exit(1);
	}

	
	while (std::getline(file, text, ' '))
	{
		std::istringstream iss(text);

		if (text == "\n")
		{
			
		}
		if (!text.empty())
		{
			tokens.push_back(text);
		}
		

		++position;
	}
	return tokens;
}
std::vector<std::string> tokenizer::get_line()
{
	//return  tokens;
}

std::string tokenizer::get_next_token()
{
	return "hi";
}

