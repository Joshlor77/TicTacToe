#include <iostream>

#include "HeaderFiles/TicTacToe.h"

void setMatrix(Matrix3& board){
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board.size(); j++)
			for (int k = 0; k < board.size(); k++)
				board.set(i, j, k, 't');
}

void printMatrix(Matrix3& board){
	for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board.size(); j++)
				for (int k = 0; k < board.size(); k++)
					cout << board.get(i, j, k);
}

int main(){
	//std::cout << "text1\n";
	//TicTacToe game;
	//game.start();
	Matrix3 board = Matrix3(4);
	//setMatrix(board);
	printMatrix(board);

	return 0;
}
