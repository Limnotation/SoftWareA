#pragma once
#ifndef INTOPST_H
#define INTOPOST_H
#include<iostream>

using namespace std;

struct node                 //��ջ�ڵ�
{
	char data;				//������
	node* next;             //ָ����
};

class InToPost
{
public:
	InToPost();
	~InToPost();
	void InInfix(string inString);
	string OutPostfix();
private:
	node* top;              //ջ��ָ��.top=NULL��ʾΪ��ջ
	string infix;
	string postfix;

	void push(char var);	//ѹջ
	char pop();             //��ջ.��ջ֮ǰ�����ж�ջ�Ƿ��ѿ�.��Ҫͨ��isEmpty()�ж�
	char topElement();		//����ջ��Ԫ�أ����ı�ջ
	bool isEmpty();         //�п�.�շ���true,��֮����false
	void InfixToPostfix();
};

#endif // !INTOPST_H


