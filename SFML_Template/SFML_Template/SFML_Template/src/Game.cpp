//Adding in additional libraries.
#include "../include/Game.h"
#include "../include/Variables.h"

#include <string>

//Getting variables from Variables.h.
const int Variables::kiNoOfAliensAtStart;
int Variables::iNoOfAliens;
unsigned int Variables::iLives = 3;

//Private functions
void Game::initWindow()
{
	//Creating the window and setting it up.
	this->window = new RenderWindow(VideoMode(1000, 1000), "Space Invaders!", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);

	//Starts the backgound music.
	SoundEngine::playBackgroundScreen();
}

void Game::initTextures()
{
	//Loads all textures.

	//Bullets.
	this->textures["BULLET"] = new Texture();
	this->textures["BULLET"]->loadFromFile("Textures/Shot_3.png");

	//Invaders.
	//Crab.
	this->textures["CrabF1"] = new Texture();
	this->textures["CrabF1"]->loadFromFile("Textures/Crab_Frame_1.png");
	//Squid.
	this->textures["SquidF1"] = new Texture();
	this->textures["SquidF1"]->loadFromFile("Textures/Squid_Frame_1.png");
	//Octopus.
	this->textures["OctopusF1"] = new Texture();
	this->textures["OctopusF1"]->loadFromFile("Textures/Octopus_Frame_1.png");
}

void Game::initGUI()
{
	//Sets up the GUI.

	//Load font.
	this->font.loadFromFile("Fonts/space_invaders.ttf"); //Font downloaded from:https://fontsmagazine.com/ for free.
	//Initialises point text.
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(12);
	this->pointText.setFillColor(Color::White);
	this->pointText.setString("Lives: 3");
	this->pointText.setPosition(Vector2f(10, 950));
}

void Game::initPlayer()
{
	//Creates the player.
	this->player = new Player();
}

void Game::initInvaders()
{
	//Initialises the variables.
	this->fSpawnTimerMax = 55.f;
	this->fSpawnTimer = 0.f;
}

void Game::initBarriers()
{
	//Creates the barriers.
	this->barrier = new Barriers();
}

void Game::spawnInvaders()
{
	//Spawns the invaders if there are no more than 55 invaders.
	if (this->fSpawnTimer < this->fSpawnTimerMax)
	{
		for (int iY = 0; iY < 5; iY++)
		{
			for (int iX = 0; iX < 11; iX++)
			{
				//Spawns them from the top row to the bottom row.
				//Sets the variables and the position of the aliens.
				this->fSpawnTimer += 1.f;
				float fInvaderX = 25 + (iX * 56.25f);
				float fInvaderY = 25 + (iY * 75);
				//Creates the aliens in the vector and sets the texture that will be different depending on their row.
				switch (iY)
				{
				case 0:
					this->vInvaders.push_back(new Invaders(this->textures["SquidF1"], fInvaderX, fInvaderY));
					break;
				case 1:
					this->vInvaders.push_back(new Invaders(this->textures["OctopusF1"], fInvaderX, fInvaderY));
					break;
				case 2:
					this->vInvaders.push_back(new Invaders(this->textures["OctopusF1"], fInvaderX, fInvaderY));
					break;
				case 3:
					this->vInvaders.push_back(new Invaders(this->textures["CrabF1"], fInvaderX, fInvaderY));
					break;
				case 4:
					this->vInvaders.push_back(new Invaders(this->textures["CrabF1"], fInvaderX, fInvaderY));
					break;
				}
			}
		}
		//Sets the variables to 55.
		Variables::iNoOfAliens = Variables::kiNoOfAliensAtStart;
		//TEST cout << fSpawnTimer << endl;
	}
}

//Constructor.
Game::Game()
{
	//Calls the void functions to set up the start of the game.
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initPlayer();
	this->initInvaders();
	this->initBarriers();
	this->spawnInvaders();
}

//Destructor.
Game::~Game()
{
	//Deletes the objects to keep from memory leaks and keep the program stable.

	//Deletes the window.
	delete this->window;
	//Deletes the player.
	delete this->player;
	//Deletes the barriers.
	delete this->barrier;
	//Deletes the textures.
	for (auto i : this->textures)
	{
		delete i.second;
	}
	//Deletes the bullets.
	for (auto* i : this->vBullets)
	{
		delete i;
	}
	//Deletes the invaders.
	for (auto* i : this->vInvaders)
	{
		delete i;
	}
	//Deletes the invader bullets.
	for (auto* i : this->vInvaderBullets)
	{
		delete i;
	}
}

//Functions
void Game::run()
{
	//Game Loop works only if work is open.
	while (this->window->isOpen())
	{
		//Works only if the Boolean value is false.
		while (!bGameOver)
		{
			//Updates and renders each frame by calling the subroutine.
			this->update();
			this->render();
		}
		//Stops the background music if the game is over and allows the window to close.
		if (bGameOver)
		{
			SoundEngine::stopBackgroundScreen();
			this->updatePollEvents();
		}
	}
}

void Game::gameOver()
{
	//If the game is over this checks how.

	//If the player loses if all their lives have gone.
	if (Variables::iLives == 0)
	{
		//Clears window and sets the text for lose screen.
		window->clear();
		gameOverText.setString("GAME OVER! YOU LOSE!");
		gameOverText.setFillColor(Color::Red);
		gameOverText.setFont(this->font);
		gameOverText.setCharacterSize(50);
		gameOverText.setPosition(Vector2f(200, 400));
		//Sets the Boolean value to true.
		bGameOver = true;
	}
	//If the player loses if any of the invaders touch the player.
	for (int i = 0; i < this->vInvaders.size(); i++)
	{
		if (this->vInvaders[i]->getBounds().intersects(this->player->getBounds()))
		{
			//Plays all the sound.
			SoundEngine::playPlayerExplosion();
			SoundEngine::playInvaderKilled();
			//Clears window and sets the text for lose screen.
			window->clear();
			gameOverText.setString("GAME OVER! YOU LOSE!");
			gameOverText.setFillColor(Color::Red);
			gameOverText.setFont(this->font);
			gameOverText.setCharacterSize(50);
			gameOverText.setPosition(Vector2f(200, 400));
			//Sets the Boolean value to true.
			bGameOver = true;
		}
	}

	//If the player wins.
	if (Variables::iNoOfAliens == 0)
	{
		//Clears window and sets the text for win screen.
		window->clear();
		gameOverText.setString("GAME OVER! YOU WON!");
		gameOverText.setFillColor(Color::Green);
		gameOverText.setFont(this->font);
		gameOverText.setCharacterSize(50);
		gameOverText.setPosition(Vector2f(200, 400));
		//Sets the Boolean value to true.
		bGameOver = true;
	}
}

void Game::updatePollEvents()
{
	//Allows the program to get the players inputs and close the window.

	Event input;
	while (this->window->pollEvent(input))
	{
		//Closes window.
		if (input.Event::type == Event::Closed)
		{
			this->window->close();
		}
		if (input.Event::KeyPressed && input.Event::key.code == Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updateInputs()
{
	//Gets the players inputs.

	//Calls the updateInputs function of player.
	player->updateInputs();

	//Creating the bullets and plays the sound effects if space is pressed and the Boolean value is true.
	if ((Keyboard::isKeyPressed(Keyboard::Space)) && (this->player->bCanAttack()))
	{
		this->vBullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f));
		SoundEngine::playShot();
	}
}

void Game::updateBullets()
{
	//Calls the update function from Bullets and culls the bullets if they go offscreen.

	//Sets the variable to 0 and doesn't allow it to go below that.
	unsigned int iCounter = 0;
	//For all the bullets in the vector.
	for (auto* bullet : this->vBullets)
	{
		//Calls the update function of Bullets.
		bullet->update();

		//Bullet culling at top of screen and decreases the counter.
		if ((bullet->getBounds().top + bullet->getBounds().height) < 0.f)
		{
			delete this->vBullets.at(iCounter);
			this->vBullets.erase(this->vBullets.begin() + iCounter);
			iCounter--;
			//Check to see if bullets are deleted.
			//TEST cout << this->bullets.size() << endl;
		}
		//Increases the counter.
		iCounter++;
	}
}

void Game::updateInvaders()
{
	//Calls the update function of Invaders and handles the collision of the player bullets and invaders.

	//Calls the update function of Invaders and handles collisions between bullets and invaders for all the invaders in the vector.
	for (int i = 0; i < this->vInvaders.size(); i++)
	{
		//Sets the Boolean value to false.
		bool bInvaderGone = false;
		//Calls the update function of invaders for each invader.
		this->vInvaders[i]->update(this->window, *player, *barrier);
		//For all the invaders in the vector and if the Boolean value is false.
		for (size_t k = 0; k < this->vBullets.size() && !bInvaderGone; k++)
		{
			//If any of the players bullets intersects any of the invaders.
			if (this->vBullets[k]->getBounds().intersects(this->vInvaders[i]->getBounds()))
			{
				//Plays the invader killed sound effect.
				SoundEngine::playInvaderKilled();
				//Erases the bullet and the invader that was hit.
				this->vBullets.erase(this->vBullets.begin() + k);
				this->vInvaders.erase(this->vInvaders.begin() + i);
				//Sets the Boolean value to true for the invader killed.
				bInvaderGone = true;
				//Decreases the variable.
				Variables::iNoOfAliens--;
			}
		}
	}
}

void Game::updateBarriers()
{
	//Handles the collision between the barriers and bullets.

	//For all of the bullets in the vector.
	for (size_t k = 0; k < this->vBullets.size(); k++)
	{
		//If any of the players bullets intersects the first barrier.
		if (this->vBullets[k]->getBounds().intersects(this->barrier->getBounds(1)))
		{
			//Plays barrier hit sound effect.
			SoundEngine::playBarrierHit();
			//Erases the bullet that was hit.
			this->vBullets.erase(this->vBullets.begin() + k);
			//Calls the barrierHit function of Barrier passing in the argument for barrier 1.
			this->barrier->barrierHit(1);
		}
		//If any of the players bullets intersects the second barrier.
		else if (this->vBullets[k]->getBounds().intersects(this->barrier->getBounds(2)))
		{
			//Plays barrier hit sound effect.
			SoundEngine::playBarrierHit();
			//Erases the bullet that was hit.
			this->vBullets.erase(this->vBullets.begin() + k);
			//Calls the barrierHit function of Barrier passing in the argument for barrier 2.
			this->barrier->barrierHit(2);
		}
		//If any of the players bullets intersects the third barrier.
		else if (this->vBullets[k]->getBounds().intersects(this->barrier->getBounds(3)))
		{
			//Plays barrier hit sound effect.
			SoundEngine::playBarrierHit();
			//Erases the bullet that was hit.
			this->vBullets.erase(this->vBullets.begin() + k);
			//Calls the barrierHit function of Barrier passing in the argument for barrier 3.
			this->barrier->barrierHit(3);
		}
		//If any of the players bullets intersects the fourth barrier.
		else if (this->vBullets[k]->getBounds().intersects(this->barrier->getBounds(4)))
		{
			//Plays barrier hit sound effect.
			SoundEngine::playBarrierHit();
			//Erases the bullet that was hit.
			this->vBullets.erase(this->vBullets.begin() + k);
			//Calls the barrierHit function of Barrier passing in the argument for barrier 4.
			this->barrier->barrierHit(4);
		}
	}
}

void Game::updateGUI()
{
	//Updates the GUI with the lives.

	//If the variable iLives from Variables is 3. 
	if (Variables::iLives == 3)
	{
		//Sets the pointText to show the lives.
		this->pointText.setString("Lives: 3");
	}
	//If the variable iLives from Variables is 2.
	else if (Variables::iLives == 2)
	{
		//Sets the pointText to show the lives.
		this->pointText.setString("Lives: 2");
	}
	//If the variable iLives from Variables is 1.
	else if (Variables::iLives == 1)
	{
		//Sets the pointText to show the lives.
		this->pointText.setString("Lives: 1");
	}
	//If the variable iLives from Variables is 1.
	else if (Variables::iLives == 0)
	{
		//Sets the pointText to show the lives.
		this->pointText.setString("Lives: 0");
	}
}

void Game::update()
{
	//Calls all the void functions for the update of the game and the update functions of Player and Barriers.
	this->updatePollEvents();
	this->updateInputs();
	this->player->update(this->window);
	this->updateBullets();
	this->updateInvaders();
	this->updateBarriers();
	this->updateGUI();
	this->barrier->update(this->window);
	this->gameOver();
}

void Game::renderGUI()
{
	//Renders all the text for the game.
	this->window->draw(this->pointText);
	this->window->draw(this->gameOverText);
}

void Game::render()
{
	//Renders all the game objects.

	//Clears the screen.
	this->window->clear();

	//Draw items if game is not over.
	if (!bGameOver)
	{
		//Renders the bullets.
		for (auto* bullet : this->vBullets)
		{
			bullet->render(this->window);
		}
		//Renders the player.
		this->player->render(*this->window);
		//Renders the barriers.
		this->barrier->render(*this->window);
		//Renders invaders and their bullets.
		for (auto* invader : this->vInvaders)
		{
			invader->render(this->window);
		}
		//Renders invaders bullets.
		//for (auto* invaderBullet : this->vInvaderBullets)
		//{
		//	invaderBullet->render(this->window);
		//}
	}
	//Renders GUI.
	this->renderGUI();

	//Display items.
	this->window->display();
}