/*
 * HumanPlayer.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */
#include <iostream>
#include "HumanPlayer.h"
#include "Board.h"
using namespace std;

HumanPlayer::HumanPlayer(const string &name, const char &color) : Player(name, color)
{}


int HumanPlayer::makeMove(Board * board) const
{
	int column;
	cout << "Where do you want to throw your piece in, " << name << "?" << endl;
	cin >> column;

	column--; //IT guys count from 0 instead from 1

	while(!(board->checkMove(column)))
	{
		cout << "Move not possible! Where do you want to throw your piece in, " << name << "?" << endl;
		cin >> column;
		column--;
	}
	return column;

}

HumanPlayer::~HumanPlayer()
{}

