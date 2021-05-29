#ifndef CODEMON_HPP
#define CODEMON_HPP
#include"game.hpp"
#include<fstream>
#include<cstdlib>
#include"swap.hpp"
#include"textureManager.hpp"


/*

Il codemon possiede vari attributi, necessari non solo per le lotte, ma anche per il suo riconoscimento all'interno di un eventuale Codedex
All'interno del file specifiche.txt si trova una descrizione più dettagliata di ogni attributo e metodo della classe.

*/

//class Mossa;

class Codemon{
private:
	std::string nome;
	int id;
	int tipo;
	int livello;
	int maxL;
	int *levels;
	int expI;
	int exp;
	int expM;
	int nMosseI;
	int nMosse;
	int nMosseC;
	int nMosseA;
	int attacco;
	int difesa;
	int attaccoX;
	int difesaX;
	int velocita;
	int precisione;
	int stadio;
	int hpM;
	int hp;
	std::string stato;
	bool fainted;
	int identification;
	Mossa **mosseI;
	Mossa **mosse;
	Mossa **mosseC;
	Mossa **mosseA;
	SDL_Texture * font ;
	SDL_Rect sourceF,destinationF;
	SDL_Texture *textFront,*textBack;
	SDL_Rect source,destination;
	const char* filenameFront;
	const char* filenameBack;
	
public:
		
	int posx;
	int posy;		
	
	Codemon(){}
	
	Codemon(std::string nome,int id,int tipo,int livello,int nMosseI,int attacco,int difesa,int attaccoX,int difesaX,int velocita,int precisione,int stadio,int hpM,const char* filenameFront, const char* filenameBack){
		this->nome = nome;
		this->id = id;
		this->tipo = tipo;
		this->livello = livello;
		this->maxL = 100;
		this->expM = 505000;
		this->levels = new int[maxL];
		int epl = 0;
		int mL = this->maxL;
		for(int i = mL; i>=-1, mL>=-1; i--,mL--){
			if(epl == 0) this->levels[maxL] = this->expM;
			this->levels[i] = (this->expM-epl);
			epl += mL*100;
			
		}
		int x = 0;
		for(int i = livello; i >= 0; i--,livello--){
			x += livello*100;
		}
		this->expI = x;
		this->exp = x;
		this->nMosseI = 2;
		this->nMosse = 0;
		this->nMosseC = 4;
		this->nMosseA = 20;
		this->attacco = attacco;
		this->difesa = difesa;
		this->attaccoX = attaccoX;
		this->difesaX = difesaX;
		this->velocita = velocita;
		this->precisione = precisione;
		this->stadio = stadio;
		this->hpM = hpM;
		this->hp = hpM;
		this->stato = "OK";
		this->fainted = false;
		this->identification = rand()%1000000;
		this->mosseI = new Mossa*[this->nMosseI];
		for(int i = 0; i < this->nMosseI; i++) this->mosseI[i] = NULL;
		this->mosse = new Mossa*[this->nMosse];
		for(int i = 0; i < this->nMosse; i++) this->mosse[i] = NULL;
		this->mosseC = new Mossa*[this->nMosseC];
		for(int i = 0; i < this->nMosseC; i++) this->mosseC[i] = NULL;
		this->mosseA = new Mossa*[this->nMosseA];
		for(int i = 0; i < this->nMosseA; i++) this->mosseA[i] = NULL;  	
		textFront = TextureManager::loadText(filenameFront);
		textBack = TextureManager::loadText(filenameBack);
		font = TextureManager::loadFont(this->nome,20);
		posx = 0; 
		posy = 0;
	}
	//metodi get->possono essere usati per tener traccia dei valori del codemon al di fuori della classe codemon (ad esempio durante uno scontro o durante altre features)
	
	std::string getNome(){
		return this->nome;
	}
	
	int getID(){
		return this->id;
	}

	int getTipo(){
		return this->tipo;
	}

	int getLivello(){
		return this->livello;
	}

	int getMaxL(){
		return this->maxL;
	}

	int* getLevels(){
		return this->levels;
	}

	int getExpI(){
		return this->expI;
	}

	int getExp(){
		return this->exp;
	}

	int getExpM(){
		return this->expM;
	}

	int getNMI(){
		return this->nMosseI;
	}

	int getNMC(){
		return this->nMosseC;
	}

	int getNMA(){
		return this->nMosseA;
	}
	
	int getNM(){
		return this->nMosse;
	}	
	int getAttacco(){
		return this->attacco;
	}

	int getDifesa(){
		return this->difesa;
	}
	
	int getAttaccoX(){
		return this->attaccoX;
	}

	int getDifesaX(){
		return this->difesaX;
	}
	
	int getVelocita(){
		return this->velocita;
	}
	
	int getPrecisione(){
		return this->precisione;
	}
	
	int getStadio(){
		return this->stadio;
	}
	
	int getHP(){
		return this->hp;
	}
	
	std::string getStato(){
		return this->stato;
	}
	
	bool getFainted(){
		if(this->hp  == 0){
			this->fainted = true;
			return this->fainted;
		}
		else return false;
		
	}
	
	int getIdentification(){
		return this->identification;
	}
	
	void incNmosse(){
		if(this->nMosse < this->nMosseC)
			this->nMosse = this->nMosse + 1;
		else {
			std::cout << "Non e' possibile imparare altre mosse\n";
			return;
		}	
	}
	
	
	//metodi set,inc,dec ->void()
	void incExp(int increment){
		if(this->exp+increment<this->expM){
			this->exp = this->exp+increment;
			int lev = this->livello;
			while(this->exp >= levels[lev+1] && this->exp<=expM){
				lev++;
				incL();
			}	
		}
		else{
			this->exp = this->expM;
			this->livello = 100;
		}
	}
		
	void incL(){
		this->livello = this->livello+1;
		this->attacco = this->attacco+10;
		this->difesa = this->difesa+10;
		this->attaccoX = this->attaccoX+5;
		this->difesaX = this->difesaX+5;
		this->hpM = this->hpM+10;
		this->hp = this->hp + 10;
		this->velocita = this->velocita+5;
		this->precisione = this->precisione+5;
	}
	
	void setAttacco(int att){
		this->attacco = this->attacco+att;
	}
	
	void setAttaccoX(int attX){
		this->attaccoX = this->attaccoX+attX;
	}
	
	void setDifesa(int dif){
		this->difesa = this->difesa+dif;
	}
	
	void setDifesaX(int difX){
		this->difesaX = this->difesaX+difX;
	}
	
	void setVelocita(int vel){
		this->velocita = this->velocita+vel;
	}
	
	void setPrecisione(int prec){
		this->precisione = this->precisione+prec;
	}
	
	void evolvi(){
		if(this->stadio<3){
			this->stadio= this->stadio+1;	
			std::cout << "Il Codemon si e' evoluto\n"; 
		}
	}
	
	void setFainted(bool fain){
		this->fainted = fain;
	}
	
	void modifyHp(int mod){
		this->hp = this->hp + mod;
		if(this->hp <= 0) {
			this->hp = 0;
			this->fainted = true;
		}
	}
	
	void setStato(std::string state){
		this->stato = state;
	}
	
	void setIdentification(int val){
		this->identification = val;
	}
	
	void show(std::ostream& out){
		out << "Nome : " << this->nome << "\n";
		out << "ID : " << this->id << "\n";
		out << "Tipo : " << this->tipo << "\n";
		out << "Livello : " << this->livello << "\n";
		out << "Esperienza iniziale : " << this->expI<< "\n";
		out << "Esperienza Massima : " << this->expM << "\n";
		out << "Numero mosse Iniziale : " << this->nMosseI << "\n";
		out << "Numero mosse conosciute : " << this->nMosseC << "\n";
		out << "Numero totale mosse apprendibili : " << this->nMosseA << "\n";
		out << "Attacco base : " << this->attacco << "\n";
		out << "Difesa base : " << this->difesa << "\n";
		out << "Attacco speciale : " << this->attaccoX << "\n";
		out << "Difesa speciale : " << this->difesaX << "\n";
		out << "Velocita' : " << this->velocita << "\n";
		out << "Precisione : " << this->precisione << "\n";
		out << "Stadio evelutivo : " << this->stadio << "\n";
		out << "Esperienza acquisita : " << this->exp << "\n";
		out << "Health Points attuali " << this->hp << " su un totale massimo di "<< this->hpM <<"\n";
		out << "Stato di salute : " << this->stato << "\n";
		if(fainted) out << "Il Codemon e' esausto " << "\n";
		else out << "Il Codemon puo' ancora essere utilizzato in battaglia" << "\n";
		out << "Identificativo Univoco Codemon :" << this->identification << "\n";
		for(int i = 0; i < this->nMosse; i++){
				mosse[i]->show(out);
		}
		
	}
	
	//mostra i valori di esperienza relativa ad ogni livello
	void show1(){
		for(int i = 0; i <= maxL;i++){
			std::cout << this->levels[i] << std::endl; 
		}
	}
	
	bool operator==(const Codemon& c1) const{
		return (this->identification==c1.identification); 
	}
	
	void operator=(const Codemon& c) {
			this->nome = c.nome;
			this->id = c.id;
			this->tipo = c.tipo;
			this->livello = c.livello;
			this->maxL = c.maxL;
			this->levels = c.levels;
			this->expI = c.expI;
			this->exp = c.exp;
			this->expM = c.expM;
			this->nMosseI = c.nMosseI;
			this->nMosseC = c.nMosseC;
			this->nMosseA = c.nMosseA;
			this->attacco = c.attacco;
			this->difesa = c.difesa;
			this->attaccoX = c.attaccoX;
			this->difesaX = c.difesaX;
			this->stadio = c.stadio;
			this->hp  = c.hp;
			this->stato = c.stato;
			this->fainted = c.fainted;
			this->velocita = c.velocita;
			this->precisione = c.precisione;
			this->nMosse = c.nMosse;
			this->mosse = c.mosse;
			this->mosseI = c.mosseI;
			this->mosseC = c.mosseC;
			this->mosseA = c.mosseA;
		}
		
		void setMossa(Mossa &m){
			if(nMosse < nMosseC){
				Mossa *nuova = new Mossa();
				nuova = &m;
				this->mosse[nMosse] = nuova;
				this->nMosse = this->nMosse+1;
			}
				
			else{
				int choice;
				std::cout << "Quale mossa vuoi che il Codemon scordi : 1,2,3,4 : ";
				std::cin>>choice;
				int indx = m.index(*this->mosseA,this->nMosseA,m);
				if(indx != -1){
					myswap(this->mosseA,this->mosse,indx,this->nMosse);
				}
				else{
					 std::cout << "NON POSSIBILE\n";
					return;
				}
			}	
		}
		
		void setMosseA(Mossa* arr){
			for(int i = 0; i< this->nMosseA; i++){
				this->mosseA[i] = &arr[i];
			}
		}
		
		Mossa* getMosse(){
			return *this->mosse;
		}
		
		Mossa getMossa1(){
			return *this->mosse[0];
		}
		
		Mossa getMossa2(){
			return *this->mosse[1];
		}
		
		Mossa getMossa3(){
			return *this->mosse[2];
		}
		
		Mossa getMossa4(){
			return *this->mosse[3];
		}
		
		void stampaMosse(){
			for(int i = 0; i < this->nMosseC; i++){
				mosse[i]->show(std::cout);
			}
		}
		
		void update(){
			//posx ++;
			//posy = 0;
			
			source.h = 128;
			source.w = 128;
			source.x = 0;
			source.y = 0;
			
			destination.x = posx;
			destination.y = posy;
			destination.w = 128;
			destination.h = 128;
			
			sourceF.h = 64;
			sourceF.w = 64;
			sourceF.x = 0;
			sourceF.y = 0;
			
			destinationF.x = posx;
			destinationF.y = posy+destination.h;
			destinationF.w = 128;
			destinationF.h = 32;
			
			
			}
		
		void render(){
			SDL_RenderCopy(Game::renderer,textFront,&source,&destination);
			SDL_RenderCopy(Game::renderer,font,&sourceF,&destinationF);
		}
		
		
};

#endif
