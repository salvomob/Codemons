#include"personaggio.hpp"

inline Personaggio::Personaggio(std::string nome , int func,  int n_cod ,bool onori,const char* filenameFrontM,const char* filenameBackM,const char* filenameFrontF,const char* filenameBackF,int posx, int posy){//mi serve solo saper nome , func ,numero di pokemon e se è capoDepartment, il resto settato di default/ad hoc
		this->nome = nome;
		this->func = func;
		this->speech = NULL;
		this->speechN = 0;
		this->n_codA = 0;
		this->n_cod = n_cod;
		this->team = new Codemon*[n_cod];
		for (int i = 0; i < n_cod;i++){
			team[i] = NULL;
		}
		this->soldi = 0;
		this->onori = onori;
		textFrontM = TextureManager::loadText(filenameFrontM);
		textBackM = TextureManager::loadText(filenameBackM);
		textFrontF = TextureManager::loadText(filenameFrontF);
		textBackF = TextureManager::loadText(filenameBackF);
		font = TextureManager::loadFont(this->nome,20);
		this->posx = posy;
		this->posy = posx;
		this->interation = false;
		SDL_SetRenderDrawColor(Game::renderer,255,255,255,255);
		lm = move;
		lpx = this->posx;
		lpy = this->posy;
	}
	
	//metodi set
	
	inline void Personaggio::setSpeech(std::string *discorso){
		this->speech = discorso;
	}
	
	inline void Personaggio::setSoldi(int soldini) {
		this->soldi = this->soldi + soldini;
	}
	
	inline void Personaggio::insCodInTeam(Codemon& c){
		if(this->n_codA < this->n_cod){
			this->n_codA = this->n_codA + 1;
			this->team[this->n_codA-1] = &c;

		}	
	}
	
	inline void Personaggio::setFunc(int num){//se batti un personaggio, func deve essere posto == 1 in modo da poterci parlare ancora senza sfidarlo
		this->func = this->func + num;
	}
	
	inline void Personaggio::setSpeechN(int num){
		this->speechN = num;
	}
	
	inline void Personaggio::setSpeech(std::string *arr, int n){
		for(int i = 0; i < n; i++){
			this->speech[i] = arr[i];
		}
	}
	
	//metodi get
	
	inline std::string Personaggio::getNome(){
		return this->nome;
	}
	
	inline int Personaggio::getFunc(){
		return this->func;
	}
	
	inline int Personaggio::getNCod(){
		return this->n_cod;
	}
	
	inline int Personaggio::getNcoDA(){
		return this->n_codA;
	}
	
	inline Codemon* Personaggio::getTeam(){
		return *this->team;
	}
	
	inline int Personaggio::getSoldi(){
		return this->soldi;
	}
	
	inline bool Personaggio::getOnori(){
		return this->onori;
	}
	
	inline int Personaggio::getSpeechN(){
		return (this->speechN);
	}
	
	inline std::string * Personaggio::getSpeech(){
		return this->speech;
	}
	
	inline Codemon& Personaggio::getCodemon1(){
		return *this->team[0];
	}
	
	inline Codemon& Personaggio::getCodemon2(){
		return *this->team[1];
	}
	
	inline Codemon& Personaggio::getCodemon3(){
		return *this->team[2];
	}
	
	inline Codemon& Personaggio::getCodemon4(){
		return *this->team[3];
	}
	
	inline Codemon& Personaggio::getCodemon5(){
		return *this->team[4];
	}
	
	inline Codemon& Personaggio::getCodemon6(){
		return *this->team[5];
	}
	
	inline void Personaggio::show(std::ostream& out){
		out << "Nome : " << this->nome  << "\n";
		out << "Func : " << this->func << "\n";
		out << "Numero codemon in team : " << this->n_cod  << "\n";
		if(onori )out << "Sono un capo Dipartimento " << "\n";
		else out << "Sono un Personaggio secondario" << "\n";
		if(func==3)out << "Se mi batti di do : " << this->soldi  << "\n";
		if(func == 2) out << "Non mi puoi sfidare , ma puoi comprare o vendere " << "\n";
		if(func == 1) out << "Non mi puoi sfidare, posso solo darti indicazioni o parlare del più e del meno " << "\n";
		if(n_cod != 0){
			out << "ECCO I CODEMON DEL PERSONAGGIO!!!!" << "\n\n\n\n";
			for(int i = 0; i < this->n_cod; i++){
				team[i]->show(out);
				std::cout << "\n\n\n\n\n\n\n";
			}
		}
	}
	
	inline bool Personaggio::died(){
		int n = 0;
		for(int i = 0; i < this->n_cod; i++){
			if(this->team[i]->getFainted() == true) n++;
		}
		if(n == this->n_cod) return true;
		return false;
	}
	
	inline void Personaggio::draw()
	{	
			source.h = 32;
			source.w = 32;
			source.x = 0;
			source.y = 0;
			
			destination.x = posx;
			destination.y = posy;
			destination.w = 32;
			destination.h = 32;
			
			sourceF.h = 1280;
			sourceF.w = 1280;
			sourceF.x = 0;
			sourceF.y = 0;
			
			destinationF.x = 0;
			destinationF.y = 0;
			destinationF.w = 1280;
			destinationF.h = 800;
			moves();
			if(interation)
			{
				stop();
			}
	}
	
	inline void Personaggio::render()
	{
		//qui si vede quale tipo di personaggio renderizzare e quale sprite usare, per ora è il player maschile . DA CAMBIARE
		SDL_RenderCopy(Game::renderer,textFrontM,&source,&destination);
//		else
		if(interation)
		{
			SDL_RenderCopy(Game::renderer,textFrontM,&source,&destination);
			SDL_RenderClear(Game::renderer);
			SDL_RenderCopy(Game::renderer,font,&sourceF,&destinationF);
		}
	}
	
	inline void Personaggio::moves()
	{
	//il personaggio si muove lungo un cerchio , per ora.
			lpx = posx;
			lpy = posy;
			lm = move;
			if(move == 1400) move = 1;
			if(move == 600 )
			{
				posx+= 32;
			}
			
			if(move == 1200)
			{
				posx-=32;
			}
			
			if(move == 500)
			{
				posy += 32;
			}
			if(move == 1000)
			{
				posy -=32;
			}
			move++;
			
	}
	
	inline void Personaggio::stop()
	{
		move = lm;
		posx = lpx;
		posy = lpy;
	}
		
	
	
	inline void Personaggio::interact(Player p)
	{	
		if((abs(posx-p.posx) == 32 && abs(posy-p.posy) == 0) || (abs(posx-p.posx) == 0 && abs(posy-p.posy) == 32) )
			interation = true;
		else interation = false;	
	}
	
