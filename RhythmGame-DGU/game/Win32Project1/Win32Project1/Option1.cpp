#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "Option1.h"
#include "Font.h"


Option1::Option1()
{
}

Option1::~Option1()
{
}

void Option1::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("option", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_updateTick = 0;
}

void Option1::Deinit()
{

	delete _backgroundSprite;
}

void Option1::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void Option1::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void Option1::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RANK1);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTION);
		break;
	default:
		break;
	}
}

void Option1::KeyDown(unsigned int keyCode)
{
}
