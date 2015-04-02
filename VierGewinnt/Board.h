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
	void const showBoard();
	Board();
	~Board();

private:
    bool const checkWon(int lastStoneRow,int lastStoneColumn,Player* active);
    bool const checkFull();
	static const int width;
	static const int height;
	char ** field;
	void resetBoard();
};

#endif /* BOARD_H_ */
