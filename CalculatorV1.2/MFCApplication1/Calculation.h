#pragma once
#include <iostream>
using namespace std;

class Calculation
{
public:
	Calculation();
	~Calculation();
	void InInfix(string inString);	//������׺���ʽ
	double OutAns();				//���double���ֵ
	
private:
	int start, end;					//�������ʽ'('��')'λ��
	int lengthOfOperator;			//�������ʽ����
	char tempResult[256];			//�����������ʱ���
	string infix;					//��׺���ʽ
	string postfix;					//��׺���ʽ
	string subInfix;				//�����ڵ���׺���ʽ
	double doubleResult;			//double���ֵ
	string stringResult;			//string���ֵ
	string tempInfixL, tempInfixR;	//����ǰ�������׺���ʽ
	
	void InfixToPostfixAndCalculate();		//��׺���ʽת��׺���ʽ���Ժ�׺���ʽ���м���
	void MatchBrackets(int startPosition);	//����ƥ��
	void ReplaceExpression();				//��double�Ľ��ת��Ϊstring�����뵽ԭ��׺���ʽ��
};

