#include "tokenizer.h"
#include <iterator>
#include <sstream>
std::vector<std::string> tokenizer::tokenize(std::string _line) {

	line = _line;
	int position = 0;
	bool done = false;
	std::vector<std::string> tokens;

	//char* skoob = _line.cstr();
	//char* p = strtok(skoob, " ");
	//while (p) {
	/*	printf("Token: %s\n", p);
		tokens.push_back(std::string(p));
		p = strtok(NULL, " ");
	}*/


	while (!done)
	{
		tokens.push_back(get_next_token());
		++position;
	}
	return tokens;
}

std::string tokenizer::get_next_token()
{
	return "hi";
}

