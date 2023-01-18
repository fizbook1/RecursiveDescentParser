#pragma once
class treenode
{
public:
	
	
	virtual int eval();
	treenode();
	
};

class add : public treenode {
public:
	treenode* l, *r;
	int eval();

	add(treenode* _l, treenode* _r);
};

class subtract : public treenode {
public:
	treenode* l, *r;
	int eval();

	subtract(treenode* _l, treenode* _r);
};

class multiply : public treenode {
public:
	treenode* l, *r;
	int eval();

	multiply(treenode* _l, treenode* _r);
};

class divide : public  treenode {
public:
	treenode* l, *r;
	int eval();

	divide(treenode* _l, treenode* _r);
};

class negate : public treenode {
public:
	treenode* term;
	int eval();

	negate(treenode* _term);
};

class id : public treenode {
public:
	treenode* term;
	int eval();

	//add(treenode _l, treenode _r);
};

class integer : public treenode {
public:
	int number;
	int eval();

	integer(int _value);
};
