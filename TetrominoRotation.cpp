/**
 * @file TetrominoRotation.cpp
 * @brief Implementation of rotation-related functions from Tetromino.h
 * */

#include "Tetromino.h"

/**
 * @brief Rotates Tetromino clockwise. Updates GameBoard.
 * */

void Tetromino::rotateClockwise()
{
	toggleGridLoc(); //Turns current cells OFF
	switch(m_facing) {
	case LEFT:
		m_facing = UP;
		m_gridLocs[0].row -= 1;
		m_gridLocs[0].col -= 1;
		break;
	case UP:
		m_facing = RIGHT;
		m_gridLocs[0].row += 2;
		m_gridLocs[0].col -= 2;
		break;
	case RIGHT:
		m_facing = DOWN;
		m_gridLocs[0].row += 1;
		m_gridLocs[0].col += 1;
		break;
	case DOWN:
		m_facing = LEFT;
		m_gridLocs[0].row -=2;
		m_gridLocs[0].col +=2;
		break;
	}
	updateGridLoc();
	toggleGridLoc(); //Turns new cells ON
}

/**
 * @brief Rotates Tetromino counter-clockwise. Updates GameBoard.
 * */

void Tetromino::rotateCounterClockwise()
{
	toggleGridLoc(); //Turns current cells OFF
	switch(m_facing) {
	case UP:
		m_facing = LEFT;
		m_gridLocs[0].row += 1;
		m_gridLocs[0].col += 1;
		break;
	case LEFT:
		m_facing = DOWN;
		m_gridLocs[0].row += 2;
		m_gridLocs[0].col -= 2;
		break;
	case DOWN:
		m_facing = RIGHT;
		m_gridLocs[0].row -= 1;
		m_gridLocs[0].col -= 1;
		break;
	case RIGHT:
		m_facing = UP;
		m_gridLocs[0].row -=2;
		m_gridLocs[0].col +=2;
		break;
	}
	updateGridLoc();
	toggleGridLoc(); //Turns new cells ON
}

/**
 * @overload Tetromino::rotateClockwise()
 * @param noToggle Accepts any integer value. Presence of this parameter causes rotation not to toggleGridLocs().
 * */

void Tetromino::rotateClockwise(int noToggle)
{
	switch(m_facing) {
	case LEFT:
		m_facing = UP;
		m_gridLocs[0].row -= 1;
		m_gridLocs[0].col -= 1;
		break;
	case UP:
		m_facing = RIGHT;
		m_gridLocs[0].row += 2;
		m_gridLocs[0].col -= 2;
		break;
	case RIGHT:
		m_facing = DOWN;
		m_gridLocs[0].row += 1;
		m_gridLocs[0].col += 1;
		break;
	case DOWN:
		m_facing = LEFT;
		m_gridLocs[0].row -=2;
		m_gridLocs[0].col +=2;
		break;
	}
	updateGridLoc();
}

/**
 * @overload Tetromino::rotateCounterClockwise()
 * @param noToggle Accepts any integer value. Presence of this parameter causes rotation not to toggleGridLocs().
 * */

void Tetromino::rotateCounterClockwise(int noToggle)
{
	switch(m_facing) {
	case UP:
		m_facing = LEFT;
		m_gridLocs[0].row += 1;
		m_gridLocs[0].col += 1;
		break;
	case LEFT:
		m_facing = DOWN;
		m_gridLocs[0].row += 2;
		m_gridLocs[0].col -= 2;
		break;
	case DOWN:
		m_facing = RIGHT;
		m_gridLocs[0].row -= 1;
		m_gridLocs[0].col -= 1;
		break;
	case RIGHT:
		m_facing = UP;
		m_gridLocs[0].row -=2;
		m_gridLocs[0].col +=2;
		break;
	}
	updateGridLoc();
}

/**
 * @brief Checks whether piece can rotate clockwise. Returns an enum: FALSE (no), TRUE, or BUMP (rotating will trigger wall bump)
 * */

Tetromino::rotateStatus Tetromino::checkClockwise()
{
	GameBoard ghostBoard;
	for(int rows = 0; rows <= 21; rows++) { //Make a copy of the game board
		for(int cols = 0; cols <= 9; cols++) {
			ghostBoard.toggleCell(rows,cols,m_gameBoard->cell(rows,cols));
		}
	}
	Tetromino ghost(&ghostBoard,m_gridLocs[0].row,m_gridLocs[0].col,m_facing); //and a copy of the Tetromino
	//ghost.m_facing = m_facing;
	ghost.toggleGridLoc(); //Turn ghost's position on ghostBoard off; avoids interference during upcoming checks
	ghost.rotateClockwise(1);
	for(int i = 0; i < 4; i++) { //Iterate through the four component cells of the Tetromino
		if(ghostBoard.cell(ghost.m_gridLocs[i].row, ghost.m_gridLocs[i].col)) {
			ghost.toggleGridLoc();
			return FALSE;
		} //and if those gameBoard cells are occupied, return FALSE
	}
	for(int i = 0; i < 4; i++) { //Iterate through same
		while(!((0 <= ghost.m_gridLocs[i].col) && (ghost.m_gridLocs[i].col <= 9))) { //and if those cells are out of bounds
			bool outOfBounds = 1;
			while(outOfBounds) {
				ghost.moveLeft(1); //move ghost back in bounds
			}
			for(int i = 0; i < 4; i++) {
				if(ghostBoard.cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col)) {
					ghost.toggleGridLoc(); //check if any of its new cell locations are already occupied
					return FALSE;
				}
			}
			ghost.toggleGridLoc(); //if not, return BUMP (cue a wallbump)
			return BUMP;
		}
	}
	ghost.rotateCounterClockwise(1);
	ghost.toggleGridLoc();
	return TRUE;
}

/**
 * @brief Checks whether piece can rotate counter-clockwise. Returns an enum: FALSE (no), TRUE, or BUMP (rotating will trigger wall bump)
 * */

Tetromino::rotateStatus Tetromino::checkCounterClockwise()
{
	GameBoard ghostBoard;
	for(int rows = 0; rows <= 21; rows++) { //Make a copy of the game board
		for(int cols = 0; cols <= 9; cols++) {
			ghostBoard.toggleCell(rows,cols,m_gameBoard->cell(rows,cols));
		}
	}
	Tetromino ghost(&ghostBoard,m_gridLocs[0].row,m_gridLocs[0].col,m_facing); //and a copy of the Tetromino
	//ghost.m_facing = m_facing;
	ghost.toggleGridLoc(); //Turn ghost's position on ghostBoard off; avoids interference during upcoming checks
	ghost.rotateCounterClockwise(1);
	for(int i = 0; i < 4; i++) { //Iterate through the four component cells of the Tetromino
		if(ghostBoard.cell(ghost.m_gridLocs[i].row, ghost.m_gridLocs[i].col)) {
			ghost.toggleGridLoc();
			return FALSE;
		} //and if those gameBoard cells are occupied, return FALSE
	}
	for(int i = 0; i < 4; i++) { //Iterate through same
		while(!((0 <= ghost.m_gridLocs[i].col) && (ghost.m_gridLocs[i].col <= 9))) { //and if those cells are out of bounds
			bool outOfBounds = 1;
			while(outOfBounds) {
				ghost.moveLeft(1); //move ghost back in bounds
			}
			for(int i = 0; i < 4; i++) {
				if(ghostBoard.cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col)) {
					ghost.toggleGridLoc(); //check if any of its new cell locations are already occupied
					return FALSE;
				}
			}
			ghost.toggleGridLoc(); //if not, return BUMP (cue a wallbump)
			return BUMP;
		}
	}
	ghost.rotateClockwise(1);
	ghost.toggleGridLoc();
	return TRUE;
}