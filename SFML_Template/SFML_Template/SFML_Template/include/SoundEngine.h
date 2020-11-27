#pragma once

//Adding in additional libraries.
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class SoundEngine
{
private:
	//Storage for audio files.
	SoundBuffer shotBuffer;
	SoundBuffer playerExplosionBuffer;
	SoundBuffer invaderKilledBuffer;
	SoundBuffer backgroundBuffer;
	SoundBuffer barrierHitBuffer;

	//Sounds that can be used.
	Sound shotSound;
	Sound playerExplosionSound;
	Sound invaderKilledSound;
	Sound backgroundSound;
	Sound barrierHitSound;

public:
	//Constructor.
	SoundEngine();

	//Functions.
	static void playShot();
	static void playPlayerExplosion();
	static void playInvaderKilled();
	static void playBackgroundScreen();
	static void stopBackgroundScreen();
	static void playBarrierHit();
	static SoundEngine* Instance;
};