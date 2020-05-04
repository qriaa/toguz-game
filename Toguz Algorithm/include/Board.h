#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>

struct Board
{
	Board();

	std::vector<int> holes;

	int kazanOne;
	int tuzOne;		//tuz == -1 means tuz not placed yet

	int kazanTwo;
	int tuzTwo;
};


#endif // !BOARD_H
