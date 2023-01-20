#pragma once
class treenode
{
public:
	
	//treenode class which the nodes that handle the arithmetic inherit from.
	virtual int eval();
	treenode();
	
	virtual ~treenode();
};

class add : public treenode {
private:
	treenode* l, * r;
public:
	int eval();

	add(treenode* _l, treenode* _r);

	~add();
};

class subtract : public treenode {

private:
	treenode* l, * r;
public:

	int eval();

	subtract(treenode* _l, treenode* _r);

	~subtract();
};

class multiply : public treenode {
private:
	treenode* l, * r;
public:
	int eval();

	multiply(treenode* _l, treenode* _r);

	~multiply();
};

class divide : public  treenode {
private:
	treenode* l, * r;
public:
	int eval();

	divide(treenode* _l, treenode* _r);

	~divide();
};

class negate : public treenode {
private:
	treenode* term;
public:

	int eval(); //not implemented cause that would require more regexing

	negate(treenode* _term);

	~negate();
};


class integer : public treenode {
private:
	int number;
public:
	int eval();

	integer(int _value);

	~integer();
};
