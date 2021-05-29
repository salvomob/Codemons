#ifndef IDENTIFICATION_HPP
#define IDENTIFICATION_HPP
#include"Codemon.hpp"

class Identification{
private:	
	bool *identification;
	int n;
	
public:
	Identification(){
		this->n = 1000000;
		this->identification = new bool[this->n];
		for(int i = 0; i < this->n; i++) this->identification[i] == false; 
	}
	
	void identify(Codemon& c){
		int val = c.getIdentification();
		this->identification[val] = true;
	}
	
	void showIdentificated(){
		std::cout << "I seguenti pokemon sono nella lista :" << "\n";
		for(int i = 0; i < this->n; i++){
			if(this->identification[i] == true) std::cout << i << "\n";
		}
	}
	
	bool* getIdentification(){
		return this->identification;
	}
	
};

#endif
