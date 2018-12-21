#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "musiclist3.h"
#include "Font.h"
#include "stdio.h"


musiclist3::musiclist3()
{

}

musiclist3::~musiclist3()
{
}

void musiclist3::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("musiclist3", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);



	_updateTick = 0;
}

void musiclist3::Deinit()
{

	delete _backgroundSprite;

}

void musiclist3::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void musiclist3::Render()
{
	_backgroundSprite->Render();
	_test->Render();

}

void musiclist3::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST2);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME3);
		break;
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;
	}
}

void musiclist3::KeyDown(unsigned int keyCode)
{
}
