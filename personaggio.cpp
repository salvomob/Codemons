#include"personaggio.h"

inline Personaggio::Personaggio(std::string nome , int func,  int n_cod ,bool onori){//mi serve solo saper nome , func ,numero di pokemon e se è capoDepartment, il resto settato di default/ad hoc
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
