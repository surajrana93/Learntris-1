#include <stdio.h>
#include <iostream>
//#include "GameBoard.h"
#include "Tetromino.h"

using namespace std;

int main(int argc, char **argv)
{
	GameBoard gameBoard;
	gameBoard.printBoard();
	cout << endl << endl << "Initializing Tetromino.\n";
	Tetromino tester(&gameBoard);
	cout << endl << "Status of cell (22,5): " << gameBoard.cell(22,5) << endl;
	gameBoard.printBoard();
	cout << endl << "Doing gravity." << endl;
	tester.doGravity();
	gameBoard.printBoard();
	cout << endl << "Rotating clockwise." << endl;
	tester.rotateClockwise();
	gameBoard.printBoard();
	
	/*gameBoard.toggleCell(5,5,true);
	gameBoard.printBoard();
	gameBoard.toggleCell(5,5,false);
	gameBoard.printBoard();
	*/
	return 0;
}
