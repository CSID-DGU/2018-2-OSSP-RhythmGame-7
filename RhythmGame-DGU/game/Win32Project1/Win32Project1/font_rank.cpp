#include "sdl_ttf.h"
#include "GameSystem.h"
#include "font_rank.h"

Font_rk::Font_rk(const char* fontName, int fontSize)
{
	_font = TTF_OpenFont("../Resources/Font/pcsenior.ttf", 40);
	_fontColor = { 255, 255, 255 };
}

Font_rk::~Font_rk()
{
}

void Font_rk::SetText(const char* text, int x, int y)
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

