#pragma once
class treenode
{
public:
	
	//treenode class which the nodes that handle the arithmetic inherit from.
	virtual int eval();
	treenode();
	
};

class add : public treenode {
private:
	treenode* l, * r;
public:
	int eval();

	add(treenode* _l, treenode* _r);
};

class subtract : public treenode {

private:
	treenode* l, * r;
public:

	int eval();

	subtract(treenode* _l, treenode* _r);
};

class multiply : public treenode {
private:
	treenode* l, * r;
public:
	int eval();

	multiply(treenode* _l, treenode* _r);
};

class divide : public  treenode {
private:
	treenode* l, * r;
public:
	int eval();

	divide(treenode* _l, treenode* _r);
};

class negate : public treenode {
private:
	treenode* term;
public:

	int eval(); //not implemented cause that would require more regexing

	negate(treenode* _term);
};


class integer : public treenode {
private:
	int number;
public:
	int eval();

	integer(int _value);
};
