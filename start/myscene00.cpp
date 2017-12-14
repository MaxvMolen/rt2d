/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"


MyScene00::MyScene00() : CoreScene()
{
	test = new BasicEntity();
	test->addSprite("assets/StartGarage.tga");
	test->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[7]->addChild(test);
}


MyScene00::~MyScene00()
{
	this->removeChild(test);
	delete test;
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
