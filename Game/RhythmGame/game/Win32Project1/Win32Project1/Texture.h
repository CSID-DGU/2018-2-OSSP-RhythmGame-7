#pragma once

#include "SDL_Image.h"

class Texture
{
protected:
	SDL_Texture* _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;

public:
	Texture() {}
	Texture(const char* fileName);
	~Texture();

	void Render();

	void SetScale(float scaleW, float scaleH);
	void SetPosition(int x, int y);
	
	int GetRenderWidth();
	int GetRenderHeight();

};
