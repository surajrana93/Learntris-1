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
		bool cell(int,int);
		
	/*
	 * Diagnostic functions, located in GameBoardDiag.cpp
	 * */
		
		void printBoard();

	protected:
		
	private:
		BoardCell m_grid[22][10];
 };