
// CalculatorProtoType.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCalculatorProtoTypeApp:
// �йش����ʵ�֣������ CalculatorProtoType.cpp
//

class CCalculatorProtoTypeApp : public CWinApp
{
public:
	CCalculatorProtoTypeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorProtoTypeApp theApp;