/**
 * @file GameBoard.h
 * @brief Defines class GameBoard, representing the playing field
 * @author Chance Rosenthal
 * */

 enum color {
	BLUE,
	CYAN,
	GREEN,
	YELLOW,
	ORANGE,
	RED,
	EMPTY
 };
 
 class GameBoard {
	//friend Tetromino;
	public:
		struct BoardCell { //Represents a single cell on the game board
			color cellColor;
			bool state; //True if the cell is occupied, false if it's open
		};
	
		GameBoard();
		
		void toggleCell(int,int,color);
		void toggleCell(int,int,bool,color);
		
		
		int returnHeight();
		int returnWidth();
		
		
		bool cell(int,int);
		
		void rowClear(int);
		void checkLines();
		
		void setColor(color);
		color cellColor(int,int);
		
		void tetroCycle();
		
	/*
	 * Diagnostic functions, located in GameBoardDiag.cpp
	 * */
		
		void printBoard();

		int m_prevLinesCleared;

	protected:
		
	private:
		const static int m_height = 22;
		const static int m_width = 11;
		color m_workingColor;
		BoardCell m_grid[m_height][m_width];
 };