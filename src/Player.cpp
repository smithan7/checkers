/*
 * Player.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: andy
 */

#include "Player.h"

Player::Player(char myPiece, char myKing, char opponentPiece, char opponentKing, int moveDirection){
	this->myPiece = myPiece;
	this->myKing = myKing;

	this->opponentPiece = opponentPiece;
	this->opponentKing = opponentKing;

	this->moveDirection = moveDirection;
}


void Player::MCTSPlayer(Board &board){

}

void Player::greedyPlayer(Board &board){
	board.getPossibleJumps(this->myPiece, this->myKing, this->opponentPiece, this->opponentKing); //
	if(board.jumps.size() > 0){ // jump moves exist

	}
}

void Player::displayPossibleMovesAndJumps(Board &board){
	if(this->moveDirection < 0){
		board.flipBoard();
	}
	cout << "---------------------------------------------" << endl;
	cout << "Displaying moves for " << this->myPiece << endl;
	board.displayPossibleMovesAndJumps(this->myPiece,this->myKing, this->opponentPiece, this->opponentKing);

	if(this->moveDirection < 0){
		board.flipBoard();
	}
}

void Player::randomPlayer(Board &board){
	if(this->moveDirection < 0){
		board.flipBoard();
	}

	board.getPossibleMoves(this->myPiece, this->myKing); // have the board find all possible moves
	board.getPossibleJumps(this->myPiece, this->myKing, this->opponentPiece, this->opponentKing);

	cout << "moves: " << board.moves.size() << endl;

	if(board.moves.size() + board.jumps.size() > 0){ // check that moves exist
		int move = rand() % ( board.moves.size() + board.jumps.size() );
		if( move < board.moves.size() ){
			vector<int> mMove = board.moves[move];
			board.makeMove(mMove);
		}
		else{
			move = move - board.moves.size();
			vector<int> jJump = board.jumps[move];
			board.makeJump(jJump);
		}
	}

	board.makeKing(this->myPiece, this->myKing);

	if(this->moveDirection < 0){
		board.flipBoard();
	}

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

