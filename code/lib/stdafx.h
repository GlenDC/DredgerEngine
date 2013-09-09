#pragma once

//====================== stdafx.h ====================================
// Description:
//		include file for standard system include files,
//		or project specific include files that are used frequently, but
//		are changed infrequently
//====================================================================

#ifdef WIN32     
	#define NOMINMAX
	#include <windows.h>
#endif

// Extra unicode defines
#if defined(_UNICODE) && defined(WIN32)
	#include <tchar.h>
	#define tstring std::wstring
	#define tcin std::wcin
	#define tcout std::wcout
	#define tstringstream std::wstringstream
	#define tofstream std::wofstream
	#define tifstream std::wifstream
	#define tfstream std::wfstream
	#define to_tstring std::to_wstring
	#define tchar wchar_t
	#define tuchar unsigned char
#else
	#define tstring std::string
	#define tcin std::cin
	#define tcout std::cout
	#define tstringstream std::stringstream
	#define tofstream std::ofstream
	#define tifstream std::ifstream
	#define tfstream std::fstream
	#define to_tstring std::to_string
	#define tchar char
	#define tuchar unsigned char
#endif

#undef min
#undef max
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <crtdbg.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#ifndef NDEBUG
#define ASSERT \
if ( false ) {} \
else \
struct LocalAssert { \
	int mLine; \
	LocalAssert(int line=__LINE__) : mLine(line) {} \
	LocalAssert(bool isOK, const TCHAR* message=_T("")) { \
		if ( !isOK ) { \
			tstringstream buffer; \
			buffer << _T("ERROR!! Assert failed on line ") << LocalAssert().mLine << _T(" in file '") << __FILE__ << _T("'\\Message: \"") << message << _T("\"\n"); \
			OutputDebugString(buffer.str().c_str()); \
			__asm { int 3 } \
		} \
	} \
} myAsserter = LocalAssert
#define ASSERTC \
if ( false ) {} \
else \
struct LocalAssert { \
	int mLine; \
	LocalAssert(int line=__LINE__) : mLine(line) {} \
	LocalAssert(bool isOK, const char* message="") { \
		if ( !isOK ) { \
			std::stringstream buffer; \
			buffer << "ERROR!! Assert failed on line " << LocalAssert().mLine << " in file '" << __FILE__ << "'\\Message: \"" << message << "\"\n"; \
			OutputDebugStringA(buffer.str().c_str()); \
			__asm { int 3 } \
		} \
	} \
} myAsserter = LocalAssert
#else
#define ASSERT \
if ( true ) {} else \
struct NoAssert { \
	NoAssert(bool isOK, const TCHAR* message=_T("")) {} \
} myAsserter = NoAssert
#define ASSERTC \
if ( true ) {} else \
struct NoAssert { \
	NoAssert(bool isOK, const TCHAR* message=_T("")) {} \
} myAsserter = NoAssert
#endif

namespace GlobalHelpers
{
	std::string ConvertToString(const tstring & str);
}
