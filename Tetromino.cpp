/**
 * @file Tetromino.cpp
 * @brief Implements Tetromino class
 * @author Chance Rosenthal
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
	 m_gridLocs[0].row = 22;
	 m_gridLocs[0].col = 6;
	 updateGridLoc();
	 toggleGridLoc();
 }
 
 /**
  * @overload Tetromino::Tetromino(GameBoard *grid)
  * @brief Alternate constructor; does not toggleGridLoc on init.
  * */
  Tetromino::Tetromino(GameBoard *grid, int row, int col)
 {
	 
	 m_gameBoard = grid;
	 m_facing = LEFT;
	 m_gridLocs[0].row = row;
	 m_gridLocs[0].col = col;
	 updateGridLoc();
 }

/**
 * @brief Updates positions of m_gridLocs[n].row and .col, based on m_gridLocs[0].
 * */

 void Tetromino::updateGridLoc()
 {
	 for(int i = 1; i < 4; i++) //Checks current facing and sets gridLoc up accordingly
	 {
		 switch(m_facing)
		 {
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
	 for(int i = 0; i < 4; i++)
	 {
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
	 toggleGridLoc();
	 funcGravity();
	 toggleGridLoc();
 }
 
 /**
  * @brief Rotates Tetromino clockwise. Updates GameBoard.
  * */
 
 void Tetromino::rotateClockwise()
 {
	 toggleGridLoc(); //Turns current cells OFF
	 switch(m_facing)
	 {
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
	 switch(m_facing)
	 {
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
	 switch(m_facing)
	 {
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
	 switch(m_facing)
	 {
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
	Tetromino ghost(m_gameBoard,m_gridLocs[0].row,m_gridLocs[0].col);	//Initialize a "ghost" Tetromino to test conditions
	ghost.m_facing = m_facing; //Set ghost's facing to Tetromino's facing
	toggleGridLoc(); //Temporarily toggle Tetronimo's location to allow for next operations (OFF)
	ghost.rotateClockwise(1); //Perform the rotation
	for(int i = 0; i < 4; i++) //Iterate through the four component cells of the Tetromino
	{
		if(m_gameBoard->cell(ghost.m_gridLocs[i].row, ghost.m_gridLocs[i].col))
			{
				ghost.rotateCounterClockwise(1); //Turn ghost back the way it started 
				toggleGridLoc(); //and turn Tetronimo's location back on.
				return FALSE;
			} //and if those gameBoard cells are occupied, return FALSE
	}
	for(int i = 0; i < 4; i++) //Iterate through same
	{
		if(!((0 <= ghost.m_gridLocs[i].col) && (ghost.m_gridLocs[i].col <= 9)))
			{
				ghost.rotateCounterClockwise(1);
				toggleGridLoc();
				return BUMP;
			} //and if those cells are out of bounds, return BUMP (cue wallbump)
	}
	ghost.rotateCounterClockwise(1); 
	toggleGridLoc();
	return TRUE; //if control gets this far, rotation is free and clear. return TRUE.
}

 /**
  * @brief Checks whether piece can rotate counter-clockwise. Returns an enum: FALSE (no), TRUE, or BUMP (rotating will trigger wall bump)
  * */

Tetromino::rotateStatus Tetromino::checkCounterClockwise()
{
	Tetromino ghost(m_gameBoard,m_gridLocs[0].row,m_gridLocs[0].col);
	ghost.m_facing = m_facing;
	toggleGridLoc();
	ghost.rotateCounterClockwise(1);
	for(int i = 0; i < 4; i++) //Iterate through the four component cells of the Tetromino
	{
		if(m_gameBoard->cell(ghost.m_gridLocs[i].row, ghost.m_gridLocs[i].col))
			{
				ghost.rotateClockwise(1); //Turn ghost back the way it started 
				toggleGridLoc(); //and turn Tetronimo's location back on.
				return FALSE;
			} //and if those gameBoard cells are occupied, return FALSE
	}
	for(int i = 0; i < 4; i++) //Iterate through same
	{
		if(!((0 <= ghost.m_gridLocs[i].col) && (ghost.m_gridLocs[i].col <= 9)))
			{
				ghost.rotateClockwise(1);
				toggleGridLoc();
				return BUMP;
			} //and if those cells are out of bounds, return BUMP (cue wallbump)
	}
	ghost.rotateClockwise(1); 
	toggleGridLoc();
	return TRUE;
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