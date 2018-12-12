#pragma once

#include "Texture.h"
#include "SDL_ttf.h"



class Font_t : public Texture
{
private:
	TTF_Font* _font;
	TTF_Font* _font1;
	SDL_Color _fontColor;
	SDL_Color _fontColor2;

public:
	Font_t(const char* fontName, int fontSize);
	~Font_t();

	void SetText(const char* text, int x, int y);

};