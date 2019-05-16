
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "Numbers.h"
#include "Operator.h"
#include "Functions.h"
#include "StdAfx.h"
#include "Caculation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_COMMAND(ID_M_E, &CAboutDlg::OnME)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_strExp = _T("");   // 表达式字符串形式
	m_strRes = _T("");   // 结果字符串形式
	m_hIcon = AfxGetApp()->LoadIcon( IDI_ICON1 ); // 修改应用图标
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON_Functions, Function);
	DDX_Control(pDX, IDC_BTN_CONVERT, m_btn_convert);
	DDX_Control(pDX, IDC_RADIO1, m_radio_radian);
	DDX_Control(pDX, IDC_RADIO2, m_radio_degree);
	DDX_Control(pDX, IDC_EDIT1, m_strExpc);
	DDX_Text(pDX, IDC_EDIT1, m_strExp);
	DDX_Text(pDX, IDC_EDIT2, m_strRes);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	//ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	//ON_BN_CLICKED(OK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_NUmbers, &CMFCApplication1Dlg::OnBnClickedButtonNumbers)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_Operator, &CMFCApplication1Dlg::OnBnClickedButtonOperator)
	ON_BN_CLICKED(IDC_BUTTON_Functions, &CMFCApplication1Dlg::OnBnClickedButtonFunctions)
	ON_BN_CLICKED(IDC_BUTTON_Constant, &CMFCApplication1Dlg::OnBnClickedButtonConstant)
	ON_BN_CLICKED(IDC_BUTTON_HistrExp, &CMFCApplication1Dlg::OnBnClickedButtonHistrexp)
	//ON_BN_CLICKED(IDC_BUTTON_Cancel, &CMFCApplication1Dlg::OnBnClickedButtonCancel)
	ON_COMMAND(ID_M_PI, &CMFCApplication1Dlg::OnMPi)
	ON_COMMAND(ID_M_E, &CMFCApplication1Dlg::OnME)
	ON_COMMAND(ID_M_C, &CMFCApplication1Dlg::OnMC)
	ON_COMMAND(ID_M_NA, &CMFCApplication1Dlg::OnMNa)
	ON_COMMAND(ID_M_G, &CMFCApplication1Dlg::OnMG)
	ON_COMMAND(ID_M_R, &CMFCApplication1Dlg::OnMR)
	ON_COMMAND(ID_M_K, &CMFCApplication1Dlg::OnMK)
	ON_COMMAND(ID_M_VM, &CMFCApplication1Dlg::OnMVm)
	ON_COMMAND(ID_M_KE, &CMFCApplication1Dlg::OnMKe)
	ON_COMMAND(ID_M_E0, &CMFCApplication1Dlg::OnME0)
	//ON_BN_CLICKED(IDC_BTN_CONVERT, &CMFCApplication1Dlg::OnBnClickedBtnConvert)
	ON_BN_CLICKED(OK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_Cancel, &CMFCApplication1Dlg::OnBnClickedButtonCancel)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	/*ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	}*/

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

		// TODO: Add extra initialization here
	m_menu2.CreatePopupMenu();
	pNUMDlg = new Numbers;
	pNUMDlg->Create( IDD_DIALOG_Numbers );        // 设置数字键盘窗口
	pOPDlg = new Operator;
	pOPDlg->Create(IDD_Operator);               // 设置操作数键盘窗口
	pFUNCDlg = new Functions;
	pFUNCDlg->Create( IDD_DIALOG_Functions );   // 设置函数键盘窗口
	bIsNumBoardOpen = 0;
	bIsOpBoardOpen = 0;
	bIsFuncBoardOpen = 0;
	bIsOk = 0;
	m_radio_radian.SetCheck(1);
	m_btn_convert.SetBitmap(m_bitmap);

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if ( IsIconic() )
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData(1);
	if ( pNUMDlg->m_strN == "OVER" )
	{
		bIsNumBoardOpen = 0;
		KillTimer(0);
	}
	else if ( pNUMDlg->m_strN == "BACK" )
	{
		UpdateData(1);
		Paster( "", 0 );
		m_strExpc.GetSel( m_nStart, m_nEnd );
		m_strExp.Delete( m_nStart - 1 );
		UpdateData(0);
		m_strExpc.SetFocus();
		m_strExpc.SetSel(m_nStart - 1, m_nStart - 1);
		pNUMDlg->m_strN = "";
	}
	else if (!pNUMDlg->m_strN.IsEmpty())
	{
		Paster(pNUMDlg->m_strN, 0);
		pNUMDlg->m_strN = "";
	}

	if (pOPDlg->m_strN == "OVER")
	{
		bIsOpBoardOpen = 0;
		KillTimer(1);
	}
	else if (!pOPDlg->m_strN.IsEmpty())
	{
		Paster(pOPDlg->m_strN, 0);
		pOPDlg->m_strN = "";
	}

	if (pFUNCDlg->m_strN == "OVER")
	{
		bIsFuncBoardOpen = 0;
		KillTimer(2);
	}
	else if (!pFUNCDlg->m_strN.IsEmpty())
	{
		Paster(pFUNCDlg->m_strN, 1);
		pFUNCDlg->m_strN = "";
	}
	if (nIDEvent == 3)
	{
		GetWindowRect(m_rect);
		pNUMDlg->SetWindowPos( NULL, m_rect.left + 375, m_rect.top, -1, -1, SWP_NOSIZE );
		pFUNCDlg->SetWindowPos( NULL, m_rect.left, m_rect.top - 165, -1, -1, SWP_NOSIZE );
		pOPDlg->SetWindowPos( NULL, m_rect.left + 256, m_rect.top - 118, -1, -1, SWP_NOSIZE );
	}
	UpdateData(0);
	CDialogEx::OnTimer(nIDEvent);
}

/* 函数功能:定义数字键盘窗口的行为,包括大小,位置等*/
void CMFCApplication1Dlg::OnBnClickedButtonNumbers()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!bIsNumBoardOpen)
	{
		GetWindowRect(m_rect);
		pNUMDlg->SetWindowPos( NULL, m_rect.left + 610, m_rect.top, -1, -1, SWP_NOSIZE );
		pNUMDlg->ShowWindow(SW_SHOW);
		SetTimer(0, 200, NULL);
		bIsNumBoardOpen = 1;
	}
	else
	{
		pNUMDlg->ShowWindow(SW_HIDE);
		bIsNumBoardOpen = 0;
		KillTimer(0);
	}
}

/* 函数功能:定义操作符键盘窗口的行为,包括大小,位置等*/
void CMFCApplication1Dlg::OnBnClickedButtonOperator()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!bIsOpBoardOpen)
	{
		GetWindowRect(m_rect);
		pOPDlg->SetWindowPos(NULL, m_rect.left + 300, m_rect.top + 355, -1, -1, SWP_NOSIZE);
		pOPDlg->ShowWindow(SW_SHOW);
		SetTimer(1, 200, NULL);
		bIsOpBoardOpen = 1;
	}
	else
	{
		pOPDlg->ShowWindow(SW_HIDE);
		bIsOpBoardOpen = 0;
		KillTimer(1);
	}
}

/* 函数功能:定义函数键盘窗口的行为,包括大小,位置等*/
void CMFCApplication1Dlg::OnBnClickedButtonFunctions()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!bIsFuncBoardOpen)
	{
		GetWindowRect(m_rect);
		pFUNCDlg->SetWindowPos(NULL, m_rect.left - 200, m_rect.top + 355, -1, -1, SWP_NOSIZE);
		pFUNCDlg->ShowWindow(SW_SHOW);
		SetTimer(2, 200, NULL);
		bIsFuncBoardOpen = 1;
	}
	else
	{
		pFUNCDlg->ShowWindow(SW_HIDE);
		bIsFuncBoardOpen = 0;
		KillTimer(2);
	}
}

/* 函数功能:对输入表达式进行处理,以便后续计算*/
void CMFCApplication1Dlg::Paster(CString strSign, BOOL bIsSingle)
{
	// TODO: 在此处添加实现代码.
	UpdateData(1);
	CString str;
	m_nlen = m_strExp.GetLength();
	m_strExpc.GetSel( m_nStart, m_nEnd );
	str = m_strExp.Mid( m_nEnd, m_nlen - m_nEnd );
	m_strExp = m_strExp.Left( m_nStart ) + strSign;
	m_nlen = m_strExp.GetLength();
	if (bIsSingle)
		m_nlen -= 2;
	m_strExp += str;
	UpdateData( 0 );
	m_strExpc.SetFocus();
	m_strExpc.SetSel( m_nlen, m_nlen );
}

BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->wParam == HTCAPTION && pMsg->message == WM_NCLBUTTONDOWN && pMsg->hwnd == this->m_hWnd)
	{
		if (!bIsOk)
		{
			SetTimer(3, 20, NULL);
			//		MessageBox("set");
			bIsOk = 1;
		}
	}
	else
	{
		if (bIsOk)
		{
			KillTimer(3);
			//		MessageBox("kill");
			bIsOk = 0;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

/*函数功能:选择输入常数值*/
void CMFCApplication1Dlg::OnBnClickedButtonConstant()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	CWnd* pFrame;
	pFrame = AfxGetApp()->GetMainWnd();
	CWnd* pWndPopupOwner = this;
	VERIFY(m_menu.LoadMenu(IDR_MENU1));
	CPoint point;
	GetCursorPos(&point);
	::SetForegroundWindow(m_hWnd);
	CMenu* pPopup = m_menu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWndPopupOwner, NULL);
	m_menu.DestroyMenu();
}

/*函数功能:将已完成计算的表达式加入到"历史表达式"中*/
void CMFCApplication1Dlg::AddToHistr(CString strExp)
{
	// TODO: 在此处添加实现代码.
	if ( m_menu2.m_hMenu )
	{
		int b = m_menu2.GetMenuItemCount();
		BOOL bRet = m_menu2.AppendMenu(MF_STRING, IMENU_ITEM_ID + b, strExp);
		if ( bRet ) 
			m_menuItem.Add(strExp);
	}
}

/*函数功能:相应"历史表达式"按键的点击,显示历史表达式*/
void CMFCApplication1Dlg::OnBnClickedButtonHistrexp()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint point;
	GetCursorPos(&point);
	m_menu2.TrackPopupMenu(TPM_CENTERALIGN, point.x, point.y, this);
}
/*
void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
*/


/*
void CMFCApplication1Dlg::OnBnClickedButtonCancel()
{
	// TODO: 在此添加控件通知处理程序代码
}*/


void CMFCApplication1Dlg::OnMPi()
{
	// TODO: 在此添加命令处理程序代码
	Paster("PI", 0);
}


void CMFCApplication1Dlg::OnME()
{
	// TODO: 在此添加命令处理程序代码
	Paster("E", 0);
}


void CMFCApplication1Dlg::OnMC()
{
	// TODO: 在此添加命令处理程序代码
	Paster("LS", 0);
}


void CMFCApplication1Dlg::OnMNa()
{
	// TODO: 在此添加命令处理程序代码
	Paster("NA", 0);
}


void CMFCApplication1Dlg::OnMG()
{
	// TODO: 在此添加命令处理程序代码
	Paster("GR", 0);
}


void CMFCApplication1Dlg::OnMR()
{
	// TODO: 在此添加命令处理程序代码
	Paster("MG", 0);
}


void CMFCApplication1Dlg::OnMK()
{
	// TODO: 在此添加命令处理程序代码
	Paster("BC", 0);
}


void CMFCApplication1Dlg::OnMVm()
{
	// TODO: 在此添加命令处理程序代码
	Paster("VM", 0);
}


void CMFCApplication1Dlg::OnMKe()
{
	// TODO: 在此添加命令处理程序代码
	Paster("EF", 0);
}


void CMFCApplication1Dlg::OnME0()
{
	// TODO: 在此添加命令处理程序代码
	Paster("DC", 0);
}


/*
void CMFCApplication1Dlg::OnBnClickedBtnConvert()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	CWnd* pFrame;
	pFrame = AfxGetApp()->GetMainWnd();
	CWnd* pWndPopupOwner = this;
	VERIFY(m_menu.LoadMenu(IDR_MENU1));
	CPoint point;
	GetCursorPos(&point);
	::SetForegroundWindow(m_hWnd);
	CMenu* pPopup = m_menu.GetSubMenu(1);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWndPopupOwner, NULL);
	m_menu.DestroyMenu();
}*/




void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	/*if (m_radio_degree.GetCheck() == 1)
		calcu.m_bDegree = 1;*/
	//	calcu.Dec2Hex(&m_strExp);
	string Expr( m_strExp.GetBuffer() );
	calcu.set_input(Expr);
	calcu.caculation();
	double Result1 = calcu.get_output();
	CString strRes;
	strRes.Format( _T("%.8f"), Result1 );   // 获得计算结果,这是UI与后端的交互端
	m_strRes = strRes;
	m_strResTmp = strRes; 
	AddToHistr( m_strExp + "= " + strRes );  //将已经计算完毕的表达式存入"历史表达式"中
	UpdateData(0);                           //将计算结果送到对话框显示
}


void CMFCApplication1Dlg::OnBnClickedButtonCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(TEXT("确认退出？"),TEXT("温馨提示"),MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES )
		PostMessage(WM_CLOSE);
}
