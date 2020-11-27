#pragma once

//Adding in additional libraries.
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

using namespace std;
using namespace sf;

class Bullet
{
private:
	//Variables.
	Sprite sprite;
	Vector2f direction;
	float fBulletSpeed;

public:
	//Constructor.
	Bullet(Texture* texture, float fPosX, float fPosY, float fDirX, float fDirY, float fSpeed);

	//Accessors.
	const FloatRect getBounds() const;

	//Functions.
	void update();
	void render(RenderTarget* target);
};