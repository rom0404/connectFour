#ifndef BOARD_H  
#define BOARD_H  

#include<iostream>  
#include<vector>  
#include<stack>
#include<tuple>

#include"Move.h"
//#include "Player.h"

class Board  

{  
private:
	int board[6][7] = {};
	//first int is the color, second is the row, third is the column
	std::stack<Move> moves;
	std::stack<Move> undoedMoves;

public:  

	  
	void displayBoard();  
	bool isWin(int row, int col);  
	bool canDrop(int col);
	int drop(int id, int col);
	bool isDraw();
	int unDo();
	int reDo();
	void clearUndoedMoves();

	//Move manipulateBoard(Player& curr, Player player1, Player player2);

	//usefull for ai implementation
	std::vector<int> legalMoves();  
};  

#endif // !BOARD_H