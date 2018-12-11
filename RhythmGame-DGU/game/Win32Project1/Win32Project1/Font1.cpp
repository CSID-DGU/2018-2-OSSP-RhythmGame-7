#include "sdl_ttf.h"
#include "GameSystem.h"
#include "Font1.h"

Font1::Font1(const char* fontName, int fontSize)
{
	_font = TTF_OpenFont("../Resources/Font/BLKCHCRY.ttf", 50);
	_fontColor = { 237, 169, 0 };

	SetText("Score 0000", 11100, 800);
}

Font1::~Font1()
{
}

void Font1::SetText(const char* text, int x, int y)
{
	SDL_Surface* fontSurface = TTF_RenderText_Solid(_font, text, _fontColor);
	_texture = SDL_CreateTextureFromSurface(GameSystem::GetInstance()->GetRenderer(), fontSurface);

	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = x;
	_destRect.y = y;
	_destRect.w = _srcRect.w;
	_destRect.h = _srcRect.h;
}

