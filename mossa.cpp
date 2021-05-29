#include"mossa.hpp"

	Mossa::Mossa(std::string nome,int tipo,int attacco,int difesa,int attaccoX,int difesaX,int velocita,int precisione,int hp,std::string stato,int ppM){
		this->nome = nome;
		this->description = "";
		this->tipo = tipo;
		this->attacco = attacco;
		this->difesa = difesa;
		this->attaccoX = attaccoX;
		this->difesaX = difesaX;
		this->velocita = velocita;
		this->precisione = precisione;
		this->hp = hp;
		this->stato = stato;
		this->n = 1;
		this->n_max = 99;
		this->ppM = ppM;
		this->pp = this->ppM;
	}

	inline void Mossa::applyEffect(Codemon &c){
		c.setAttacco(this->attacco);
		c.setDifesa(this->difesa);
		c.setAttaccoX(this->attaccoX);
		c.setDifesaX(this->difesaX);
		c.setVelocita(this->velocita);
		c.setPrecisione(this->precisione);
		c.modifyHp(this->hp);
		c.setStato(this->stato);
		this->pp = this->pp -1;
		//this->show(std::cout); 
		std::cout <<"Ho usato la mossa " <<this->nome <<", ecco i pp attuali " <<  this->pp << "\n";
		std::cout << c.getNome() << " ha subito : \n";
		std::cout << "Attacco : " << this->attacco << "\n";
		std::cout << "Difesa : " << this->difesa << "\n";
		std::cout << "AttaccoX : " << this->attaccoX << "\n";
		std::cout << "DifesaX : " << this->difesaX << "\n";
		std::cout << "Velocita' : " << this->velocita << "\n";
		std::cout << "Precisione : " << this->precisione << "\n";
		std::cout << "HP : " << this->hp << "\n";
		if(c.getFainted()) std::cout << "QUALQUADRA NON MI COSA :"<< c.getNome() << "E' MORTO\n" ;
	}
	
	inline void Mossa::setN(int num){
		if(this->n+num <= this->n_max)
			this->n = this->n+num;
		else this->n = n_max;
	}
	
	inline void Mossa::setDescription(std::string desc){
		this->description = desc;
	}
	
	inline void Mossa::setPP(int num){
		this->pp = this->pp + num;
	}
	
	inline bool Mossa::operator==(const Mossa& m) const{
		return (this->nome == m.nome);
	}
	
	inline void Mossa::operator=(const Mossa& m) {
			this->nome = m.nome;
			this->description = m.description;
			this->tipo = m.tipo;
			this->attacco = m.attacco;
			this->difesa = m.difesa;
			this->attaccoX = m.attaccoX;
			this->difesaX = m.difesaX;
			this->hp  = m.hp;
			this->stato = m.stato;
			this->velocita = m.velocita;
			this->precisione = m.precisione;
			this->pp = m.pp;
			this->ppM = m.ppM;
			this->n  = m.n;
			this->n_max = m.n_max;
	}
		
	inline int Mossa::index(Mossa* v,int n,Mossa& m){
			for(int i = 0; i < n ; i++){
				if(v[i]==m){
					std::cout << "ECCO I : " << i << "\n";
					return i;
				} 
				
			}
			return -1;
	}
	
	inline std::string Mossa::getNome(){
		return this->nome;
	}
	
	inline void Mossa::show(std::ostream& out){
		out << "Mossa : "<< this->nome << "\n";
		out << "Descrizione : "<< this->description << "\n";
		out << "Tipo : "<< this->tipo << "\n";
		out << "Effetto Attacco : "<< this->attacco << "\n";
		out << "Effetto Difesa : "<< this->difesa << "\n";
		out << "Effetto AttaccoX : "<< this->attaccoX << "\n";
		out << "Effetto DifesaX : "<< this->difesaX << "\n";
		out << "Effetto HP : "<< this->hp << "\n";
		out << "Effetto Stato : "<< this->stato << "\n";
		out << "Effetto Velocita' : "<< this->velocita << "\n";
		out << "Effetto Precisione : "<< this->precisione << "\n";
		out << "PP Massimi : "<< this->ppM << "\n";
		out << "PP Attuali : "<< this->pp << "\n";
		out << "N  : "<< this->n << "\n";
		out << "N max : "<< this->n_max << "\n";
	}
	
	inline int Mossa::getPP(){
		return this->pp;
	}
