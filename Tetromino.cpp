/**
 * @file Tetromino.cpp
 * @brief Implements Tetromino constructors and some basic motion functions
 **/

#include "Tetromino.h"

using namespace std;

/**
 * @brief Initializes object with default values.
 * */
Tetromino::Tetromino(GameBoard *grid)
{
	m_gameBoard = grid;
	m_facing = LEFT;
	m_gridLocs[0].row = 20;
	m_gridLocs[0].col = 7;
	updateGridLoc();
	toggleGridLoc();
}

/**
 * @overload Tetromino::Tetromino(GameBoard *grid)
 * @brief Alternate constructor; does not toggleGridLoc on init.
 * */
Tetromino::Tetromino(GameBoard *grid, int row, int col, facing face)
{
	m_gameBoard = grid;
	m_facing = face;
	m_gridLocs[0].row = row;
	m_gridLocs[0].col = col;
	updateGridLoc();
}

/**
 * @brief Updates positions of m_gridLocs[n].row and .col, based on m_gridLocs[0].
 * */

void Tetromino::updateGridLoc()
{
	for(int i = 1; i < 4; i++) { //Checks current facing and sets gridLoc up accordingly
		switch(m_facing) {
		case RIGHT:
			m_gridLocs[i].row = m_gridLocs[0].row;
			m_gridLocs[i].col = m_gridLocs[0].col + i;
			break;
		case DOWN:
			m_gridLocs[i].row = m_gridLocs[0].row - i;
			m_gridLocs[i].col = m_gridLocs[0].col;
			break;
		case LEFT:
			m_gridLocs[i].row = m_gridLocs[0].row;
			m_gridLocs[i].col = m_gridLocs[0].col - i;
			break;
		case UP:
			m_gridLocs[i].row = m_gridLocs[0].row + i;
			m_gridLocs[i].col = m_gridLocs[0].col;
			break;
		}
	}
}

/**
 * @brief Calls to GameBoard, toggling empty/full state of all cells currently identified with Tetromino.
 * */

void Tetromino::toggleGridLoc()
{
	for(int i = 0; i < 4; i++) {
		m_gameBoard->toggleCell((m_gridLocs[i].row),(m_gridLocs[i].col));
	}
}

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

/**
 * @brief Moves Tetromino to the left n cells.
 * */

void Tetromino::moveLeft(int n)
{
	toggleGridLoc();
	m_gridLocs[0].col -= n;
	updateGridLoc();
	toggleGridLoc();
}

/**
 * @brief Moves Tetromino to the right n cells.
 * */

void Tetromino::moveRight(int n)
{
	toggleGridLoc();
	m_gridLocs[0].col += n;
	updateGridLoc();
	toggleGridLoc();
}

/**
 * @overload void Tetromino::moveLeft(int n)
 * */

void Tetromino::moveLeft(int n, bool toggleCells)
{
	if(toggleCells) toggleGridLoc();
	m_gridLocs[0].col -= n;
	updateGridLoc();
	if(toggleCells) toggleGridLoc();
}

/**
 * @overload void Tetromino::moveRight(int n)
 * */

void Tetromino::moveRight(int n, bool toggleCells)
{
	if(toggleCells) toggleGridLoc();
	m_gridLocs[0].col += n;
	updateGridLoc();
	if(toggleCells) toggleGridLoc();
}

bool Tetromino::inBounds()
{
	for(int i = 0; i <= 3; i++)
	{
		if((m_gridLocs[i].col < 1) || (m_gridLocs[i].col > 10))
		{
			return 0;
		}
	}
	return 1;
}

int Tetromino::returnGridLocs(int n,bool row)
{
	if(row) return m_gridLocs[n].row; else return m_gridLocs[n].col;
}