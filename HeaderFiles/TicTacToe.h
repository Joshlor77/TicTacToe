#include "Matrix.h"
#include "TicTacToeDisplay.h"
#include "Input.h"

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe {
private:
	Matrix3 board;
	TicTacToeDisplay display;
	tttInput input;
	short state; //Keeps track of the state of the game. This involves turn player and if and who won

	//These are used for checking win condition
	char* nDim,* mDim,* hDim;

	void checkBoardState();
	void finish();
	void updateVisual();
	void reset(); //Resets board state
	void updateState(); //Updates the game state
	void inputMove(int n, int h, int m);
public:
	TicTacToe() : TicTacToe(3) {}
	TicTacToe(int n);
	void start();
	~TicTacToe();
};

// Constructor
TicTacToe::TicTacToe(int n){
	board = Matrix3(n);
	state = 0;
	nDim = new char[n];
	mDim = new char[n];
	hDim = new char[n];
	display = TicTacToeDisplay();
}

/* Fills board with ' ' characters
 * Fills the dim arrays with ' ' characters
 */
void TicTacToe::reset(){
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++)
			for (int k = 0; k < board.size(); k++)
				board.set(i, j, k, ' ');
		(hDim)[i] = ' ';
		(nDim)[i] = ' ';
		(mDim)[i] = ' ';
	}
}

TicTacToe::~TicTacToe(){
	delete [] nDim;
	delete [] mDim;
	delete [] hDim;
}

//Updates the state of the board
void TicTacToe::updateState(){
	updateVisual();
	checkBoardState();

	switch (state){
	case 0:
		state = 1;
		return;
	case 1:
		state = 0;
		return;
	default:
		finish();
		return;
	}
}

//Called for inputting a move
void TicTacToe::inputMove(int n, int m, int h){
	switch (state){
	case 0: //X to move
		board.set(input.getN(), input.getM(), input.getH(), 'X');
		break;
	case 1: //O to move
		board.set(input.getN(), input.getM(), input.getH(), 'O');
		break;
	default:
		return;
	}
	updateState();
}

//Checks the board state to see if a player has won
void TicTacToe::checkBoardState(){
	//TODO check if a player has won. If a player has won, set board state to 2;
}

//Called when game ends
void TicTacToe::finish(){
	if (state == 2)
		display.xWinEndScreen();
	if (state == 3)
		display.oWinEndScreen();
}

//Called for updating visuals
void TicTacToe::updateVisual(){
	display.update();
}

//Starts the game
void TicTacToe::start(){
	while(true){
		inputMove(input.getN(), input.getM(), input.getH());
	}
}

#endif
