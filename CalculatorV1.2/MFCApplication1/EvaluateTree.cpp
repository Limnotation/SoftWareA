
#include "pch.h"
#include "EvaluateTree.h"
#include <iostream>
#include "BinaryTreeNode.h"
#include <stdlib.h>
#include <math.h>
const int NUL = -1;

using namespace std;

EvaluateTree::EvaluateTree()
{
}


EvaluateTree::~EvaluateTree()
{
}

void EvaluateTree::get_suff(string suff)
{
	suff_ = suff;
}

void EvaluateTree::seperate_op_and_num()
{
	unsigned int i;
	int j, k;
	double num_tmp, num_int, num_decimal;
	for (i = 0, k = 0; i < suff_.length(); i++)
	{
		num_tmp = 0;
		num_int = 0;
		num_decimal = 0;
		while (suff_[i] >= '0' && suff_[i] <= '9')
		{
			num_int = num_int * 10 + (double)(suff_[i] - 48);
			i++;
		}
		if (suff_[i] == '.')
		{
			i++;
			j = 0;
			while (suff_[i] >= '0' && suff_[i] <= '9')
			{
				num_decimal += pow(10, --j) * (double)(suff_[i] - 48);
				i++;
			}
		}
		if (suff_[i] == '$')
		{
			num_tmp = num_decimal + num_int;
			num_[k] = num_tmp;
			op_[k++] = '#';
			continue;
		}
		op_[k++] = suff_[i];
	}
	total = k;
}

void EvaluateTree::create_tree()
{
	int top = 0;
	for (int i = 0; i < total; i++)
	{
		if (total == 1)
		{
			node[i].set_node(op_[i], num_[i]);
			root_ = i;
			break;
		}
		if (strchr("+-*/", op_[i]) != NULL)
		{
			node[i].set_node(op_[i], num_[i]);
			tr_ = i;
			node[tr_].allocate_rch(stack_[--top]);
			node[tr_].allocate_lch(stack_[--top]);
			stack_[top++] = tr_;
		}
		else
		{
			node[i].set_node(op_[i], num_[i]);
			tr_ = i;
			stack_[top++] = tr_;
		}
	}
	root_ = stack_[--top];
}

void EvaluateTree::caculate()
{
	while ( node[root_].op_ != '#' )
	{
		int tr = root_;
		while ( node[node[tr].lch].op_ != '#' || node[node[tr].rch].op_ != '#' )
		{
			if (node[node[tr].lch].op_ != '#')
				tr = node[tr].lch;
			else
				tr = node[tr].rch;
		}
		switch (node[tr].op_)
		{
		case '+':
		{
			node[tr].num_ = node[node[tr].lch].num_ + node[node[tr].rch].num_;
			node[tr].lch = NUL;
			node[tr].rch = NUL;
			node[tr].op_ = '#';
			break;
		}
		case '-':
		{
			node[tr].num_ = node[node[tr].lch].num_ - node[node[tr].rch].num_;
			node[tr].lch = NUL;
			node[tr].rch = NUL;
			node[tr].op_ = '#';
			break;
		}
		case '*':
		{
			node[tr].num_ = node[node[tr].lch].num_ * node[node[tr].rch].num_;
			node[tr].lch = NUL;
			node[tr].rch = NUL;
			node[tr].op_ = '#';
			break;
		}
		case '/':
		{
			node[tr].num_ = node[node[tr].lch].num_ / node[node[tr].rch].num_;
			node[tr].lch = NUL;
			node[tr].rch = NUL;
			node[tr].op_ = '#';
			break;
		}
		default:
			break;
		}
	}
	result = node[root_].num_;
}

double EvaluateTree::output()
{
	seperate_op_and_num();
	create_tree();
	caculate();
	return result;
}
