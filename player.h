#ifndef PLAYER_H
#define PLAYER_H

#include<fstream>
#include"box.h"

class Player{
private:
	std::string nome;
	bool sex;//if sex == true maschi , femmina altrimenti
	int soldi;
	int soldiM;//soldi massimi 
	int onori;
	int onoriM;//medaglie massime -->> per ora 8, da definire
	//float posx,posy;->in un secondo momento ci serviranno per la visualizzazione grafica del player all'interno della window
	Codemon **team;
	int nMT;//numero massimo di codemons in team
	int nCT;//numero effettivo di codemons in team	
public:
	Player(std::string nome,bool sex){
		this->nome = nome;
		this->sex = sex;
		this->soldi = 0;
		this->soldiM = 999999;
		this->onori = 0;
		this->onoriM = 8;
		this->nMT = 6;
		this->nCT = 0;
		this->team = new Codemon*[nMT];
		for (int i = 0; i < nMT;i++){
			team[i] = NULL;
		}
	}
	
	void setNome(std::string name){
		this->nome = name;
	}
	
	void setSoldi(int amount){
		this->soldi = this->soldi + amount;
	}
	
	void incOnori(){
		if(this->onori< this->onoriM)
			this->onori = this->onori+1;
	}
	
	void incnCT(){
		if(this->nCT< this->nMT)
			this->nCT = this->nCT+1;
	}
	
	void decnCT(){
		if(this->nCT>1)
		this->nCT = this->nCT-1;
	}
	
	void insCodInTeam(Codemon& c,Box &b){
		if(!isFull()){
			this->incnCT();
			//c.show(std::cout);
			this->team[this->nCT-1] = &c;
		}
		else insBox(c, b);	
	}
	
	void pullCodInTeam(Codemon& c){
		for(int i = 0; i < this->nCT; i++){
			if(this->team[i] == &c) {
				for(int j = i; j < this->nCT-1; j++){
					this->team[j] = this->team[j+1];
				}
			}
			
		}
		this->decnCT();
	}
	
	Codemon *getTeam(){
		return *this->team;
	}
	
	void mostrami(std::ostream& out){
		out << "Nome : " << this->nome << "\n";
		if(this->sex) out << "Maschio" << "\n";
		else out << "Femmina" << "\n";
		out << "Soldi : " << this->soldi  << "\n";
		out << "Soldi massimi : " << this->soldiM  << "\n";
		out << "Onori ottenuti : " << this->onori  << "\n";
		out << "Onori massimi :" << this->onoriM  << "\n";
		out << "Onori ottenibili : " <<this->onoriM - this->onori  << "\n";
		out << "Numero attuale codemons in team : " << this->nCT << "\n";
		out << "ECCO I CODEMON DEL PLAYER!!!!" << "\n\n\n\n";
		for(int i = 0; i < nCT; i++){
			
			team[i]->show(out);
			out << "\n\n\n\n\n\n\n";
		}
		out << "Numero massimo codemons in team : " << this->nMT  << "\n";
	}
	
	void mostraTeam(Codemon *team,std::ostream& out){
		for(int i = 0; i < nCT; i++)
			team[i].show(out);	
	}
	
	bool isFull(){
		return (this->nCT == this->nMT);
	}
	
	void insBox(Codemon &c,Box b){
		//std::cout << "qui" << std::endl;
		b.insert(c,b.getRowDispPos(),b.getColDispPos());
	}
	
	Codemon& getCodemon1(){
		return *this->team[0];
	}
	
	Codemon& getCodemon2(){
		return *this->team[1];
	}
	
	Codemon& getCodemon3(){
		return *this->team[2];
	}
	
	Codemon& getCodemon4(){
		return *this->team[3];
	}
	
	Codemon& getCodemon5(){
		return *this->team[4];
	}
	
	Codemon& getCodemon6(){
		return *this->team[5];
	}
	
	int getNCT(){
		return this->nCT;
	}
	
	bool died(){
		int n = 0;
		for(int i = 0; i < nCT; i++){
			if(this->team[i]->getFainted() == true) n++;
		}
		if(n == nCT-1) return true;
		return false;
	}
	
};

#endif
