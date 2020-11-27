//Adding in additional libraries.
#include "../include/Barriers.h"

//Defining a variable for the scale of the barriers.
float fScale = 0.75f;

//Private functions.
void Barriers::initTextures()
{
	//Initialising all the barrier textures.

	//Full barriers.
	this->textures["BarrierFull"] = new Texture();
	this->textures["BarrierFull"]->loadFromFile("Textures/Barrier.png");

	//Partial barriers.
	this->textures["BarrierPhase1"] = new Texture();
	this->textures["BarrierPhase1"]->loadFromFile("Textures/Barrier_Destroyed_Phase_1.png");

	//Almost destroyed barriers.
	this->textures["BarrierPhase2"] = new Texture();
	this->textures["BarrierPhase2"]->loadFromFile("Textures/Barrier_Destroyed_Phase_2.png");
}

void Barriers::initVariables()
{
	//Initialises all the variables.
	iNoOfHitsMax = 9;
	iNoOfHitsBarrier1 = iNoOfHitsMax;
	iNoOfHitsBarrier2 = iNoOfHitsMax;
	iNoOfHitsBarrier3 = iNoOfHitsMax;
	iNoOfHitsBarrier4 = iNoOfHitsMax;
}

void Barriers::initBarriers()
{
	//Sets up the barriers with textures, scale and their positions.

	//Barrier 1 set up.
	this->barrier1.setTexture(*textures["BarrierFull"]);
	this->barrier1.setScale(fScale, fScale);
	this->barrier1.setPosition(50.f, 750.f);

	//Barrier 2 set up.
	this->barrier2.setTexture(*textures["BarrierFull"]);
	this->barrier2.setScale(fScale, fScale);
	this->barrier2.setPosition(310.f, 750.f);

	//Barrier 3 set up.
	this->barrier3.setTexture(*textures["BarrierFull"]);
	this->barrier3.setScale(fScale, fScale);
	this->barrier3.setPosition(570.f, 750.f);

	//Barrier 4 set up.
	this->barrier4.setTexture(*textures["BarrierFull"]);
	this->barrier4.setScale(fScale, fScale);
	this->barrier4.setPosition(830.f, 750.f);
}

//Constructor.
Barriers::Barriers()
{
	//Calls the void functions to set up the barriers.
	this->initTextures();
	this->initVariables();
	this->initBarriers();
}


//Accessors.
const FloatRect Barriers::getBounds(int iBarrierNo) const
{
	//Gets the bounds of each barrier using a switch.

	switch (iBarrierNo)
	{
		//Barrier 1.
	case 1:
		return this->barrier1.getGlobalBounds();
		break;
		//Barrier 2.
	case 2:
		return this->barrier2.getGlobalBounds();
		break;
		//Barrier 3.
	case 3:
		return this->barrier3.getGlobalBounds();
		break;
		//Barrier 4.
	case 4:
		return this->barrier4.getGlobalBounds();
		break;
	}
}

//Functions.
void Barriers::barrierHit(int iBarrierNo)
{
	//Decreases the value of the hit variable for each barrier using a switch.

	switch (iBarrierNo)
	{
		//Barrier 1.
	case 1:
		this->iNoOfHitsBarrier1--;
		//TEST cout << iNoOfHitsBarrier1 << endl;
		break;
		//Barrier 2.
	case 2:
		this->iNoOfHitsBarrier2--;
		//TEST cout << iNoOfHitsBarrier2 << endl;
		break;
		//Barrier 3.
	case 3:
		this->iNoOfHitsBarrier3--;
		//TEST cout << iNoOfHitsBarrier3 << endl;
		break;
		//Barrier 4.
	case 4:
		this->iNoOfHitsBarrier4--;
		//TEST cout << iNoOfHitsBarrier4 << endl;
		break;
	}
}

void Barriers::update(RenderTarget* target)
{
	//Updates each barrier giving them a different sprites depended of their hit variable.

	//Barrier 1 update.
	//Phase 1.
	if (iNoOfHitsBarrier1 == 6)
	{
		this->barrier1.setTexture(*textures["BarrierPhase1"]);
		this->barrier1.setScale(fScale, fScale);
	}
	//Phase 2.
	else if (iNoOfHitsBarrier1 == 3)
	{
		this->barrier1.setTexture(*textures["BarrierPhase2"]);
		this->barrier1.setScale(fScale, fScale);
	}
	//Disappear.
	else if (iNoOfHitsBarrier1 == 0)
	{
		//Moves the barrier off screen.
		this->barrier1.setPosition(1100.f, 1100.f);
	}

	//Barrier 2 update.
	//Phase 1.
	if (iNoOfHitsBarrier2 == 6)
	{
		this->barrier2.setTexture(*textures["BarrierPhase1"]);
		this->barrier2.setScale(fScale, fScale);
	}
	//Phase 2.
	else if (iNoOfHitsBarrier2 == 3)
	{
		this->barrier2.setTexture(*textures["BarrierPhase2"]);
		this->barrier2.setScale(fScale, fScale);
	}
	//Disappear.
	else if (iNoOfHitsBarrier2 == 0)
	{
		//Moves the barrier off screen.
		this->barrier2.setPosition(1100.f, 1100.f);
	}

	//Barrier 3 update.
	//Phase 1.
	if (iNoOfHitsBarrier3 == 6)
	{
		this->barrier3.setTexture(*textures["BarrierPhase1"]);
		this->barrier3.setScale(fScale, fScale);
	}
	//Phase 2.
	else if (iNoOfHitsBarrier3 == 3)
	{
		this->barrier3.setTexture(*textures["BarrierPhase2"]);
		this->barrier3.setScale(fScale, fScale);
	}
	//Disappear.
	else if (iNoOfHitsBarrier3 == 0)
	{
		//Moves the barrier off screen.
		this->barrier3.setPosition(1100.f, 1100.f);
	}

	//Barrier 4 update.
	//Phase 1.
	if (iNoOfHitsBarrier4 == 6)
	{
		this->barrier4.setTexture(*textures["BarrierPhase1"]);
		this->barrier4.setScale(fScale, fScale);
	}
	//Phase 2.
	else if (iNoOfHitsBarrier4 == 3)
	{
		this->barrier4.setTexture(*textures["BarrierPhase2"]);
		this->barrier4.setScale(fScale, fScale);
	}
	//Disappear.
	else if (iNoOfHitsBarrier4 == 0)
	{
		//Moves the barrier off screen.
		this->barrier4.setPosition(1100.f, 1100.f);
	}
}

void Barriers::render(RenderTarget& target)
{
	//Draws all the barriers to the screen.
	target.draw(this->barrier1);
	target.draw(this->barrier2);
	target.draw(this->barrier3);
	target.draw(this->barrier4);
}