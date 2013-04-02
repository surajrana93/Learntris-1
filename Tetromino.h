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
		Tetromino(GameBoard* grid);
		~Tetromino();
		
		void updateGridLoc();
		void funcGravity();
		void doGravity();
		void testTetromino();
		void toggleGridLoc();
		bool canRotate(bool); //Not yet implemented
		
		void rotateClockwise();
		void rotateCounterClockwise();
		
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
		sub = (Tetromino::facing)(sub + 1);
		return oldFacing;
	}
	
	inline Tetromino::facing operator--(Tetromino::facing &sub,int)
	{
		Tetromino::facing oldFacing = sub;
		sub = (Tetromino::facing)(sub - 1);
		return oldFacing;
	}