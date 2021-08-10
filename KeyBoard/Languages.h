#pragma once


struct KEY_BUTTON
{

	int virtKey; // a -> 65
	int button_id; // a -> IDC_BUTTON29
	
};

struct Letter
{
	Letter(KEY_BUTTON &btn, wchar_t c, wchar_t s):button(btn),capitalLetter(c),smallLetter(s)
	{

	};
	KEY_BUTTON &button;
	WCHAR capitalLetter; // a -> Ա
	WCHAR smallLetter; // a -> ա

};



struct LANGUAGE
{

	LPCTSTR name;
	Letter letters[49];

	
};



class Layout
{
public:
	LPCTSTR GetLanguageName(int index);
	void SetCurSel(int index);
	int GetCurSel();
	int GetLanguageCount();
	int GetButtonCount();
	CString GetCharByButtonID(int buttonID, bool capital);
	CString GetCharByVirtualKey(int virtKey, bool capital);
	wchar_t GetLetter(int lIndex, int bIndex, bool capital);
	int GetButtonID(int bIndex);
private:
	static LANGUAGE languages[];
	static KEY_BUTTON keyButtons[49];
	
	int curSel=0;




};