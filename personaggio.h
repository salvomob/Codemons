#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

class Codemon;

class Personaggio{
private:
	std::string nome;
	int func;//func == 1 -> parla e basta, func=2 compra/vende , func == 3 combatte e parla default 0, da settare in un secondo momento attraverso funzione!
	std::string * speech;
	int speechN;
	Codemon **team;
	int n_codA;
	int n_cod;//numero codemons in team
	int soldi;
	bool onori;//se true e viene sconfitto, da un attestato al player
	
public:
	Personaggio(std::string nome , int func,  int n_cod ,bool onori);
	
	//metodi set
	
	void setSpeech(std::string *discorso);
	
	void setSoldi(int soldini);
	
	void insCodInTeam(Codemon& c);
	
	void setFunc(int num);//se batti un personaggio, func deve essere posto == 1 in modo da poterci parlare ancora senza sfidarlo
		
	
	void setSpeechN(int num);
	
	void setSpeech(std::string *arr, int n);
	
	//metodi get
	
	std::string getNome();
	
	int getFunc();
	
	int getNCod();
	
	int getNcoDA();
	
	Codemon* getTeam();
	
	int getSoldi();
	
	bool getOnori();
	
	int getSpeechN();
	
	std::string * getSpeech();
	
	void show(std::ostream& out);
	
	Codemon& getCodemon1();
	
	Codemon& getCodemon2();
	
	Codemon& getCodemon3();
	
	Codemon& getCodemon4();
	
	Codemon& getCodemon5();
	
	Codemon& getCodemon6();
	
	bool died();
};

#endif
