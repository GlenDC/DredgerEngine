#pragma once
//windows header files:
#include <Windows.h>

//C Runtime header files:
#include <tchar.h>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>

#include <math.h>

#include <algorithm>

#include <process.h> //MT

#include <cstdlib> //rand()

#include <sys/stat.h> //file info

#include <atlbase.h> //CComPtr


#ifdef _UNICODE
#define XML_UNICODE_WCHAR_T
#endif

//////UNICODE
#ifdef _UNICODE
#define tstring wstring
#define tcin wcin
#define tcout wcout
#define tstringstream wstringstream
#define tostringstream wostringstream
#define tofstream wofstream
#define tifstream wifstream
#define tfstream wfstream
#define tstrtod wcstod
#define tstrtol wcstol
#define tchar wchar_t 
#define tstrcmp wcscmp
#define tstrcpy_s wcscpy_s
#define tfopen _wfopen_s
#define tstrtod	wcstod
#define tof _wtof
#else
#define tstring string
#define tcin cin
#define tcout cout
#define tstringstream stringstream
#define tostringstream ostringstream
#define tofstream ofstream
#define tifstream ifstream
#define tfstream fstream
#define tstrod strtod
#define tstrtol strtol
#define tchar char 
#define tstrcmp strcmp
#define tstrcpy_s strcpy_s
#define tfopen fopen_s
#define	tstrtod strtod
#define tof atof
#endif

struct RGBCOLOR
{	
public:
	RGBCOLOR(){};
	RGBCOLOR(byte r, byte g, byte b){R=r;G=g;B=b;}
	byte R;
	byte G;
	byte B;

};


//////NumToStr
//template <class Number>
//std::tstring NumToStrT(const Number& type, int precision)
//{
//	std::tstringstream buffer;
//	buffer << std::fixed << std::setprecision(precision) << type;
//	return buffer.str();
//}

template <class Number>
std::string NumToStr(const Number& type, int precision)
{
	std::stringstream buffer;
	buffer << std::fixed << std::setprecision(precision) << type;
	return buffer.str();
}



