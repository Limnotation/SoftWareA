// Operator.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "Operator.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// Operator 对话框

IMPLEMENT_DYNAMIC(Operator, CDialog)

Operator::Operator(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Operator, pParent)
{

}

Operator::~Operator()
{
}

void Operator::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Operator, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Add, &Operator::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_Minus, &Operator::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_Multip, &Operator::OnBnClickedButtonMultip)
	ON_BN_CLICKED(IDC_BUTTON_Lbrac, &Operator::OnBnClickedButtonLbrac)
	ON_BN_CLICKED(IDC_BUTTON_Divide, &Operator::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_Pow, &Operator::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_Mod, &Operator::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_Rbrac, &Operator::OnBnClickedButtonRbrac)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



BOOL Operator::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT n = pWnd->GetDlgCtrlID();
	if (n == IDC_BUTTON_Pow)
	{
		m_toolTip.ShowToolTip(n);
		m_nCtrlIDTmp = n;
		return 1;
	}
	else if (n == IDC_BUTTON_Mod)
	{
		m_toolTip.ShowToolTip(n);
		m_nCtrlIDTmp = n;
		return 1;
	}
	m_toolTip.ErasePreviousToolTipDisplay(m_nCtrlIDTmp);
	//return CDialog::OnSetCursor(pWnd, nHitTest, message);

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void Operator::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_strN = "OVER";
	CDialog::OnCancel();
}



// Operator 消息处理程序
void Operator::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "+";      // 表达式加 "+"               
}


void Operator::OnBnClickedButtonMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "-";
}


void Operator::OnBnClickedButtonMultip()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "*";
}


void Operator::OnBnClickedButtonLbrac()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "(";
}


void Operator::OnBnClickedButtonDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "/";
}


void Operator::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "^";
}


void Operator::OnBnClickedButtonMod()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "%";
}


void Operator::OnBnClickedButtonRbrac()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = ")";
}

/* 功能:鼠标移动到相应按键时显示按键功能*/
BOOL Operator::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialog::OnInitDialog();
	m_toolTip.Create(this);
	CStringArray straInfo;

	straInfo.RemoveAll();
	straInfo.Add("x的y次方");   // 给"^"符号添加额外信息
	m_toolTip.AddControlInfo(IDC_BUTTON_Pow, straInfo, RGB(255, 255, 0));

	straInfo.RemoveAll();
	straInfo.Add("x模y");       // 给"%"符号添加额外信息
	m_toolTip.AddControlInfo(IDC_BUTTON_Mod, straInfo, RGB(255, 255, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}