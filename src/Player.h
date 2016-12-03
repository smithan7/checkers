/*
 * Player.h
 *
 *  Created on: Jun 14, 2016
 *      Author: andy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"

class Player {
public:
	Player(char myPiece, char myKing, char opponentPiece, char opponentKing, int moveDirection);
	virtual ~Player();

	void MCTSPlayer(Board &board);
	void greedyPlayer(Board &board);
	void randomPlayer(Board &board);
	void displayPossibleMovesAndJumps(Board &board);


	int moveDirection; // handles flipping the board
	char myPiece;
	char myKing;
	char opponentPiece;
	char opponentKing;
};

#endif /* PLAYER_H_ */
