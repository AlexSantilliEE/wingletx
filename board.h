#ifndef WINGLET_BOARD_H

#define WINGLET_BOARD_H


#include "defines.h"

struct Board
{
	BitMap whiteKing, whiteQueens, whiteRooks, whiteBishops, whiteKnights,
		   whitePawns;
	
	BitMap blackKing, blackQueens, blackRooks, blackBishops, blackKnights,
		   blackPawns;
		   
	BitMap whitePieces, blackPieces, occupiedSquares;
	
	unsigned char nextMove; // White or black
	unsigned char castleWhite; // White's castle status, CANCASTLEOO = 1, CANCASTLEOOO = 2;
	unsigned char castleBlack; // Black's castle status, CANCASTLEOO = 1, CANCASTLEOOO = 2;
	
	int epSquare; // En-passant target square
	int fiftyMove; // Moves since the last pawn move or capture
	
	// additional variables:
	int Material; // Incrementally updated, total material on board
				 // unites in centipawns, from white's side of view
	
	int square[64]; // Probe what kind of piece is on a particular square.
	
	BOOLTYPE viewRotated; // Only used for displaying the board. TRUE or FALSE.
	
	// Methods:
	
	void init();
	
	void initFromSquares( int input[64], unsigned char next, int fiftyM, int castleW, int castleB, int epSq );
	
	void initFromFen( char fen[], char fencolor[], char fencastling[], char fenenpassant[], int fenhalfmoveclock, int fenfullmovenumber );
	
	void display();
};


#endif