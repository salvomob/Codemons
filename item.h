#ifndef ITEM_H
#define ITEM_H

class Item{
private:
	std::string nome;
	std::string description;
	int n_max;
	int n;
	int attacco;
	int difesa;
	int attaccoX;
	int difesaX;
	int velocita;
	int precisione;
	int stadio;
	int hp;
	std::string stato;
	bool fainted;
	int prezzoA;
	int prezzoV;
	
public:
	Item(std::string nome, int attacco , int difesa,int attaccoX, int difesaX,int velocita, int precisione , int stadio, int hp, std::string stato, bool fainted,int prezzoA){
		this->description  = "";
		this->n_max = 99;
		this->n = 1;
		this->nome = nome;
		this->attacco = attacco;
		this->difesa = difesa ;
		this->attaccoX = attaccoX;
		this->difesaX = difesaX;
		this->velocita = velocita;
		this->precisione = precisione;
		this->stadio = stadio;
		this->hp = hp;
		this->stato = stato;
		this->fainted = fainted;
		this->prezzoA = prezzoA;
		this->prezzoV = (int) (this->prezzoA/2);
	}
	
	void applyEffect(Codemon &c){
		c.setAttacco(this->attacco);
		c.setDifesa(this->difesa);
		c.setAttaccoX(this->attaccoX);
		c.setDifesaX(this->difesaX);
		c.setVelocita(this->velocita);
		c.setPrecisione(this->precisione);
		if(this->stadio == 1) c.evolvi();
		if(this->fainted==false || c.getFainted()==false)
		c.modifyHp(this->hp);
		c.setStato(this->stato);
		c.setFainted(this->fainted);
		this->n = this->n -1;
	}
	
	void setN(int val){
		if(this->n + val > 99) this->n = this->n_max;
		this->n = this->n + val;
	}
	
	void setDescription(std::string desc){
		this->description = desc;
	}
	
	void operator=(const Item& i){
		this->description  = i.description;
		this->n_max = i.n_max;
		this->n = i.n;
		this->nome = i.nome;
		this->attacco = i.attacco;
		this->difesa = i.difesa ;
		this->attaccoX = i.attaccoX;
		this->difesaX = i.difesaX;
		this->velocita = i.velocita;
		this->precisione = i.precisione;
		this->stadio = i.stadio;
		this->hp = i.hp;
		this->stato = i.stato;
		this->fainted = i.fainted;
		this->prezzoA = i.prezzoA;
		this->prezzoV = i.prezzoV;
	}
	
	void show(std::ostream& out){
		out << "NOME ITEM : " << this->nome << "\n";
	}
	
	std::string getNome(){
		return this->nome;
	}
	
	int getN(){
		return this->n;
	}
	
};

#endif
