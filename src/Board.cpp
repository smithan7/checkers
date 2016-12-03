/*
 * Board.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: andy
 */

#include "Board.h"

using namespace std;

Board::Board() {

	int f = -1; // for offset
	for(int i=0; i<7; i++){
		f = f*-1; // alternate offset
		if(f == 1){
			this->moveTran[4*i+0][0] = -1;
			this->moveTran[4*i+0][1] = 4*i+4;
			this->moveTran[4*i+1][0] = 4*i+4;
			this->moveTran[4*i+1][1] = 4*i+5;
			this->moveTran[4*i+2][0] = 4*i+5;
			this->moveTran[4*i+2][1] = 4*i+6;
			this->moveTran[4*i+3][0] = 4*i+6;
			this->moveTran[4*i+3][1] = 4*i+7;
		}
		else{
			this->moveTran[4*i+0][0] = 4*i+4;
			this->moveTran[4*i+0][1] = 4*i+5;
			this->moveTran[4*i+1][0] = 4*i+5;
			this->moveTran[4*i+1][1] = 4*i+6;
			this->moveTran[4*i+2][0] = 4*i+6;
			this->moveTran[4*i+2][1] = 4*i+7;
			this->moveTran[4*i+3][0] = 4*i+7;
			this->moveTran[4*i+3][1] = -1;
		}
	}

	for(int i=28; i<32; i++){
		this->moveTran[i][0] = -1;
		this->moveTran[i][1] = -1;
	}

	/// Set all possible jumps
	f = -1;
	for(int i=0; i<6; i++){
		f = f*-1; // alternate offset
		if(f == 1){
			this->jumpTran[4*i+0][0] = -1;
			this->jumpTran[4*i+0][1] = -1;
			this->jumpTran[4*i+0][2] = 4*i+4; // opponent piece
			this->jumpTran[4*i+0][3] = 4*i+9; // open square

			this->jumpTran[4*i+1][0] = 4*i+4;
			this->jumpTran[4*i+1][1] = 4*i+8;
			this->jumpTran[4*i+1][2] = 4*i+5;
			this->jumpTran[4*i+1][3] = 4*i+10;

			this->jumpTran[4*i+2][0] = 4*i+5;
			this->jumpTran[4*i+2][1] = 4*i+9;
			this->jumpTran[4*i+2][2] = 4*i+6;
			this->jumpTran[4*i+2][3] = 4*i+11;

			this->jumpTran[4*i+3][0] = 4*i+6;
			this->jumpTran[4*i+3][1] = 4*i+10;
			this->jumpTran[4*i+3][2] = -1;
			this->jumpTran[4*i+3][3] = -1;
		}
		else{
			this->jumpTran[4*i+0][0] = -1;
			this->jumpTran[4*i+0][1] = -1;
			this->jumpTran[4*i+0][2] = 4*i+4;
			this->jumpTran[4*i+0][3] = 4*i+9;

			this->jumpTran[4*i+1][0] = 4*i+5;
			this->jumpTran[4*i+1][1] = 4*i+8;
			this->jumpTran[4*i+1][2] = 4*i+6;
			this->jumpTran[4*i+1][3] = 4*i+10;

			this->jumpTran[4*i+2][0] = 4*i+6;
			this->jumpTran[4*i+2][1] = 4*i+9;
			this->jumpTran[4*i+2][2] = 4*i+7;
			this->jumpTran[4*i+2][3] = 4*i+11;

			this->jumpTran[4*i+3][0] = 4*i+7;
			this->jumpTran[4*i+3][1] = 4*i+10;
			this->jumpTran[4*i+3][2] = -1;
			this->jumpTran[4*i+3][3] = -1;
		}
	}
	for(int i=24; i<32; i++){
		this->jumpTran[i][0] = -1;
		this->jumpTran[i][1] = -1;
		this->jumpTran[i][2] = -1;
		this->jumpTran[i][3] = -1;
	}
}

void Board::makeKing(char pl, char kg){

	for(int i=28; i<32; i++){
		if(this->squares[i] == pl){
			this->squares[i] = kg;
		}
	}
}

void Board::makeBoard(){
	// TODO Auto-generated constructor stub
	for(int i = 0; i<32; i++){
		this->squares[i] = '.';
	}
	for(int i=0; i<12; i++){
		this->squares[i] = 'r';
	}
	for(int i=20; i<32; i++){
		this->squares[i] = 'b';
	}
}

void Board::displayMovesAndJumpsFromSquare(int sq){
	Board temp;

	for(int i=0; i<32; i++){
		temp.squares[i] = ' ';
	}

	temp.squares[sq] = 'x';

	int m0 = temp.moveTran[sq][0];
	int m1 = temp.moveTran[sq][1];

	if(m0 >= 0){
		temp.squares[m0] = 'm';
	}
	if(m1 >= 0){
		temp.squares[m1] = 'm';
	}
	temp.displayBoard();

	int j00 = temp.jumpTran[sq][0];
	int j01 = temp.jumpTran[sq][1];
	int j10 = temp.jumpTran[sq][2];
	int j11 = temp.jumpTran[sq][3];

	if(j00 >= 0){
		temp.squares[j00] = 'o';
		temp.squares[j01] = 'j';
	}
	if(j10 >= 0){
		temp.squares[j10] = 'o';
		temp.squares[j11] = 'j';
	}
	temp.displayBoard();
}

void Board::displayBoard(){
	cout << "---------------------------------------------" << endl;
	int f = 1; // for offset
	for(int i=0; i<8; i++){
		f = f*-1; // alternate offset
		if(f == 1){
			cout << "|-"; // emplace offset
			for(int j=0; j<3; j++){
				cout << "|" << this->squares[i*4+j] << "|-";
			}
			cout << "|" << this->squares[i*4+3] << "|";
		}
		else{
			for(int j=0; j<4; j++){
				cout << "|" << this->squares[i*4+j] << "|-";
			}
			cout << "|"; // emplace offset
		}
		cout << endl;
	}
}

void Board::getPossibleMoves(char myPiece, char myKing){
	this->moves.clear();

	for(int i=0; i<32; i++){
		if(this->squares[i] == myPiece || this->squares[i] == myKing){
			int pMove0 = this->moveTran[i][0];
			int pMove1 = this->moveTran[i][1];
			if(pMove0 > -1){
				if(this->squares[pMove0] == '.'){
					vector<int> tM;
					tM.push_back(i);
					tM.push_back(pMove0);
					this->moves.push_back(tM);
				}
			}
			if(pMove1 > -1){
				if(this->squares[pMove1] == '.'){
					vector<int> tM;
					tM.push_back(i);
					tM.push_back(pMove1);
					this->moves.push_back(tM);
				}
			}
		}
	}
	// look for king moves by flipping board
	this->flipBoard();

	for(int i=0; i<32; i++){
		if(this->squares[i] == myKing){
			int pMove0 = this->moveTran[i][0];
			int pMove1 = this->moveTran[i][1];
			if(pMove0 > -1){
				if(this->squares[pMove0] == '.'){
					vector<int> tM;
					tM.push_back(i);
					tM.push_back(pMove0);
					this->moves.push_back(tM);
				}
			}
			if(pMove1 > -1){
				if(this->squares[pMove1] == '.'){
					vector<int> tM;
					tM.push_back(i);
					tM.push_back(pMove1);
					this->moves.push_back(tM);
				}
			}
		}
	}
	this->flipBoard();
}

void Board::displayPossibleMovesAndJumps(char myPiece, char myKing, char opPiece, char opKing){
	this->getPossibleMoves(myPiece, myKing);
	this->getPossibleJumps(myPiece, myKing, opPiece, opKing);

	Board temp;
	for(int i=0; i<32; i++){
		temp.squares[i] = this->squares[i];
	}
	for(size_t i =0; i<this->moves.size(); i++){
		temp.squares[this->moves[i][1]] = 'm';
	}
	cout << "jumps: " << jumps.size() << endl;
	for(size_t i =0; i<this->jumps.size(); i++){
		temp.squares[this->jumps[i][2]] = 'j';
	}
	temp.displayBoard();
}


void Board::flipBoard(){
	char sq[32];
	for(int i=0; i<32; i++){
		sq[31-i] = this->squares[i];
	}
	for(int i=0; i<32; i++){
		this->squares[i] = sq[i];
	}
}

void Board::getPossibleJumps(char myPiece, char myKing, char opponentPiece, char opponentKing){
	this->jumps.clear();

	for(int i=0; i<32; i++){
		if(this->squares[i] == myPiece || this->squares[i] == myKing){
			int pJump0 = this->jumpTran[i][0]; // middle square 1
			int pJump2 = this->jumpTran[i][2]; // middle square 2
			if(pJump0 > -1){
				int pJump1 = this->jumpTran[i][1]; // landing square 1
				if( (this->squares[pJump0] == opponentPiece || this->squares[pJump0] == opponentKing) && this->squares[pJump1] == '.'){
					vector<int> tJ;
					tJ.push_back(i);
					tJ.push_back(pJump0);
					tJ.push_back(pJump1);
					this->jumps.push_back(tJ);
				}
			}

			if(pJump2 > -1){
				int pJump3 = this->jumpTran[i][3]; // landing square 2
				if( (this->squares[pJump2] == opponentPiece || this->squares[pJump0] == opponentKing) && this->squares[pJump3] == '.'){
					vector<int> tJ;
					tJ.push_back(i);
					tJ.push_back(pJump2);
					tJ.push_back(pJump3);
					this->jumps.push_back(tJ);
				}
			}
		}
	}

	// flip board to check king jumps
	this->flipBoard();

	for(int i=0; i<32; i++){
		if(this->squares[i] == myKing){
			int pJump0 = this->jumpTran[i][0]; // middle square 1
			int pJump2 = this->jumpTran[i][2]; // middle square 2
			if(pJump0 > -1){
				int pJump1 = this->jumpTran[i][1]; // landing square 1
				if( (this->squares[pJump0] == opponentPiece || this->squares[pJump0] == opponentKing) && this->squares[pJump1] == '.'){
					vector<int> tJ;
					tJ.push_back(i);
					tJ.push_back(pJump0);
					tJ.push_back(pJump1);
					this->jumps.push_back(tJ);
				}
			}

			if(pJump2 > -1){
				int pJump3 = this->jumpTran[i][3]; // landing square 2
				if( (this->squares[pJump2] == opponentPiece || this->squares[pJump0] == opponentKing) && this->squares[pJump3] == '.'){
					vector<int> tJ;
					tJ.push_back(i);
					tJ.push_back(pJump2);
					tJ.push_back(pJump3);
					this->jumps.push_back(tJ);
				}
			}
		}
	}
	this->flipBoard();


}

void Board::getPieceCount(char myPiece, char myKing, char opPiece, char opKing){
	int oCnt = 0;
	int mCnt = 0;

	for(int i=0; i<32; i++){
		if(this->squares[i] == myPiece){
			mCnt++;
		}
		else if(this->squares[i] == myKing){
			mCnt += 2;
		}
		else if(this->squares[i] == opPiece){
			oCnt++;
		}
		else if(this->squares[i] == opKing){
			oCnt += 2;
		}
	}
	cout << "Board Count:" << endl << "  Me: " << mCnt << endl << "  Opponent: " << oCnt << endl;
}
void Board::makeMove(vector<int> move){
	char piece = this->squares[move[0]];
	this->squares[move[0]] = '.';
	this->squares[move[1]] = piece;
}

void Board::makeJump(vector<int> jump){
	char piece = this->squares[jump[0]];
	this->squares[jump[0]] = '.';
	this->squares[jump[1]] = '.';
	this->squares[jump[2]] = piece;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

