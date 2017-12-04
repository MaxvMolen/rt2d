/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "mycar.h"

MyCar::MyCar(float x1, float y1, float r) : Entity()
{
	this->addSprite("assets/StartCar.tga");
	this->sprite()->color.r = 255;
	this->sprite()->color.g = 0;
	this->sprite()->color.b = 0;
}

MyCar::~MyCar()
{

}

void MyCar::update(float deltaTime)
{

}
