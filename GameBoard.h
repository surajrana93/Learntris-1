/**
 * @file GameBoard.h
 * @brief Defines class GameBoard, representing the playing field
 * @author Chance Rosenthal
 * */
 
 class GameBoard {
	//friend Tetromino;
	public:
		struct BoardCell { //Represents a single cell on the game board
			enum color {
				BLUE,
				CYAN,
				GREEN,
				YELLOW,
				ORANGE,
				RED
			};
			
			bool state; //True if the cell is occupied, false if it's open
		};
	
		GameBoard();
		
		void toggleCell(int,int);
		void toggleCell(int,int,bool);
		int returnHeight();
		int returnWidth();
		bool cell(int,int);
		
	/*
	 * Diagnostic functions, located in GameBoardDiag.cpp
	 * */
		
		void printBoard();

	protected:
		
	private:
		const static int m_height = 22;
		const static int m_width = 11;
		BoardCell m_grid[m_height][m_width];
 };