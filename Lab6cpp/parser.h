#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>

class parser
{
	std::vector<std::string> tokens;
	int position;
	const std::string ETX = "\u0003";

	std::string peek();
	std::string peek(int steps);

	//0 decimal, 1 hex, 2 binary
	int config_mode = 0;
	std::map<std::string, int> lookuptable;
	std::string assign_target;

	void init();

	void consume(const std::string& token);

	bool evaluate();

	bool parse_logExp();

	bool parse_orExp();

	bool parse_andExp();

	bool parse_cmpExp();

	bool parse_primaryExp();

	int parse_statement();

	int parse_config();

	int parse_assign();

	int parse_print();

	int parse_math();

	int parse_sum();

	int parse_product();

	int parse_primary();

	int parse_variable();

	int parse_int();

	void do_print(int number);

};

