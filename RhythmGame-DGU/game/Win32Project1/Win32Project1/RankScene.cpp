#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "Rankscene.h"
#include "Font.h"

static int score1 = 1800;
static int score2 = 1500;
static int score3 = 900;
static int score4 = 700;
static int score5 = 200;

RankScene::RankScene()
{
}

RankScene::~RankScene()
{
}

void RankScene::Init()
{

	_rankTitle = new Font("arialbd.ttf", 50);
	_score1 = new Font("arialbd.ttf", 50);
	_score2 = new Font("arialbd.ttf", 50);
	_score3 = new Font("arialbd.ttf", 50);
	_score4 = new Font("arialbd.ttf", 50);
	_score5 = new Font("arialbd.ttf", 50);

	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("rank_scene", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_updateTick = 0;

	int score = GameSystem::GetInstance()->GetFinalScore();

	if (score > score1) { score5 = score4; score4 = score3; score3 = score2; score2 = score1; score1 = score; }
	else if (score > score2) { score5 = score4; score4 = score3; score3 = score2;  score2 = score; }
	else if (score > score3) { score5 = score4; score4 = score3; score3 = score; }
	else if (score > score4) { score5 = score4; score4 = score; }
	else if (score > score5) { score5 = score; }
}

void RankScene::Deinit()
{

	delete _backgroundSprite;
}

void RankScene::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/

	char text[256];
	sprintf(text, "RANK SCENE");
	_rankTitle->SetText(text, 500, 200);

	char text1[256];
	sprintf(text1, "1st   %d", score1);
	_score1->SetText(text1, 500, 300);

	char text2[256];
	sprintf(text2, "2rd   %d", score2);
	_score2->SetText(text2, 500, 350);

	char text3[256];
	sprintf(text3, "3th   %d", score3);
	_score3->SetText(text3, 500, 400);

	char text4[256];
	sprintf(text4, "4th   %d", score4);
	_score4->SetText(text4, 500, 450);

	char text5[256];
	sprintf(text5, "5th   %d", score5);
	_score5->SetText(text5, 500, 500);

	_backgroundSprite->Update(deltaTime);


}

void RankScene::Render()
{
	_backgroundSprite->Render();
	_test->Render();
	_rankTitle->Render();
	_score1->Render();
	_score2->Render();
	_score3->Render();
	_score4->Render();
	_score5->Render();
}

void RankScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RANK1);
		break;

	default:
		break;
	}
}

void RankScene::KeyDown(unsigned int keyCode)
{
}
