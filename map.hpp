#ifndef MAP_HPP
#define MAP_HPP
#include "game.hpp"
#include "textureManager.hpp"
#include <fstream>


class Map
{
private:
	
	SDL_Rect src,dest;
	SDL_Texture* mattonella;
	SDL_Texture* armadio;
	SDL_Texture* tavolo1;
	SDL_Texture* tavolo2;
	SDL_Texture* tavolo3;
	SDL_Texture* tavolo4;
	SDL_Texture* tavolo1L;
	SDL_Texture* tavolo2L;
	SDL_Texture* tavolo3L;
	SDL_Texture* tavolo4L;
	SDL_Texture* libreria;
	SDL_Texture* finestra;
	SDL_Texture* muro;
	SDL_Texture* pianta;
	SDL_Texture* sediasx;
	SDL_Texture* sediadx;
	SDL_Texture* sediaup;
	SDL_Texture* sediadown;
	
	int map[25][40];
	
	
public:

	Map();
	~Map();
	
	void loadMap(int arr[25][40]);
	void loadMap(const char* filename);
	void drawMap();
		
};

#endif
