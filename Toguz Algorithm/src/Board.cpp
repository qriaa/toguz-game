#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 18; i++)
	{
		holes.emplace_back(0);
	}
	kazanOne = 0;
	tuzOne = 0;
	kazanTwo = 0;
	tuzTwo = 0;
}