#include "Board.h"





void Board::displayBoard()
{
	std::cout << "\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == 0) 
				std::cout << "| ";

			int val = board[i][j];
			if (val == 0)
				std::cout << " ";
			else if (val == 1)
				std::cout << "\033[43m\033[30m \033[0m";
			else
				std::cout << "\033[41m\033[30m \033[0m";

			if (j!=6)
				std::cout << " | ";
			if (j == 6) 
				std::cout << " |";
		}
        std::cout << '\n';
        for (int i = 0; i < 7; i++)
        {
            std::cout << "|   ";
        }
        std::cout << "|\n";
	}
	for (int i = 0; i < 7; i++)
	{
		if (i==6)
			std::cout << "|___|";
		else
			std::cout << "|___";
	}
	std::cout << '\n';
	for (int i = 0; i < 7; i++)
		std::cout << "  " << i + 1 << " ";
	std::cout << "\n\n\n";
}

bool Board::isWin(int row, int col)
{
	bool iswin = false;
    int color = board[row][col];

    //vertical
    if (
        (board[row - 1][col] == color)
        &&
        (board[row - 2][col] == color)
        &&
        (board[row - 3][col] == color)
        ) {
        iswin = true;
    }


    //diagonal y=x
    if (board[row + 1][col + 1] == color)
    {
        if (board[row + 2][col + 2] == color)
        {
            if (board[row + 3][col + 3] == color)
            {
                iswin = true;
            }
        }
    }
    if (board[row + -1][col + -1] == color)
    {
        if (board[row + 0][col + 0] == color)
        {
            if (board[row + 1][col + 1] == color)
            {
                if (board[row + 2][col + 2] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row + -2][col + -2] == color)
    {
        if (board[row + -1][col + -1] == color)
        {
            if (board[row + 0][col + 0] == color)
            {
                if (board[row + 1][col + 1] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row + -3][col + -3] == color)
    {
        if (board[row + -2][col + -2] == color)
        {
            if (board[row + -1][col + -1] == color)
            {
                if (board[row + 0][col + 0] == color)
                {
                    iswin = true;
                }
            }
        }
    }


    //diagonal y=-x
    if (board[row + -3][col + 3] == color)
    {
        if (board[row + -2][col + 2] == color)
        {
            if (board[row + -1][col + 1] == color)
            {
                if (board[row + 0][col + 0] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row + -2][col + 2] == color)
    {
        if (board[row + -1][col + 1] == color)
        {
            if (board[row + 0][col + 0] == color)
            {
                if (board[row + 1][col + -1] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row + -1][col + 1] == color)
    {
        if (board[row + 0][col + 0] == color)
        {
            if (board[row + 1][col + -1] == color)
            {
                if (board[row + 2][col + -2] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row + 0][col + 0] == color)
    {
        if (board[row + 1][col + -1] == color)
        {
            if (board[row + 2][col + -2] == color)
            {
                if (board[row + 3][col + -3] == color)
                {
                    iswin = true;
                }
            }
        }
    }



        //horizontal
    if (board[row][col + -2] == color)
    {
        if (board[row][col + -1] == color)
        {
            if (board[row][col + 0] == color)
            {
                if (board[row][col + 1] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row][col + -1] == color)
    {
        if (board[row][col + 0] == color)
        {
            if (board[row][col + 1] == color)
            {
                if (board[row][col + 2] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row][col + -3] == color)
    {
        if (board[row][col + -2] == color)
        {
            if (board[row][col + -1] == color)
            {
                if (board[row][col + 0] == color)
                {
                    iswin = true;
                }
            }
        }
    }
    if (board[row][col + 0] == color)
    {
        if (board[row][col + 1] == color)
        {
            if (board[row][col + 2] == color)
            {
                if (board[row][col + 3] == color)
                {
                    iswin = true;
                }
            }
        }
    }


	return iswin;
}

bool Board::canDrop(int col)
{
	bool candrop = false;
	if (board[0][col] == 0)
        candrop = true;
	return candrop;
}

//returns row
int Board::drop(int id, int col)
{
    if (canDrop(col))
    {
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][col]==0)
            {
                board[i][col] = id;
                undoedMoves = std::stack<std::tuple<int, int, int>>();
                moves.push(std::make_tuple(id, i, col));
                return i;
            }
        }
    }
    return -1;
}

bool Board::isDraw()
{
    int colsAvailable = 0;
    for (int i = 0; i < 7; i++)
        if (canDrop(i))
            colsAvailable++;
    if (colsAvailable == 0)
        return true;
    else return false;
}

void Board::unDo()
{
    board[std::get<1>(moves.top())][std::get<2>(moves.top())] = 0;
    undoedMoves.push(moves.top());
    moves.pop();
}

void Board::reDo()
{
    board[std::get<1>(moves.top())][std::get<2>(moves.top())] = std::get<0>(undoedMoves.top());
    moves.push(undoedMoves.top());
    undoedMoves.pop();

}


std::vector<int> Board::legalMoves()
{
	std::vector<int> legalmoves;
	for (int i = 0; i < 7; i++)
		if (canDrop(i))
			legalmoves.push_back(i);
	return legalmoves;
}



