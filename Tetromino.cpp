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
	 m_gridLoc[0][0] = 22;
	 m_gridLoc[0][1] = 6;
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
				m_gridLoc[i][0] = m_gridLoc[0][0];
				m_gridLoc[i][1] = m_gridLoc[0][1] + i;
				break;
			 case DOWN:
				m_gridLoc[i][0] = m_gridLoc[0][0] - i;
				m_gridLoc[i][1] = m_gridLoc[0][1];
				break;
			 case LEFT:
				m_gridLoc[i][0] = m_gridLoc[0][0];
				m_gridLoc[i][1] = m_gridLoc[0][1] - i;
				break;
			 case UP:
				m_gridLoc[i][0] = m_gridLoc[0][0] + i;
				m_gridLoc[i][1] = m_gridLoc[0][1];
				break;
		 }
	 }
 }
 
 void Tetromino::toggleGridLoc()
 {
	 for(int i = 0; i < 4; i++)
	 {
		 m_gameBoard->toggleCell((m_gridLoc[i][0]),(m_gridLoc[i][1]));
	 }
 }
 
 void Tetromino::funcGravity()
 {
	 /*for(int i = 0; i < 4; i++)
	 {
		 m_gridLoc[i][1]--;
	 }*/
	 
	 m_gridLoc[0][0]--;
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
			m_gridLoc[0][0] -= 1;
			m_gridLoc[0][1] -= 1;
			break;
		case UP:
			m_facing = RIGHT;
			m_gridLoc[0][0] += 2;
			m_gridLoc[0][1] -= 2;
			break;
		case RIGHT:
			m_facing = DOWN;
			m_gridLoc[0][0] += 1;
			m_gridLoc[0][1] += 1;
			break;
		case DOWN:
			m_facing = LEFT;
			m_gridLoc[0][0] -=2;
			m_gridLoc[0][1] +=2;
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
			m_gridLoc[0][0] += 1;
			m_gridLoc[0][1] += 1;
			break;
		case LEFT:
			m_facing = UP;
			m_gridLoc[0][0] -= 2;
			m_gridLoc[0][1] += 2;
			break;
		case DOWN:
			m_facing = RIGHT;
			m_gridLoc[0][0] -= 1;
			m_gridLoc[0][1] -= 1;
			break;
		case RIGHT:
			m_facing = UP;
			m_gridLoc[0][0] +=2;
			m_gridLoc[0][1] -=2;
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
	 ghost.m_gridLoc[0][0] = m_gridLoc[0][0];
	 ghost.m_gridLoc[1][1] = m_gridLoc[1][1];
	 ghost.updateGridLoc();
	 if(clockwise){ghost.rotateClockwise();}
	 else {ghost.rotateCounterClockwise();}
	 ghost.updateGridLoc();
	 
	 for(int i = 0; i < 4; i++)
	 {
		 if(m_gameBoard->cell(ghost.m_gridLoc[i][0],m_gridLoc[i][1]))
		 {
			 return false;
		 }
		 else if(!(23 >= m_gridLoc[i][0] >= 0) || !(9 >= m_gridLoc[i][1] >= 0))
		 {
			 return false;
		 }
	 }
	 return true;
 }