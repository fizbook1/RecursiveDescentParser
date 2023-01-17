#include "treenode.h"
#include <iostream>
#pragma once

int treenode::eval() 
{

}
void treenode::print()
{

}





void add::print() 
{
	
}

int add::eval() 
{
	return l.eval() + r.eval();
}



int subtract::eval() 
{
	return l.eval() - r.eval();
}



int multiply::eval()
{
	return l.eval() * r.eval();
}



int divide::eval() 
{
	return l.eval() / r.eval();
}



int negate::eval() 
{
	return -term.eval();
}



int id::eval()
{
	return 1;
}




int integer::eval()
{
	return number;
}
