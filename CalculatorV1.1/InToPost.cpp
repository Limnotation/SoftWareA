#include <iostream>
#include "InToPost.h"
//#include"pch.h"
#include <map>

using namespace std;
map<char, int> p;

InToPost::InToPost()
{
	top = NULL;				//top=NULL表示链栈为空
}


InToPost::~InToPost()
{
	node* ptr = NULL;

	while (top != NULL)     //循环释放栈节点空间
	{
		ptr = top->next;
		delete top;
		top = ptr;
	}
}

void InToPost::InInfix(string inString)
{
	infix = inString;
}

string InToPost::OutPostfix()
{
	InfixToPostfix();
	return postfix;
}

void InToPost::push(char var)
{
	node* ptr = new node;

	ptr->data = var;        //新栈顶存值
	ptr->next = top;        //新栈顶指向旧栈顶

	top = ptr;              //top指向新栈顶
}

char InToPost::pop()
{
	char var;
	node* ptr = top->next;  //预存下一节点的指针
	var = top->data;		//预存栈顶元素
	delete top;             //释放栈顶空间
	top = ptr;              //栈顶变化
	return var;
}

char InToPost::topElement()
{
	return top->data;		//返回栈顶元素
}

bool InToPost::isEmpty()
{
	return top == NULL;     //栈顶为NULL表示栈空
}

void InToPost::InfixToPostfix()
{
	int i = 0;
	char var;

	p['('] = 0;
	p['+'] = p['-'] = 1;
	p['*'] = p['/'] = 2;

	if (infix[0] == '-')				//表达式以'-opnum'开始，转化为0-opnum
	{
		infix = '0' + infix;
	}
	while (i < infix.length())
	{
		if (infix[i] == '(')			//遇到左括号：将其入栈
		{
			push(infix[i]);
		}
		else if (infix[i] == ')')		//遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
		{
			var = pop();
			while (var != '(')
			{
				postfix += var;
				var = pop();
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
		else							//遇到操作符：弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈
		{
			if (infix[i - 1] == '(' && infix[i] == '-')		//遇到负数'(-opnum)'，转化为'(0-opnum)'
			{
				postfix += "0$";
			}
			while (!isEmpty() && p[infix[i]] <= p[topElement()])
			{
				postfix += pop();
			}
			push(infix[i]);
		}
		i++;
	}
	while (!isEmpty())				//将栈中剩余内容依次弹出后缀表达式
	{
		postfix += pop();
	}
}



