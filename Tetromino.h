/**
 * @file Tetromino.h
 * @brief Define Tetromino class (serves as I block and template for other blocks)
 */
 #include "GameBoard.h"

 
 class Tetromino
 {
	public: 
		 enum facing //Tetromino's facing direction, used by location functions
		 {
			 LEFT = 0,
			 UP,
			 RIGHT,
			 DOWN
		 };
		 
/**
 * @brief Enumerated type contains possible results of an attempted rotation:
 *        unsuccessful, successful, or trigger a wall bump.
 * */
		 enum rotateStatus
		 {
			 FALSE = 0,
			 TRUE,
			 BUMP
		 };
		 
		Tetromino(GameBoard* grid);
		Tetromino(GameBoard* grid,int,int,facing);
		
		void updateGridLoc();
		
		void funcGravity();
		void doGravity();
		bool canGravity();
		
		void testTetromino();
		void toggleGridLoc();
		
		bool inBounds();
		rotateStatus checkClockwise();
		rotateStatus checkCounterClockwise();
		void rotateClockwise();
		void rotateClockwise(int);
		void rotateCounterClockwise();
		void rotateCounterClockwise(int);
		void wallBumpClockwise();
		void wallBumpCounterClockwise();
		
		void moveLeft(int);
		void moveRight(int);
		void moveLeft(int,bool);
		void moveRight(int,bool);
		bool canMoveLeft(int);
		bool canMoveRight(int);
		
		int returnGridLocs(int,bool);
		
	private:
		facing m_facing;
		GameBoard* m_gameBoard;
		struct gridLocs
		{
			int row, col;
		};
		gridLocs m_gridLocs[4];
		const static color m_color = CYAN;
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