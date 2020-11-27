//Adding in additional libraries.
#include "../include/Player.h"
#include "../include/SoundEngine.h"

#include <iostream>

//Private functions.
void Player::initVariables()
{
	//Setting all variables.
	this->fSpeed = 5.f;
	this->fShotMax = 1.f;
	this->fCooldown = this->fShotMax;
}

void Player::initTexture()
{
	//Loading all the textures for the ship and giving them names to point back to. 

	//Ship
	this->textures["Ship"] = new Texture();
	this->textures["Ship"]->loadFromFile("Textures/Ship.png");

	//Explosion.
	this->textures["Explosion"] = new Texture();
	this->textures["Explosion"]->loadFromFile("Textures/Ship_Explosion.png");
}

void Player::initSprite()
{
	//Setting up the sprites of the ship.

	//Sets a texture to the sprite.
	this->sprite.setTexture(*textures["Ship"]);

	//Resize Sprite.
	this->sprite.scale(0.375f, 0.375f);

	//Setting position of sprite.
	this->sprite.setPosition(Vector2f(500, 900));
}

//Constructor.
Player::Player()
{
	//Calls all the set up void functions for start of game.
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

//Accessors.
const Vector2f& Player::getPos() const
{
	//Returns the position of the player.
	return this->sprite.getPosition();
}

const FloatRect Player::getBounds() const
{
	//Returns the bounding box of player.
	return this->sprite.getGlobalBounds();
}

//Functions.
void Player::updateInputs()
{
	//Calls the move function in response to the inputs.
	//Left.
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		//Calls the move function of Player passing in the arguments -1.f and 0.
		move(-1.f, 0);
	}
	//Right.
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		//Calls the move function of Player passing in the arguments 1.f and 0.
		move(1.f, 0);
	}
}

void Player::move(const float kfDirX, const float kfDirY)
{
	//Moves the player in the direction it is given.
	this->sprite.move(this->fSpeed * kfDirX, 0);
}

bool Player::bCanAttack()
{
	//Allows the player to shoot.

	//Gets the time since last shot.
	this->attackElapsedTime = this->attackTimer.getElapsedTime();
	//If the variable fCooldown is less than or equal to the variable fShotMax.
	if (this->fCooldown <= this->fShotMax)
	{
		//Increase the variable.
		this->fCooldown += 1.f;
		//TEST cout << "True" << endl;
		//Returns true.
		return true;
	}
	//If it is more than the variable.
	else
	{
		//If the timer is greater than a second.
		if (this->attackElapsedTime.asSeconds() > 1.0f)
		{
			//Sets the variable.
			this->fCooldown = 0.f;
			//Resets the timer.
			this->attackTimer.restart();
		}
		//TEST cout << "False" << endl;
		//Returns false.
		return false;
	}
}

void Player::updateAttack()
{
	//Allows a max number of shots.
	if (this->fCooldown < this->fShotMax)
	{
		//Increases the cooldown timer.
		this->fCooldown += 1.f;
	}
}

void Player::isDead(bool bDead)
{
	//If Boolean value is true.
	if (bDead)
	{
		//TEST cout << "IsDead is happening" << endl;
		//Plays player dead sound effect.
		SoundEngine::playPlayerExplosion();
		//Set the new position.
		sprite.setPosition(500.f, 900.f);
	}
}

void Player::updateWindowBoundsCollision(const RenderTarget* target)
{
	//Doesn't allow the player to go off the edge of screen.

	//Sets the variable.
	FloatRect GunshipBounds = this->sprite.getGlobalBounds();
	//Left bound collision.
	if (GunshipBounds.left <= 0.f)
	{
		//Sets the new position.
		this->sprite.setPosition(0.f, GunshipBounds.top);
	}
	//Right bound collision.
	else if ((GunshipBounds.left + GunshipBounds.width) >= target->getSize().x)
	{
		//Sets the new position.
		this->sprite.setPosition((target->getSize().x - GunshipBounds.width), GunshipBounds.top);
	}
}

void Player::update(const RenderTarget* target)
{
	//Updates the player by calling all the update functions.
	this->updateWindowBoundsCollision(target);
	this->updateAttack();
}

void Player::render(RenderTarget& target)
{
	//Draws the player.
	target.draw(this->sprite);
}