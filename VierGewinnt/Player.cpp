/*
 * Player.cpp
 *
 *  Created on: 02.04.2015
 *      Author: Arthur Bouz
 *      		Christoph Majcen
 */

#include "Player.h"
using namespace std;

Player::Player(const string &name, const char &color)
{
	playerColor = color;
	this->name = name;
	winCount = 0;
}

string Player::getName() const
{
	return name;
}

char Player::getColor() const
{
	return playerColor;
}

void Player::win()
{
	winCount++;
}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

