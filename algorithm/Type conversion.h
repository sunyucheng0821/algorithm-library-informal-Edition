#include <bits/stdc++.h>
#include <Windows.h>
#include <cstdio>
#include <io.h>
#include <windows.h>
#include <crtdbg.h>
#include <netfw.h>
#include <objbase.h>
#include <oleauto.h>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
using namespace std;
LPCWSTR stringToLPCWSTR(string orig)
{
    size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t) * (orig.length() - 1));
    mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

    std::wstring wstrResult(wcstring);

    free(wcstring);

    return wstrResult.c_str();
}

string DwordToString(DWORD val)
{
    string cur_str = to_string(val);
    return cur_str;
}
DWORD StringToDword(string val)
{
    DWORD cur_dword;
    sscanf(val.c_str(), "%ul", &cur_dword);
    return cur_dword;
}
int StringToInt(string val)
{
    return atoi(val.c_str());
}

char *wideCharToMultiByte(wchar_t *pWCStrKey)
{
    //第一次调用确认转换后单字节字符串的长度，用于开辟空间
    int pSize = WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), NULL, 0, NULL, NULL);
    char *pCStrKey = new char[pSize + 1];
    //第二次调用将双字节字符串转换成单字节字符串
    WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), pCStrKey, pSize, NULL, NULL);
    pCStrKey[pSize] = '\0';
    return pCStrKey;

    //如果想要转换成string，直接赋值即可
    //string pKey = pCStrKey;
}

wchar_t *multiByteToWideChar(const string &pKey)
{
    const char *pCStrKey = pKey.c_str();
    //第一次调用返回转换后的字符串长度，用于确认为wchar_t*开辟多大的内存空间
    int pSize = MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, NULL, 0);
    wchar_t *pWCStrKey = new wchar_t[pSize];
    //第二次调用将单字节字符串转换成双字节字符串
    MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, pWCStrKey, pSize);
    return pWCStrKey;
}
void Wchar_tToString(std::string &szDst, wchar_t *wchar)
{
    wchar_t *wText = wchar;
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE); // WideCharToMultiByte的运用
    char *psText;                                                                       // psText为char*的临时数组，作为赋值给std::string的中间变量
    psText = new char[dwNum];
    WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE); // WideCharToMultiByte的再次运用
    szDst = psText;                                                             // std::string赋值
    delete[] psText;                                                            // psText的清除
}