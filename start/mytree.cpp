/**
* This class describes MyEntity behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "mytree.h"

MyTree::MyTree() : Entity()
{
	this->addSprite("assets/StartTree.tga");
	this->sprite()->color.r = 12;
	this->sprite()->color.g = 255;
	this->sprite()->color.b = 0;
}

MyTree::~MyTree()
{

}

void MyTree::update(float deltaTime)
{

}
