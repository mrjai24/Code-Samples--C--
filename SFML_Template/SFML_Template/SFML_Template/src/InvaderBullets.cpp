//Adding in additional libraries.
#include "../include/InvaderBullets.h"

//Constructor.
InvaderBullets::InvaderBullets(Texture* texture, float fPosX, float fPosY, float fDirX, float fDirY, float fSpeed)
{
	//Setting textures and variables.
	this->sprite.setTexture(*texture);
	this->sprite.setScale(0.375f, 0.5f);
	this->sprite.setPosition(fPosX, fPosY);
	this->direction.x = fDirX;
	this->direction.y = fDirY;
	this->fBulletSpeed = fSpeed;
}

//Accessors.
const FloatRect InvaderBullets::getBounds() const
{
	//Gets position of bullet.
	return this->sprite.getGlobalBounds();
}

//Functions.
void InvaderBullets::update()
{
	//Movement of the bullets.
	this->sprite.move(this->fBulletSpeed * this->direction);
	//TEST cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
}

void InvaderBullets::render(RenderTarget* target)
{
	//Draws the invaders bullets to the screen.
	target->draw(this->sprite);
}