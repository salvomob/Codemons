#ifndef SFIDA_H
#define SFIDA_H

bool sfida(Player& p,Personaggio& pe,Zaino& z);

bool sfidaP(Player& p, Codemon& c, Zaino& z, Box& b);

bool checkFirst(Player& p,Personaggio& pe);

bool checkWin(Player& p, Personaggio& pe);

inline void check(Player& p,Personaggio& pe);

#endif 
