#include <iostream>

using std::cout;

#ifndef HEADERFILES_TICTACTOEDISPLAY_H_
#define HEADERFILES_TICTACTOEDISPLAY_H_

class TicTacToeDisplay {
private:
	void printAsText();
	Matrix3* board;
public:
	TicTacToeDisplay();
	TicTacToeDisplay(Matrix3* board);
	void update();
	void xWinEndScreen();
	void oWinEndScreen();
};

TicTacToeDisplay::TicTacToeDisplay(){
	board = nullptr;
}

TicTacToeDisplay::TicTacToeDisplay(Matrix3* matrix3){
	board = matrix3;
}

void TicTacToeDisplay::printAsText(){
	for (int i = 0; i < board->sizeH(); i++){
		for (int j = 0; j < board->sizeN(); j++)
			cout << "----";
		cout << "-----\n";
		for (int j = 0; j < board->sizeN(); j++){
			for(int k = 0; k < board->sizeH(); k++){
				cout << "|" << board->get(i, j, k) <<  "|";
			}
		}
		for (int j = 0; j < board->sizeN(); j++)
			cout << "----";
		cout << "-----\n";
		std::cout << "\n\n";
	}
}

//Prints the game status onto the screen
void TicTacToeDisplay::update(){
	printAsText();
}

void TicTacToeDisplay::xWinEndScreen(){
	std::cout << "X Win\033[2J\033[1;1H";
}

void TicTacToeDisplay::oWinEndScreen(){
	std::cout << "O Win\n\033[2J\033[1;1H";
}


#endif
