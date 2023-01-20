#include "tokenizer.h"
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>

void tokenizer::tokenize() {

	position = 0;
	
	std::string text;

	lines.push_back(std::vector<std::string>()); //push back one vector so we have something to write to

	std::ifstream file;
	file.open("code.c@");

	if (!file) {
		std::cerr << "ERROR: File couldn't be opened, likely currently used by another program.";
		exit(1);
	}

	//fix formatting

	while (std::getline(file, text, ' '))
	{
		std::istringstream iss(text);

		int newline = text.find("\n"); //if new line found, save location to split later

		if (newline > 0)
		{
			std::string before_n_line = text.substr(0, newline);
			lines[position].push_back(before_n_line);

			++position;
			lines.push_back(std::vector<std::string>()); //add a new vector on the vector vector to signify a new line and increment position AFTER the line break
			std::string after_n_line = text.substr(newline + 1, text.length());
			lines[position].push_back(after_n_line);
		}
		else if (!text.empty())
		{
			lines[position].push_back(text); //to only push back elements that make sense
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
	if (position == lines.size() - 1) //dunno why <= and stuff doesn't work, returning bool might be the issue? not sure
	{
		return true;
	}

	return false;
}

