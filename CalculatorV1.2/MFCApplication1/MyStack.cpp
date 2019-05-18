#include <iostream>
#include "MyStack.h"
using namespace std;

MyStack::MyStack()
{
	top = NULL;				//top=NULL��ʾ��ջΪ��
}

MyStack::~MyStack()
{
	node* ptr = NULL;

	while (top != NULL)     //ѭ���ͷ�ջ�ڵ�ռ�
	{
		ptr = top->next;
		delete top;
		top = ptr;
	}
}

void MyStack::push(char var)
{
	node* ptr = new node;

	ptr->data = var;        //��ջ����ֵ
	ptr->next = top;        //��ջ��ָ���ջ��

	top = ptr;              //topָ����ջ��
}

char MyStack::pop()
{
	char var;
	node* ptr = top->next;  //Ԥ����һ�ڵ��ָ��
	var = top->data;		//Ԥ��ջ��Ԫ��
	delete top;             //�ͷ�ջ���ռ�
	top = ptr;              //ջ���仯
	return var;
}

char MyStack::topElement()
{
	return top->data;		//����ջ��Ԫ��
}

bool MyStack::isEmpty()
{
	return top == NULL;     //ջ��ΪNULL��ʾջ��
}
