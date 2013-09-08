#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "stdinc.h"
//-----------------------------------------------------
// Console Class									
//-----------------------------------------------------
class Console
{
public:
	Console();				// Constructor
	virtual ~Console();		// Destructor

	//-------------------------------------------------
	// Own methods								
	//-------------------------------------------------
//#ifdef _DEBUG

	void RedirectIOToConsole();

//#endif

private: 
	//-------------------------------------------------
	// Datamembers								
	//-------------------------------------------------
	static const WORD MAX_CONSOLE_LINES = 500;

	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Console(const Console& yRef);									
	Console& operator=(const Console& yRef);	
};

 
