#pragma once
#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

class EvaluateTree
{
public:
	EvaluateTree();
	~EvaluateTree();
	void get_suff(string suff);
	double output();

private:
	char op_[100];
	double num_[100];
	string suff_;
	int root_, tr_;
	int stack_[100];
	BinaryTreeNode node[100];
	int total;
	double result;
	void seperate_op_and_num();
	void create_tree();
	void caculate();
};

