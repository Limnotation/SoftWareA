#pragma once
#include <iostream>
using namespace std;

class Calculation
{
public:
	Calculation();
	~Calculation();
	void InInfix(string inString);	//输入中缀表达式
	double OutAns();				//输出double结果值
	
private:
	int start, end;					//函数表达式'('、')'位置
	int lengthOfOperator;			//函数表达式长度
	char tempResult[256];			//函数运算的暂时结果
	string infix;					//中缀表达式
	string postfix;					//后缀表达式
	string subInfix;				//函数内的中缀表达式
	double doubleResult;			//double结果值
	string stringResult;			//string结果值
	string tempInfixL, tempInfixR;	//函数前后的子中缀表达式
	
	void InfixToPostfixAndCalculate();		//中缀表达式转后缀表达式，对后缀表达式进行计算
	void MatchBrackets(int startPosition);	//括号匹配
	void ReplaceExpression();				//将double的结果转化为string并插入到原中缀表达式中
};

