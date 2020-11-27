#pragma once

//Adding in additional libraries.
#include "Player.h"
#include "Bullet.h"
#include "Invaders.h"
#include "SoundEngine.h"
#include "InvaderBullets.h"
#include "Barriers.h"

#include <map>

using namespace std;
using namespace sf;

class Game
{
private:
	//Variables.
	//Window.
	RenderWindow* window;
	bool bGameOver = false;
	//Player.
	Player* player;
	//Invaders.
	float fSpawnTimer;
	float fSpawnTimerMax;
	vector<Invaders*> vInvaders;
	//Barriers.
	Barriers* barrier;
	//GUI.
	Font font;
	Text pointText;
	Text gameOverText;

	//Resources.
	map<String, Texture*> textures;
	vector<Bullet*> vBullets;
	vector<InvaderBullets*> vInvaderBullets;

	//Private functions.
	void initWindow();
	void initTextures();
	void initGUI();
	void initPlayer();
	void initInvaders();
	void initBarriers();
	void spawnInvaders();

public:
	//Instances.
	SoundEngine soundEngine; //Sound instance.

	//Constructor / destructor.
	Game();
	virtual ~Game();

	//Functions.
	void run();
	void gameOver();
	void updatePollEvents();
	void updateInputs();
	void updateBullets();
	void updateInvaders();
	void updateBarriers();
	void updateGUI();
	void update();
	void renderGUI();
	void render();
};