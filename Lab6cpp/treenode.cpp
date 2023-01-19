#include "treenode.h"
#include <iostream>
#pragma once

int treenode::eval() 
{
	return 1;
}


treenode::treenode()
{

}







int add::eval() 
{
	return l->eval() + r->eval();
}

add::add(treenode* _l, treenode* _r)
{
	l = _l;
	r = _r;
}



int subtract::eval() 
{
	return l->eval() - r->eval();
}

subtract::subtract(treenode* _l, treenode* _r)
{
	l = _l;
	r = _r;
}



int multiply::eval()
{
	return l->eval() * r->eval();
}

multiply::multiply(treenode* _l, treenode* _r)
{
	l = _l;
	r = _r;
}



int divide::eval() 
{
	return l->eval() / r->eval();
}

divide::divide(treenode* _l, treenode* _r)
{
	l = _l;
	r = _r;
}


int negate::eval() 
{
	return -term->eval();
}

negate::negate(treenode* _term)
{
	term = _term;
}


int integer::eval()
{
	return number;
}

integer::integer(int _value)
{
	number = _value;
}