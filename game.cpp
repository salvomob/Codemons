#include "game.hpp"
#include"Codemon.hpp"
#include"textureManager.hpp"
#include "map.hpp"


Map *map;
Codemon *c;
Player *p;
SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title,int posx,int posy,int width,int height,bool fullscreen)
{
	

	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	TTF_Init();
		
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		std::cout << "Subsystems initialized succesfully\n";
		
		window = SDL_CreateWindow(title , posx , posy , width , height , flags);
		
		if(window)
		{
			std::cout << "Window created succesfully\n";
		}
		
		renderer = SDL_CreateRenderer(window,-1,0);
		
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			std::cout << "Renderer created succesfully\n";
		}
		
		
		
		isRunning = true;
	}else{
		isRunning = false;
	}	
	
	p = new Player("Salvo",0,"SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Female/FrontStopFemale.png","SPRITES/Player/Female/FrontStopFemale.png");
	c = new Codemon("abc",1,1,5,2,10,10,5,5,5,5,1,100,"SPRITES/Sprites_Codemon/GENERIC/MATRIX.png","SPRITES/Sprites_Codemon/GENERIC/AND.png");
	map = new Map();
	

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYUP:
		{
			switch(event.key.keysym.sym)
				{
				case SDLK_w:
					p->posy = p->posy - 32;
					break;
				case SDLK_s:
					p->posy = p->posy + 32;
					break;
				case SDLK_a:
					p->posx = p->posx -32;
					break;
				case SDLK_d:
					p->posx = p->posx + 32;
					break;	
				case SDLK_p:
					sfidaP(*p,*c);
				}		
		}
		default:
			break;	
	}
}


void Game::update()
{
	p->update();
	//c->update();
	/*
	N.B. caricheremo le matrici direttamente da file testuali per rendere il codice più leggibile
	prova ! funziona :)
	if(c->posx >= 500 )//&& c->posy<=64 && c->posy>=32)
	{
		map->loadMap(p2);
	}*/
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();
	p->render();
	//c->render();
	//add stuff to render
	
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned\n";
}
