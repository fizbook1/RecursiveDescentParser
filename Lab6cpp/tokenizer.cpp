#include "tokenizer.h"
std::vector<std::string> tokenizer::tokenize(std::string _line) {

	line = _line;
	int position = 0;
	bool done = false;
	std::vector<std::string> tokens;

	while (!done)
	{
		tokens.push_back(get_next_token());
		++position;
	}

}

std::string tokenizer::get_next_token()
{

}

