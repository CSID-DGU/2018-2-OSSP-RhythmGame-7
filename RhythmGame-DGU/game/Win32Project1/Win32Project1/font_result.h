#pragma once

#include "Texture.h"
#include "SDL_ttf.h"



class Font_r : public Texture
{
private:
	TTF_Font* _font;
	TTF_Font* _font1;
	SDL_Color _fontColor;
	SDL_Color _fontColor2;

public:
	Font_r(const char* fontName, int fontSize);
	~Font_r();

	void SetText(const char* text, int x, int y);

};