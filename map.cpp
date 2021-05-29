#include"map.hpp"
#include "textureManager.hpp"

int p1[25][40] = {
	{0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,3,3,1,1,4,1,1,1,3,1,1,1,4,3,3,1,1,1,1,1,4,1,1,3,1,1,4,1,1,1,3,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,17,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,6,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,8,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,13,13,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,13,13,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,6,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,8,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,13,13,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,5,6,15,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,7,8,15,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,9,10,15,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,11,12,15,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
	
};


Map::Map()
{

	mattonella = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Mattonella_base.png");
	armadio = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Armadio.png");
	tavolo1 = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloA.png");
	tavolo2 = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloB.png");
	tavolo3 = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloC.png");
	tavolo4 = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloD.png");
	tavolo1L = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloAL.png");
	tavolo2L = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloBL.png");
	tavolo3L = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloCL.png");
	tavolo4L = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/TavoloDL.png");
	libreria = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Scaffale.png");
	finestra = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Finestra.png");
	muro = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Muro.png");
	pianta = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/Pianta.png");
	sediasx = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/SediaSx.png");
	sediadx = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/SediaDx.png");
	sediaup = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/SediaAx.png");
	sediadown = TextureManager::loadText("/home/salvatore/Scrivania/Codemons/SPRITES/Ambienti/Primo_Piano/SediaAx.png");
	
	loadMap(p1);
	
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	
	dest.x = dest.y = 0;
	

}

inline void Map::loadMap(int arr[25][40])
{	
	for(int rows = 0; rows < 25; rows++)
	{
		for(int cols = 0; cols < 40 ; cols++)
		{
			map[rows][cols] = arr[rows][cols];
		}
	}
}


inline void Map::loadMap(const char* filename)
{
	std::ifstream in(filename);	
	for(int rows = 0; rows < 25; rows++)
	{
		for(int cols = 0; cols < 40 ; cols++)
		{
			in>>map[rows][cols];
		}
	}
}


inline void Map::drawMap()
{
	int type = 0;
	for(int rows = 0; rows < 25; rows++)
	{
		for(int cols = 0; cols < 40 ; cols++)
		{
			type = map[rows][cols];
			
			dest.x = cols * 32;
			dest.y = rows * 32;
			
			switch(type)
			{
				case 0:
					TextureManager::draw(muro,src,dest);
					break;
				case 1:
					TextureManager::draw(mattonella,src,dest);
					break;
				case 2:
					TextureManager::draw(finestra,src,dest);
					break;
				case 3:
					TextureManager::draw(armadio,src,dest);
					break;
				case 4:
					TextureManager::draw(pianta,src,dest);
					break;
				case 5:
					TextureManager::draw(tavolo1,src,dest);
					break;
				case 6:
					TextureManager::draw(tavolo2,src,dest);
					break;
				case 7:
					TextureManager::draw(tavolo3,src,dest);
					break;
				case 8:
					TextureManager::draw(tavolo4,src,dest);
					break;
				case 9:
					TextureManager::draw(tavolo1L,src,dest);
					break;
				case 10:
					TextureManager::draw(tavolo2L,src,dest);
					break;
				case 11:
					TextureManager::draw(tavolo3L,src,dest);
					break;
				case 12:
					TextureManager::draw(tavolo4L,src,dest);
					break;
				case 13:
					TextureManager::draw(libreria,src,dest);
					break;
				case 14:
					TextureManager::draw(sediasx,src,dest);
					break;
				case 15:
					TextureManager::draw(sediadx,src,dest);
					break;
				case 16:
					TextureManager::draw(sediaup,src,dest);
					break;
				case 17:
					TextureManager::draw(sediadown,src,dest);
					break;																
				default:
					break;		
			}	
		}
	}

}
