
// CalculatorProtoTypeDlg.h : 头文件
//

#pragma once


// CCalculatorProtoTypeDlg 对话框
class CCalculatorProtoTypeDlg : public CDialogEx
{
// 构造
public:
	CCalculatorProtoTypeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATORPROTOTYPE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	//定义函数（手动）
	void Bracket( CString str0,int *h );
	void Calculator();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedA1();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedA2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedLbrace();
	afx_msg void OnBnClickedRbrace();

private:
	//编辑框内字符串
	CString m_strResult;
	//
	CString m_Edit3;
	CString m_MM3;
	//按键判断
	boolean OperatorPressed;
	boolean Restarted;
};
