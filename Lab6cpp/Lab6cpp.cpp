// Lab6cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "parser.h"
#include "tokenizer.h"
#include "treenode.h"

int main()
{
    parser parse = parser();
	tokenizer token = tokenizer();

    parse.init();
    
    std::cout << "Hello World!\n" ;

	token.tokenize();

    

    while (!token.reading_complete())
    {
        parse.parse(token.get_line());
    }

}

