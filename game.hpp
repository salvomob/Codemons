#ifndef GAME_HPP
#define GAME_HPP

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<fstream>

class Player;
class Map;

class Game{

private:
	bool isRunning;
	SDL_Window *window;
	int a = 0;
	
public:
	Game();
	~Game();
	void init(const char *title,int posx,int posy,int width,int height,bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	static SDL_Renderer *renderer;
	static TTF_Font *font;
	bool running()
	{
		return isRunning;
	}
	void collision(Player* p,Map *map);
};

#endif


