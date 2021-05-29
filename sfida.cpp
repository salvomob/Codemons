#include"sfida.hpp"

inline bool sfida(Player& p,Personaggio& pe,Zaino& z){
	bool turno = checkFirst(p,pe);
	bool done = false;
	Codemon* team = p.getTeam();
	Codemon* team1 = pe.getTeam();
	while(!done)
	{
		done = checkWin(p,pe);
		if(done) return true;
		check(p,pe);
		if(turno)
		{
			int choice;
			std::cout << "Cosa vuoi fare :\n";
			std::cout << "1)Combatti\n";
			std::cout << "2)Zaino\n";
			std::cout << "3)Codemons :\n";
			std::cout << "4)SCAPPA :\n";
			std::cin >> choice;
			switch(choice){
				case 1:
				{
						Mossa *m = team[0].getMosse();
						for(int i = 0; i < team[0].getNM(); i++)
						{
							std::cout <<i+1 <<")Mossa " << i+1 << " : " << m[i].getNome() << "\n";
						}
						int choice1;
						std::cin >> choice1;
						switch(choice1) {
							case 1:
								std::cout << team[0].getNome() << " ";
								m[0].applyEffect(team1[0]);
								turno = false;
								continue;
							case 2:
								std::cout << team[1].getNome() << " ";
								m[1].applyEffect(team1[0]);
								turno = false;
								continue;
							case 3:
								std::cout << team[2].getNome() << " ";
								m[2].applyEffect(team1[0]);
								turno = false;
								continue;
							case 4:
								std::cout << team[3].getNome() << " ";
								m[3].applyEffect(team1[0]);
								turno = false;
								continue;
						}
				}
					case 2:
					{
						std::cout << "1)Item\n";
						std::cout << "2)Item Base\n";
						std::cout << "3)Codecubes\n";
						int choice2;
						std::cin>>choice2;
						switch(choice2)
						{
							case 1:
								{
									Item* items = z.getItems();
									for(int i = 0; i < z.getIt(); i++ ){
										std::cout <<i+1 << ")" <<  items[i].getNome() << " x" << items[i].getN() << "\n";
									}
									int choice3;
									std::cin >> choice3;
									std::cout << "Su quale Codemon : \n";
									Codemon* team = p.getTeam();
									for(int i = 0; i < p.getNCT(); i++){
										std::cout << i+1 << ") " << team[i].getNome() << "\n";
									}
									int choice4;
									std::cin>>choice4;
									items[choice2-1].applyEffect(team[choice4-1]);
									turno  = false;
									continue;
								}
							case 2:
							{
								std::cout << "Non usabili in questo momento \n";
								turno = true;
								continue;
							}
							case 3:
							{
								std::cout << "Non usabili in questo momento \n";
								turno = true;
								continue;
							}	
					}
				}
					case 3:
					{
						std::cout << "Quale Codemon vuoi mettere in campo?\n";
						for(int i = 1; i < p.getNCT(); i++){
							std::cout << i+1 << ") " << team[i].getNome() << "\n";
						}
						int choice5;
						std::cin>>choice5;
						std::swap(team[0],team[choice5-1]);//swapLocal(team,0,choice5-1);
						turno = false;
						continue;
					}
					case 4:
					{
						std::cout << "Non puoi fuggire da una sfida\n";
						turno = true;
						continue;
					}
					continue;
				}
				break;
			}
		else {
			int x =  rand()%100;
			if(x <= 25){
				std::cout << team1[0].getNome() << " ";
				team1[0].getMossa1().applyEffect(team[0]);
				turno = true;
				break;
			}
			if(x > 25 && x <= 50){
				std::cout << team1[0].getNome() << " ";
				team1[0].getMossa2().applyEffect(team[0]);
				turno = true;
				break;
			}
			if(x > 50 && x<=75 ){
				std::cout << team1[0].getNome() << " ";
				team1[0].getMossa3().applyEffect(team[0]);
				turno = true;
				break;
			}
			if(x > 75 && x <= 100){
				std::cout << team1[0].getNome() << " ";
				team1[0].getMossa4().applyEffect(team[0]);
				turno = true;
				break;
			}
		}
	}
	return done;
}


inline bool checkFirst(Player& p,Personaggio& pe){
	return(p.getCodemon1().getVelocita() >= pe.getCodemon1().getVelocita());
}


inline void check(Player& p,Personaggio& pe){
		Codemon* team = p.getTeam();
		Codemon* team1 = pe.getTeam();
		if(checkWin(p,pe)) return;
		if(team[0].getFainted() == true && team[0].getHP() == 0){
			std::cout << "Quale Codemon vuoi mettere in campo?\n";
			for(int i = 1; i < p.getNCT(); i++){
				std::cout << i+1 << ") " << team[i].getNome() << "\n";
			}
			int choice;
			std::cin>>choice;
			std::swap(team[0],team[choice-1]);//swapLocal(team,0,choice-1); 
			return;
		}
		if(team1[0].getFainted() == true && team1[0].getHP() == 0){
			std::cout << "Il tuo avversario ha scambiato Codemon dopo la sconfitta di " << team1[0].getNome() <<"!\n";
			int x=0;
			for(int i = 0; i< pe.getNCod();i++){
				if(team1[i].getFainted() == true && team1[i].getHP() == 0) x++;
			}
			std::swap(team1[0],team1[x]);//swapLocal(team1,0,x-1);
			std::cout << "Il nuovo Codemon in campo e' " << team1[0].getNome() <<" che ha " << team1[0].getHP() << " HP!\n";
			return;
		}
}

inline bool checkWin(Player& p, Personaggio& pe){
		Codemon* team1 = pe.getTeam();
		Codemon* team = p.getTeam();
		int x1 = 0, x2 = 0;
		for(int i = 0; i < pe.getNCod(); i++){
			if(team1[i].getFainted() == true && team1[i].getHP() == 0) x1++;
		}
		for(int i = 1; i < p.getNCT(); i++){
				if(team[i].getFainted() == true && team[i].getHP() == 0) x2++;
		}
		if(x1 == (pe.getNCod())){
			std::cout << "Hai vinto l'incontro !!!\n";
			return true;
		}
		else if(x1 == (p.getNCT())){
			std::cout << "Hai perso l'incontro!!!\n";
			p.setSoldi(pe.getSoldi());
			std::cout << "Paghi " << pe.getSoldi() << " per la sconfitta!!!\n";
			return true;
		}
		return false;
}


inline bool sfidaP(Player& p, Codemon& c){
	std::cout << "il collegamento funziona" << std::endl;
	return 1;	
}
