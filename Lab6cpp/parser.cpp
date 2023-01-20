#include "parser.h"
#include <regex>
#include <iostream>
#include <bitset>
#include <stdexcept>

parser::parser(std::ostream* _output)
{
	output = _output;
	position = 0;
}

void parser::init()
{
	hashmap = std::unordered_map<std::string, int>();
}

void parser::parse(std::vector<std::string> tokenlist)
{
	tokens = tokenlist;
	position = 0;
	parse_statement();
}

std::string parser::peek() {
	return peek(0);
}
std::string parser::peek(int steps) {
	if (position + steps >= tokens.size()) {
		return ETX;
	}

	return tokens[position + steps];
}

void parser::consume(const std::string& token) {
	std::string next_token = peek();
	if (next_token == ETX)
	{
		
	}
	if (next_token != token)
	{
		
	}

	++position;
}

bool parser::is_integer(const std::string check)
{
	return (std::regex_match(check, std::regex("-?[0-9][0-9]*")));
	//integer is allowed to start on - but doesn't have to. has to contain a number in its first spot (after eventual -). additional numbers are allowed but not required.
}

bool parser::is_variable(const std::string check)
{
	return (std::regex_match(check, std::regex("[A-z][A-z0-9]*")));
	//variable must start with a letter, but following characters may be letters or numbers if any at all.
}

int parser::parse_statement()
{
	return parse_config();
}

int parser::parse_config()
{
	int result = parse_print();

	std::string next_token = peek();
	while (1)
	{
		if (next_token == "config")
		{
			consume("config");
			next_token = peek();
			if (next_token == "dec")
			{
				consume("dec");
				config_mode = 0;
				* output << "Configuration mode set to decimal.\n";
				return 0;
			}
			else if (next_token == "hex")
			{
				consume("hex");
				config_mode = 1;
				*output << "Configuration mode set to hexadecimal.\n";
				return 1;
			}
			else if (next_token == "bin")
			{
				consume("bin");
				config_mode = 2;
				*output << "Configuration mode set to binary.\n";
				return 2;
			}
			else
				*output << "ERROR: No suitable configuration mode entered. Configuration mode unchanged. \n";
			switch (config_mode)
			{
			case 0:
				*output << "Current configuration mode is decimal. \n";
				break;

			case 1:
				*output << "Current configuration mode is hexadecimal. \n";
				break;

			case 2:
				*output << "Current configuration mode is binary. \n";
				break;
				}
		}
		else
			break;
		next_token = peek();
	}

	return result;
}

int parser::parse_print()
{
	int result = parse_assign();

	std::string next_token = peek();

	if (next_token == "print")
	{
		consume("print");
		result = (parse_math());
		do_print(result);
	}
	
	next_token = peek();
	

	return result;
}

int parser::parse_assign()
{
	std::string next_token = peek();

	if (is_variable(next_token) && next_token != "print" && next_token != "config")
	{
		std::string assign_target = next_token;

		consume(next_token);
			
		next_token = peek();
		if (next_token == "=")
		{
			consume("=");

			hashmap.insert_or_assign(assign_target, parse_math());
		}
	}

		if (next_token == "print" || next_token == "config")
		{
			next_token = peek(1);
			if (next_token == "=")
			{
				*output << "ERROR: Cannot use 'print' or 'config' as variable names. \n";
			}

		}
	
	
	return 0;
}

int parser::parse_math()
{
	treenode* result = parse_expression();
	return result->eval();
}

treenode* parser::parse_factor()
{
	std::string next_token = peek();
	if (is_integer(next_token))
	{
		//return std::stoi(next_token);
		consume(next_token);
		integer* dummy = new integer(std::stoi(next_token));
		return dummy;
		
	}
	else if (is_variable(next_token))
	{
		consume(next_token);
		if (hashmap.count(next_token) == 0)
		{

			*output << "ERROR: Use of unassigned variable " << next_token << ". Assigning new variable and returning 1 as its value.\n";
			hashmap.insert_or_assign(next_token, 1);
			return new integer(1);
		}
		integer* dummy = new integer(hashmap.at(next_token)); //no need to mess around with weird stuff for this one when I can just add an integer node to the tree with the value of the variable, hasn't caused any weirdness as far as I could tell
		return dummy;
	}
	else if (next_token == "(")
	{
		consume("(");
		next_token = peek();
		treenode* a = parse_expression();

		next_token = peek();
		if (next_token == ")")
		{
			consume(")");
			return a;
		}
		else
		{
			*output << "ERROR: No closing parenthesis found.\n";
		}
	}
	else if (next_token == "-" || next_token == "*" || next_token == "/" || next_token == "+" || next_token == ")")
	{
		*output << "ERROR: No complete expression found after operator. Returning 0 as value. \n";
		integer* dummy = new integer(0);
		return dummy;
	}
}

treenode* parser::parse_expression()
{
	std::string next_token = peek();
	treenode* a = parse_term();

	next_token = peek();
	while (1 == 1)
	{
		if (next_token == "\x3")
		{
			return a;
			//break;
		}
		if (next_token == "+")
		{
			consume("+");
			next_token = peek();
			treenode* b = parse_expression();
			add* dummy = new add(a, b);
			treenode* c = dummy;
			a = c;
		}
		else if (next_token == "-")
		{
			consume("-");
			next_token = peek();
			treenode* b = parse_expression();
			subtract* dummy = new subtract(a, b);
			treenode* c = dummy;
			a = c;
		}
		else
			return a; 
	}
}

treenode* parser::parse_term()
{
	std::string next_token = peek();
	treenode* a = parse_factor();
	while (1)
	{
		next_token = peek();
		if (next_token == "*")
		{
			consume("*");
			next_token = peek();
			treenode* b = parse_term();
			multiply* dummy = new multiply(a, b);
			treenode* c = dummy;
			a = c;
		}
		else if (next_token == "/")
		{
			consume("/");
			next_token = peek();
			treenode* b = parse_term();
			divide* dummy = new divide(a, b);
			treenode* c = dummy;
			a = c;
		}
		else
			return a;

		return a;
	}
}


void parser::do_print(const int number) const
{
	switch (config_mode)
	{
		case 0:
			
			*output << std::dec << number << std::endl;

		break;

		case 1:

			*output << std::hex << number << std::endl;

		break;

		case 2:

			*output << std::bitset<32>(number).to_string() << std::endl;

		break;
	}
}
