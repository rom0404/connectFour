#include "Player.h"


void Player::setID(int num)
{
	id = num;
}

int Player::getID()
{
	return id;
}

int Player::getMove(Board board)
{
	std::cout << "enter a column number(1-7): ";
	while (true)
	{
		int col;
		std::cin >> col;
		col--;
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
