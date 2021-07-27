#include "textureManager.hpp"

inline SDL_Texture* TextureManager::loadText(const char *filename)
{
	SDL_Surface *tmp = IMG_Load(filename);
	SDL_Texture *text = SDL_CreateTextureFromSurface(Game::renderer,tmp);
	SDL_FreeSurface(tmp);
	return text;

}

inline void TextureManager::draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer,text,&src,&dest);
}

inline SDL_Texture* TextureManager::loadFont(std::string desc,int dim)
{
	SDL_Color color = {0,0,0};
	TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", dim);
	const char * descr = desc.c_str();
	SDL_Surface *tmp = TTF_RenderText_Solid(font,descr, color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(Game::renderer,tmp);
	SDL_FreeSurface(tmp);
	TTF_CloseFont(font);
	return text;

}

inline SDL_Texture* TextureManager::loadFontRed(std::string desc,int dim)
{
	SDL_Color color = {255,0,0};
	TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", dim);
	const char * descr = desc.c_str();
	SDL_Surface *tmp = TTF_RenderText_Solid(font,descr, color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(Game::renderer,tmp);
	SDL_FreeSurface(tmp);
	TTF_CloseFont(font);
	return text;

}
