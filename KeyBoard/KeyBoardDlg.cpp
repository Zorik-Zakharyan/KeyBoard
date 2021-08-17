
// KeyBoardDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"
#include "afxdialogex.h"
#include "Languages.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Layout gLayout;

//CKeyBoardDlg* app = (CKeyBoardDlg*)AfxGetApp();
//CKeyBoardDlg* pDlg = (CKeyBoardDlg*)(app->getdlg);
//HWND win = pDlg->GetSafeHwnd();
// FindWindow("CKeyBoardDlg", Keyboard);*/


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
	DDX_Control(pDX, IDC_LANGUAGECOMBO, m_Lcombo);
	DDX_Control(pDX, IDC_BUTTON28, m_btnCapsLock);
	DDX_Control(pDX, IDC_CAPS_INDICATE, m_RBcaps);
}
BOOL CKeyBoardDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYUP)
	{
		BOOL ret = CDialogEx::PreTranslateMessage(pMsg);

		UpDateKeyboard();

		return ret;
	}
	if (pMsg->message == WM_KEYDOWN)
	{
		BOOL ret = 1;

		if (pMsg->wParam == VK_CAPITAL || pMsg->wParam == VK_SHIFT || pMsg->wParam == 37 || pMsg->wParam == 38 || pMsg->wParam == 39 || pMsg->wParam == 40 || pMsg->wParam == 8 || pMsg->wParam == 13 || pMsg->wParam == 46 || ((pMsg->wParam >= 96) && (pMsg->wParam <= 111)))
		{
			ret = CDialogEx::PreTranslateMessage(pMsg);
		}

		stdlog("WM_KEYDOWN: wParam = %d lParam = %d\n", pMsg->wParam, pMsg->lParam);

		bool isCaps = UpDateKeyboard();
		//if (pMsg->wParam == VK_CAPITAL || pMsg->wParam == VK_SHIFT) //Caps Lock
		//{		
		//	m_btnCapsLock.SetState(capsON);
		//	if ((GetKeyState(VK_CAPITAL) & 0x01) == 1)
		//	{
		//		SwitchToCaps(0, true);
		//	}
		//	else
		//	{
		//		SwitchToCaps(0, false);
		//	}
		//}
		
	
		//if (pMsg->wParam == 8) //BackSP
		//{
		//	m_Dboard.GetWindowTextW(tmp);
		//	m_Dboard.GetSel(a, b);
		//	index = b - 1;
		//	tmp.Delete(index, 1);
		//	m_Dboard.SetWindowTextW(tmp);
		//	m_Dboard.SetSel(b - 1, b - 1);
		//	m_Dboard.SetFocus();
		//}

		//Numbers 0-9 and operaations ( * / + -)
		/*switch (pMsg->wParam)
		{
			case 96:
				m_Dboard.ReplaceSel(_T("0"));
				m_Dboard.SetFocus();
				break;
			case 97:
				m_Dboard.ReplaceSel(_T("1"));
				m_Dboard.SetFocus();
				break;
			case 98:
				m_Dboard.ReplaceSel(_T("2"));
				m_Dboard.SetFocus();
				break;
			case 99:
				m_Dboard.ReplaceSel(_T("3"));
				m_Dboard.SetFocus();
				break;
			case 100:
				m_Dboard.ReplaceSel(_T("4"));
				m_Dboard.SetFocus();
				break;
			case 101:
				m_Dboard.ReplaceSel(_T("5"));
				m_Dboard.SetFocus();
				break;
			case 102:
				m_Dboard.ReplaceSel(_T("6"));
				m_Dboard.SetFocus();
				break;
			case 103:
				m_Dboard.ReplaceSel(_T("7"));
				m_Dboard.SetFocus();
				break;
			case 104:
				m_Dboard.ReplaceSel(_T("8"));
				m_Dboard.SetFocus();
				break;
			case 105:
				m_Dboard.ReplaceSel(_T("9"));
				m_Dboard.SetFocus();
				break;
			case 106:
				m_Dboard.ReplaceSel(_T("*"));
				m_Dboard.SetFocus();
				break;
			case 107:
				m_Dboard.ReplaceSel(_T("+"));
				m_Dboard.SetFocus();
				break;		
			case 109:
				m_Dboard.ReplaceSel(_T("-"));
				m_Dboard.SetFocus();
				break;
			case 110:
				m_Dboard.ReplaceSel(_T("."));
				m_Dboard.SetFocus();
				break;
			case 111:
				m_Dboard.ReplaceSel(_T("/"));
				m_Dboard.SetFocus();
				break;
		}*/
		//////////////////////////////////////////

		//bool capsON = GetKeyState(VK_CAPITAL) & 0x01;
		//stdlog("GetKeyState(): tmp = %x \n", capsON);
					
		
		m_Dboard.ReplaceSel(gLayout.GetCharByVirtualKey(pMsg->wParam, isCaps));
		m_Dboard.SetFocus();
		
		return ret;
		
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON58, &CKeyBoardDlg::OnBnClicked)
	
	ON_CBN_SELCHANGE(IDC_LANGUAGECOMBO, &CKeyBoardDlg::OnCbnSelchangeLanguagecombo)

END_MESSAGE_MAP()


// CKeyBoardDlg message handlers

BOOL CKeyBoardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	m_Lcombo.AddString(_T("Armenian"));
	m_Lcombo.AddString(_T("English"));
	m_Lcombo.SetCurSel(0);






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

	/////////CAPS CHECK//////////////////////////


	UpDateKeyboard();

	/////////////////////////////////////////////
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
	CClientDC dc(this);
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

//void CKeyBoardDlg::SwitchToCapital(Layout language[],int x)
//{
//	for (int i = 1; i <= 58; i++)
//	{
//		if (i == language[x].keyButtons[i].button_id)
//		{
//			CString cap(language[x].keyButtons[i].capitalLetter);
//		//	GetDlgItem(i)->SetWindowTextW(cap);
//		}
//	}
//	
//}

void SendKey(WCHAR ch)
{
	INPUT inputs[2] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = ch;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = ch;
	inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
	
}
void CKeyBoardDlg::OnBnClicked(UINT nID)
{

	//CString tmp;
	//for (int i = 0; i < 40; i++)
	//{
	//	if (nID == language->keyButtons[i].button_id)
	//	{
	//		tmp += language->keyButtons[i].capitalLetter;
	//		m_Dboard.ReplaceSel(tmp);
	//		
	//		tmp = _T("");
	//		//break;
	//	}
	//}
	////m_Dboard.SetWindowTextW(_T("է"));
	////CString temp;
	////m_Dboard.GetWindowTextW(temp);
	////temp += _T("s");
	////m_Dboard.SetWindowTextW(temp);
	//CString tmp;
	//int index,a,b;
	////m_Dboard.ReplaceSel(_T("a"), TRUE);
	////m_Dboard.SetFocus();
	//switch (nID)
	//{
	//case IDC_BUTTON2:
	//	TypeChar(_T('է'));
	//	break;
	//case IDC_BUTTON3:
	//	TypeChar(_T('թ'));
	//	break;
	//case IDC_BUTTON14:
	//	m_Dboard.GetWindowTextW(tmp);
	//	m_Dboard.GetSel(a, b);
	//	index = b-1;
	//	tmp.Delete(index,1);
	//	m_Dboard.SetWindowTextW(tmp);
	//	m_Dboard.SetSel(b-1,b-1);
	//	m_Dboard.SetFocus();
	//	
	//}

	if (nID == IDC_BUTTON28)//Caps Lock
	{
		SendKey(VK_CAPITAL);
	/*	capsON = GetKeyState(VK_CAPITAL) & 0x01;
		m_btnCapsLock.SetState(capsON);*/
		UpDateKeyboard();
	}
	if (nID == 1014) //BackSp
	{
		m_Dboard.GetWindowTextW(tmp);
		m_Dboard.GetSel(a, b);
		index = b-1;
		tmp.Delete(index,1);
		m_Dboard.SetWindowTextW(tmp);
		m_Dboard.SetSel(b-1,b-1);
		m_Dboard.SetFocus();
	}

	bool capsON = GetCAPSstatus();
	m_Dboard.ReplaceSel(gLayout.GetCharByButtonID(nID, capsON));
	m_Dboard.SetFocus();
	
}
void CKeyBoardDlg::OnCbnSelchangeLanguagecombo()
{
	
	int CurrentSel;
	CurrentSel=m_Lcombo.GetCurSel();
	gLayout.SetCurSel(CurrentSel);
	UpDateKeyboard();

}
bool CKeyBoardDlg::UpDateKeyboard()
{
	bool caps = GetCAPSstatus();

	for (int i = 0; i < gLayout.GetButtonCount(); i++)
	{
	
			CStringW ch(gLayout.GetLetter(gLayout.GetCurSel(), i, caps));
			SetDlgItemText(gLayout.GetButtonID(i), ch);
			
	}
	SetDlgItemText(IDC_BUTTON15, _T("Tab"));
	SetDlgItemText(IDC_BUTTON56, _T("SPACE"));
	
	return caps;
}

bool CKeyBoardDlg::GetCAPSstatus()
{
	bool capsON = GetKeyState(VK_CAPITAL) & 0x01;
	bool shiftON = GetKeyState(VK_LSHIFT) & 0x01;
	//BYTE arr[256];
	//GetKeyboardState(arr);
	//bool capsON = arr[VK_CAPITAL] & 0x01;
	//bool shiftON = arr[VK_SHIFT] & 0x01;
	bool isCaps = (capsON && !shiftON) || (shiftON && !capsON);
	stdlog("capsON = %d, shiftON = %d, isCups = %d  \n", capsON, shiftON, isCaps);

	if (capsON == 1)
	{
		m_RBcaps.SetCheck(true);
	}
	else
	{
		m_RBcaps.SetCheck(false);
	}
	return isCaps;
}



