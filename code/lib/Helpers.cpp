//====================== #INCLUDES ===================================
#include "Helpers.h"
#include <cmath>
#include <ctime>
//====================================================================

namespace GlobalHelpers
{
	const UINT GenerateHash(const tstring & str) 
	{
		UINT hash(0);
		for(size_t i = 0; i < str.size(); ++i) 
			hash = 65599 * hash + str[i];
		return hash ^ (hash >> 16);
	}

	tstring GetTimeStringFromSecondsValue(UINT seconds)
	{
		tstringstream time;
		UINT minutes(seconds / 60);
		seconds = seconds % 60;
		time << ( minutes < 10 ? _T("0") : _T("") ) << minutes;
		time << _T(":");
		time << ( seconds < 10 ? _T("0") : _T("") ) << seconds;
		return time.str();
	}

	tstring GetFullTimeStringFromSecondsValue(UINT seconds)
	{
		tstringstream time;
		UINT minutes(seconds / 60);
		UINT hours(minutes / 60);
		minutes = minutes % 60;
		seconds = seconds % 60;
		time << ( hours < 10 ? _T("0") : _T("") ) << hours;
		time << _T(":");
		time << ( minutes < 10 ? _T("0") : _T("") ) << minutes;
		time << _T(":");
		time << ( seconds < 10 ? _T("0") : _T("") ) << seconds;
		return time.str();
	}

	tstring GetFullTimeString()
	{
		time_t t = time(0);   // get time now
		tm now;
		localtime_s(&now, & t );
		// parse session date and time
		tstringstream timeParse;
		timeParse << now.tm_mday << '-'
			 << (now.tm_mon + 1) << '-'
			 << (now.tm_year + 1900) << ' '
			 << now.tm_hour << 'h'
			 << now.tm_min << 'm'
			 << now.tm_sec << 's';
		return timeParse.str();
	}
}