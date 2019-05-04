
// CalculatorProtoTypeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CalculatorProtoType.h"
#include "CalculatorProtoTypeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorProtoTypeDlg 对话框



CCalculatorProtoTypeDlg::CCalculatorProtoTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorProtoTypeDlg::IDD, pParent)
	,m_strResult( _T("") )
	,OperatorPressed(false)
	,Restarted(false)
	,m_Edit3(_T(""))
	,m_MM3(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorProtoTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strResult);
	DDX_Text(pDX, IDC_EDIT1, m_Edit3 );
	DDX_Text(pDX, IDC_EDIT1,m_MM3 );
}

BEGIN_MESSAGE_MAP(CCalculatorProtoTypeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorProtoTypeDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(0, &CCalculatorProtoTypeDlg::OnBnClicked0)
	ON_BN_CLICKED(A1, &CCalculatorProtoTypeDlg::OnBnClickedA1)
	ON_BN_CLICKED(A2, &CCalculatorProtoTypeDlg::OnBnClickedA2)
	ON_BN_CLICKED(3, &CCalculatorProtoTypeDlg::OnBnClicked3)
	ON_BN_CLICKED(4, &CCalculatorProtoTypeDlg::OnBnClicked4)
	ON_BN_CLICKED(5, &CCalculatorProtoTypeDlg::OnBnClicked5)
	ON_BN_CLICKED(6, &CCalculatorProtoTypeDlg::OnBnClicked6)
	ON_BN_CLICKED(7, &CCalculatorProtoTypeDlg::OnBnClicked7)
	ON_BN_CLICKED(8, &CCalculatorProtoTypeDlg::OnBnClicked8)
	ON_BN_CLICKED(9, &CCalculatorProtoTypeDlg::OnBnClicked9)
	ON_BN_CLICKED(Add, &CCalculatorProtoTypeDlg::OnBnClickedAdd)
	ON_BN_CLICKED(Sub, &CCalculatorProtoTypeDlg::OnBnClickedSub)
	ON_BN_CLICKED(Mul, &CCalculatorProtoTypeDlg::OnBnClickedMul)
	ON_BN_CLICKED(Div, &CCalculatorProtoTypeDlg::OnBnClickedDiv)
	ON_BN_CLICKED(LBrace, &CCalculatorProtoTypeDlg::OnBnClickedLbrace)
	ON_BN_CLICKED(RBrace, &CCalculatorProtoTypeDlg::OnBnClickedRbrace)
END_MESSAGE_MAP()


// CCalculatorProtoTypeDlg 消息处理程序

BOOL CCalculatorProtoTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorProtoTypeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorProtoTypeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorProtoTypeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorProtoTypeDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

#1015

	// TODO:  在此添加控件通知处理程序代码
}



/*如下部分为对应按钮的事件响应程序，一般是自定义的*/
void CCalculatorProtoTypeDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "0";
	m_strResult += "0";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}



void CCalculatorProtoTypeDlg::OnBnClickedA1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "1";
	m_strResult += "1";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}




void CCalculatorProtoTypeDlg::OnBnClickedA2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "2";
	m_strResult += "2";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}



void CCalculatorProtoTypeDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "3";
	m_strResult += "3";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "4";
	m_strResult += "4";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}




void CCalculatorProtoTypeDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "5";
	m_strResult += "5";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "6";
	m_strResult += "6";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "7";
	m_strResult += "7";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "8";
	m_strResult += "8";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "9";
	m_strResult += "9";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                      //把编辑框显示的文本字符串传给相应的变量m_strResult
	m_strResult += "+";                                    //在变量m_strResult后面加“+”
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                      //把编辑框显示的文本字符串传给相应的变量m_strResult
	m_strResult += "-";                                    //在变量m_strResult后面加“-”
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                      //把编辑框显示的文本字符串传给相应的变量m_strResult
	m_strResult += "*";                                    //在变量m_strResult后面加“*”
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                      //把编辑框显示的文本字符串传给相应的变量m_strResult
	m_strResult += "/";                                    //在变量m_strResult后面加“/”
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedLbrace()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "(";
	else 
		m_strResult += "(";
	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedRbrace()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);                                     //把编辑框显示的文本字符串传给相应的变量m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = ")";
	else 
		m_strResult += ")";
	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}

void CCalculatorProtoTypeDlg::Calculator()
{
	UpdateData(TRUE);

}