﻿
// KeyBoardDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct KEY_BUTTON
{
	int key_id; // a -> 65
	int button_id; // a -> IDC_BUTTON29
	WCHAR capitalLetter; // a -> Ա
	WCHAR smallLetter; // a -> ա
};

struct LANGUAGE
{
	LPCTSTR name;
	KEY_BUTTON keyButtons[2];
};

LANGUAGE languages[] =
{
	_T("Armenian"),
	{
		{65, IDC_BUTTON29, 'Ա', 'ա'},
		{66, IDC_BUTTON46, 'Բ', 'բ'},
	},
};

LANGUAGE* language = &languages[0];

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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
END_MESSAGE_MAP()


// CKeyBoardDlg dialog



CKeyBoardDlg::CKeyBoardDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KEYBOARD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_b1);
	DDX_Control(pDX, IDC_DASH_BOARD, m_Dboard);
}
BOOL CKeyBoardDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		stdlog("WM_KEYDOWN: wParam = %d lParam = %d\n", pMsg->wParam, pMsg->lParam);
		if (pMsg->wParam == 65)
		{
			TypeChar(_T('ա'));
		}
		return (1);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON58, &CKeyBoardDlg::OnBnClicked)
	
END_MESSAGE_MAP()


// CKeyBoardDlg message handlers

BOOL CKeyBoardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
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
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKeyBoardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKeyBoardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	CRect rc;
	m_b1.GetWindowRect(&rc);
	ScreenToClient(rc);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKeyBoardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CKeyBoardDlg::TypeChar(TCHAR ch)
{
	TCHAR szText[2];
	szText[0] = ch;
	szText[1] = 0;
	m_Dboard.ReplaceSel(szText, TRUE);
	m_Dboard.SetFocus();
}


void CKeyBoardDlg::OnBnClicked(UINT nID)
{
	
	//m_Dboard.SetWindowTextW(_T("է"));
	//CString temp;
	//m_Dboard.GetWindowTextW(temp);
	//temp += _T("s");
	//m_Dboard.SetWindowTextW(temp);
	CString tmp;
	int index,a,b;
	//m_Dboard.ReplaceSel(_T("a"), TRUE);
	//m_Dboard.SetFocus();
	switch (nID)
	{
	case IDC_BUTTON2:
		TypeChar(_T('է'));
		break;
	case IDC_BUTTON3:
		TypeChar(_T('թ'));
		break;
	case IDC_BUTTON14:
		m_Dboard.GetWindowTextW(tmp);
		m_Dboard.GetSel(a, b);
		index = b-1;
		tmp.Delete(index,1);
		m_Dboard.SetWindowTextW(tmp);
		m_Dboard.SetSel(b-1,b-1);
		m_Dboard.SetFocus();
		
	}
}

