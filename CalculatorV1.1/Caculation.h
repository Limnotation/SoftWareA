#pragma once
#include"InToPost.h"
#include"EvaluateTree.h"
#include "MFCApplication1.h"
#include<iostream>

using namespace std;

class Caculation
{
public:
	Caculation();
	~Caculation();
	string input_;
	double output_;
	InToPost stack_adt;
	EvaluateTree tree_adt;
	void set_input(string input);
	void caculation();
	double get_output();
};


