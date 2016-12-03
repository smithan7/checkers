//============================================================================
// Name        : checkers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "Player.h"

int main(){
	srand(time(NULL));


	Board board;
	board.makeBoard();

	Player me('r','R','b','B',1);
	Player opponent('b','B','r','R',-1);

	for(int i=0; i<100; i++){

		board.displayBoard();
		me.displayPossibleMovesAndJumps(board);
		//board.displayMovesAndJumpsFromSquare(5);
		me.randomPlayer(board);
		board.displayBoard();
		//opponent.displayPossibleMovesAndJumps(board);
		opponent.randomPlayer(board);
		board.displayBoard();
		board.getPieceCount(me.myPiece, me.myKing,opponent.myPiece, opponent.myKing);
	}

	return 0;
}
