//Adding in additional libraries.
#include "../include/SoundEngine.h"

#include <assert.h>

using namespace std;
using namespace sf;

//Sets Instance as a null pointer.
SoundEngine* SoundEngine::Instance = nullptr;

//Constructor.
SoundEngine::SoundEngine()
{
	//Diagnostics.
	assert(Instance == nullptr);
	Instance = this;

	/*
	All sound effects were downloaded from: https://www.classicgaming.cc/classics/space-invaders/sounds.
	Background music was downloaded from: https://soundcloud.com/ubimusic/space-invaders-remix.
	*/

	//Loads the sounds into the correct buffers.
	shotBuffer.loadFromFile("Sounds/shoot.wav");
	playerExplosionBuffer.loadFromFile("Sounds/explosion.wav");
	invaderKilledBuffer.loadFromFile("Sounds/invaderkilled.wav");
	backgroundBuffer.loadFromFile("Sounds/Space_Invaders_Remix.wav");
	barrierHitBuffer.loadFromFile("Sounds/barrierhit.wav");

	//Associate the sounds to the buffers.
	shotSound.setBuffer(shotBuffer);
	playerExplosionSound.setBuffer(playerExplosionBuffer);
	invaderKilledSound.setBuffer(invaderKilledBuffer);
	backgroundSound.setBuffer(backgroundBuffer);
	barrierHitSound.setBuffer(barrierHitBuffer);

	//Setting volume of background music and making it loop.
	shotSound.setVolume(10.f);
	playerExplosionSound.setVolume(20.f);
	invaderKilledSound.setVolume(10.f);
	backgroundSound.setVolume(5.f);
	backgroundSound.setLoop(true);
	barrierHitSound.setVolume(10.f);
}


//Functions.
void SoundEngine::playShot()
{
	//Plays the shot sound effect if called.
	Instance->shotSound.play();
}

void SoundEngine::playPlayerExplosion()
{
	//Plays the player explosion sound effect if called.
	Instance->playerExplosionSound.play();
}

void SoundEngine::playInvaderKilled()
{
	//Plays the invader killed sound effect if called.
	Instance->invaderKilledSound.play();
}

void SoundEngine::playBackgroundScreen()
{
	//Plays the title music if called.
	Instance->backgroundSound.play();
}

void SoundEngine::stopBackgroundScreen()
{
	//Stops the title music if called.
	Instance->backgroundSound.stop();
}

void SoundEngine::playBarrierHit()
{
	//Plays the barrier hit sound effect if called.
	Instance->barrierHitSound.play();
}