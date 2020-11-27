#pragma once

//Adding in additional libraries.

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Player
{
private:
	//Variables.
	Sprite sprite;
	Clock attackTimer;
	Time attackElapsedTime;
	Clock deathTimer;
	Time deathElapsedTime;
	float fSpeed;
	float fCooldown;
	float fShotMax;

	//Resources.
	map<String, Texture*> textures;

	//Private functions.
	void initVariables();
	void initTexture();
	void initSprite();

public:
	//Constructor.
	Player();

	//Accessors.
	const Vector2f& getPos() const;
	const FloatRect getBounds() const;

	//Functions.
	void updateInputs();
	void move(const float kfDirX, const float kfDirY);
	bool bCanAttack();
	void updateAttack();
	void isDead(bool bDead);
	void updateWindowBoundsCollision(const RenderTarget* target);
	void update(const RenderTarget* target);
	void render(RenderTarget& target);
};