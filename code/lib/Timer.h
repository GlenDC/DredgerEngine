//====================== #INCLUDES ===================================
#include "stdafx.h"
#include "GeneralStructs.h"
#include <functional>
//====================================================================

//====================== Timer Class =================================
// Description:
//		A stand alone timer class, 
//		used for the Stopwatch (== time management) class.
//====================================================================

class Timer final
{
public:
	Timer();
	Timer(const float targetTime, const bool countingDown, const bool loop, std::function<void ()> func, const bool paused = false);
	~Timer();
	Timer(const Timer& yRef);									
	Timer& operator=(const Timer& yRef);


	bool Update(const GameContext& context);
	void SetPaused(const bool paused);
	void SetCountingDown(const bool countingDown);
	void SetLoop(const bool looping);
	void Reset(const bool paused = false);
	void SetTargetTime(const float targetTime, const bool reset = true, const bool paused = false);
	void SetFunction(std::function<void ()> func);

	int GetCurrentTimeMinutes() const;
	int GetCurrentTimeSeconds() const;
	int GetCurrentTimeTotalSeconds() const;

private:
	float m_TargetTime, m_CurrentTime;
	bool m_CountingDown, m_Looping, m_Paused, m_Infinite;

	std::function<void ()> m_ExcecutingFunction;
};