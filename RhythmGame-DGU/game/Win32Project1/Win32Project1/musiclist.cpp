#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "musiclist.h"
#include "Font.h"


musiclist::musiclist()
{
}

musiclist::~musiclist()
{
}

void musiclist::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("musiclist", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_updateTick = 0;
}

void musiclist::Deinit()
{

	delete _backgroundSprite;
}

void musiclist::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void musiclist::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void musiclist::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST1);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME);
		break;
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;

	}
}

void musiclist::KeyDown(unsigned int keyCode)
{
}
