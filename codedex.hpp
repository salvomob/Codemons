#ifndef CODEDEX_HPP
#define CODEDEX_HPP


#include<string>
#include<cstdlib>


class Game;
class Codedex{
private:
	Codemon **all;
	bool *locked;
	std::string *descriptions;
	std::string *names;
	SDL_Texture *fontDesc,*fontName,*fontID;
	SDL_Rect sourceF,destinationFD,destinationFN,destinationFID;
	SDL_Texture *textFront;
	SDL_Rect source,destination;
	
public:
	int idk = 0;
	bool show;
	int posx,posy;
	Codedex(){}
	Codedex(Codemon **all)
	{
		this->all = all;
		locked = new bool[3];//da definire quanti codemon creare
		for(int i = 0; i < 3 ; i++) locked[i] = false;
		this->descriptions = new std::string[3];
		for(int i = 0; i < 3 ; i++) descriptions[i] = "";
		this->names = new std::string[3];
		for(int i = 0; i < 3 ; i++) names[i] = "";
		this->setNames();
		this->posx = 560;
		this->posy = 420;
		show = false;
		SDL_SetRenderDrawColor(Game::renderer,255,255,255,255);
	}
	
	void setNames()
	{
		for(int i = 0; i< 3 ; i++)
		{
			names[i] = all[i]->getNome();
		}
	}
	
	void loadFront(int id)
	{
		Codemon *c = all[id];
		textFront = TextureManager::loadText(c->getFile());
		
	}
	
	void loadFontDesc(int id)
	{
		Codemon *c = all[id];
		fontDesc = TextureManager::loadFont(c->getDescription(),10);
	}
	
	void loadFontName(int id)
	{
		Codemon *c = all[id];
		fontName = TextureManager::loadFontRed(c->getNome(),20);
	}
	
	void loadFontID(int id)
	{
		Codemon *c = all[id];
		fontID = TextureManager::loadFont(std::to_string(c->getID()),20);
	}
	
	void draw()
	{
		
		loadFront(idk);
		loadFontDesc(idk);
		loadFontName(idk);
		loadFontID(idk);
		source.h = 128;
		source.w = 128;
		source.x = 0;
		source.y = 0;
			
		sourceF.h = 1280;
		sourceF.w = 1280;
		sourceF.x = 0;
		sourceF.y = 0;
		
		destination.x = posx;
		destination.y = posy;
		destination.w = 128;
		destination.h = 128;
			
		destinationFN.x = posx;
		destinationFN.y = posy+destination.h;
		destinationFN.w = 128;
		destinationFN.h = 128;
		
		destinationFID.x = posx+20;
		destinationFID.y = 0;
		destinationFID.w = 128;
		destinationFID.h = 128;
		
		destinationFD.x = 0;
		destinationFD.y = posy+destination.h+destinationFN.h;
		destinationFD.w = 1280;
		destinationFD.h = 64;
		
		
	}
	
	
	void reset()
	{
		idk = 0;
	}
	
	void avanti()
	{
		if(idk < 2)
			idk++;
		else idk = 2;	
	}
	
	void indietro()
	{
		if(idk != 0)
		idk--;
		else idk = 0;
	}
	
	void render()
	{
		//SDL_RenderClear(Game::renderer);
		SDL_RenderCopy(Game::renderer,textFront,&source,&destination);
		SDL_RenderCopy(Game::renderer,fontID,&sourceF,&destinationFID);
		SDL_RenderCopy(Game::renderer,fontDesc,&sourceF,&destinationFD);
		SDL_RenderCopy(Game::renderer,fontName,&sourceF,&destinationFN);
	}
	
};

#endif
