#pragma once

#include "SDL_Image.h"
#include "Array.h"

class Texture;

class Sprite
{
private:
	Array<Texture*>* _textureList;

	int _x;
	int _y;

	int _frameMaxCount;
	int _frame;

	bool _isLoop;
	bool _isPlay;
	int _frameInterval;
	int _frameDuration;

public:
	Sprite(const char* scriptFilename, bool isLoop);
	~Sprite();

	void Update(int deltaTime);
	void Render();

	void UpdateTexturePosition(Texture* texture);
	void SetPosition(int x, int y);

	void Play();
	void Life();
	void LifeDelete();
};