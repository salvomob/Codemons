#ifndef CODEDEX_HPP
#define CODEDEX_HPP
#include "Codemon.hpp"

class Codedex{
private:
	int n;
	int effn;
	int *id;
	std::string *description;
	bool unlocked;
	
public:
	Codedex(){
		this->effn = 0;
		this->n = 100;
		this->id = new int[n];
		for(int i = 0; i < this->n ; i++) this->id[i] = 0;
		this->description = new std::string[n];
		for(int i = 0; i < this->n; i++) this->description[i] = "";
		this->unlocked = false;
	}
	
	//metodi set
	
	void incEffN(){
		this->effn = this->effn+1;
	}
	
	void setID(int i){
		this->id[i] = i;
	}
	
	void setDescription(std::string desc,int id){
		this->description[id] = desc;
	}
	
	void unlock(){
		this->unlocked = true;
	}
	
	//metodi get
	
	bool getLock(){
		return this->unlocked;
	}
	
	int getEffN(){
		return this->effn;
	}
	
	int* getIDs(){
		return this->id;
	}
	
	int getID(Codemon &c){
		return c.getID();
	}	
	
	std::string* getDescriptions(){
		return this->description;
	}
	
	std::string getDescription(Codemon& c){
		return this->description[c.getID()];
	}
};

#endif
