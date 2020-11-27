//Adding in additional libraries.
#include "../include/Invaders.h"
#include "../include/Variables.h"
#include "../include/SoundEngine.h"

#include <math.h>

//Private functions.
void Invaders::initTextures()
{
	//Loads all the bullet textures.
	this->textures["Bullet"] = new Texture();
	this->textures["Bullet"]->loadFromFile("Textures/Shot_2.png");
}

void Invaders::initVariables()
{
	//Initialises the variables.
	this->iType = 0;
	this->iPoints = 100;
	this->bMoveRight = true;
}

void Invaders::setSpeed()
{
	//Formula for the speed depended on the number of aliens.
	fSpeed = ((-1) * (log(Variables::iNoOfAliens))) + 5;
	//TEST cout << fSpeed << endl;
}

void Invaders::invaderShoot()
{
	//Allows one of the invaders to shot a bullet at a random time.

	//Gets the time since the last shot.
	this->shotElapsedTime = this->shotTimer.getElapsedTime();
	//If the tie is greater than a randomly generated number.
	if (shotElapsedTime.asSeconds() > rand())
	{
		//Gets position of the invader that is shooting.
		float fPosX = this->sprite.getPosition().x;
		float fPosY = this->sprite.getPosition().y;
		//TEST cout << fPosX << " " << fPosY << endl;
		//Creates a bullet by passing in all the required arguments.
		this->vInvaderBullets.push_back(new InvaderBullets(this->textures["Bullet"], fPosX, fPosY, 0.f, 1.f, 5.f));
		//Plays the invader shoot sound effect.
		SoundEngine::playShot();
		//Restarts the timer.
		this->shotTimer.restart();
	}
}

//Constructor.
Invaders::Invaders(Texture* texture, float fPosX, float fPosY)
{
	//Sets up the sprite and calls all the void functions for the start of the game.
	this->initTextures();
	this->sprite.setTexture(*texture);
	this->sprite.setScale(0.375f, 0.375f);
	this->initVariables();
	this->sprite.setPosition(fPosX, fPosY);
}

//Accessors.
const FloatRect Invaders::getBounds() const
{
	//Gets position of the invader.
	return this->sprite.getGlobalBounds();
}

//Functions.
void Invaders::updateBullets(Player player, Barriers barrier)
{
	//Handles the collision between the bullet and the player, culls the bullets if they go offscreen and handles the collision between the bullet and the barriers.

	//Sets the variable.
	unsigned int iCounter = 0;
	//For all the bullets in the vector.
	for (auto* invaderBullet : this->vInvaderBullets)
	{
		//Calls the update function of InvaderBullets.
		invaderBullet->update();
		//For all of the bullets in the vector.
		for (size_t k = 0; k < this->vInvaderBullets.size(); k++)
		{
			//If any of the bullets hit the player.
			if (this->vInvaderBullets[k]->getBounds().intersects(player.getBounds()))
			{
				//TEST cout << player.getBounds().left << " " << player.getBounds().top << endl;
				//Erases the bullet that hit.
				this->vInvaderBullets.erase(this->vInvaderBullets.begin() + k);
				//Calls the isDead function of Player passing in the argument of true.
				player.isDead(true);
				//Decreases the variable.
				Variables::iLives--;
			}
			//If none of the bullets hit the player.
			else
			{
				//Calls the isDead function of Player passing in the argument of false.
				player.isDead(false);
			}
		}

		//Bullet culling at bottom of screen.
		if ((invaderBullet->getBounds().top + invaderBullet->getBounds().height) > 1100.f)
		{
			//Deletes the bullet in the vector.
			delete this->vInvaderBullets.at(iCounter);
			//Erases the bullet at the bottom of the screen.
			this->vInvaderBullets.erase(this->vInvaderBullets.begin() + iCounter);
			//Decreases the variable.
			iCounter--;
			//Check to see if bullets are deleted.
			//TEST cout << this->invaderBullets.size() << endl;
		}
		//Increases the variable.
		iCounter++;

		//For all the bullets in the vector.
		for (size_t k = 0; k < this->vInvaderBullets.size(); k++)
		{
			//If any bullet hits the barrier 1.
			if (this->vInvaderBullets[k]->getBounds().intersects(barrier.getBounds(1)))
			{
				//Plays the barrier hit sound effect.
				SoundEngine::playBarrierHit();
				//Erases the bullet that hit.
				this->vInvaderBullets.erase(this->vInvaderBullets.begin() + k);
				//Calls the barrierHit function of Barriers passing in the argument of 1.
				barrier.barrierHit(1);
			}
			//If any bullet hits the barrier 2.
			else if (this->vInvaderBullets[k]->getBounds().intersects(barrier.getBounds(2)))
			{
				//Plays the barrier hit sound effect.
				SoundEngine::playBarrierHit();
				//Erases the bullet that hit.
				this->vInvaderBullets.erase(this->vInvaderBullets.begin() + k);
				//Calls the barrierHit function of Barriers passing in the argument of 2.
				barrier.barrierHit(2);
			}
			//If any bullet hits the barrier 3.
			else if (this->vInvaderBullets[k]->getBounds().intersects(barrier.getBounds(3)))
			{
				//Plays the barrier hit sound effect.
				SoundEngine::playBarrierHit();
				//Erases the bullet that hit.
				this->vInvaderBullets.erase(this->vInvaderBullets.begin() + k);
				//Calls the barrierHit function of Barriers passing in the argument of 3.
				barrier.barrierHit(3);
			}
			//If any bullet hits the barrier 4.
			else if (this->vInvaderBullets[k]->getBounds().intersects(barrier.getBounds(4)))
			{
				//Plays the barrier hit sound effect.
				SoundEngine::playBarrierHit();
				//Erases the bullet that hit.
				this->vInvaderBullets.erase(this->vInvaderBullets.begin() + k);
				//Calls the barrierHit function of Barriers passing in the argument of 4.
				barrier.barrierHit(4);
			}
		}
	}
}

void Invaders::update(RenderTarget* target, Player player, Barriers barrier)
{
	//Updates the invader.

	//Calls the void function to set speed.
	this->setSpeed();

	//Doesn't allow the invaders to go off the edge of screen.
	//Gets the invaders position.
	FloatRect InvadersBounds = this->sprite.getGlobalBounds();
	//Left bound collision.
	if (InvadersBounds.left <= 0.f)
	{
		//Sets the new position of the invader.
		this->sprite.setPosition(0.f, InvadersBounds.top + 37.5f);
		//Sets the Boolean to true.
		bMoveRight = true;
	}
	//Right bound collision.
	else if ((InvadersBounds.left + InvadersBounds.width) >= target->getSize().x)
	{
		//Sets the new position of the invader.
		this->sprite.setPosition((target->getSize().x - InvadersBounds.width), InvadersBounds.top + 37.5f);
		//Sets the Boolean to false.
		bMoveRight = false;
	}

	//If the invader is moving right.
	if (bMoveRight)
	{
		//Moves the invader.
		this->sprite.move(fSpeed, 0.f);
	}
	//If the invader is moving left.
	else if (!bMoveRight)
	{
		//Moves the invader.
		this->sprite.move(-fSpeed, 0.f);
	}
	//Calls the void functions to shoot and update the bullets.
	this->invaderShoot();
	this->updateBullets(player, barrier);
}

void Invaders::render(RenderTarget* target)
{
	//Draws the invader.
	target->draw(this->sprite);
	//Renders invaders bullets.
	for (auto* invaderBullet : this->vInvaderBullets)
	{
		invaderBullet->render(target);
	}
}