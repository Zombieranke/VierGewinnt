/*
 * ComputerPlayer.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Christine
 */
#include "ComputerPlayer.h"
using namespace std;

ComputerPlayer::ComputerPlayer()
{
	//do something
}

ComputerPlayer::ComputerPlayer(const string &name, const char &color) : Player(name, color)
{}


int ComputerPlayer::makeMove(const Board * board) const
{
	//do something
	return 0;
}

ComputerPlayer::~ComputerPlayer()
{}


