/*
 * HumanPlayer.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Christoph Majcen
 */
#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(const string &name, const char &color) : Player(name, color)
{}


int HumanPlayer::makeMove(const Board * &board) const
{
	int column;
	cout << "Where do you want to throw your piece in, " << name << "?" << endl;
	cin >> column;
	return column;

}

HumanPlayer::~HumanPlayer()
{}

