#include "pch.h"
#include "Caculation.h"
#include"EvaluateTree.h"
#include"InToPost.h"
#include "MFCApplication1.h"
#include "StdAfx.h"

#include<iostream>

using namespace std;
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

Caculation::Caculation()
{
}


Caculation::~Caculation()
{
}

void Caculation::set_input( string input )
{
	input_ = input;
}

void Caculation::caculation()
{
	string tmp;
	stack_adt.InInfix( input_ );
	tmp = stack_adt.OutPostfix();
	tree_adt.get_suff(tmp);
	tree_adt.seperate_op_and_num();
	tree_adt.create_tree();
	tree_adt.caculate();
	output_ = tree_adt.output();
}

double Caculation::get_output()
{
	return output_;
}





