#pragma once
#include <string>
#include <vector>
class tokenizer
{
private:
	int position;
	std::vector<std::vector<std::string>> lines;
public:
	std::string line;
	void tokenize();
	std::vector<std::string> get_line();
	bool reading_complete();
};

