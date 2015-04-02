/*
 * Board.h
 *
 *  Created on: 01.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */


#ifndef BOARD_H_
#define BOARD_H_

#include "Player.h"

class Board
{
public:
	bool setStone(int selectedColumn, Player * active);
	const void showBoard();
	Board();
	Board(int height,int width);
	~Board();

private:
	const bool checkWon(int lastStoneRow,int lastStoneColumn,Player * active);
	const bool checkFull();
	int width;
	int height;
	char * field;
	void resetBoard();
};

#endif /* BOARD_H_ */
