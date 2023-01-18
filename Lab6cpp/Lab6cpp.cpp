// Lab6cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "parser.h"
#include "tokenizer.h"
#include "treenode.h"

int main()
{
    parser parse = parser();

    parse.init();
    
    std::cout << "Hello World!\n";

    std::vector<std::string> tokenlist;

	tokenlist.push_back("myvar");
	tokenlist.push_back("=");
	tokenlist.push_back("3");
	tokenlist.push_back("+");
	tokenlist.push_back("3");
	tokenlist.push_back("+");
	tokenlist.push_back("3");
	parse.parse(tokenlist);
	tokenlist.clear();

	tokenlist.push_back("print");
	tokenlist.push_back("myvar");
	parse.parse(tokenlist);
	tokenlist.clear();

	tokenlist.push_back("myvar2");
	tokenlist.push_back("=");
	tokenlist.push_back("myvar");
	tokenlist.push_back("+");
	tokenlist.push_back("3");
//	tokenlist.push_back("+");
//	tokenlist.push_back("3");
	parse.parse(tokenlist);
	tokenlist.clear();

	tokenlist.push_back("print");
	tokenlist.push_back("myvar");
	parse.parse(tokenlist);
	tokenlist.clear();

	tokenlist.push_back("print");
	tokenlist.push_back("myvar2");
	parse.parse(tokenlist);
	tokenlist.clear();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
