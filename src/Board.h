/*
 * Board.h
 *
 *  Created on: Jun 14, 2016
 *      Author: andy
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Board {
public:
	Board();
	virtual ~Board();
	void makeBoard();
	void flipBoard();
	void displayBoard();
	void displayPossibleMovesAndJumps(char myPiece, char myKing, char opPiece, char opKing);
	void displayMovesAndJumpsFromSquare(int sq);
	void getPossibleMoves(char myPiece, char myKing);
	void getPossibleJumps(char myPiece, char myKing, char opponentPiece, char opponentKing);
	void getPieceCount(char myPiece, char myKing, char opPiece, char opKing);
	void makeKing(char pl, char kg);
	void makeMove(vector<int> move);
	void makeJump(vector<int> jump);



	int moveTran[32][2];
	int jumpTran[32][4];
	char squares [32];
	vector<vector<int> > moves;
	vector<vector<int> > jumps;


};

#endif /* BOARD_H_ */
