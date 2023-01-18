#include "parser.h"
#include <regex>
#include <iostream>
#include <bitset>

void parser::init()
{
	hashmap = std::unordered_map<std::string, int>();
	tokens.push_back("print");
	tokens.push_back("3");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("-");
	tokens.push_back("3");
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

bool parser::is_integer(std::string check)
{
	return (std::regex_match(check, std::regex("-?[0-9][0-9]*")));
}

bool parser::is_variable(std::string check)
{
	return (std::regex_match(check, std::regex("[A-z][A-z0-9]*")));
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
				std::cout << "Configuration mode set to decimal.";
				return 0;
			}
			else if (next_token == "hex")
			{
				consume("hex");
				config_mode = 1;
				std::cout << "Configuration mode set to hexadecimal.";
				return 1;
			}
			else if (next_token == "bin")
			{
				consume("bin");
				config_mode = 2;
				std::cout << "Configuration mode set to binary.";
				return 2;
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
		assign_target = next_token;

		consume(next_token);
			
		next_token = peek();
		if (next_token == "=")
		{
			consume("=");

			hashmap.insert_or_assign(assign_target, parse_math());
		}
	}
	return 0;
}

int parser::parse_math()
{
	treenode* hell = parse_expression();
	return hell->eval();
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

	}
	else if (next_token == "(")
	{
		consume("(");
		next_token = peek();
		treenode* a = parse_expression();

		if (next_token == ")")
		{
			consume(")");
			return a;
		}
	}
	else if (next_token == "-")
	{
		consume("-");
		next_token = peek();
		


		//negate dummy = negate(&parse_factor());
		//return dummy;
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








int parser::parse_product()
{
	int result = parse_product();

	int a = std::stoi(peek());
	int b = 1;

	std::string next_token = peek(1);
	if (next_token == "*")
	{
		consume("*");
		b = std::stoi(peek(1));
	}
	return 1;
}

int parser::parse_sum()
{
	std::string next_token = peek();
	if (next_token == "*")
	{
		return 1;
		//result = 
	}
}

int parser::parse_primary()
{
	int result;
	std::string next_token = peek();
	if (std::regex_match(next_token, std::regex("[A-Za-z][A-Za-z0-9]*")))
	{
		//return *lookuptable.find(next_token);
	}
	else if (std::regex_match(next_token, std::regex("[0-9][0-9]*")))
	{
		return std::stoi(next_token);
	}
	else if (next_token == "(")
	{
		consume(next_token);
		result = parse_math();
	}
}

bool parser::evaluate() 
{
	return parse_statement();
}

void parser::do_print(int number)
{
	switch (config_mode)
	{
		case 0:
			
			std::cout << std::dec << number;

		break;

		case 1:

			std::cout << std::hex << number;

		break;

		case 2:

			std::cout << std::bitset<32>(number).to_string();

		break;
	}
}

















bool parser::parse_logExp() 
{
	return parse_orExp();
}

bool parser::parse_orExp() 
{
	bool result = parse_andExp();

	std::string next_token = peek();
	while (1)
	{
		if (next_token == "||")
		{
			consume("||");
			result = (result || parse_andExp());
		}
		else
			break;
		next_token = peek();
	}

	return result;
}

bool parser::parse_andExp() 
{
	bool result = parse_cmpExp();
	std::string next_token = peek();
	while (1)
	{
		if (next_token == "&&")
		{
			consume("&&");
			result = result && parse_cmpExp();
		}
		else
			break;

		next_token = peek();
	}

	return result;
}

bool parser::parse_cmpExp() 
{
	int result = parse_primaryExp();

	std::string next_token = peek();
	while (1)
	{
		if (next_token == "==")
		{
			consume("==");
			result = (result == parse_primaryExp());
		}
		else if (next_token == "<")
		{
			consume("<");
			result = (result < parse_primaryExp());
		}
		else if (next_token == ">")
		{
			consume(">");
			result = (result > parse_primaryExp());
		}
		else
			break;

		next_token = peek();
	}
	return (bool)result;
}

bool parser::parse_primaryExp() 
{
	int value;
	std::string next_token = peek();
	// Number
	//if (is_int(next_token))
	{
		value = std::stoi(next_token);
		consume(next_token);
	}
	// Parenthesis expression: ( LogExp )
	if (next_token == "(")
	{
		consume("(");
		value = parse_logExp();
		if (peek() == ")")
			consume(")");
	}
	// No valid PrimaryExp found, which is an error

	return value;
}