#pragma once
class treenode
{
public:
	
	virtual int eval();
	virtual void print();
	treenode();
	
};

class add : public treenode {
public:
	treenode l, r;
	void print();
	int eval();

	add(treenode _l, treenode _r);
};

class subtract : public treenode {
public:
	treenode l, r;
	void print();
	int eval();

	subtract(treenode _l, treenode _r);
};

class multiply : public treenode {
public:
	treenode l, r;
	void print();
	int eval();

	multiply(treenode _l, treenode _r);
};

class divide : public  treenode {
public:
	treenode l, r;
	void print();
	int eval();

	divide(treenode _l, treenode _r);
};

class negate : public treenode {
public:
	treenode term;
	void print();
	int eval();

	negate(treenode term);
};

class id : public treenode {
public:
	treenode term;
	void print();
	int eval();

	//add(treenode _l, treenode _r);
};

class integer : public treenode {
public:
	int number;
	void print();
	int eval();

	integer(int _value);
};
