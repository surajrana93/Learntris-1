/**
 * @file GameBoardDiag.cpp
 * @brief Diag functions for class GameBoard
 * @author Chance Rosenthal
 * */

#include <iostream>
#include <iomanip>
#include "GameBoard.h"

using namespace std;

/**
 * Production function. Prints grid state to console. Used for testing new motion functionality.
 * */

void GameBoard::printBoard()
{
	//Print column labels
	cout << setw(5) << "";
	for(int i = 0; i < 10; i++){cout << " " << i << " ";}
	cout << endl;
	cout << "---|";
	cout << setfill('-') << setw(33) << '|' << endl;
	cout << setfill(' ');
	//For each row and each column, print contents.
	//Print extra rows below rows 23-22 and 21-20.
	//These identify where Tetronimos spawn (horizontally) and where they wait their turn.
	for(int rows = 23; rows >= 0; rows--)
	{
		if(rows ==  21 || rows == 19)
		{
			cout << "---|";
			cout << setfill('-') << setw(33) << '|' << endl;
			cout << setfill(' ');
		}
		cout << setw(2) << rows <<" | ";
		for(int cols = 0; cols < 10; cols++)
		{
			if(m_grid[rows][cols])
			{
				cout << " X ";
			}
			else cout << " 0 ";
		}
		cout << " |\n";
	}
}