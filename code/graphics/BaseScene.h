#ifndef BASE_SCENE
#define BASE_SCENE

#include "..\lib\stdafx.h"

class BaseScene
{
public:
	BaseScene(tstring name);
	~BaseScene(void);

	virtual void Initialize();
	virtual void Update(float deltatime){};
	virtual void Draw(){};
	virtual tstring GetName(){return m_SceneName;}
	bool IsInitialized(){return m_bInitialized;}

private:
	const tstring m_SceneName;
	bool m_bInitialized;
};
#endif
