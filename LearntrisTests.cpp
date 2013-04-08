/**
 * @file LearntrisTests.cpp
 * @brief Implements console test environment for Learntris source
 * */

#include "LearntrisTests.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

ConsoleMenu::ConsoleMenu(){

	m_MenuItems['0'] = "Please select from the following:";
	m_MenuItems['1'] = "Initialize Tetromino";
	m_MenuItems.insert(std::pair<char,string>('2',"Drop Tetromino"));
	m_MenuItems.insert(pair<char,string>('3',"Rotate clockwise"));
	m_MenuItems.insert(pair<char,string>('4',"Rotate counterclockwise"));
	m_MenuItems.insert(pair<char,string>('5',"rotateStatus cwise"));
	m_MenuItems.insert(pair<char,string>('6',"rotateStatus ccwise"));
	m_MenuItems.insert(pair<char,string>('7',"Move left"));
	m_MenuItems.insert(pair<char,string>('8',"Move right"));
	m_MenuItems.insert(pair<char,string>('9',"Wall bump clockwise"));
	m_MenuItems.insert(pair<char,string>('A',"Wall bump counterclockwise"));
	m_MenuItems.insert(pair<char,string>('B',"Print inBounds()"));
	m_MenuItems.insert(pair<char,string>('Q',"Quit"));	
}

void ConsoleMenu::printMenu()
{
	std::map<char,string>::iterator MapIterator;
	bool odd = 0;
	bool zero = 1;
	for(MapIterator = m_MenuItems.begin(); MapIterator != m_MenuItems.end(); ++MapIterator)
	{
		string thisString = "(" + string(&MapIterator->first) + ") " + MapIterator->second;
		
		if(zero)
		{
			cout << MapIterator->second << endl;
			zero = 0;
		}
		else if(odd)
		{
			cout << left << setw(30) << thisString;
		}
		else
		{
			cout << setw(5) << right << "" << thisString << endl;
		}
		odd = !odd;
	}
	
	cout << "\nEnter your selection: ";
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
			case '9':
				tetromino.wallBumpClockwise();
				break;
			case 'A':
			case 'a':
				tetromino.wallBumpCounterClockwise();
				break;
			case 'B':
			case 'b':
				for(int i = 0; i < 4; i++)
				{
					cout << "Tetromino::m_gridLocs[" << i << "].col: " << tetromino.returnGridLocs(i,false) << endl;
				}
				cout << "Tetromino::inBounds(): " << tetromino.inBounds() << endl;
				break;
			case 'Q':
			case 'q':
				continueLoop = false;
				break;
			default:
				cout << "Invalid input.\n";
				break;
		}
	}
}