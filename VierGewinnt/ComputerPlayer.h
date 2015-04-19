/*
 * ComputerPlayer.h
 *
 *  Created on: 02.04.2015
 *      Author: Christoph Majcen
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_
#include <string>
#include "Player.h"

class ComputerPlayer : public Player
{
	public:
		ComputerPlayer();
		ComputerPlayer(const std::string &name, const char &color);
		~ComputerPlayer();
		int makeMove(const Board * board) const;
};



#endif /* COMPUTERPLAYER_H_ */
