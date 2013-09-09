//====================== #INCLUDES ===================================
#include "XMLConverter.h"
//====================================================================

namespace XMLConverter
{
	template <>
	tstring ConvertTString(const tstring & value)
	{
		return value;
	}
	
	template <>
	std::string ConvertTString(const tstring & value)
	{
		return std::string(value.begin(), value.end());
	}

	template <>
	bool ConvertTString(const tstring & value)
	{
		return value == _T("True") ? true : false;
	}
	
	template <>
	tstring ConvertToTString(const tstring & value)
	{
		return value;
	}

	template <>
	tstring ConvertToTString(const std::string & value)
	{
		tstring str(value.begin(), value.end());
		return str;
	}

	template <>
	tstring ConvertToTString(const bool & value)
	{
		tstringstream strstr;
		strstr << value;
		return strstr.str();
	}
};