/**
* This class describes MyEntity behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "myperson.h"

MyPerson::MyPerson(float x1, float y1, float r) : Entity()
{
	this->addSprite("assets/StartPerson.tga");
	this->sprite()->color.r = 255;
	this->sprite()->color.g = 171;
	this->sprite()->color.b = 103;

}

MyPerson::~MyPerson()
{

}

void MyPerson::update(float deltaTime)
{

}
