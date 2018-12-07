#include <stdio.h>
#include "sdl_mixer.h"
#include "sdl_ttf.h"

#include "GameSystem.h"
#include "Font.h"
#include "Sprite.h"
#include "Track.h"
#include "GameScene.h"

#include "SceneManager.h"

#include "OptionScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}
	if (NULL != _lifeBarSprite)
	{
		delete _lifeBarSprite;
		_lifeBarSprite = NULL;
	}

}

void GameScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);
	   	 
	float totalPlayingSec = GameSystem::GetInstance()->GetTotalPlayingTime() / 1000.0f;
	
	float tempo = (float)BPM / 60.0f;

	int trackHeightMin = GameSystem::GetInstance()->GetWindowHeight();
	int trackHeight = (float)trackHeightMin * (float)totalPlayingSec * tempo;
	GameSystem::GetInstance()->SetTrackHeight(trackHeight);

	/*_track = new Track();
	_track->Init();*/
	int trackCount = TRACK_COUNT;
	_trackArray = new Array<Track*>(trackCount);

	int startX = 300;
	for (int i = 0; i < trackCount; i++) 
	{
		int x = startX + (i * 64) + 2;
		Track* track = new Track();
		track->Init(x);
		_trackArray->Set(i, track);
	}

	// 멤버 변수 초기화
	_gameDuration = 0;
	_finalScore = 0;
	_maxCombo = 0;
	
	// Font
	_text = new Font("arialbd.ttf", 24);
	_combo = new Font("arialbd.ttf", 24);

	int result = Mix_Init(MIX_INIT_MP3);
	if (MIX_INIT_MP3 == result)
	{
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("../Resources/Music/The Concept of Love.mp3");
		if (NULL != music)
		{
			Mix_PlayMusic(music, 1);
		}
		else
		{
			printf("Error LoadMusic!\n");
		}
	}
}

void GameScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);


	if (_gameDuration <= GameSystem::GetInstance()->GetTotalPlayingTime() + 500)
	{
		_gameDuration += deltaTime;
		//_track->Update(deltaTime);

		//if (_prevScore != _track->GetScore())
		//{
		//	// Score Text
		//	_prevScore = _track->GetScore();
		//	char text[256];
		//	sprintf(text, "Score %04d", _track->GetScore());
		//	_text->SetText(text, 100, 500);

		//	//Combo Text
		//	char combo[256];
		//	sprintf(combo, "Combo %04d", _track->GetCombo());
		//	_combo->SetText(combo, 100, 300);
		//}
		int sumScore = 0;
		int sumCombo = 0;
		
		// 각각의 트랙에서 얻어오는 콤보 수와 점수를 받아옴.
		for (int i = 0; i < _trackArray->Size(); i++)
		{
			Track* track = _trackArray->Get(i);
			track->Update(deltaTime);
			sumScore += track->GetScore();
			sumCombo += track->GetCombo();
			
			
		}
		if (_finalScore <= sumScore)
		{
			// 득점하는 점수를 표현
			_finalScore = sumScore;
			char text[256];
			sprintf(text, "Score %04d", _finalScore);
			_text->SetText(text, 100, 500);
		}
		if (_maxCombo <= sumCombo)
		{
			// 최대 콤보수를 표현
			_maxCombo = sumCombo;
			char combo[256];
			sprintf(combo, "Combo %04d", _maxCombo);
			_combo->SetText(combo, 100, 200);
		}
	}
	else
	{
		Mix_PauseMusic();
		GameSystem::GetInstance()->SetFinalScore(_finalScore);
		GameSystem::GetInstance()->SetMaxCombo(_maxCombo);
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RESULT);
	}
}

void GameScene::Render()
{
	_backgroundSprite->Render();

	for (int i = 0; i < _trackArray->Size(); i++)
	{
		Track* track = _trackArray->Get(i);
		track->Render();
	}
	_text->Render();
	_combo->Render();
}

void GameScene::Deinit()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}



	for (int i = 0; i < _trackArray->Size(); i++)
	{
		Track* track = _trackArray->Get(i);
		track->Deinit();
	}
}

void GameScene::KeyDown(unsigned int keyCode)
{
	if (TRACK_COUNT == 5)
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyDown();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyDown();
			break;
		case SDLK_SPACE:
			_trackArray->Get(2)->KeyDown();
			break;
		case SDLK_k:
			_trackArray->Get(3)->KeyDown();
			break;
		case SDLK_l :
			_trackArray->Get(4)->KeyDown();
			break;

		}
	}
	else if (TRACK_COUNT == 7)
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyDown();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyDown();
			break;
		case SDLK_d:
			_trackArray->Get(2)->KeyDown();
			break;
		case SDLK_SPACE:
			_trackArray->Get(3)->KeyDown();
			break;
		case SDLK_j:
			_trackArray->Get(4)->KeyDown();
			break;
		case SDLK_k:
			_trackArray->Get(5)->KeyDown();
			break;
		case SDLK_l:
			_trackArray->Get(6)->KeyDown();
			break;
		}
	}
	else
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyDown();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyDown();
			break;
		case SDLK_d:
			_trackArray->Get(2)->KeyDown();
			break;
		case SDLK_f:
			_trackArray->Get(3)->KeyDown();
			break;
		case SDLK_SPACE:
			_trackArray->Get(4)->KeyDown();
			break;
		case SDLK_h:
			_trackArray->Get(5)->KeyDown();
			break;
		case SDLK_j:
			_trackArray->Get(6)->KeyDown();
			break;
		case SDLK_k:
			_trackArray->Get(7)->KeyDown();
			break;
		case SDLK_l:
			_trackArray->Get(8)->KeyDown();
			break;
		}
	}
}

void GameScene::KeyUp(unsigned int keyCode)
{
	if (TRACK_COUNT == 5)
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyUp();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyUp();
			break;
		case SDLK_SPACE:
			_trackArray->Get(2)->KeyUp();
			break;
		case SDLK_k:
			_trackArray->Get(3)->KeyUp();
			break;
		case SDLK_l:
			_trackArray->Get(4)->KeyUp();
			break;

		}
	}
	else if (TRACK_COUNT == 7)
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyUp();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyUp();
			break;
		case SDLK_d:
			_trackArray->Get(2)->KeyUp();
			break;
		case SDLK_SPACE:
			_trackArray->Get(3)->KeyUp();
			break;
		case SDLK_j:
			_trackArray->Get(4)->KeyUp();
			break;
		case SDLK_k:
			_trackArray->Get(5)->KeyUp();
			break;
		case SDLK_l:
			_trackArray->Get(6)->KeyUp();
			break;
		}
	}
	else
	{
		switch (keyCode)
		{
		case SDLK_a:
			_trackArray->Get(0)->KeyUp();
			break;
		case SDLK_s:
			_trackArray->Get(1)->KeyUp();
			break;
		case SDLK_d:
			_trackArray->Get(2)->KeyUp();
			break;
		case SDLK_f:
			_trackArray->Get(3)->KeyUp();
			break;
		case SDLK_SPACE:
			_trackArray->Get(4)->KeyUp();
			break;
		case SDLK_h:
			_trackArray->Get(5)->KeyUp();
			break;
		case SDLK_j:
			_trackArray->Get(6)->KeyUp();
			break;
		case SDLK_k:
			_trackArray->Get(7)->KeyUp();
			break;
		case SDLK_l:
			_trackArray->Get(8)->KeyUp();
			break;
		}
	}
}
