/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "myperson.h"


MyPerson::MyPerson() : Entity()
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
