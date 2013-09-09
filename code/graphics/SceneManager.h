#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "BaseScene.h"
#include <map>
#include "..\lib\stdafx.h"

using namespace std;

//====================== Stopwatch Class =============================
// Description:
//		Manages Scenes, Added scenes can be activated or disbaled at any time
//		When setting a new active scene, it will become the active scene next
//		update cycle, this insures that previous active scene finilazes
// TODO: 
//		Multiple active scenes
//		Scene transition
//====================================================================

static class SceneManager
{
public:
	
	virtual ~SceneManager(void);

	static SceneManager* GetInstance();

	BaseScene* GetActiveScene(){return m_ActiveScene;}
	BaseScene* GetScene(tstring name){return m_ScenesList[name];}
	bool SetActiveScene(tstring name);
	bool AddScene(tstring name,BaseScene* scene);
	bool RemoveScene(tstring name);

	void Update(float deltatime);
	void Draw();

private:
	//Data Members
	static SceneManager* m_pSceneManager;

	map<const tstring,BaseScene*> m_ScenesList;
	BaseScene* m_ActiveScene;
	BaseScene* m_NewActiveScene;

	bool m_bSwitchingScene;
	bool m_bInitialized;
	tstring CurrentSceneName;

	//Private Functions
	bool InitializeCurScene();
	SceneManager(void);


	//disabling default copy constructor
	SceneManager(const SceneManager& yRef);									
	SceneManager& operator=(const SceneManager& yRef);
};

#endif