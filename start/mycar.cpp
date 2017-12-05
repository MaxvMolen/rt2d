/**
* This class describes MyCar behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "mycar.h"

MyCar::MyCar() : Entity()
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
