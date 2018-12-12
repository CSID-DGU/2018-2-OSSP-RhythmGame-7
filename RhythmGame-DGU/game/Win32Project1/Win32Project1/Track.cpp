#include <stdio.h>
#include <stdlib.h>

#include "GameSystem.h"
#include "Note.h"
#include "Sprite.h"

#include "Track.h"

Track::Track()
{
	_backgroundSprite = NULL;
	_judgeLineSprite = NULL;
	_lifeBar1Sprite = NULL;
	_lifeBar2Sprite = NULL;
	_lifeBar3Sprite = NULL;
	_lifeBar4Sprite = NULL;
	_lifeBar5Sprite = NULL;
	_isKeyDown = false;
	_combo = 0;
	_maxCombo = 0;
	life = 5;
	
}

Track::~Track()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}

	if (NULL != _judgeLineSprite)
	{
		delete _judgeLineSprite;
		_judgeLineSprite = NULL;
	}

	if (NULL != _explosionSprite)
	{
		delete _explosionSprite;
		_explosionSprite = NULL;
	}

	if (NULL != _failEffectSprite)
	{
		delete _failEffectSprite;
		_failEffectSprite = NULL;
	}
	if (NULL != _lifeBar1Sprite)
	{
		delete _lifeBar1Sprite;
		_lifeBar1Sprite = NULL;
	}
	if (NULL != _lifeBar2Sprite)
	{
		delete _lifeBar2Sprite;
		_lifeBar2Sprite = NULL;
	}
	if (NULL != _lifeBar3Sprite)
	{
		delete _lifeBar3Sprite;
		_lifeBar3Sprite = NULL;
	}
	if (NULL != _lifeBar4Sprite)
	{
		delete _lifeBar4Sprite;
		_lifeBar4Sprite = NULL;
	}
	if (NULL != _lifeBar5Sprite)
	{
		delete _lifeBar5Sprite;
		_lifeBar5Sprite = NULL;
	}
}

void Track::Init(int x)
{
	int judgeLineOffset = 100;

	_backgroundSprite = new Sprite("trackspr", true);
	_backgroundSprite->SetPosition(x, GameSystem::GetInstance()->GetWindowHeight() / 2);

	_judgeLineSprite = new Sprite("judgelinespr", true);
	_judgeLineSprite->SetPosition(x, GameSystem::GetInstance()->GetWindowHeight() - judgeLineOffset);

	_explosionSprite = new Sprite("successeffectspr", false);
	_explosionSprite->SetPosition(x, GameSystem::GetInstance()->GetWindowHeight() - judgeLineOffset);
	
	_failEffectSprite = new Sprite("faileffectspr", false);
	_failEffectSprite->SetPosition(x, GameSystem::GetInstance()->GetWindowHeight() / 2);

	_lifeBar1Sprite = new Sprite("lifebar1spr", false);
	_lifeBar1Sprite->SetPosition(900, 700);

	_lifeBar2Sprite = new Sprite("lifebar2spr", false);
	_lifeBar2Sprite->SetPosition(900, 630);

	_lifeBar3Sprite = new Sprite("lifebar3spr", false);
	_lifeBar3Sprite->SetPosition(900, 560);

	_lifeBar4Sprite = new Sprite("lifebar4spr", false);
	_lifeBar4Sprite->SetPosition(900, 490);

	_lifeBar5Sprite = new Sprite("lifebar5spr", false);
	_lifeBar5Sprite->SetPosition(900, 420);


	float totalPlayingSec = GameSystem::GetInstance()->GetTotalPlayingTime() / 1000.0f;
	float startNoteSec = 1.0f;
	while (startNoteSec < totalPlayingSec)
	{
		Note*	note = new Note(startNoteSec, judgeLineOffset, x);
		_noteList.Append(note);

		int randVal = rand() % 3;
		switch (randVal)
		{
		case 0:
			startNoteSec += 0.25f;
			break;
		case 1:
			startNoteSec += 0.5f;
			break;
		case 2:
			startNoteSec += 0.75f;
			break;
		case 3:
			startNoteSec += 1.0f;
			break;
		}
	}

	_score = 0;

	int judgeTick = GameSystem::GetInstance()->GetTotalPlayingTime();
	_judgeStartTick = judgeTick - 100;
	_judgeEndTick = judgeTick + 100;
}

void Track::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
	_judgeLineSprite->Update(deltaTime);
	_lifeBar1Sprite->Update(250);
	_lifeBar2Sprite->Update(250);
	_lifeBar3Sprite->Update(250);
	_lifeBar4Sprite->Update(250);
	_lifeBar5Sprite->Update(250);

	DLinkedListIterator<Note*> itr = _noteList.GetIterator();
	for (itr.begin(); itr.valid(); itr.forth())
	{
		Note* note = itr.item();
		if (note->IsLive())
		{
			note->Update(deltaTime);

			if (_judgeEndTick < note->GetCurrentTime() && false == note->IsPassed())
			{
				note->Passed();
				printf("Fail Effect\n");
				life--;
				//printf("life : %d\n", life);
				_failEffectSprite->Play();
				_combo = 0;
			}
		}
	}

	_explosionSprite->Update(deltaTime);
	_failEffectSprite->Update(deltaTime);
}

void Track::Render()
{
	_backgroundSprite->Render();
	_judgeLineSprite->Render();
	_lifeBar1Sprite->Render();
	_lifeBar2Sprite->Render();
	_lifeBar3Sprite->Render();
	_lifeBar4Sprite->Render();
	_lifeBar5Sprite->Render();

	DLinkedListIterator<Note*> itr = _noteList.GetIterator();
	for (itr.begin(); itr.valid(); itr.forth())
	{
		itr.item()->Render();
	}

	_explosionSprite->Render();
	_failEffectSprite->Render();

	if (life >= 5)
	{
		_lifeBar1Sprite->Play();
		_lifeBar2Sprite->Play();
		_lifeBar3Sprite->Play();
		_lifeBar4Sprite->Play();
		_lifeBar5Sprite->Play();
	}
	else if (life == 4)
	{
		_lifeBar1Sprite->Play();
		_lifeBar2Sprite->Play();
		_lifeBar3Sprite->Play();
		_lifeBar4Sprite->Play();
		
	}
	if (life == 3)
	{
		_lifeBar1Sprite->Play();
		_lifeBar2Sprite->Play();
		_lifeBar3Sprite->Play();
	

	}
	if (life == 2)
	{
		_lifeBar1Sprite->Play();
		_lifeBar2Sprite->Play();
	

	}
	if (life == 1)
	{
		_lifeBar1Sprite->Play();
	
	}

}

void Track::Deinit()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}

	if (NULL != _judgeLineSprite)
	{
		delete _judgeLineSprite;
		_judgeLineSprite = NULL;
	}

	if (NULL != _explosionSprite)
	{
		delete _explosionSprite;
		_explosionSprite = NULL;
	}

	if (NULL != _failEffectSprite)
	{
		delete _failEffectSprite;
		_failEffectSprite = NULL;
	}

	if (NULL != _lifeBar1Sprite)
	{
		delete _lifeBar1Sprite;
		_lifeBar1Sprite = NULL;
	}

	if (NULL != _lifeBar2Sprite)
	{
		delete _lifeBar2Sprite;
		_lifeBar2Sprite = NULL;
	}

	if (NULL != _lifeBar3Sprite)
	{
		delete _lifeBar3Sprite;
		_lifeBar3Sprite = NULL;
	}

	if (NULL != _lifeBar4Sprite)
	{
		delete _lifeBar4Sprite;
		_lifeBar4Sprite = NULL;
	}

	if (NULL != _lifeBar5Sprite)
	{
		delete _lifeBar5Sprite;
		_lifeBar5Sprite = NULL;
	}

	DLinkedListIterator<Note*> itr = _noteList.GetIterator();
	for (itr.begin(); itr.valid(); itr.forth())
	{
		delete itr.item();
		_noteList.Remove(itr);
	}
}

void Track::KeyDown()
{
	if (true ==_isKeyDown)
		return;
	_isKeyDown = true;

	bool isJudge = false;
	DLinkedListIterator<Note*> itr = _noteList.GetIterator();
	for (itr.begin(); itr.valid(); itr.forth())
	{
		Note* note = itr.item();

		if (false == note->IsLive())
		{
			continue;
		}

		if (note->IsPassed())
		{
			continue;
		}

		if (note->GetCurrentTime() < _judgeStartTick)
		{
			break;
		}

		if (_judgeStartTick <= note->GetCurrentTime() && note->GetCurrentTime() <= _judgeEndTick)
		{
			isJudge = true;
			break;
		}
	}

	if (isJudge)
	{
		printf("Success Effect\n");
		
		_explosionSprite->Play();
		_score += 100;
		_combo += 1;
		life++;
		printf("life : %d, life : \n", life);
		itr.item()->SetLive(false);
		if (_combo >= _maxCombo) {
			_maxCombo = _combo;
			Track::SetCombo(_maxCombo);
		}
	}
	else
	{
		_combo = 0;
	}
	

}

void Track::KeyUp()
{
	_isKeyDown = false;
}