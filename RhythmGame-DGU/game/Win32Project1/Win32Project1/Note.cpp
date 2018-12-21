#include "GameSystem.h"

#include "Sprite.h"
#include "Note.h"

Note::Note(float startSec, int judgeLineOffset, int x)
{
	_sprite = new Sprite("notespr", true);

	//_x = GameSystem::GetInstance()->GetWindowWidth() / 2;
	_x = x;
	_judgeLineOffset = judgeLineOffset;

	// 필요한 데이터
	_isLive = true;

	_trackHeight = GameSystem::GetInstance()->GetTrackHeight();
	int noteTick = startSec * 2500;
	int startTick = GameSystem::GetInstance()->GetTotalPlayingTime() - noteTick;

	_updateDuration = startTick;
	UpdatePosition(0);

	_isPassed = false;
}

Note::~Note()
{
	delete _sprite;
}

void Note::Update(int deltaTime)
{
	if (false == _isLive)
		return;
	UpdatePosition(deltaTime);
	_sprite->Update(deltaTime);
}

void Note::Render()
{
	if (false == _isLive)
		return;
	_sprite->Render();
}

void Note::UpdatePosition(int deltaTime)
{
	_updateDuration += deltaTime;
	float timePositionRate = (float)_updateDuration / (float)GameSystem::GetInstance()->GetTotalPlayingTime();
	float positionByTick = (float)_trackHeight * timePositionRate;
	_y = positionByTick - (_trackHeight - GameSystem::GetInstance()->GetWindowHeight()) - _judgeLineOffset;

	_sprite->SetPosition(_x, _y);

	if (GameSystem::GetInstance()->GetTotalPlayingTime()+500 < _updateDuration)
	{
		_isLive = false;
	}
}

bool Note::IsLive()
{
	return _isLive;
}

void Note::Passed()
{
	_isPassed = true;
}

bool Note::IsPassed()
{
	return _isPassed;
}

int Note::GetCurrentTime()
{
	return _updateDuration;
}
