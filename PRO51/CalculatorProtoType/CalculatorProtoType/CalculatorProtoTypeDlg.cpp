
// CalculatorProtoTypeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CalculatorProtoType.h"
#include "CalculatorProtoTypeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCalculatorProtoTypeDlg �Ի���



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


// CCalculatorProtoTypeDlg ��Ϣ�������

BOOL CCalculatorProtoTypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorProtoTypeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorProtoTypeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorProtoTypeDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



/*���²���Ϊ��Ӧ��ť���¼���Ӧ����һ�����Զ����*/
void CCalculatorProtoTypeDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "0";
	m_strResult += "0";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}



void CCalculatorProtoTypeDlg::OnBnClickedA1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "1";
	m_strResult += "1";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}




void CCalculatorProtoTypeDlg::OnBnClickedA2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "2";
	m_strResult += "2";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}



void CCalculatorProtoTypeDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "3";
	m_strResult += "3";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "4";
	m_strResult += "4";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}




void CCalculatorProtoTypeDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "5";
	m_strResult += "5";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "6";
	m_strResult += "6";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "7";
	m_strResult += "7";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "8";
	m_strResult += "8";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	if( OperatorPressed == true || Restarted == true )
		m_strResult = "9";
	m_strResult += "9";

	OperatorPressed = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                      //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	m_strResult += "+";                                    //�ڱ���m_strResult����ӡ�+��
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                      //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	m_strResult += "-";                                    //�ڱ���m_strResult����ӡ�-��
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                      //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	m_strResult += "*";                                    //�ڱ���m_strResult����ӡ�*��
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                      //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
	m_strResult += "/";                                    //�ڱ���m_strResult����ӡ�/��
	OperatorPressed  = false;
	Restarted = false;
	UpdateData(FALSE);
}


void CCalculatorProtoTypeDlg::OnBnClickedLbrace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);                                     //�ѱ༭����ʾ���ı��ַ���������Ӧ�ı���m_strResult
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