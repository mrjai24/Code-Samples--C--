//Used as interface.

#pragma once

class Player;

class Variables
{
public:
	//Static variables that the whole program can share and use.
	static const int kiNoOfAliensAtStart = 55;
	static int iNoOfAliens;
	static unsigned int iLives;
	Player* player = new Player();
};