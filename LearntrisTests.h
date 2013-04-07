/**
 * @file LearntrisTests.h
 * @brief Defines console test environment for Learntris source
 * */

#include "Tetromino.h"
#include <map>
#include <string>

class ConsoleMenu{
public:
	ConsoleMenu();

	void menuContents();
	void printMenu();
	void loopMenu(GameBoard&, Tetromino&);
	
private:
	std::map<char,std::string> m_MenuItems;
};