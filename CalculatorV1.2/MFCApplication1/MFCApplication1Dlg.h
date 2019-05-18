// MFCApplication1Dlg.h: 头文件
//
#pragma once
//#include "Calculation.h"

#include "Numbers.h"
#include "Operator.h"
#include "Functions.h"
#include "Calculation.h"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	Calculation calcu;     // 计算核心算法部分
	Numbers *pNUMDlg;       // 创建数字键盘对话框
	Operator *pOPDlg;       // 创建操作符键盘对话框
	Functions *pFUNCDlg;    // 创建运算函数键盘对话框
// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
	CButton m_radio_radian;      // 角度制选择按钮
	CButton m_radio_degree;      // 弧度制选择按钮
	CEdit m_strExpc;             // 输入表达式的编辑框
	CString m_strRes;            // 存储输出表达式的字符串
	CString m_strExp;            // 存储表达式的字符串
	//CButton m_btn_convert;       // 
	CString strRes;
	

//#endif
	public:
		virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
		virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	CBitmap m_bitmap;
	CRect m_rect;
	CMenu m_menu;
	CMenu m_menu2;
	CStringArray m_menuItem;
	CString m_strResTmp;
	bool bIsNumBoardOpen;    // 标志位判断数字键盘是否需要打开
	bool bIsOpBoardOpen;     // 标志位判断操作符键盘是否需要打开
	bool bIsFuncBoardOpen;   // 标志位判断函数键盘是否需要打开
	bool bIsOk;              // 标志位判断是否点击了"="按键
	int m_nlen;
	int m_nStart;
	int m_nEnd;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	

	/*如下是关于主键盘的按键的事件响应函数的定义*/
	afx_msg void OnBnClickedButtonNumbers();         // 数字键盘按键按钮
	afx_msg void OnTimer(UINT_PTR nIDEvent);         // Timer()函数
	afx_msg void OnBnClickedButtonOperator();        // 操作数键盘按钮
	afx_msg void OnBnClickedButtonFunctions();       // 函数键盘按钮
	afx_msg void OnBnClickedButtonConstant();        // 常数表按钮
	afx_msg void OnBnClickedButtonHistrexp();        // 历史表达式按钮
	afx_msg void OnMPi();	                         // 常数:圆周率Π                      
	afx_msg void OnMC();						     // 常数:真空中光速
	afx_msg void OnMNa();                            // 常数:阿伏伽德罗常数
	afx_msg void OnMG();                             // 常数:万有引力常数
	afx_msg void OnMR();                             // 常数:摩尔气体常数
	afx_msg void OnMK();                             // 常数:玻尔兹曼常数
	afx_msg void OnMVm();                            // 常数:摩尔体积
	afx_msg void OnMKe();                            // 常数:静电力常量
	afx_msg void OnME0();                            // 常数:真空中介电常数
	afx_msg void OnME();                             // 常数:自然常数e
	//afx_msg void OnBnClickedBtnConvert();
	DECLARE_MESSAGE_MAP()
private:
	//void Paster(CString strSign);
	void Paster(CString strSign, BOOL bIsSingle); // 函数功能: 对字符串进行修改粘贴操作
	void AddToHistr(CString strExp);              
public:
	afx_msg void OnBnClickedOk();          // "="按键的事件响应函数定义
	afx_msg void OnBnClickedButtonCancel();// "退出"按键的事件响应函数定义
};
