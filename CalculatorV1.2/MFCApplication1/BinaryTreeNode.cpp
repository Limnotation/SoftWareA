#include "pch.h"
#include "BinaryTreeNode.h"
const int NUL = -1;


BinaryTreeNode::BinaryTreeNode()
{
}


BinaryTreeNode::~BinaryTreeNode()
{
}

void BinaryTreeNode::set_node(char op, double num)
{
	op_ = op;
	num_ = num;
	lch = NUL;
	rch = NUL;
}

void BinaryTreeNode::allocate_rch(int r)
{
	rch = r;
}

void BinaryTreeNode::allocate_lch(int l)
{
	lch = l;
}






