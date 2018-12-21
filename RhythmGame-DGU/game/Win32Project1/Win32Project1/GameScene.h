#pragma once

//#include "sdl_image.h"
#include "Scene.h"
#include "Array.h"
#include "OptionScenex1.h"

class Sprite;
class Track;
class Font;
class OptionScene;

class GameScene : public Scene
{
private:
	//Sprite* _backgroundSprite;

	//Track* _track;
	Array<Track*>* _trackArray;
	int _gameDuration;
	int _finalScore;
	int _maxCombo;

	Font* _text;
	Font* _combo;
	OptionScene* bpm;


public:
	GameScene();
	~GameScene();

	void Init();
	void Update(int deltaTime);
	void Render();
	void Deinit();
	

	// Input
public:
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};