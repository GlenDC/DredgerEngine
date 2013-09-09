#pragma once

//====================== General Structs =============================
// Description:
//		General structures can be found here. 
//====================================================================

// GameTime structure, the time representation of the engine.
struct GameTime
{
	long ElapsedGameTime;
	long TotalGameTime;
	float ElapsedSpeedGameTime;
	float TotalSpeedGameTime;

	float ElapsedSeconds() const { return ElapsedGameTime/1000.0f; }
	float TotalSeconds() const { return TotalGameTime/1000.0f; }
};

struct GameContext
{
	GameTime GameTime;
	// [TODO]
	// + Add Camera
	// + Add Input Manager
};
