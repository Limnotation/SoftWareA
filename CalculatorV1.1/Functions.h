#pragma once

#include "MFECToolTip.h"
// Functions 对话框

class Functions : public CDialog
{
	DECLARE_DYNAMIC(Functions)

public:
	Functions(CWnd* pParent = nullptr);   // 标准构造函数
	CString m_strN;
	virtual ~Functions();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Functions };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFECToolTip m_toolTip;
	UINT m_nCtrlID[16];
	CString m_strCtrlName[16];
	UINT m_nCtrlIDTmp;
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtonTan();
	afx_msg void OnBnClickedButtonCot();
	afx_msg void OnBnClickedButtonAcrsin();
	afx_msg void OnBnClickedButtonArccos();
	afx_msg void OnBnClickedButtonArctan();
	afx_msg void OnBnClickedButtonLog();
	afx_msg void OnBnClickedButtonSh();
	afx_msg void OnBnClickedButtonCh();
	afx_msg void OnBnClickedButtonTh();
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonExp();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnBnClickedButtonAbs();
	afx_msg void OnBnClickedButton10exp();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
