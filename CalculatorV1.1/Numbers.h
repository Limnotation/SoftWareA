#pragma once

#include "MFECToolTip.h"
//#include  "Numbers.cpp"
// Numbers 对话框

class Numbers : public CDialog
{
	DECLARE_DYNAMIC(Numbers)

public:
	CString m_strN;

	Numbers(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Numbers();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Numbers };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFECToolTip m_toolTip;
	UINT m_nCtrlIDTmp;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonPi();
	afx_msg void OnBnClickedButtonEe();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonSpace();
	virtual void OnCancel();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnBnClickedButtonDecimal();
};
