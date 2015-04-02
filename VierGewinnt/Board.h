/*
 * Board.h
 *
 *  Created on: 01.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */
#include "Player.h"

#ifndef BOARD_H_
#define BOARD_H_

class Board
{
public:
	void setStone(int selectedColumn, Player* active);
	const void showBoard();
	Board();
	~Board();

private:
	const bool checkWon(int lastStoneRow,int lastStoneColumn,Player* active);
	const bool checkFull();
	const static int width;
	const static int height;
	char ** field;
	void resetBoard();
};

#endif /* BOARD_H_ */
