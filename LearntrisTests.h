#include "Tetromino.h"

class ConsoleMenu{
public:
	ConsoleMenu();

	void printMenu();
	void loopMenu(GameBoard&, Tetromino&);
};