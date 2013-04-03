/**
 * @file Tetromino.h
 * @brief Define Tetromino class (serves as I block and template for other blocks)
 * @author Chance Rosenthal
 * @todo Implement canRotate()
 */
 #include "GameBoard.h"

 
 class Tetromino
 {
	public: 
		 enum facing
		 {
			 LEFT = 0,
			 UP,
			 RIGHT,
			 DOWN
		 };
		 enum rotateStatus
		 {
			 FALSE = 0,
			 TRUE,
			 BUMP
		 };
		 
		Tetromino(GameBoard* grid);
		
		void updateGridLoc();
		void funcGravity();
		void doGravity();
		void testTetromino();
		void toggleGridLoc();
		bool canRotate(bool); //Not yet implemented
		
		rotateStatus checkClockwise();
		rotateStatus checkCounterClockwise();
		void rotateClockwise();
		void rotateClockwise(int);
		void rotateCounterClockwise();
		void rotateCounterClockwise(int);
		
		void moveLeft(int);
		void moveRight(int);
		
	private:
		facing m_facing;
		GameBoard* m_gameBoard;
		struct gridLocs
		{
			int row, col;
		};
		gridLocs m_gridLocs[4];
 };
 
	inline Tetromino::facing operator++(Tetromino::facing &sub,int)
	{
		Tetromino::facing oldFacing = sub;
		//sub = (Tetromino::facing)(sub + 1);
		//return oldFacing;
		switch(oldFacing)
		{
			case 0:
			case 1:
			case 2:
				sub = (Tetromino::facing)(sub + 1);
				break;
			case 3:
				sub = (Tetromino::facing)(0);
				break;
		}
		return oldFacing;
	}
	
	inline Tetromino::facing operator--(Tetromino::facing &sub,int)
	{	
		Tetromino::facing oldFacing = sub;
		switch(oldFacing)
		{
			case 3:
			case 1:
			case 2:
				sub = (Tetromino::facing)(sub - 1);
				break;
			case 0:
				sub = (Tetromino::facing)(3);
				break;
		}
		return oldFacing;
	}