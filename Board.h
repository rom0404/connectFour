#ifndef BOARD_H  
#define BOARD_H  

#include<iostream>  
#include<vector>  
#include<stack>
#include<tuple>
class Board  
{  
private:
	int board[6][7] = {};
	//first int is the color, second is the row, third is the column
	std::stack<std::tuple<int, int,int>> moves;
	std::stack<std::tuple<int, int,int>> undoedMoves;

public:  

	  
	void displayBoard();  
	bool isWin(int row, int col);  
	bool canDrop(int col);
	int drop(int id, int col);
	bool isDraw();
	void unDo();
	void reDo();

	//usefull for ai implementation
	std::vector<int> legalMoves();  
};  

#endif // !BOARD_H