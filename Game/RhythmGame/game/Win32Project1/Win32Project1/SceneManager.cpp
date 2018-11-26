#include "SceneManager.h"

#include "GameScene.h"
#include "TitleScene.h"
#include "ResultScene.h"
#include "StartMenuScene.h"
#include "OptionScene.h"
#include "Option1.h"
#include "Rank1.h"
#include "Quit.h"


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
	case SCENE_RESULT:
		_scene = new ResultScene();
		break;
	case SCENE_STARTMENU:
		_scene = new StartMenuScene();
		break;
	case SCENE_OPTION:
		_scene = new OptionScene();
		break;
	case SCENE_OPTION1:
		_scene = new Option1();
		break;
	case SCENE_RANK1:
		_scene = new Rank1();
		break;
	case SCENE_QUIT:
		_scene = new Quit();
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