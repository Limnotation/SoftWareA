#pragma once

struct node                 //��ջ�ڵ�
{
	char data;				//������
	node* next;             //ָ����
};

class MyStack
{
public:
	MyStack();
	~MyStack();
	void push(char var);	//ѹջ
	char pop();             //��ջ.��ջ֮ǰ�����ж�ջ�Ƿ��ѿ�.��Ҫͨ��isEmpty()�ж�
	char topElement();		//����ջ��Ԫ�أ����ı�ջ
	bool isEmpty();         //�п�.�շ���true,��֮����false

private:
	node* top;              //ջ��ָ��.top=NULL��ʾΪ��ջ
};

