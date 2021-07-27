#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
#include<unistd.h>

SDL_Window *window;
SDL_Renderer *renderer;

int main()
{
	if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO)==0)
	{
		std::cout << "Subsystems initialized succesfully\n";
		
		window = SDL_CreateWindow("prova" , 0 , 0 , 100 , 100 , false);
		
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
		
	}
	Mix_Music *background0 = Mix_LoadMUS("back.mp3");
	

	Mix_PlayMusic(background0,-1);
	usleep(100000000);	
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	//Mix_FreeChunk(collided);
	Mix_FreeMusic(background0);
	//collided = NULL;
	background0 = NULL;
//	TTF_Quit();
	SDL_Quit();
	Mix_Quit();	
}
