#pragma once

//Adding in additional libraries.
#include <SFML/Graphics.hpp>

#include "InvaderBullets.h"
#include "Player.h"
#include "Barriers.h"

#include <iostream>
#include <map>

using namespace std;
using namespace sf;

class Invaders
{
private:
	//Variables.
	Sprite sprite;
	Clock timer;
	Time elapsedTime;
	Clock shotTimer;
	Time shotElapsedTime;
	int iType;
	int iPoints;
	int iNoOfInvadersAlive;
	float fSpeed;
	bool bMoveRight;
	bool bFrame1;
	//Player player;
	//Barriers barrier;

	//Resources.
	map<String, Texture*> textures;
	vector<InvaderBullets*> vInvaderBullets;

	//Private functions.
	void initTextures();
	void initVariables();
	void setSpeed();
	void invaderShoot();

public:
	//Constructor / destructor.
	Invaders(Texture* texture, float fPosX, float fPosY);

	//Accessors.
	const FloatRect getBounds() const;

	//Functions.
	void updateBullets(Player player, Barriers barrier);
	void update(RenderTarget* target, Player player, Barriers barrier);
	void render(RenderTarget* target);
};