#pragma once

//====================== #INCLUDES ===================================
#include "GeneralStructs.h"
//====================================================================

//====================== State Class =================================
// Description:
//		A state base class. Can be used to implement some kind of state.
//====================================================================

class State
{
public:
	virtual ~State() {}

	virtual void Initialize(void) = 0;
	virtual void Update(const GameContext& context) = 0;
	virtual void Draw(const GameContext& context) = 0;
	virtual void Draw2D(const GameContext& context) = 0;

	virtual void Activate() { m_Active = true; }
	virtual void Deactivate() { m_Active = false; }

	bool IsActive() const { return m_Active; }

protected:
	State() : m_Active(false) {}
	bool m_Active;

private:
	// Disabling default copy constructor and default assignment operator.
	State(const State& yRef);									
	State& operator=(const State& yRef);
};
