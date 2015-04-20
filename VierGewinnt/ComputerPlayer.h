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
		ComputerPlayer(int number);
		ComputerPlayer(const char &otherPlayerColor);
		ComputerPlayer(const std::string &name, const char &color, const char &otherPlayerColor);
		~ComputerPlayer();
		int makeMove(const Board * board) const;

	private:
		char otherPlayerColor;
};



#endif /* COMPUTERPLAYER_H_ */
