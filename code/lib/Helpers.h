#pragma once

//====================== #INCLUDES ===================================
#include "stdafx.h"
#include "GeneralStructs.h"
//====================================================================

//====================== Global Helpers ==============================
// Description:
//		Global helpers that don't belong in any specific class
//====================================================================

namespace GlobalHelpers
{
	const UINT GenerateHash(const tstring & str);

	tstring GetTimeStringFromSecondsValue(UINT seconds);
	tstring GetFullTimeStringFromSecondsValue(UINT seconds);
	tstring GetFullTimeString();
}