#ifndef ZAINO_H
#define ZAINO_H

class Zaino{
private:
	Codecube **cubes;
	Item **items;
	Itemb **itembs;
	int max;
	// max mmi idrà quanti slot oggetto posso avere all'interno dello  zaino, poi per settare il numero, devo usare i metodi relativi nelle classi relative
	//max deve essere ben decisa in un secondo momento, quando si penserà alla reale implementazione del gioco, in modo da non avere più slot del numero di oggetti possibili
	//e magari creare diverse variabili max relative al numero di codecubes, itm e itemBase relativi
	int nc;
	int it;
	int itb;
public:
	Zaino(){
		this->max = 50;
		this->cubes = new Codecube*[max];
		this->items = new Item*[max];
		this->itembs = new Itemb*[max];
		for(int i = 0; i < this->max; i++){
			cubes[i] = NULL;
			items[i] = NULL;
			itembs[i] = NULL;
		}	
		this->nc = 0;
		this->it = 0;
		this->itb = 0; 
	}
	//metodi set
	
	void insCube(Codecube& c){
		if(this->nc < this->max){
			this->nc = this->nc+1;
			this->cubes[nc-1] = &c;
		}
		else{
			std::cout << "NON POSSIBILE, RAGGIUNTO MASSIMO";
			return;
		}
	}
	
	void insItem(Item& i){
		if(this->it < this->max){
			this->it = this->it+1;
			this->items[it-1] = &i;
		}
		else{
			std::cout << "NON POSSIBILE, RAGGIUNTO MASSIMO";
			return;
		}
	}
	
	void insItemb(Itemb& ib){
		if(this->itb < this->max){
			this->itb = this->itb+1;
			this->itembs[itb-1] = &ib;
		}
		else{
			std::cout << "NON POSSIBILE, RAGGIUNTO MASSIMO";
			return;
		}
	}
	
	//metodi get
	Codecube* getCubes(){
		return *this->cubes;
	}
	
	Item* getItems(){
		return *this->items;
	}
	
	Itemb* getItembs(){
		return *this->itembs;
	}
	
	
	void show(std::ostream& out){
		out << "Item Presenti : " << this->it  << "\n";
		out << "Item Base Presenti : " << this->itb  << "\n";
		out << "CodeCubes Presenti " << this->nc  << "\n";
		out << "Ecco Gli ITEM : \n";
		for(int i = 0; i< it; i++){
			items[i]->show(out);
		}
		out << "Ecco Gli ITEM BASE: \n";
		for(int i = 0; i< itb; i++){
			itembs[i]->show(out);
		}
		out << "Ecco Le Codecubes : \n";
		for(int i = 0; i< nc; i++){
			cubes[i]->show(out);
		}
	}
	
	int getIt(){
		return this->it;
	}
	
	int getNc(){
		return this->nc;
	}
	
	int getItb(){
		return this->itb;
	}
	
};

#endif
