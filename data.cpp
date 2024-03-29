#include <iostream>
#include <iomanip>
#include "defines.h"
#include "protos.h"
#include "extglobals.h"

void dataInit()
{
	int i, rank, file;
	
	// set all bits:
	BITSET[0] = 0x1;
	for( i = 1; i < 64; i++ ) BITSET[i] = BITSET[i-1] << 1;
	
	// BOARDINDEX translates [file][rank] to [square]:
	for( rank = 0; rank < 9; rank++ )
	{
		for( file = 0; file < 9; file++ )
		{
			BOARDINDEX[file][rank] = (rank-1) * 8 + file - 1;
		}
	}
	
	// initialize the board:
	board.init();
	
	//     Initialize MS1BTABLE, used in lastOne (see bitops.cpp)
    for (i = 0; i < 256; i++)
    {
        MS1BTABLE[i] = (
            (i > 127) ? 7 :
            (i >  63) ? 6 :
            (i >  31) ? 5 :
            (i >  15) ? 4 :
            (i >   7) ? 3 :
            (i >   3) ? 2 :
            (i >   1) ? 1 : 0 );
    }
 
    return;
}

void info()
{
	
	//  your playground... display variables - meant for testing/verification purposes only
    std::cout << std::endl << "============ info start ==============" << std::endl;
    std::cout << "size of board, in bytes   = " << sizeof(board) << std::endl;
    std::cout << "Material value            = " << board.Material << std::endl;
    std::cout << "White castling rights     = " << int(board.castleWhite) << std::endl;
    std::cout << "Black castling rights     = " << int(board.castleBlack) << std::endl;
    std::cout << "En-passant square         = " << board.epSquare << std::endl;
    std::cout << "Fifty move count          = " << board.fiftyMove << std::endl;
 
    std::cout << "bitCnt of white pawns     = " << bitCnt(board.whitePawns) << std::endl;
    std::cout << std::endl << "bitmap of blackKnights | board.whitePawns:" << std::endl;
    displayBitmap(board.blackKnights | board.whitePawns);
    std::cout << "============ info end ================" << std::endl << std::endl;
 
    return;
	
}