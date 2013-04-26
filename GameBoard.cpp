/**
 * @file GameBoard.cpp
 * @brief Implements class GameBoard
 * @author Chance Rosenthal
 * */

#include "GameBoard.h"

using namespace std;

/**
 * @brief Initializes GameBoard object. grid[][] toggled to {false}-equivalent state.
 * */

GameBoard::GameBoard()
{
	for(int rows = m_height; rows >= 0; rows--)
	{
		for(int cols = 0; cols < m_width; cols++)
			m_grid[rows][cols].state = false;
	}
	m_workingColor = RED;
}

int GameBoard::returnHeight()
{
	return m_height;
}

int GameBoard::returnWidth()
{
	return m_width;
}
/**
 * @brief Toggles specified cell
 * @param row Row of cell to toggle
 * @param col Column of cell to toggle
 * */

void GameBoard::toggleCell(int row,int col,color i_color)
{
	m_grid[row][col].state = !m_grid[row][col].state;
	m_grid[row][col].cellColor = i_color;
}

/**
 * @overload void GameBoard::toggleCell(int row,int col,bool state)
 * @param state Target state: cell open (false) or occupied (true)
 * */
 
void GameBoard::toggleCell(int row,int col,bool state,color i_color)
{
	m_grid[row][col].state = state;
	m_grid[row][col].cellColor = i_color;
}

/**
 * @brief Returns true if cell is occupied and false if it's free
 * @param row Row of cell
 * @param col Column of cell
 * */
bool GameBoard::cell(int row,int col)
{
	return m_grid[row][col].state;
}

void GameBoard::setColor(color Color)
{
	m_workingColor = Color;
}

color GameBoard::cellColor(int rows,int cols)
{
	return m_grid[rows][cols].cellColor;
}