/**
 * @file TetrominoGravity.cpp
 * @brief Implements Tetromino gravity functions
 **/

#include "Tetromino.h"

using namespace std;

/**
 * @brief Mechanics behind gravity. Will contain checks and math as class evolves.
 * */

void Tetromino::funcGravity()
{
	m_gridLocs[0].row--;
	updateGridLoc();
}

/**
 * @brief Toggles gridLocs before and after calling funcGravity, updating GameBoard.
 * */

void Tetromino::doGravity()
{
	bool canGravity = 1;
	for(int i = 0; i < 4; i++)
	{
		if(m_gridLocs[i].row == 0)
		{
		canGravity = 0;
		}
	}
		if(canGravity)
		{
		toggleGridLoc();
		funcGravity();
		toggleGridLoc();
		}
}