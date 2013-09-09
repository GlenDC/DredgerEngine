#include "stdafx.h"

namespace GlobalHelpers
{
	std::string ConvertToString(const tstring & str)
	{
	#if defined(UNICODE) && defined(WIN32)
		return std::string(str.begin(), str.end());
	#else
		return str;
	#endif
	}
}