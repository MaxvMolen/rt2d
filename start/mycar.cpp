/**
* This class describes MyCar behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "mycar.h"

MyCar::MyCar() : Entity()
{
	// ###############################################################
	// Set texture and color of object
	// ###############################################################
	this->addSprite("assets/StartCar.tga");
	this->sprite()->color.r = 236;
	this->sprite()->color.g = 16;
	this->sprite()->color.b = 18;
}

MyCar::~MyCar()
{

}

void MyCar::update(float deltaTime)
{

}
