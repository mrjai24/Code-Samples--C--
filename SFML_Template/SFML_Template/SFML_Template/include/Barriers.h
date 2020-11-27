#pragma once

//Adding in additional libraries.
#include <SFML/Graphics.hpp>

#include "InvaderBullets.h"
#include "Player.h"

#include <iostream>
#include <map>

using namespace std;
using namespace sf;

class Barriers
{
private:
	//Variables.
	Sprite barrier1;
	Sprite barrier2;
	Sprite barrier3;
	Sprite barrier4;
	int iNoOfHitsMax;
	int iNoOfHitsBarrier1;
	int iNoOfHitsBarrier2;
	int iNoOfHitsBarrier3;
	int iNoOfHitsBarrier4;

	//Resources.
	map<String, Texture*> textures;

	//Private functions.
	void initTextures();
	void initVariables();
	void initBarriers();

public:
	//Constructor.
	Barriers();

	//Accessors.
	const FloatRect getBounds(int iBarrierNo) const;

	//Functions.
	void barrierHit(int iBarrierNo);
	void update(RenderTarget* target);
	void render(RenderTarget& target);
};