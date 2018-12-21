#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "musiclist1.h"
#include "Font.h"
#include "stdio.h"


musiclist1::musiclist1()
{

}

musiclist1::~musiclist1()
{
}

void musiclist1::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("musiclist1", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);



	_updateTick = 0;
}

void musiclist1::Deinit()
{

	delete _backgroundSprite;

}

void musiclist1::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void musiclist1::Render()
{
	_backgroundSprite->Render();
	_test->Render();

}

void musiclist1::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST);
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST2);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME1);
		break;
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;

	}
}

void musiclist1::KeyDown(unsigned int keyCode)
{
}
