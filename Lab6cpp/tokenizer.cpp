#include "tokenizer.h"
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>

void tokenizer::tokenize() {

	position = 0;
	bool done = false;
	
	std::string text;

	lines.push_back(std::vector<std::string>());

	std::ifstream file;
	file.open("text.c@");

	if (!file) {
		std::cerr << "ERROR: File couldn't be opened, likely currently used by another program.";
		exit(1);
	}

	//fix formatting

	while (std::getline(file, text, ' '))
	{
		std::istringstream iss(text);

		int newline = text.find("\n");

		if (newline > 0)
		{
			std::string before_n_line = text.substr(0, newline);
			lines[position].push_back(before_n_line);

			++position;
			lines.push_back(std::vector<std::string>());
			std::string after_n_line = text.substr(newline + 1, text.length());
			lines[position].push_back(after_n_line);
		}
		else if (!text.empty())
		{
			lines[position].push_back(text);
		}

	}
	position = -1;
}
std::vector<std::string> tokenizer::get_line()
{
	//return  tokens;
	position++;
	return lines[position];
}

bool tokenizer::reading_complete()
{
	if (position == lines.size() - 1)
	{
		return true;
	}

	return false;
}

