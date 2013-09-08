#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include <process.h> //MT
#include <cstdlib> //rand()
#include <sys/stat.h> //file info
#include <atlbase.h> //CComPtr
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

	void RedirectIOToConsole()

	{
		int hConHandle;
		long lStdHandle;

		CONSOLE_SCREEN_BUFFER_INFO coninfo;
		FILE *fp;

		// allocate a console for this app

		AllocConsole();

		// set the screen buffer to be big enough to let us scroll text

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&coninfo);
		coninfo.dwSize.Y = MAX_CONSOLE_LINES;
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),
			coninfo.dwSize);

		// redirect unbuffered STDOUT to the console

		lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
		hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
		fp = _fdopen( hConHandle, "w" );
		*stdout = *fp;
		setvbuf( stdout, NULL, _IONBF, 0 );

		// redirect unbuffered STDIN to the console

		lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
		hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
		fp = _fdopen( hConHandle, "r" );
		*stdin = *fp;
		setvbuf( stdin, NULL, _IONBF, 0 );

		// redirect unbuffered STDERR to the console

		lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
		hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
		fp = _fdopen( hConHandle, "w" );
		*stderr = *fp;
		setvbuf( stderr, NULL, _IONBF, 0 );

		// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog

		// point to console as well

		ios::sync_with_stdio();

	}

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

 
