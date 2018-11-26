#pragma once

#include "DLinkedList.h"

class Sprite;
class Note;

class Track
{
private:
	DLinkedList<Note*> _noteList;
	Sprite* _backgroundSprite;
	Sprite* _judgeLineSprite;
	Sprite* _explosionSprite;
	Sprite* _failEffectSprite;
	Sprite* _lifeBar1Sprite;
	Sprite* _lifeBar2Sprite;
	Sprite* _lifeBar3Sprite;
	Sprite* _lifeBar4Sprite;
	Sprite* _lifeBar5Sprite;

	int _judgeStartTick;
	int _judgeEndTick;

	int _score;
	int _combo;
	int _maxCombo;
	int life;

public:
	Track();
	~Track();

	void Init(int x);
	void Update(int deltaTime);
	void Render();
	void Deinit();

	int GetScore() { return _score;  }
	int GetCombo() { return _combo; }
	void SetCombo(int combo) { _combo = combo; }

	// Input
private:
	bool _isKeyDown;

public:
	void KeyDown();
	void KeyUp();
};