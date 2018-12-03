#pragma once

#include "Scene.h"

class Sprite;
class Font;

class Rank1 : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font* _test;

public:
	Rank1();
	~Rank1();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

};
