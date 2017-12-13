/**
* This class describes MyTree behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "mytree.h"

MyTree::MyTree() : Entity()
{
	// ###############################################################
	// Set texture and color of object
	// ###############################################################
	this->addSprite("assets/StartTree.tga");
	this->sprite()->color.r = 110;
	this->sprite()->color.g = 156;
	this->sprite()->color.b = 56;
}

MyTree::~MyTree()
{

}

void MyTree::update(float deltaTime)
{

}