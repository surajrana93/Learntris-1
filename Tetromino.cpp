/**
 * @file Tetromino.cpp
 * @brief Implements Tetromino class
 * @author Chance Rosenthal
 **/
 
 #include "Tetromino.h"
 
 using namespace std;
 
 Tetromino::Tetromino(GameBoard *grid)
 {
	 
	 m_gameBoard = grid;
	 m_facing = LEFT;
	 m_gridLocs[0].row = 22;
	 m_gridLocs[0].col = 6;
	 updateGridLoc();
	 toggleGridLoc();
 }
 
  Tetromino::Tetromino(GameBoard *grid, int row, int col)
 {
	 
	 m_gameBoard = grid;
	 m_facing = LEFT;
	 m_gridLocs[0].row = row;
	 m_gridLocs[0].col = col;
	 updateGridLoc();
 }

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
 
 void Tetromino::toggleGridLoc()
 {
	 for(int i = 0; i < 4; i++)
	 {
		 m_gameBoard->toggleCell((m_gridLocs[i].row),(m_gridLocs[i].col));
	 }
 }
 
 void Tetromino::funcGravity()
 {
	 m_gridLocs[0].row--;
	 updateGridLoc();
 }
 
 void Tetromino::doGravity()
 {
	 toggleGridLoc();
	 funcGravity();
	 toggleGridLoc();
 }
 
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
  * @brief Returns true if piece can rotate
  * @param clockwise Boolean. Set true if you want to check clockwise rotation; false for counter-clockwise.
  * */
 bool Tetromino::canRotate(bool clockwise)
 {
	 Tetromino ghost(m_gameBoard);
	 
	 ghost.m_gridLocs[0].row = m_gridLocs[0].row;
	 ghost.m_gridLocs[1].col = m_gridLocs[1].col;
	 ghost.updateGridLoc();
	 if(clockwise){ghost.rotateClockwise(1);}
	 else {ghost.rotateCounterClockwise(1);}
	 
	 for(int i = 0; i < 4; i++)
	 {
		 if(m_gameBoard->cell(ghost.m_gridLocs[i].row,m_gridLocs[i].col))
		 {
			 return false;
		 }
		 else if(!(23 >= m_gridLocs[i].row >= 0) || !(9 >= m_gridLocs[i].col >= 0))
		 {
			 return false;
		 }
	 }
	 return true;
 }

Tetromino::rotateStatus Tetromino::checkClockwise()
{
	Tetromino ghost(m_gameBoard,m_gridLocs[0].row,m_gridLocs[0].col);	//Initialize a "ghost" Tetromino to test conditions
	ghost.m_facing = m_facing; //Set ghost's facing to Tetromino's facing
	ghost.rotateClockwise(1); //Perform the rotation
	for(int i = 0; i < 4; i++) //Iterate through the four component cells of the Tetromino
	{
		if(m_gameBoard->cell(ghost.m_gridLocs[i].row, ghost.m_gridLocs[i].col)){return FALSE;} //and if those gameBoard cells are occupied, return FALSE
	}
	for(int i = 0; i < 4; i++) //Iterate through same
	{
		if(!((0 <= ghost.m_gridLocs[i].col) && (ghost.m_gridLocs[i].col <= 9))){return BUMP;} //and if those cells are out of bounds, return BUMP (cue wallbump)
	}
	return TRUE; //if control gets this far, rotation is free and clear. return TRUE.
}

Tetromino::rotateStatus Tetromino::checkCounterClockwise()
{
	Tetromino ghost(m_gameBoard,m_gridLocs[0].row,m_gridLocs[0].col);	//Initialize a dummy Tetromino and use its positions resulting from
	ghost.m_facing = m_facing;						//a variety of operations to determine rotateStatus.
	ghost.rotateCounterClockwise(1);
	ghost.updateGridLoc();							//ghost is now located where Tetromino would be if it rotated counter-clockwise.
	for(int i = 0; i < 4; i++)
	{
		if(m_gameBoard->cell(ghost.m_gridLocs[i].row,ghost.m_gridLocs[i].col)){return FALSE;}
	}
	for(int i = 0; i < 4; i++)
	{
		if(!(0 <= ghost.m_gridLocs[i].col) && !(ghost.m_gridLocs[i].col <= 9)){return BUMP;}
	}
	return TRUE;
}

void Tetromino::moveLeft(int n)
{
	toggleGridLoc();
	m_gridLocs[0].col -= n;
	updateGridLoc();
	toggleGridLoc();
}

void Tetromino::moveRight(int n)
{
	toggleGridLoc();
	m_gridLocs[0].col += n;
	updateGridLoc();
	toggleGridLoc();
}