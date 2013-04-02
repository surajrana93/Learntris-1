/**
 * @file GameBoard.h
 * @brief Defines class GameBoard, representing the playing field
 * @author Chance Rosenthal
 * */
 
 class GameBoard {
	//friend Tetromino;
	public:
		GameBoard();
		~GameBoard();
		
		void toggleCell(int,int);
		void toggleCell(int,int,bool);
		bool cell(int,int);
		
	/*
	 * Diagnostic functions, located in GameBoardDiag.cpp
	 * */
		
		void printBoard();

	protected:
		
	private:
		bool m_grid[24][10];
 };


