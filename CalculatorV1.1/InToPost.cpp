#include <iostream>
#include "InToPost.h"
//#include"pch.h"
#include <map>

using namespace std;
map<char, int> p;

InToPost::InToPost()
{
	top = NULL;				//top=NULL��ʾ��ջΪ��
}


InToPost::~InToPost()
{
	node* ptr = NULL;

	while (top != NULL)     //ѭ���ͷ�ջ�ڵ�ռ�
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

	ptr->data = var;        //��ջ����ֵ
	ptr->next = top;        //��ջ��ָ���ջ��

	top = ptr;              //topָ����ջ��
}

char InToPost::pop()
{
	char var;
	node* ptr = top->next;  //Ԥ����һ�ڵ��ָ��
	var = top->data;		//Ԥ��ջ��Ԫ��
	delete top;             //�ͷ�ջ���ռ�
	top = ptr;              //ջ���仯
	return var;
}

char InToPost::topElement()
{
	return top->data;		//����ջ��Ԫ��
}

bool InToPost::isEmpty()
{
	return top == NULL;     //ջ��ΪNULL��ʾջ��
}

void InToPost::InfixToPostfix()
{
	int i = 0;
	char var;

	p['('] = 0;
	p['+'] = p['-'] = 1;
	p['*'] = p['/'] = 2;

	if (infix[0] == '-')				//���ʽ��'-opnum'��ʼ��ת��Ϊ0-opnum
	{
		infix = '0' + infix;
	}
	while (i < infix.length())
	{
		if (infix[i] == '(')			//���������ţ�������ջ
		{
			push(infix[i]);
		}
		else if (infix[i] == ')')		//���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
		{
			var = pop();
			while (var != '(')
			{
				postfix += var;
				var = pop();
			}
		}
		else if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.')	//������������ֱ�����
		{
			postfix += infix[i];
			if (infix[i + 1] > '9' || (infix[i + 1] < '0' && infix[i + 1] != '.'))
			{
				postfix += '$';			//������ĩβ��'$'��ǽ���
			}
		}
		else							//�����������������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
		{
			if (infix[i - 1] == '(' && infix[i] == '-')		//��������'(-opnum)'��ת��Ϊ'(0-opnum)'
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
	while (!isEmpty())				//��ջ��ʣ���������ε�����׺���ʽ
	{
		postfix += pop();
	}
}



