// Numbers.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "Numbers.h"
#include "afxdialogex.h"


// Numbers 对话框

IMPLEMENT_DYNAMIC(Numbers, CDialog)

Numbers::Numbers(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Numbers, pParent)
{

}

Numbers::~Numbers()
{
}

void Numbers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Numbers, CDialog)

	ON_BN_CLICKED(IDC_BUTTON_Pi, &Numbers::OnBnClickedButtonPi)
	ON_BN_CLICKED(IDC_BUTTON_EE, &Numbers::OnBnClickedButtonEe)
	ON_BN_CLICKED(IDC_BUTTON_0, &Numbers::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &Numbers::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &Numbers::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &Numbers::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &Numbers::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &Numbers::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &Numbers::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &Numbers::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &Numbers::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &Numbers::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_Dot, &Numbers::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_Back, &Numbers::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_Space, &Numbers::OnBnClickedButtonSpace)
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_BUTTON_Decimal, &Numbers::OnBnClickedButtonDecimal)
END_MESSAGE_MAP()


// Numbers 消息处理程序




/* 功能:显示符号代表的数字意义 */
BOOL Numbers::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_toolTip.Create(this);
	CStringArray straInfo;

	// TODO:  在此添加额外的初始化
	straInfo.RemoveAll();
	straInfo.Add("圆周率π");
	m_toolTip.AddControlInfo(IDC_BUTTON_Pi, straInfo, RGB(255, 255, 0));

	straInfo.RemoveAll();
	straInfo.Add("自然对数e");
	m_toolTip.AddControlInfo(IDC_BUTTON_EE, straInfo, RGB(255, 255, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Numbers::OnBnClickedButtonPi()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "PI";
}


void Numbers::OnBnClickedButtonEe()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "e";
}


void Numbers::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "0";
}


void Numbers::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "1";
}


void Numbers::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "2";
}


void Numbers::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "3";
}


void Numbers::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "4";
}


void Numbers::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "5";
}


void Numbers::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "6";
}


void Numbers::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "7";
}


void Numbers::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "8";
}


void Numbers::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "9";
}


void Numbers::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = ".";
}


void Numbers::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "BACK";
}


void Numbers::OnBnClickedButtonSpace()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = " ";
}


void Numbers::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_strN = "OVER";
	CDialog::OnCancel();
}


BOOL Numbers::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	UINT n = pWnd->GetDlgCtrlID();
	bool bOk = 0;

    if ( n == IDC_BUTTON_EE )
		bOk = 1;
	else if ( n == IDC_BUTTON_Pi )
		bOk = 1;
	if ( bOk )
	{
		m_toolTip.ShowToolTip(n);
		m_nCtrlIDTmp = n;
		return 1;
	}
	m_toolTip.ErasePreviousToolTipDisplay(m_nCtrlIDTmp);
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


void Numbers::OnBnClickedButtonDecimal()
{
	// TODO: 在此添加控件通知处理程序代码
	// do nothing
}
