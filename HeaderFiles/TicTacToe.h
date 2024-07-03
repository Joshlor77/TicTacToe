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
	char* nDim;
	char* mDim;
	char* hDim;
	void deleteDimArrays();

	void checkBoardState();
	void finish();
	void updateVisual();
	void reset(int h, int n, int m); //Resets board state
	void updateState(); //Updates the game state
	void inputMove(int n, int h, int m);
public:
	TicTacToe();
	TicTacToe(int n, int m, int h);
	void start();
	~TicTacToe();
};

TicTacToe::TicTacToe(){
	//board = Matrix3(3, 3, 3);
	state = 0;
	nDim = new char[3];
	mDim = new char[3];
	hDim = new char[3];
	//display = TicTacToeDisplay(&board);
}

TicTacToe::TicTacToe(int h, int n, int m){
	board = Matrix3(h, n, m);
	state = 0;
	nDim = new char[n];
	mDim = new char[m];
	hDim = new char[h];
	display = TicTacToeDisplay(&board);

}

void TicTacToe::reset(int h, int n, int m){

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
		updateVisual();
		inputMove(input.getN(), input.getM(), input.getH());
	}
}

#endif
