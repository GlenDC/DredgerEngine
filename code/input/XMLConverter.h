#pragma once
//====================== #INCLUDES ===================================
#include "../lib/stdafx.h"
//====================================================================

//====================== XMLConverter NameSpace =================================
// Description:
//		Convert classes/types from/to XML format strings
//====================================================================

namespace XMLConverter
{
	template <typename T>
	T ConvertTString(const tstring & value)
	{
		T var(0);
		tstringstream strstr;
		strstr << value;
		strstr >> var;
		return var;
	}
	template <>
	tstring ConvertTString(const tstring & value);

	template <>
	std::string ConvertTString(const tstring & value);

	template <>
	bool ConvertTString(const tstring & value);

	template <typename T>
	tstring ConvertToTString(const T & value)
	{
		tstringstream strstr;
		strstr << value;
		return strstr.str();
	}
	template <>
	tstring ConvertToTString(const tstring & value);

	template <>
	tstring ConvertToTString(const std::string & value);

	template <>
	tstring ConvertToTString(const bool & value);
};