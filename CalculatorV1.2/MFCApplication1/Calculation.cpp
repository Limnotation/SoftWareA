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

/*����Ϊstring����׺���ʽ*/
void Calculation::InInfix(string inString)
{
	infix = inString;
}

/*���Ϊdouble���͵Ľ��*/
double Calculation::OutAns()
{
	/*��׺���ʽת��׺���ʽ���Ժ�׺���ʽ���м���*/
	InfixToPostfixAndCalculate();
	return doubleResult;
}

/*��׺���ʽת��׺���ʽ���Ժ�׺���ʽ���м���*/
void Calculation::InfixToPostfixAndCalculate()
{
	Calculation SubCalculate;
	int i = 0;
	char var;

	MyStack Stack;

	/*���ö�Ԫ��������ȼ�*/
	priorityOfOperator['('] = 0;
	priorityOfOperator['+'] = priorityOfOperator['-'] = 1;
	priorityOfOperator['*'] = priorityOfOperator['/'] = 2;

	while (i < infix.length())
	{
		if (infix[0] == '-')			//���ʽ��'-opnum'��ʼ��ת��Ϊ0-opnum
		{
			infix = '0' + infix;
		}
		if (infix[i] == '(')			//���������ţ�������ջ
		{
			Stack.push(infix[i]);
		}
		else if (infix[i] == ')')		//���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
		{
			var = Stack.pop();
			while (var != '(')
			{
				postfix += var;
				var = Stack.pop();
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
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')		//�����������������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
		{
			if (infix[i - 1] == '(' && infix[i] == '-')		//��������'(-opnum)'��ת��Ϊ'(0-opnum)'
			{
				postfix += "0$";
			}
			while (!Stack.isEmpty() && priorityOfOperator[infix[i]] <= priorityOfOperator[Stack.topElement()])
			{
				postfix += Stack.pop();
			}
			Stack.push(infix[i]);
		}
		else							                 //����һԪ����
		{
			if (infix[i] == 's' && infix[i + 1] == 'i' && infix[i + 2] == 'n')
			{
				lengthOfOperator = 3;	                    //��¼��������ȣ����ڷָ�滻�ַ���
				i = i + lengthOfOperator;
				MatchBrackets(i);		                    //����ƥ��
				SubCalculate.InInfix(subInfix);	            //��ȡ�������ڵĲ��֣���׺���ʽ��
				doubleResult = sin(SubCalculate.OutAns());	//���ú������������������ֵ��double��
				ReplaceExpression();	                    //��double�Ľ��ת��Ϊstring�����뵽ԭ��׺���ʽ��
				i = i - lengthOfOperator - 1;	            //i��ֵ�ָ�������ǰ�Ĳ�����
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
	while (!Stack.isEmpty())			//��ջ��ʣ���������ε�����׺���ʽ
	{
		postfix += Stack.pop();
	}

	/*��׺���ʽ��ֵ*/
	EvaluateTree Tree;
	Tree.get_suff(postfix);				//����string��׺���ʽ��ֵ
	doubleResult = Tree.output();		//���double�Ľ��
}

/*��ջʵ������ƥ��*/
void Calculation::MatchBrackets(int startPosition)
{
	char stack[100];		//ջ
	int top = 0;			//ջ��ָ��
	int flag = 1;			//ƥ�������־
	start = startPosition;	//��һ��'('��λ��
	end = startPosition;	//��ʼ�ӵ�һ��'('��ʼ������ʱָ�����һ��')'��λ��
	while (flag)
	{
		if (infix[end] == '(')		//����'('��'('��ջ
		{
			stack[top] = '(';
			top++;
		}
		else if (infix[end] == ')')	//����')'����ջ
		{
			stack[top] = '0';
			top--;
		}
		if (top == 0 || end >= infix.length())	//ջ�ٴ�Ϊ�ջ��������׺���ʽĩβ
		{
			flag = 0;				//ƥ�����
		}
		else
		{
			end++;					//�ж���һ��Ԫ��
		}
	}
	subInfix = infix.substr(startPosition + 1, end - startPosition - 1);	//��ȡ�������ڵĲ��֣���׺���ʽ��
}

/*��double�Ľ��ת��Ϊstring�����뵽ԭ��׺���ʽ��*/
void Calculation::ReplaceExpression()
{
	sprintf_s(tempResult, "%lf", doubleResult);	//stringתdouble
	stringResult = tempResult;
	if (start != lengthOfOperator)				//���ʽ���Ժ�����ͷ
	{
		tempInfixL = infix.substr(0, start - lengthOfOperator);	//��ȡ�������ʽ֮ǰ�ı��ʽ
	}
	else										//���ʽ�Ժ�����ʼ
	{
		tempInfixL = "";						//����֮ǰ�ı��ʽΪ��
	}
	if (end != infix.length())					//���ʽ���Ժ�����β
	{
		tempInfixR = infix.substr(end + 1);		//��ȡ�������ʽ֮��ı��ʽ
	}
	else										//���ʽ�Ժ�����β
	{
		tempInfixR = "";						//����֮��ı��ʽΪ��
	}
	infix = tempInfixL + '(' + stringResult + ')' + tempInfixR;	//ƴ�ӱ��ʽ
}
