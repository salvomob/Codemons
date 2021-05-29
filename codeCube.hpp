#ifndef CODECUBE_HPP
#define CODECUBE_HPP

class Codecube{
private:
	int max_n;
	int n;
	float effectiveness;
	std::string nome;
	std::string description;
		
public:
	Codecube(std::string nome,float effectiveness){
		this->max_n = 99;
		this->n = 0;
		this->effectiveness = effectiveness;
		this->nome = nome;
		this->description = "";
	}
	
	//metodi set
	
	void setDescription(std::string desc){
		this->description = description;
	}
	
	void setN(int val){
		this->n = this->n+val;
	}
	
	//metodi get
	
	float getEffectiveness(){
		return (this->effectiveness);
	}
	
	int getN(){
		return (this->n);
	}
	
	int getMaxN(){
		return (this->max_n);
	}
	
	std::string getDescription(){
		return (this->description);
	}
	
	std::string getNome(){
		return (this->nome);
	}
	
	void show(std::ostream& out){
		out << "NOME : " << this->nome << "\n";
		out << "EFFECTIVENESS : " << this->effectiveness << "\n";
	}
	
};

#endif
