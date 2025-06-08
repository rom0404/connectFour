#include <iostream>

#include"Board.h"
#include"Player.h"


int main()
{
    Board board;
    Player player1, player2;
    player1.setID(1);
    player2.setID(2);
    Player* curr = &player1;
    while (true)
    {
        board.displayBoard();
        if (curr->getID()==1)
        {
            std::cout << "it's YELLOW's turn\n";
        }
        else
        {
            std::cout << "it's RED's turn\n";
        }
        int col=curr->getMove(board);
        if (col==-1)
        {
            board.unDo();
            if (curr == &player1)
            {
                curr = &player2;
            }
            else
            {
                curr = &player1;
            }
            continue;
        }
        if (col==7)
        {
            board.reDo();
            if (curr == &player1)
            {
                curr = &player2;
            }
            else
            {
                curr = &player1;
            }
            continue;
        }

        int row=board.drop(curr->getID(), col);
        if (board.isWin(row,col))
        {
            std::cout<<"\n\n\n";
            board.displayBoard();
            std::cout << "\n\ncongratulations! player: " << curr->getID() << " won\n\n\n";
            break;
        }
        else if (board.isDraw())
        {
            std::cout << "\n\n\n";
            board.displayBoard();
            std::cout << "\n\nREALLY? A DRAW?!\n\n\n";
            break;
        }
        else
        {
            if (curr==&player1)
            {
                curr = &player2;
            }
            else
            {
                curr = &player1;
            }
        }
    }
    
}

