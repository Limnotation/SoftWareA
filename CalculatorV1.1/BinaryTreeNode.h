#pragma once
class BinaryTreeNode
{
public:
	BinaryTreeNode();
	~BinaryTreeNode();
	char op_;
	double num_;
	int lch;
	int rch;
	void set_node(char op, double num);
	void allocate_rch(int r);
	void allocate_lch(int l);
private:

};


