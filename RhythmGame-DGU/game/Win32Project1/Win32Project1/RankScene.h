#pragma once

#include "Scene.h"

extern int score1;
extern int socre2;
extern int socre3;
extern int socre4;
extern int socre5;


class Sprite;
class Font;

class RankScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font* _test;

	Font* _rankTitle;
	Font* _score1;
	Font* _score2;
	Font* _score3;
	Font* _score4;
	Font* _score5;

public:
	RankScene();
	~RankScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

};
