#include "Player.h"


void Player::setID(int num)
{
	id = num;
}

int Player::getID()
{
	return id;
}

//returns -1 for undo, 7 for redo
int Player::getMove(Board board)
{
	std::cout << "enter 0 for undo, 8 for redo\n or enter a column number(1-7): ";
	while (true)
	{
		int col;
		std::cin >> col;
		col--;
		if (col==-1 || col==7)
		{
			return col;
		}
		if (col>=0 &&col<7)
		{
			if (board.canDrop(col))
			{
				return col;
			}
			else
			{
				std::cout << "it's only 6 a column, pick another one!\n";
			}
		}
		else
			std::cout << "looks like you're playing connect 5! enter a valid number(1-7): ";
	}
	return -1;
}
