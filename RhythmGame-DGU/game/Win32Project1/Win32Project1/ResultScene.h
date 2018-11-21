#pragma once

#include "Scene.h"

class Sprite;
class Font;

class ResultScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	Font* _score;
	Font* _maxCombo;

public:
	ResultScene();
	~ResultScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);
};
