#pragma once
#include "MFECToolTip.h"

// Operator 对话框

class Operator : public CDialog
{
	DECLARE_DYNAMIC(Operator)

public:
	CString m_strN;
	Operator(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Operator();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Operator };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
protected:
	CMFECToolTip m_toolTip;
	UINT m_nCtrlIDTmp;
	virtual void OnCancel();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultip();
	afx_msg void OnBnClickedButtonLbrac();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonPow();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonRbrac();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
