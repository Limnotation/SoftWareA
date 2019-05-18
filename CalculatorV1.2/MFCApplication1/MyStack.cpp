#include <iostream>
#include "MyStack.h"
using namespace std;

MyStack::MyStack()
{
	top = NULL;				//top=NULL表示链栈为空
}

MyStack::~MyStack()
{
	node* ptr = NULL;

	while (top != NULL)     //循环释放栈节点空间
	{
		ptr = top->next;
		delete top;
		top = ptr;
	}
}

void MyStack::push(char var)
{
	node* ptr = new node;

	ptr->data = var;        //新栈顶存值
	ptr->next = top;        //新栈顶指向旧栈顶

	top = ptr;              //top指向新栈顶
}

char MyStack::pop()
{
	char var;
	node* ptr = top->next;  //预存下一节点的指针
	var = top->data;		//预存栈顶元素
	delete top;             //释放栈顶空间
	top = ptr;              //栈顶变化
	return var;
}

char MyStack::topElement()
{
	return top->data;		//返回栈顶元素
}

bool MyStack::isEmpty()
{
	return top == NULL;     //栈顶为NULL表示栈空
}
