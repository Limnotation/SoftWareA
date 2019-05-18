// Functions.cpp: 实现文件
//
/**/
#include "pch.h"
#include "MFCApplication1.h"
#include "Functions.h"
#include "afxdialogex.h"


// Functions 对话框

IMPLEMENT_DYNAMIC(Functions, CDialog)

Functions::Functions(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Functions, pParent)
{

}

Functions::~Functions()
{
}

void Functions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Functions, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Sin, &Functions::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_Cos, &Functions::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_Tan, &Functions::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_Cot, &Functions::OnBnClickedButtonCot)
	ON_BN_CLICKED(IDC_BUTTON_Acrsin, &Functions::OnBnClickedButtonAcrsin)
	ON_BN_CLICKED(IDC_BUTTON_Arccos, &Functions::OnBnClickedButtonArccos)
	ON_BN_CLICKED(IDC_BUTTON_Arctan, &Functions::OnBnClickedButtonArctan)
	ON_BN_CLICKED(IDC_BUTTON_Log, &Functions::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_Sh, &Functions::OnBnClickedButtonSh)
	ON_BN_CLICKED(IDC_BUTTON_Ch, &Functions::OnBnClickedButtonCh)
	ON_BN_CLICKED(IDC_BUTTON_Th, &Functions::OnBnClickedButtonTh)
	ON_BN_CLICKED(IDC_BUTTON_In, &Functions::OnBnClickedButtonIn)
	ON_BN_CLICKED(IDC_BUTTON_Exp, &Functions::OnBnClickedButtonExp)
	ON_BN_CLICKED(IDC_BUTTON_Sqrt, &Functions::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_Abs, &Functions::OnBnClickedButtonAbs)
	ON_BN_CLICKED(IDC_BUTTON_10Exp, &Functions::OnBnClickedButton10exp)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

BOOL Functions::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_nCtrlID[0] = IDC_BUTTON_Sin;    m_nCtrlID[1] = IDC_BUTTON_Cos;     m_nCtrlID[2] = IDC_BUTTON_Tan;
	m_nCtrlID[3] = IDC_BUTTON_Cot;    m_nCtrlID[4] = IDC_BUTTON_Log;     m_nCtrlID[5] = IDC_BUTTON_Arccos;
	m_nCtrlID[6] = IDC_BUTTON_Acrsin; m_nCtrlID[7] = IDC_BUTTON_In;      m_nCtrlID[8] = IDC_BUTTON_Sqrt;
	m_nCtrlID[9] = IDC_BUTTON_Abs;    m_nCtrlID[10] = IDC_BUTTON_Sh;     m_nCtrlID[11] = IDC_BUTTON_Exp;
	m_nCtrlID[12] = IDC_BUTTON_Ch;    m_nCtrlID[13] = IDC_BUTTON_Arctan; m_nCtrlID[14] = IDC_BUTTON_Th;
	m_nCtrlID[15] = IDC_BUTTON_10Exp;
	m_strCtrlName[0] = "正弦"; m_strCtrlName[1] = "余弦"; m_strCtrlName[2] = "正切";
	m_strCtrlName[3] = "余切"; m_strCtrlName[4] = "以10为底的对数"; m_strCtrlName[5] = "反余弦";
	m_strCtrlName[6] = "反正弦"; m_strCtrlName[7] = "以e为底的对数"; m_strCtrlName[8] = "开平方";
	m_strCtrlName[9] = "取绝对值"; m_strCtrlName[10] = "双曲正弦"; m_strCtrlName[11] = "e的幂次方";
	m_strCtrlName[12] = "双曲余弦"; m_strCtrlName[13] = "反正切"; m_strCtrlName[14] = "双曲正切";
	m_strCtrlName[15] = "10的幂次方";
	m_toolTip.Create(this);
	CStringArray straInfo;
	for (int i = 0; i < 16; i++)
	{
		straInfo.RemoveAll();
		straInfo.Add( m_strCtrlName[i] );
		m_toolTip.AddControlInfo( m_nCtrlID[i], straInfo, RGB(255, 255, 0) );
	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void Functions::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_strN = "OVER";
	CDialog::OnCancel();
}

BOOL Functions::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT n = pWnd->GetDlgCtrlID();
	for (int i = 0; i < 16; i++)
	{
		if (n == m_nCtrlID[i])
		{
			m_toolTip.ShowToolTip(n);
			m_nCtrlIDTmp = n;
			return 1;
		}
	}
	m_toolTip.ErasePreviousToolTipDisplay(m_nCtrlIDTmp);

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}


// Functions 消息处理程序
void Functions::OnBnClickedButtonSin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "sin( )";
}


void Functions::OnBnClickedButtonCos()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "cos( )";
}


void Functions::OnBnClickedButtonTan()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "tan( )";
}


void Functions::OnBnClickedButtonCot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "cot( )";
}


void Functions::OnBnClickedButtonAcrsin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "as( )";
}


void Functions::OnBnClickedButtonArccos()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "ac( )";
}


void Functions::OnBnClickedButtonArctan()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "at( )";
}


void Functions::OnBnClickedButtonLog()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "log( )";
}


void Functions::OnBnClickedButtonSh()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "sh( )";
}


void Functions::OnBnClickedButtonCh()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "ch( )";
}


void Functions::OnBnClickedButtonTh()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "th( )";
}


void Functions::OnBnClickedButtonIn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "In( )";
}


void Functions::OnBnClickedButtonExp()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "e^( )";
}


void Functions::OnBnClickedButtonSqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "sqrt( )";
}


void Functions::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "abs( )";
}


void Functions::OnBnClickedButton10exp()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strN = "exp( )";
}
