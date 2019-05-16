#pragma once
#ifndef INTOPST_H
#define INTOPOST_H
#include<iostream>

using namespace std;

struct node                 //链栈节点
{
	char data;				//数据域
	node* next;             //指针域
};

class InToPost
{
public:
	InToPost();
	~InToPost();
	void InInfix(string inString);
	string OutPostfix();
private:
	node* top;              //栈顶指针.top=NULL表示为空栈
	string infix;
	string postfix;

	void push(char var);	//压栈
	char pop();             //出栈.出栈之前并不判断栈是否已空.需要通过isEmpty()判断
	char topElement();		//返回栈顶元素，不改变栈
	bool isEmpty();         //判空.空返回true,反之返回false
	void InfixToPostfix();
};

#endif // !INTOPST_H


