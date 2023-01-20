#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include "treenode.h"
#include <unordered_map>

class parser
{
private:
	std::ostream* output;
	std::vector<std::string> tokens;
	int position;
	const std::string ETX = "\u0003";

	std::string peek();
	std::string peek(int steps);

	//0 decimal, 1 hex, 2 binary
	int config_mode = 0;

	std::unordered_map<std::string, int> hashmap; //to save variables

	void consume(const std::string& token);

	//not entirely sure this follows the grammar precisely but it seems to work with the code

	treenode* parse_expression();

	treenode* parse_term();

	treenode* parse_factor();

	bool is_integer(const std::string check);
	bool is_variable(const std::string check);

	int parse_statement();

	int parse_config();

	int parse_assign();

	int parse_print();

	int parse_math();

	void do_print(const int number) const;

public:
	
	void parse(std::vector<std::string> tokenlist);
	void init();
	parser(std::ostream* _output);
	parser();
	
};

