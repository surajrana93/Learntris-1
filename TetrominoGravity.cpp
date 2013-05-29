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
		if(canGravity())
		{
		toggleGridLoc();
		funcGravity();
		toggleGridLoc();
		}
}

bool Tetromino::canGravity()
{
	GameBoard ghostBoard;
	for(int rows = 0; rows <= 21; rows++) { //Make a copy of the game board
		for(int cols = 1; cols <= 10; cols++)
		{
			ghostBoard.toggleCell(rows,cols,m_gameBoard->cell(rows,cols),m_gameBoard->cellColor(rows,cols));
		}
	}
	Tetromino ghost(&ghostBoard,m_gridLocs[0].row,m_gridLocs[0].col,m_facing); //and a copy of the Tetromino

	ghost.toggleGridLoc(); //Turn ghost's position on ghostBoard off; avoids interference during upcoming checks
	ghost.funcGravity();
	
	if(!ghost.inBounds()){ return FALSE; }	//If ghost is out of bounds, return FALSE
	for(int i = 0; i < 4; i++) { //Iterate through the four component cells of the Tetromino (post-drop)
		if(ghostBoard.cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col))
		{
			return FALSE;
		} //and if those gameBoard cells are occupied, return FALSE
	}
	return TRUE;
}