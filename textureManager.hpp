#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include"game.hpp"

class TextureManager{
private:

public:
	static SDL_Texture* loadText(const char *filename);
	static SDL_Texture* loadFont(std::string desc,int dim);
	static SDL_Texture* loadFontRed(std::string desc,int dim);
	static void draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};

#endif
