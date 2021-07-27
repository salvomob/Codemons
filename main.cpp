#include<iostream>
//#include<unistd.h>
#include"mossa.hpp"
#include"personaggio.hpp"
#include"Codemon.hpp"
#include"player.hpp"
#include"identification.hpp"
#include"mossa.cpp"
#include"personaggio.cpp"
#include"codedex.hpp"
#include"box.hpp"
#include"item.hpp"
#include"itemb.hpp"
#include"codeCube.hpp"
#include"zaino.hpp"
#include"sfida.hpp"
#include"sfida.cpp"
#include "game.hpp"
#include "game.cpp"
#include "textureManager.hpp"
#include "textureManager.cpp"
#include "map.hpp"
#include "map.cpp"

using namespace std;

Game *game = nullptr;


int main()
{
	/*srand(time(NULL));
	Codemon c("abc",1,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c1("def",2,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c2("ghi",3,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c3("lmn",4,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c4("opq",4,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c5("rst",4,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c6("uvz",4,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c7("xy",4,1,5,2,10,10,5,5,5,5,1,100);
	Codemon c8("x1234",4,1,5,2,10,10,5,5,5,5,1,100);*/

	/*c.show(cout);
	
	cout << "\n\n\n\n\n\n\n";
	/*c.incExp(502500);
	c.show(cout);
	c.modifyHp(-150);
	c.show(cout);
	
	cout << "\n\n\n\n\n\n\n";*/
/*
	FUNZIONA	
		
*/
	
//	FUNZIONA
/*	Box b("BOX 1");
	Player p("Salvo",1);
	
	
	Personaggio personaggio1("Personaggio 1",1,0,0);
	Personaggio personaggio2("Personaggio 2",2,0,0);
	Personaggio personaggio3("Personaggio 3",3,3,0);
	Personaggio personaggio4("Personaggio 4",3,2,1);*/
	
	
	
	/*
	
	p.insCodInTeam(c);
	p.insCodInTeam(c1);
	p.insCodInTeam(c2);
	p.insCodInTeam(c3);
	
	
	p.pullCodInTeam(c);
	p.pullCodInTeam(c3);
	
	p.mostrami(cout);


/*

	FUNZIONA
		
	Codedex codedex;
	for(int i = 1; i <= 4; i++){
		codedex.setID(i);
	}

*/

/*	
	
		FUNZIONA	
	
	
	Identification id;
	

	id.identify(c);
	id.identify(c1);
	id.identify(c2);
	id.identify(c3);
	id.showIdentificated();	
	
	
/*

	FUNZIONA

	codedex.setDescription("abc e' il primo codemon creato\n",1);
	codedex.incEffN();
	codedex.setDescription("def e' il secondo codemon creato\n",2);
	codedex.incEffN();
	codedex.setDescription("ghi e' il terzo codemon creato\n",3);
	codedex.incEffN();
	codedex.setDescription("lmn e' il quarto codemon creato\n",4);
	codedex.incEffN();
	//cout << codedex.getDescription(c);
	
	string *s = codedex.getDescriptions();
	for(int i = 1; i <= codedex.getEffN(); i++){
		cout << s[i];
	}
*/
	
	
/*
	FUNZIONA
		Box b("BOX 1");
		//b.insert(c1,0,0);
			
	p.insCodInTeam(c,b);
	p.insCodInTeam(c1,b);
	p.insCodInTeam(c2,b);
	p.insCodInTeam(c3,b);
	
	p.insCodInTeam(c4,b);
	p.insCodInTeam(c5,b);
	p.insCodInTeam(c6,b);
	p.insCodInTeam(c7,b);
	
	p.mostrami(cout);	
			
		//b.show();
		*/
		
		
/*

FUNZIONA

	
	Item i("pozione",1,1,1,1,1,1,1,10,"NONOK",true,200);
	i.applyEffect(c);
	c.show(cout);




	cout << "\n\n\n\n";
*/	

/*


 FUNZIONA assign deve essere chiamata sull' elemento dell'array che poniabo uguale all'itembase così come sotto!!!


*/

/*
		FUNZIONA
		
	cout << "Prima di assegnare" << "\n\n\n\n";


	Itemb itb("item base 1");
	itb.setDescription("primo item base creato");
	itb.show(cout);

	cout << "\n\n\n\n";

	Itemb itb1("item base 2");
	itb1.setDescription("secondo item base creato");
	itb1.show(cout);

	cout << "\n\n\n\n";
	
	Itemb itb2("item base 3");
	itb2.setDescription("tezo item base creato");
	itb2.show(cout);
	
	cout << "\n\n\n\n";
	
	Itemb* a = new Itemb[3];
	a[0] = itb;
	a[1] = itb1;
	a[2] = itb2;	
	
	cout << "Qi ho creato arr e ho chiamato assign su a del primo\n\n\n";
	a[0].assign(a,3);
	
	
	
	
	cout <<"Non so se funzionerà! \n\n\n";
	a[0].show(cout);
	a[1].show(cout);
		
	a[2].assign(a,3);	
	
	cout << "\n\n\n\n";
	
	a[0].show(cout);
	a[1].show(cout);	
	a[2].show(cout);*/
	
	
	/*
		FUNZIONA
	Codecube codecube("UltraCube" , 0.60f);
	
	codecube.setN(10);
	
	for(int i = 1; i <= codecube.getN(); i++){
		float random = rand()%100;
		if(codecube.getEffectiveness()*100 >= random) cout << "OK : " <<random  <<endl;
		else cout << "NO : " << random  << endl;
	}*/
	
	/*Mossa mossa("mossa1",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa2("mossa2",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa3("mossa3",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa4("mossa4",1,0,0,0,0,0,0,-50,"NONOK",10);
*/



/*	Mossa mossa5("mossa5",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa6("mossa6",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa7("mossa7",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa8("mossa8",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa9("mossa9",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa10("mossa10",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa11("mossa11",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa12("mossa12",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa13("mossa13",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa14("mossa14",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa15("mossa15",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa16("mossa16",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa17("mossa17",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa18("mossa18",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossa19("mossa19",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa mossaprova("mossaprova",1,0,0,0,0,0,0,-50,"NONOK",10);
	Mossa *mossicine = new Mossa[20];

	mossicine[0] = mossa;
	mossicine[1] = mossa2;
	mossicine[2] = mossa3;
	mossicine[3] = mossa4;
	mossicine[4] = mossa5;
	mossicine[5] = mossa6;
	mossicine[6] = mossa7;
	mossicine[7] = mossa8;
	mossicine[8] = mossa9;
	mossicine[9] = mossa10;
	mossicine[10] = mossa11;
	mossicine[11] = mossa12;
	mossicine[12] = mossa13;
	mossicine[13] = mossa14;
	mossicine[14] = mossa15;
	mossicine[15] = mossa16;
	mossicine[16] = mossa17;
	mossicine[17] = mossa18;
	mossicine[18] = mossa19;
	mossicine[19] = mossaprova;
	
	c1.setMosseA(mossicine);*/
	/*c.setMossa(mossa);
	c.setMossa(mossa2);
	c.setMossa(mossa3);
	c.setMossa(mossa4);
	
	c1.setMossa(mossa);
	c1.setMossa(mossa2);
	c1.setMossa(mossa3);
	c1.setMossa(mossa4);
	
	c2.setMossa(mossa);
	c2.setMossa(mossa2);
	c2.setMossa(mossa3);
	c2.setMossa(mossa4);
	
	c3.setMossa(mossa);
	c3.setMossa(mossa2);
	c3.setMossa(mossa3);
	c3.setMossa(mossa4);
	
	c4.setMossa(mossa);
	c4.setMossa(mossa2);
	c4.setMossa(mossa3);
	c4.setMossa(mossa4);
	
	
	c5.setMossa(mossa);
	c5.setMossa(mossa2);
	c5.setMossa(mossa3);
	c5.setMossa(mossa4);
	
	c6.setMossa(mossa);
	c6.setMossa(mossa2);
	c6.setMossa(mossa3);
	c6.setMossa(mossa4);
	
	c7.setMossa(mossa);
	c7.setMossa(mossa2);
	c7.setMossa(mossa3);
	c7.setMossa(mossa4);
	
	c8.setMossa(mossa);
	c8.setMossa(mossa2);
	c8.setMossa(mossa3);
	c8.setMossa(mossa4);*/
	//c1.setMossa(mossaprova);
	
	/*//p.insCodInTeam(c1,b);
	p.insCodInTeam(c,b);
	p.insCodInTeam(c2,b);
	p.insCodInTeam(c3,b);
	p.insCodInTeam(c4,b);
	p.insCodInTeam(c5,b);
	//p.mostrami(cout);
	personaggio3.insCodInTeam(c6);
	personaggio3.insCodInTeam(c7);
	personaggio3.insCodInTeam(c8);
	
	personaggio4.insCodInTeam(c);
	personaggio4.insCodInTeam(c1);*/
	
	
	/*personaggio1.show(cout);
	cout <<  "\n\n\n\n";
	personaggio2.show(cout);
	cout <<  "\n\n\n\n";
	personaggio3.show(cout);
	cout <<  "\n\n\n\n";
	personaggio4.show(cout);
	cout <<  "\n\n\n\n";
	*/
	//p.mostrami(cout);
	//personaggio3.show(cout);
	
	
	//p.getCodemon2().getMossa1().applyEffect(personaggio3.getCodemon1());
	
	//cout << "\n\n\n";
	//p.getCodemon2().show(cout);
	//cout << "\n\n\n";
	//p.mostrami(cout);
	//cout << "\n\n\n";
	//personaggio3.getCodemon1().show(cout);
		
	
	//cout << p.getCodemon2().getMossa1().getPP();
	//cout << p.getCodemon2().getMossa1().getPP();
		
	//personaggio3.getCodemon1().show(cout);
	/*cout << "APPLICO POZIONE \n\n\n\n";
	Item i("pozione",1,1,1,1,1,1,1,10,"OK",true,200);
	i.applyEffect(personaggio3.getCodemon1());
	personaggio3.getCodemon1().show(cout);*/
	
	//p.getCodemon2().getMossa1().setPP(-1);
	//cout << p.getCodemon2().getMossa1().getPP();
	
	/*Codecube codecube("UltraCube" , 0.60f);
	Item i("pozione",1,1,1,1,1,1,1,10,"OK",true,200);
	Itemb itb("item base 1");
	Zaino z;
	z.insCube(codecube);
	z.insItem(i);
	z.insItemb(itb);
	
	//z.show(cout);
	Codemon * team = p.getTeam();
	Codemon * team1 = personaggio3.getTeam();
	while(!sfida(p,personaggio3,z)){
		cout << team[0].getNome() << " ha " << team[0].getHP() << endl;
		cout << team1[0].getNome() << " ha " << team1[0].getHP() << endl; 
	}
	
	
	for(int i= 0; i < p.getNCT() ; i++) team[i].show(cout);
	for(int i= 0; i < personaggio3.getNCod() ; i++) team1[i].show(cout);
	
	if(sfida(p,personaggio3,z)) cout << "HAI VINTO!!! TI MERITI UN PUGNO\n";
    else cout << "COME HAI FATTO A PERDERE BRUTTO IDIOTA! MO VATTI A CURARE\n";
	*/
	/*
	
	così funziona :/
	
	Codemon * team = p.getTeam();
	Codemon * team1 = personaggio3.getTeam();
	while(!team1[0].getFainted() == true){
	team[0].getMossa1().applyEffect(team1[0]);
	cout << team[0].getNome() << " ha " << team[0].getHP() << endl;
	cout << team1[0].getNome() << " ha " << team1[0].getHP() << endl;
	}
	*/

	
	
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	Uint32 frameStart ;
	int frameTime;
	
	game = new Game();
	
	game->init("CODEMON GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,800,false);
	
	while(game->running())
	{
		frameStart = SDL_GetTicks();
		
		
		game->handleEvents();
		game->update();
		game->render();
		
		frameTime = SDL_GetTicks() - frameStart;
		
		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay-frameTime);
		}		
	}
	
	game->clean();
	
	return 0;
}


