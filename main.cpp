#include <stdio.h>
#include <iostream>
//#include "GameBoard.h"
#include "LearntrisTests.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "Initializing game board." << endl;
	GameBoard gameBoard;
	gameBoard.printBoard();
	
	cout << endl << endl << "Initializing Tetromino.\n";
	Tetromino tester(&gameBoard);
	
	ConsoleMenu menu;
	menu.loopMenu(gameBoard,tester);
	
	/*gameBoard.printBoard();
	
	cout << endl << "Doing gravity." << endl;
	tester.doGravity();
	gameBoard.printBoard();
	
	cout << endl << "Rotating clockwise four times." << endl;
	for(int i = 0; i < 4; i++)
	{
		tester.rotateClockwise();
		gameBoard.printBoard();
	}
	cout << endl << "Rotating counterclockwise four times." << endl;
	for(int i = 0; i < 4; i++)
	{
		tester.rotateCounterClockwise();
		gameBoard.printBoard();
	}
	Tetromino::facing thisFacing = (Tetromino::LEFT);
	for(int i = 0; i < 5; i++)
	{
		cout << "thisFacing: " << thisFacing << endl;
		thisFacing--;
	}
	gameBoard.toggleCell(5,5,true);
	gameBoard.printBoard();
	gameBoard.toggleCell(5,5,false);
	gameBoard.printBoard();
	*/
	return 0;
}
