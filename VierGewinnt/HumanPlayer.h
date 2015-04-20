/*
 * HumanPlayer.h
 *
 *  Created on: 02.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include <string>
#include "Player.h"

class HumanPlayer : public Player
{
	public:
		HumanPlayer(const std::string &name, const char &color);
		~HumanPlayer();
		int makeMove(Board * board) const;
};




#endif /* HUMANPLAYER_H_ */
