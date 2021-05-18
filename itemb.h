#ifndef ITEMB_H
#define ITEMB_H

class Itemb{
private:
	int n;
	std::string nome;
	std::string description;
	bool assigned;
	
public:
	
	Itemb(){}
	
	Itemb(std::string nome){
		this->n = 1;
		this->nome = nome;
		this->description = "";
		this->assigned = false;
	}
	
	void setDescription(std::string desc){
		this->description = desc;
	}
	
	void setAssigned(bool ass){
		this->assigned = ass;
	}
	
	void assign(Itemb* array, int n){
		for(int i = 0; i < n; i++){
			array[i].setAssigned(false);
			std::cout << "???" << std::endl;
		}
		this->assigned = true;
	}
	
	void show(std::ostream& out){
		out<<"Itb :"  << this->nome << "\n";
		out<< "Descrizione : " << this->description   << "\n";
		if (this->assigned == true) out<<  "Assegnato" << "\n";
		else out << "Non assegnato\n";
	}
	
	void operator=(Itemb & i){
		this->n = i.n;
		this->nome = i.nome;
		this->description = i.description;
		this->assigned = i.assigned;
	}
	
};

#endif
