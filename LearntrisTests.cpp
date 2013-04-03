#include "LearntrisTests.h"
#include <iostream>
#include <iomanip>

using namespace std;

ConsoleMenu::ConsoleMenu(){}

void ConsoleMenu::printMenu()
{
	cout << "Please select from the following:\n";
	cout << left << "(1) Initialize Tetromino (2) Drop Tetromino\n";
	cout << left << "(3) Rotate clockwise (4) Rotate counterclockwise\n";
	cout << left << "(5) rotateStatus cwise (6) rotateStatus ccwise\n";
	cout << left << "(7) Move left (8) Move right\n";
	cout << left << "(Q)uit\n";
	cout << "Enter your selection: ";
}

void ConsoleMenu::loopMenu(GameBoard &gameBoard, Tetromino &tetromino)
{
	char userInput = ' ';
	bool continueLoop = true;
	while(continueLoop)
	{
		gameBoard.printBoard();
		printMenu();
		cin >> userInput;
		
		switch(userInput)
		{
			case '2':
				tetromino.doGravity();
				break;
			case '3':
				tetromino.rotateClockwise();
				break;
			case '4':
				tetromino.rotateCounterClockwise();
				break;
			case '5':
				cout << "checkClockwise returned: " << tetromino.checkClockwise() << endl;
				break;
			case '6':
				cout << "checkCounterClockwise returned: " << tetromino.checkCounterClockwise() << endl;
				break;
			case '7':
				tetromino.moveLeft(1);
				break;
			case '8':
				tetromino.moveRight(1);
				break;
			case 'Q':
			case 'q':
				continueLoop = false;
				break;
		}
	}
}