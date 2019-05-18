#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>
#include <map>
#include "Calculation.h"
#include "MyStack.h"
#include "EvaluateTree.h"

using namespace std;
map<char, int> priorityOfOperator;

Calculation::Calculation()
{
}


Calculation::~Calculation()
{
}

/*输入为string的中缀表达式*/
void Calculation::InInfix(string inString)
{
	infix = inString;
}

/*输出为double类型的结果*/
double Calculation::OutAns()
{
	/*中缀表达式转后缀表达式，对后缀表达式进行计算*/
	InfixToPostfixAndCalculate();
	return doubleResult;
}

/*中缀表达式转后缀表达式，对后缀表达式进行计算*/
void Calculation::InfixToPostfixAndCalculate()
{
	Calculation SubCalculate;
	int i = 0;
	char var;

	MyStack Stack;

	/*设置二元运算符优先级*/
	priorityOfOperator['('] = 0;
	priorityOfOperator['+'] = priorityOfOperator['-'] = 1;
	priorityOfOperator['*'] = priorityOfOperator['/'] = 2;

	while (i < infix.length())
	{
		if (infix[0] == '-')			//表达式以'-opnum'开始，转化为0-opnum
		{
			infix = '0' + infix;
		}
		if (infix[i] == '(')			//遇到左括号：将其入栈
		{
			Stack.push(infix[i]);
		}
		else if (infix[i] == ')')		//遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
		{
			var = Stack.pop();
			while (var != '(')
			{
				postfix += var;
				var = Stack.pop();
			}
		}
		else if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.')	//遇到操作数：直接输出
		{
			postfix += infix[i];
			if (infix[i + 1] > '9' || (infix[i + 1] < '0' && infix[i + 1] != '.'))
			{
				postfix += '$';			//在数字末尾用'$'标记结束
			}
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')		//遇到操作符：弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈
		{
			if (infix[i - 1] == '(' && infix[i] == '-')		//遇到负数'(-opnum)'，转化为'(0-opnum)'
			{
				postfix += "0$";
			}
			while (!Stack.isEmpty() && priorityOfOperator[infix[i]] <= priorityOfOperator[Stack.topElement()])
			{
				postfix += Stack.pop();
			}
			Stack.push(infix[i]);
		}
		else							                 //遇到一元函数
		{
			if (infix[i] == 's' && infix[i + 1] == 'i' && infix[i + 2] == 'n')
			{
				lengthOfOperator = 3;	                    //记录运算符长度，便于分割、替换字符串
				i = i + lengthOfOperator;
				MatchBrackets(i);		                    //括号匹配
				SubCalculate.InInfix(subInfix);	            //截取出函数内的部分（中缀表达式）
				doubleResult = sin(SubCalculate.OutAns());	//调用函数自身，计算出函数的值（double）
				ReplaceExpression();	                    //将double的结果转化为string并插入到原中缀表达式中
				i = i - lengthOfOperator - 1;	            //i的值恢复到函数前的操作符
			}
			else if (infix[i] == 'c' && infix[i + 1] == 'o' && infix[i + 2] == 's')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = cos(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 't' && infix[i + 1] == 'a' && infix[i + 2] == 'n')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = tan(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'c' && infix[i + 1] == 'o' && infix[i + 2] == 't')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = 1 / tan(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'a' && infix[i + 1] == 's')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = asin(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'a' && infix[i + 1] == 'c')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = acos(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'a' && infix[i + 1] == 't')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = atan(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'l' && infix[i + 1] == 'o' && infix[i + 2] == 'g')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = log10(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 's' && infix[i + 1] == 'h')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = sinh(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'c' && infix[i + 1] == 'h')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = cosh(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 't' && infix[i + 1] == 'h')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = tanh(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'I' && infix[i + 1] == 'n')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = log(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'e' && infix[i + 1] == '^')
			{
				lengthOfOperator = 2;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = exp(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 's' && infix[i + 1] == 'q' && infix[i + 2] == 'r' && infix[i + 3] == 't')
			{
				lengthOfOperator = 4;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = sqrt(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'a' && infix[i + 1] == 'b' && infix[i + 2] == 's')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = fabs(SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
			else if (infix[i] == 'e' && infix[i + 1] == 'x' && infix[i + 2] == 'p')
			{
				lengthOfOperator = 3;
				i = i + lengthOfOperator;
				MatchBrackets(i);
				SubCalculate.InInfix(subInfix);
				doubleResult = pow(10, SubCalculate.OutAns());
				ReplaceExpression();
				i = i - lengthOfOperator - 1;
			}
		}
		i++;
	}
	while (!Stack.isEmpty())			//将栈中剩余内容依次弹出后缀表达式
	{
		postfix += Stack.pop();
	}

	/*后缀表达式求值*/
	EvaluateTree Tree;
	Tree.get_suff(postfix);				//输入string后缀表达式的值
	doubleResult = Tree.output();		//输出double的结果
}

/*用栈实现括号匹配*/
void Calculation::MatchBrackets(int startPosition)
{
	char stack[100];		//栈
	int top = 0;			//栈顶指针
	int flag = 1;			//匹配结束标志
	start = startPosition;	//第一个'('的位置
	end = startPosition;	//初始从第一个'('开始，结束时指向最后一个')'的位置
	while (flag)
	{
		if (infix[end] == '(')		//遇到'('，'('入栈
		{
			stack[top] = '(';
			top++;
		}
		else if (infix[end] == ')')	//遇到')'，出栈
		{
			stack[top] = '0';
			top--;
		}
		if (top == 0 || end >= infix.length())	//栈再次为空或遍历到中缀表达式末尾
		{
			flag = 0;				//匹配结束
		}
		else
		{
			end++;					//判断下一个元素
		}
	}
	subInfix = infix.substr(startPosition + 1, end - startPosition - 1);	//截取出函数内的部分（中缀表达式）
}

/*将double的结果转化为string并插入到原中缀表达式中*/
void Calculation::ReplaceExpression()
{
	sprintf_s(tempResult, "%lf", doubleResult);	//string转double
	stringResult = tempResult;
	if (start != lengthOfOperator)				//表达式不以函数表开头
	{
		tempInfixL = infix.substr(0, start - lengthOfOperator);	//截取函数表达式之前的表达式
	}
	else										//表达式以函数开始
	{
		tempInfixL = "";						//函数之前的表达式为空
	}
	if (end != infix.length())					//表达式不以函数结尾
	{
		tempInfixR = infix.substr(end + 1);		//截取函数表达式之后的表达式
	}
	else										//表达式以函数结尾
	{
		tempInfixR = "";						//函数之后的表达式为空
	}
	infix = tempInfixL + '(' + stringResult + ')' + tempInfixR;	//拼接表达式
}
