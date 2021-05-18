#ifndef MOSSA_H
#define MOSSA_H

//#include"Codemon.h"

class Codemon;

class Mossa{
private:
	std::string nome;
	std::string description;
	int tipo;
	int attacco;
	int difesa;
	int attaccoX;
	int difesaX;
	int velocita;
	int precisione;
	int hp;
	std::string stato;
	int n;
	int n_max;
	int pp;
	int ppM;

public:
	Mossa(){}

	Mossa(std::string nome,int tipo,int attacco,int difesa,int attaccoX,int difesaX,int velocita,int precisione,int hp,std::string stato,int ppM);
	void applyEffect(Codemon&);
	void setN(int);
	void setDescription(std::string);
	bool operator==(const Mossa&) const;
	void operator=(const Mossa&);
	int index(Mossa*,int,Mossa&);
	void setPP(int);
	void show(std::ostream&);
	int getPP();
	std::string getNome();
};

#endif

