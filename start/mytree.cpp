/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "mytree.h"

MyTree::MyTree(float x1, float y1, float r) : Entity()
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
