#ifndef IPLAYER_H
#define IPLAYER_H

#include<iostream>
#include"Board.h"

class Player
{
private:
	int id;
public:
	int getMove(Board board);
	void setID(int num);
	int getID();

};

#endif // !IPLAYER_H


