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
	m_gridLocs[0].row = grid->returnHeight() - 2;
	m_gridLocs[0].col = (grid->returnWidth() / 2) + 2;
	m_gameBoard->setColor(m_color);
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
	m_gameBoard->setColor(m_color);
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
		m_gameBoard->toggleCell((m_gridLocs[i].row),(m_gridLocs[i].col),m_color);
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

bool Tetromino::canMoveLeft(int n)
{
	GameBoard ghostBoard;
	for(int rows = 0; rows <= 21; rows++) { //Make a copy of the game board
		for(int cols = 1; cols <= 10; cols++)
		{
			ghostBoard.toggleCell(rows,cols,m_gameBoard->cell(rows,cols),m_color);
		}
	}
	Tetromino ghost(&ghostBoard,m_gridLocs[0].row,m_gridLocs[0].col,m_facing); //and a copy of the Tetromino

	ghost.toggleGridLoc();
	ghost.moveLeft(n,0);
	
	for(int i = 0; i < 4; i++) { //Iterate through the four component cells of the Tetromino
		if(ghostBoard.cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col))
		{
			return FALSE;
		} //and if those gameBoard cells are occupied, return FALSE
	}
	return TRUE;
}

bool Tetromino::canMoveRight(int n)
{
	GameBoard ghostBoard;
	for(int rows = 0; rows <= 21; rows++) { //Make a copy of the game board
		for(int cols = 1; cols <= 10; cols++)
		{
			ghostBoard.toggleCell(rows,cols,m_gameBoard->cell(rows,cols),m_color);
		}
	}
	Tetromino ghost(&ghostBoard,m_gridLocs[0].row,m_gridLocs[0].col,m_facing); //and a copy of the Tetromino

	ghost.toggleGridLoc();
	ghost.moveRight(n,0);
	
	for(int i = 0; i < 4; i++) { //Iterate through the four component cells of the Tetromino
		if(ghostBoard.cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col))
		{
			return FALSE;
		} //and if those gameBoard cells are occupied, return FALSE
	}
	return TRUE;
}

bool Tetromino::inBounds()
{
	for(int i = 0; i <= 3; i++)
	{
		if((m_gridLocs[i].col < 1) || (m_gridLocs[i].col > 10))
		{
			return 0;
		}
		else if(m_gridLocs[i].row < 0)
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

/**Locking goes here!
*/