#include "SceneManager.h"

#include "GameScene.h"
#include "GameScene1.h"
#include "GameScene2.h"
#include "GameScene3.h"
#include "TitleScene.h"
#include "ResultScene.h"
#include "StartMenuScene.h"
#include "Option1.h"
#include "Rank1.h"
#include "Quit.h"
#include "RankScene.h"
#include "musiclist.h"
#include "musiclist1.h"
#include "musiclist2.h"
#include "musiclist3.h"
#include "OptionScenex1.h"
#include "OptionScenex2.h"
#include "OptionScenex3.h"
#include "OptionScenek5.h"
#include "OptionScenek7.h"
#include "OptionScenek9.h"
#include "OptionSceneback.h"

SceneManager* SceneManager::_instance = 0;

SceneManager::SceneManager()
{
	
}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

void SceneManager::Render()
{
	_scene->Render();
}
void SceneManager::Update(int deltaTime)
{
	_scene->Update(deltaTime);
}

void SceneManager::KeyUp(unsigned int keyCode)
{
	_scene->KeyUp(keyCode);
}

void SceneManager::KeyDown(unsigned int keyCode)
{
	_scene->KeyDown(keyCode);
}

void SceneManager::ChangeScene(eScene sceneType)
{
	switch (sceneType) {
	case SCENE_TITLE:
		_scene = new TitleScene();
		break;   
	case SCENE_GAME:
		_scene = new GameScene();
		break;
	case SCENE_GAME1:
		_scene = new GameScene1();
		break;
	case SCENE_GAME2:
		_scene = new GameScene2();
		break;
	case SCENE_GAME3:
		_scene = new GameScene3();
		break;
	case SCENE_RESULT:
		_scene = new ResultScene();
		break;
	case SCENE_STARTMENU:
		_scene = new StartMenuScene();
		break;
	case SCENE_OPTION1:
		_scene = new Option1();
		break;
	case SCENE_RankScene:
		_scene = new RankScene();
		break;
	case SCENE_RANK1:
		_scene = new Rank1();
		break;
	case SCENE_QUIT:
		_scene = new Quit();
		break;
	case SCENE_MUSICLIST:
		_scene = new musiclist();
		break;
	case SCENE_MUSICLIST1:
		_scene = new musiclist1();
		break;
	case SCENE_MUSICLIST2:
		_scene = new musiclist2();
		break;
	case SCENE_MUSICLIST3:
		_scene = new musiclist3();
		break;
	case SCENE_OPTIONx1:
		_scene = new OptionScenex1();
		break;
	case SCENE_OPTIONx2:
		_scene = new OptionScenex2();
		break;
	case SCENE_OPTIONx3:
		_scene = new OptionScenex3();
		break;
	case SCENE_OPTIONk5:
		_scene = new OptionScenek5();
		break;
	case SCENE_OPTIONk7:
		_scene = new OptionScenek7();
		break;
	case SCENE_OPTIONk9:
		_scene = new OptionScenek9();
		break;
	case SCENE_OPTIONback:
		_scene = new OptionSceneback();
		break;



	default:
		break;
	}
	_scene->Init();
}

void SceneManager::DeInit()
{
	_scene->Deinit();
	delete _scene;
}