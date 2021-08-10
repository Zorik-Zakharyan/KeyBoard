
// KeyBoardDlg.h : header file
//

#pragma once


// CKeyBoardDlg dialog
class CKeyBoardDlg : public CDialogEx
{
// Construction
public:
	CKeyBoardDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KEYBOARD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_b1;
	CEdit m_Dboard;
	afx_msg void OnBnClicked(UINT nID);

private:
	void TypeChar(TCHAR ch);

public:
	int capsCheck=0;
	CString tmp;
	int index, a, b;
	//int virtCapsCheck=0;
	CComboBox m_Lcombo;

	/*LANGUAGE* language;*/
	afx_msg void OnCbnSelchangeLanguagecombo();
	CButton m_btnCapsLock;
	bool UpDateKeyboard();
	bool GetCAPSstatus();


	
	CButton m_RBcaps;
};
