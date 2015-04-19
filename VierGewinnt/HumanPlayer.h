/*
 * HumanPlayer.h
 *
 *  Created on: 02.04.2015
 *      Author: Christoph Majcen
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
		int makeMove(const Board * board) const;
};




#endif /* HUMANPLAYER_H_ */
