#include <iostream>

#ifndef HEADERFILES_TICTACTOEDISPLAY_H_
#define HEADERFILES_TICTACTOEDISPLAY_H_

class TicTacToeDisplay {
public:
	void update(Matrix3& board);
	void xWinEndScreen();
	void oWinEndScreen();
};

//Prints the game status onto the screen
void TicTacToeDisplay::update(Matrix3& board){

}

void TicTacToeDisplay::xWinEndScreen(){
	std::cout << "X Win\n";
}

void TicTacToeDisplay::oWinEndScreen(){
	std::cout << "O Win\n";
}


#endif
