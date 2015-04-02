/*
 * Player.h
 *
 *  Created on: 02.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#ifndef PLAYER_H_
#define PLAYER_H_


/*  HALLO STOFFL! PLAYER BRAUCHEN FOLGENDE VARIABLEN (AUF JEDEN FALL DIESE - VIELLEICHT AUCH MEHR):
 * 				O name
 * 				O color
 * 				O winCount
 */

#include <string>

class Player {
public:
	Player();
	virtual ~Player();
	std::string getName() const;
	void win();
	void lose();
private:
	std::string name;
	int lossCount;
	int winCount;
	char playerColor;

};

#endif /* PLAYER_H_ */
