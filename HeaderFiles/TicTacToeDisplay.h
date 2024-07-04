#include <iostream>

using std::cout;

#ifndef HEADERFILES_TICTACTOEDISPLAY_H_
#define HEADERFILES_TICTACTOEDISPLAY_H_

class TicTacToeDisplay {
private:

public:
	TicTacToeDisplay();
	void update();
	void xWinEndScreen();
	void oWinEndScreen();
};

TicTacToeDisplay::TicTacToeDisplay(){

}

//Prints the game status onto the screen
void TicTacToeDisplay::update(){
	cout << "Update Called\n";
}

void TicTacToeDisplay::xWinEndScreen(){
	std::cout << "X Win\033[2J\033[1;1H";
}

void TicTacToeDisplay::oWinEndScreen(){
	std::cout << "O Win\n\033[2J\033[1;1H";
}


#endif
