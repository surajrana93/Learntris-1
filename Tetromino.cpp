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
 
 Tetromino::~Tetromino(){}
 
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
	 /*for(int i = 0; i < 4; i++)
	 {
		 m_gridLocs[i].col--;
	 }*/
	 
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
			m_facing = UP;
			m_gridLocs[0].row -= 2;
			m_gridLocs[0].col += 2;
			break;
		case DOWN:
			m_facing = RIGHT;
			m_gridLocs[0].row -= 1;
			m_gridLocs[0].col -= 1;
			break;
		case RIGHT:
			m_facing = UP;
			m_gridLocs[0].row +=2;
			m_gridLocs[0].col -=2;
			break;
	 }
	 updateGridLoc();
	 toggleGridLoc(); //Turns new cells ON
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
	 if(clockwise){ghost.rotateClockwise();}
	 else {ghost.rotateCounterClockwise();}
	 ghost.updateGridLoc();
	 
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
