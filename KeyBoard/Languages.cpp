#include "pch.h"
#include "Languages.h"
#include "resource.h"
#include <tchar.h>


KEY_BUTTON Layout::keyButtons[] =
{
	
		{65, IDC_BUTTON29},
		{66, IDC_BUTTON47},
		{71, IDC_BUTTON33},
		{68, IDC_BUTTON31},
		{69, IDC_BUTTON18},
		{90, IDC_BUTTON43},
		{49,  IDC_BUTTON2},
		{89, IDC_BUTTON21},
		{50,  IDC_BUTTON3},
		{187,IDC_BUTTON13},
		{73, IDC_BUTTON23},
		{76, IDC_BUTTON37},
		{219,IDC_BUTTON26},
		{221,IDC_BUTTON27},
		{75, IDC_BUTTON36},
		{72, IDC_BUTTON34},
		{52,  IDC_BUTTON5},
		{88, IDC_BUTTON44},
		{48, IDC_BUTTON11},
		{77, IDC_BUTTON49},
		{74, IDC_BUTTON35},
		{78, IDC_BUTTON48},
		{220,IDC_BUTTON40},
		{87, IDC_BUTTON17},
		{57, IDC_BUTTON10},
		{80, IDC_BUTTON25},
		{53,  IDC_BUTTON6},
		{82, IDC_BUTTON19},
		{83, IDC_BUTTON30},
		{86, IDC_BUTTON46},
		{84, IDC_BUTTON20},
		{56,  IDC_BUTTON9},
		{67, IDC_BUTTON45},
		{85, IDC_BUTTON22},
		{54,  IDC_BUTTON7},
		{51,  IDC_BUTTON4},
		{81, IDC_BUTTON16},
		{55,  IDC_BUTTON8},
		{79, IDC_BUTTON24},
		{70, IDC_BUTTON32},
		{192, IDC_BUTTON1},
		{189, IDC_BUTTON12},
		{186, IDC_BUTTON38},
		{222, IDC_BUTTON39},
		{191, IDC_BUTTON52},
		{190, IDC_BUTTON51},
		{188, IDC_BUTTON50},
		{9, IDC_BUTTON15},
		{32, IDC_BUTTON56},
};
LANGUAGE Layout::languages[] =
{

	_T("Armenian"),
	{
		Letter(Layout::keyButtons[0], L'Ա', L'ա'),
		Letter(Layout::keyButtons[1], L'Բ', L'բ'),
		Letter(Layout::keyButtons[2], L'Գ', L'գ'),
		Letter(Layout::keyButtons[3], L'Դ', L'դ'),
		Letter(Layout::keyButtons[4], L'Ե', L'ե'),
		Letter(Layout::keyButtons[5], L'Զ', L'զ'),
		Letter(Layout::keyButtons[6], L'Է', L'է'),
		Letter(Layout::keyButtons[7], L'Ը', L'ը'),
		Letter(Layout::keyButtons[8], L'Թ', L'թ'),
		Letter(Layout::keyButtons[9], L'Ժ', L'ժ'),
		Letter(Layout::keyButtons[10], L'Ի', L'ի'),
		Letter(Layout::keyButtons[11], L'Լ', L'լ'),
		Letter(Layout::keyButtons[12], L'Խ', L'խ'),
		Letter(Layout::keyButtons[13], L'Ծ', L'ծ'),
		Letter(Layout::keyButtons[14], L'Կ', L'կ'),
		Letter(Layout::keyButtons[15], L'Հ', L'հ'),
		Letter(Layout::keyButtons[16], L'Ձ', L'ձ'),
		Letter(Layout::keyButtons[17], L'Ղ', L'ղ'),
		Letter(Layout::keyButtons[18], L'Ճ', L'ճ'),
		Letter(Layout::keyButtons[19], L'Մ', L'մ'),
		Letter(Layout::keyButtons[20], L'Յ', L'յ'),
		Letter(Layout::keyButtons[21], L'Ն', L'ն'),
		Letter(Layout::keyButtons[22], L'Շ', L'շ'),
		Letter(Layout::keyButtons[23], L'Ո', L'ո'),
		Letter(Layout::keyButtons[24], L'Չ', L'չ'),
		Letter(Layout::keyButtons[25], L'Պ', L'պ'),
		Letter(Layout::keyButtons[26], L'Ջ', L'ջ'),
		Letter(Layout::keyButtons[27], L'Ռ', L'ռ'),
		Letter(Layout::keyButtons[28], L'Ս', L'ս'),
		Letter(Layout::keyButtons[29], L'Վ', L'վ'),
		Letter(Layout::keyButtons[30], L'Տ', L'տ'),
		Letter(Layout::keyButtons[31], L'Ր', L'ր'),
		Letter(Layout::keyButtons[32], L'Ց', L'ց'),
		Letter(Layout::keyButtons[33], L'Ւ', L'ւ'),
		Letter(Layout::keyButtons[34], L'Ւ', L'ւ'),
		Letter(Layout::keyButtons[35], L'Փ', L'փ'),
		Letter(Layout::keyButtons[36], L'Ք', L'ք'),
		Letter(Layout::keyButtons[37], L'և', L'և'),
		Letter(Layout::keyButtons[38], L'Օ', L'օ'),
		Letter(Layout::keyButtons[39], L'Ֆ', L'ֆ'),
		Letter(Layout::keyButtons[40], L'`', L'`'),
		Letter(Layout::keyButtons[41], L'-', L'-'),
		Letter(Layout::keyButtons[42], L';', L';'),
		Letter(Layout::keyButtons[43], L'՛', L'՛'),
		Letter(Layout::keyButtons[44], L'/', L'/'),
		Letter(Layout::keyButtons[45], L':', L':'),
		Letter(Layout::keyButtons[45], L',', L','),
		Letter(Layout::keyButtons[46], L'	', L'	'),
		Letter(Layout::keyButtons[47], L' ', L' '),
        





	},

		_T("English"),
	{
		Letter(Layout::keyButtons[0], L'A', L'a'),         
		Letter(Layout::keyButtons[1], L'B', L'b'),			
		Letter(Layout::keyButtons[2], L'G', L'g'),			
		Letter(Layout::keyButtons[3], L'D', L'd'),			
		Letter(Layout::keyButtons[4], L'E', L'e'),			
		Letter(Layout::keyButtons[5], L'Z', L'z'),			
		Letter(Layout::keyButtons[6], L'1', L'1'),			
		Letter(Layout::keyButtons[7], L'Y', L'y'),			
		Letter(Layout::keyButtons[8], L'2', L'2'),			
		Letter(Layout::keyButtons[9], L'=', L'='),			
		Letter(Layout::keyButtons[10], L'I', L'i'),			
		Letter(Layout::keyButtons[11], L'L', L'l'),			
		Letter(Layout::keyButtons[12], L'[', L'['),			
		Letter(Layout::keyButtons[13], L']', L']'),			
		Letter(Layout::keyButtons[14], L'K', L'k'),			
		Letter(Layout::keyButtons[15], L'H', L'h'),			
		Letter(Layout::keyButtons[16], L'4', L'4'),			
		Letter(Layout::keyButtons[17], L'X', L'x'),			
		Letter(Layout::keyButtons[18], L'0', L'0'),			
		Letter(Layout::keyButtons[19], L'M', L'm'),			
		Letter(Layout::keyButtons[20], L'J', L'j'),			
		Letter(Layout::keyButtons[21], L'N', L'n'),			
		Letter(Layout::keyButtons[22], L'\\', L'\\'),
		Letter(Layout::keyButtons[23], L'W', L'w'),			
		Letter(Layout::keyButtons[24], L'9', L'9'),			
		Letter(Layout::keyButtons[25], L'P', L'p'),			
		Letter(Layout::keyButtons[26], L'5', L'5'),			
		Letter(Layout::keyButtons[27], L'R', L'r'),			
		Letter(Layout::keyButtons[28], L'S', L's'),			
		Letter(Layout::keyButtons[29], L'V', L'v'),			
		Letter(Layout::keyButtons[30], L'T', L't'),			
		Letter(Layout::keyButtons[31], L'8', L'8'),			
		Letter(Layout::keyButtons[32], L'C', L'c'),			
		Letter(Layout::keyButtons[33], L'U', L'u'),			
		Letter(Layout::keyButtons[34], L'6', L'6'),			
		Letter(Layout::keyButtons[35], L'3', L'3'),			
		Letter(Layout::keyButtons[36], L'Q', L'q'),			
		Letter(Layout::keyButtons[37], L'7', L'7'),			
		Letter(Layout::keyButtons[38], L'O', L'o'),			
		Letter(Layout::keyButtons[39], L'F', L'f'),			
		Letter(Layout::keyButtons[40], L'`', L'`'),			
		Letter(Layout::keyButtons[41], L'-', L'-'),			
		Letter(Layout::keyButtons[42], L';', L';'),			
		Letter(Layout::keyButtons[43], L'՛', L'՛'),			
		Letter(Layout::keyButtons[44], L'/', L'/'),			
		Letter(Layout::keyButtons[45], L':', L':'),			
		Letter(Layout::keyButtons[45], L',', L','),			
		Letter(Layout::keyButtons[46], L'	', L'	'),		
		Letter(Layout::keyButtons[47], L' ', L' '),			
	},
};						   		 


LPCTSTR Layout::GetLanguageName(int index)
{
	return languages[index].name;
}

void Layout::SetCurSel(int index)
{
	curSel = index;
}

int Layout::GetCurSel()
{
	return curSel;
}

int Layout::GetLanguageCount()
{
	return sizeof(languages) / sizeof(languages[0]);
}

int Layout::GetButtonCount()
{
	return sizeof(keyButtons) / sizeof(keyButtons[0]);
}

CString Layout::GetCharByButtonID(int buttonID, bool capital)
{
	CString ret;
	int i;

	//LANGUAGE *language = &languages[curSel];
	for (i = 0; i < _countof(keyButtons); i++)
	{
		if (buttonID == keyButtons[i].button_id)
		{
			ret += capital ? languages[curSel].letters[i].capitalLetter : languages[curSel].letters[i].smallLetter;
			break;
		}
	}
	//sizeof(LANGUAGE::keyButtons) / sizeof(LANGUAGE::keyButtons[0])
	
	
	return ret;

}

CString Layout::GetCharByVirtualKey(int virtKey, bool capital)
{
	CString ret;
	int i;

	//LANGUAGE* language = &languages[curSel];
	for (i = 0; i < _countof(keyButtons); i++)
	{
		if (virtKey == keyButtons[i].virtKey)
		{

			ret += capital ? languages[curSel].letters[i].capitalLetter : languages[curSel].letters[i].smallLetter;
			break;
		}
	}
	
	return ret;
}
wchar_t Layout::GetLetter(int lIndex, int bIndex, bool capital)
{
	return capital ? languages[lIndex].letters[bIndex].capitalLetter : languages[lIndex].letters[bIndex].smallLetter;
}
int Layout::GetButtonID(int bIndex)
{
	return keyButtons[bIndex].button_id;
}