#ifndef	BOX_H
#define BOX_H
#include"Codemon.h"

class Box{

private:
	std::string nome;
	int max_n;
	int rows;
	int cols;
	int n;
	Codemon **box;
	
public:
	
	Box(std::string nome){
		this->nome = nome;
		this->max_n = 25;
		this->rows = 5;
		this->cols = 5;
		this->n = 0;
		this->box = new Codemon*[max_n];
		for(int i = 0; i < this->max_n; i++){
			box[i] = NULL;
		}
	}
	
	void insert(Codemon& c, int n1,int n2){
		this->box[n1*this->cols+n2]= &c;
		std::cout <<"Inserisco in pos : " << n1*this->cols+n2 << std::endl;
		this->n = this->n+1;
	}	
	
	void show(){
		std::cout << this->nome << std::endl;
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->cols ; j++){
				if(this->box[i*this->rows+j]==NULL) std::cout << "O ";
				else std::cout << "X "; 
			}
			std::cout << std::endl;	
		}
	}
	
	void setNome(std::string name){
		this->nome = name;
	}
	
	bool isFull(){
		return (this->n == this->max_n);
	}
	
	int getRowDispPos(){
		for(int i = 0; i < this->max_n; i++){
			if(this->box[i]==NULL) {
				//std::cout << "RoWDispPos :" <<  int(i/this->rows) << std::endl;	
				return int(i/this->rows);
			}
			
		}	
		return -1;
	}
	
	int getColDispPos(){
		for(int i = 0; i < this->max_n; i++){
			if(this->box[i]==NULL){
				//std::cout << "ColDispPos : " << i-i*getRowDispPos()+getRowDispPos() << std::endl;
				return (i-i*getRowDispPos()+getRowDispPos());
			}
		}
		return -1;
	}
	
};

#endif
