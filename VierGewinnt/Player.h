/*
 * Player.h
 *
 *  Created on: 02.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "board.h"

class Player {
public:
	Player(const std::string &name, const char &color);
	virtual ~Player();
	std::string getName() const;
	void win();
	virtual int makeMove(const Board * board) const = 0;
	char getColor() const;
private:
	std::string name;
	int winCount;
	char playerColor;

};

#endif /* PLAYER_H_ */
