#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "ResultScene.h"
#include "Font.h"
#include "stdio.h"


ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	int finalScore = GameSystem::GetInstance()->GetFinalScore();

	_score = new Font("arialbd.ttf", 24);
	char text[256];
	sprintf(text, "Final Score %d", finalScore);
	_score->SetText(text, 100, 500);

	// Result Max Combo
	int MaxCombo = GameSystem::GetInstance()->GetMaxCombo();
	_maxCombo = new Font("arialbd.ttf", 24);
	char textMaxCombo[256];
	sprintf(textMaxCombo, "Final Max Combo : %d", MaxCombo);
	_maxCombo->SetText(textMaxCombo, 100, 300);
	
}

void ResultScene::Deinit()
{
	delete _backgroundSprite;
}

void ResultScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}

void ResultScene::Render()
{
	_backgroundSprite->Render();
	_score->Render();
	_maxCombo->Render();
}

void ResultScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case 
	
	SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;
	default:
		break;
	}
}

void ResultScene::KeyDown(unsigned int keyCode)
{
}
