//Adding in additional libraries.
#include "../include/Bullet.h"

//Constructor.
Bullet::Bullet(Texture* texture, float fPosX, float fPosY, float fDirX, float fDirY, float fSpeed)
{
	//Setting textures and variables from the passed in arguments.
	this->sprite.setTexture(*texture);
	this->sprite.setScale(0.375f, 0.5f);
	this->sprite.setPosition(fPosX, fPosY);
	this->direction.x = fDirX;
	this->direction.y = fDirY;
	this->fBulletSpeed = fSpeed;
}

//Accessors.
const FloatRect Bullet::getBounds() const
{
	//Gets position of bullet.
	return this->sprite.getGlobalBounds();
}

//Functions.
void Bullet::update()
{
	//Moves the bullets.
	this->sprite.move(this->fBulletSpeed * this->direction);
	//cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
}

void Bullet::render(RenderTarget* target)
{
	//Draws the bullets to the screen.
	target->draw(this->sprite);
}