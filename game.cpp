#include "game.hpp"
#include"Codemon.hpp"
#include"textureManager.hpp"
#include"codedex.hpp"
#include "map.hpp"





Map *map;
Player *p;
SDL_Renderer* Game::renderer = nullptr;
Codedex *codedex;
int lastPx,lastPy;//queste sono le coordinate x e y del player prima della pressione di un tasto di movimento : mi servono nel casso in cui esso collida con qualcosa e sembra funzionare :)

Codemon *c,*c1,*c2;
Codemon **allz;
Mix_Music *background0;
Mix_Chunk *collided;
Personaggio *pers;


Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title,int posx,int posy,int width,int height,bool fullscreen)
{

	
	allz = new Codemon*[3];


	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	TTF_Init();
		
	if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO)==0)
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
		
		if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
		{
			std::cout << "Error: " << Mix_GetError() << std::endl;
		}

		
		isRunning = true;
	}else{
		isRunning = false;
	}	

	p = new Player("Salvo",0,"SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Female/FrontStopFemale.png","SPRITES/Player/Female/FrontStopFemale.png");
		c = new Codemon("a b c d",0,1,5,2,10,10,5,5,5,5,1,100,"SPRITES/Sprites_Codemon/GENERIC/MATRIX.png","SPRITES/Sprites_Codemon/GENERIC/AND.png","Descrizione di prova numero uno : codedex riesce a contenere tutto questo fino a qui e anche oltre\n potremmo arrivare anche qui");
	c1 = new Codemon("def",1,1,5,2,10,10,5,5,5,5,1,100,"SPRITES/Sprites_Codemon/GENERIC/AND.png","SPRITES/Sprites_Codemon/GENERIC/AND.png","DESCRIZIONE DI PROVA");
	c2 = new Codemon("ghi",2,1,5,2,10,10,5,5,5,5,1,100,"SPRITES/Sprites_Codemon/GENERIC/RETURN.png","SPRITES/Sprites_Codemon/GENERIC/AND.png","DESCRIZIONE DI PROVA");
	//c2 = new Codemon("ghi",3,1,5,2,10,10,5,5,5,5,1,100,"SPRITES/Sprites_Codemon/GENERIC/XOR.png","SPRITES/Sprites_Codemon/GENERIC/AND.png");
	allz[0] = c;
	allz[1] = c1;
	allz[2] = c2;
	 codedex = new Codedex(allz);
	map = new Map();
	Mix_Volume(-1, MIX_MAX_VOLUME);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	background0 = Mix_LoadMUS("music/naruto_opening_16.wav");
	collided = Mix_LoadWAV("music/ALARMCLOCK.WAV");
	Mix_PlayMusic(background0,-1);
	std::cout << Mix_GetError();
	pers =  new Personaggio ("Personaggio 3",3,3,0,"SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Male/FrontStopMale.png","SPRITES/Player/Female/FrontStopFemale.png","SPRITES/Player/Female/FrontStopFemale.png", 608,320);
	
	
}

void Game::handleEvents()
{
	

	SDL_Event event;
	SDL_PollEvent(&event);
	lastPx = p->posx;
	lastPy = p->posy;
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
					codedex->show = true;
					break;
				case SDLK_o:
					codedex->show = false;
					break;	
				}		
		}
			
	}
	
}


void Game::update()
{
	collision(p,map);
	pers->draw();
	p->update();
	pers->interact(*p);
	if (codedex->show == true){
		codedex->draw();
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
					case SDLK_r:
						codedex->reset();
						break;
					case SDLK_m:
						codedex->avanti();
						break;
					case SDLK_n:
						codedex->indietro();
						break;
					default:
						break;	
							
				}
			}	
		}
	}
	
	/*if(p->posx >= 320){
			map->loadMap("maps/p1.txt");
			c->drawF();
			c->drawB();
	}*/
	
	
	/*
	funziona :3
	
	
	*/
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
	pers->render();
	p->render();
	c->render();
	
	if(codedex->show)
	{	
		SDL_RenderClear(renderer);
		codedex->render();
	} 
	//add stuff to render
	
	
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_FreeChunk(collided);
	Mix_FreeMusic(background0);
	collided = NULL;
	background0 = NULL;
	TTF_Quit();
	SDL_Quit();
	Mix_Quit();
	std::cout << "Game Cleaned\n";
}

void Game::collision(Player *p,Map *m)
{
	int j = p->posx/32;
	int i = p->posy/32;
	
	if(m->map[i][j]!=1)
	{
		p->posx = lastPx;
		p->posy = lastPy;
		//std::cout << i << " " << j << "->" << m->map[i][j] << std::endl;
		if(Mix_PlayChannel(-1,collided,0) == 0)
		{
			std::cout << "COLLISION DETECTED\n";
		}
	}
	
		
}
