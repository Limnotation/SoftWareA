#pragma once

struct node                 //链栈节点
{
	char data;				//数据域
	node* next;             //指针域
};

class MyStack
{
public:
	MyStack();
	~MyStack();
	void push(char var);	//压栈
	char pop();             //出栈.出栈之前并不判断栈是否已空.需要通过isEmpty()判断
	char topElement();		//返回栈顶元素，不改变栈
	bool isEmpty();         //判空.空返回true,反之返回false

private:
	node* top;              //栈顶指针.top=NULL表示为空栈
};

