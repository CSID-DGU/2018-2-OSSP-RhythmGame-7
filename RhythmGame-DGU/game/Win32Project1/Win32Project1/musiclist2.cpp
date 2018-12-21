#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "musiclist2.h"
#include "Font.h"
#include "stdio.h"


musiclist2::musiclist2()
{

}

musiclist2::~musiclist2()
{
}

void musiclist2::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("musiclist2", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);



	_updateTick = 0;
}

void musiclist2::Deinit()
{

	delete _backgroundSprite;

}

void musiclist2::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void musiclist2::Render()
{
	_backgroundSprite->Render();
	_test->Render();

}

void musiclist2::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST1);
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_MUSICLIST3);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME2);
		break;
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;
	}
}

void musiclist2::KeyDown(unsigned int keyCode)
{
}
