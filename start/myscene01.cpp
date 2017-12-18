/**
* This class describes MyScene01 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene01.h"


MyScene01::MyScene01() : CoreScene()
{
	// ###############################################################
	// create myexampleright
	// ###############################################################
	myexampleright = new BasicEntity();
	myexampleright->addSprite("assets/ExampleGameplayRight.tga");
	myexampleright->position = Point2(SWIDTH / 2 -300, SHEIGHT / 2 + 250);
	layers[7]->addChild(myexampleright);
	// ###############################################################
	// create examplewrong
	// ###############################################################
	myexamplewrong = new BasicEntity();
	myexamplewrong->addSprite("assets/ExampleGameplayWrong.tga");
	myexamplewrong->position = Point2(SWIDTH / 2 + 300, SHEIGHT / 2 + 250);
	layers[7]->addChild(myexamplewrong);
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartHeaderTutorial.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
}


MyScene01::~MyScene01()
{
	this->removeChild(myexamplewrong);
	delete myexamplewrong;

	this->removeChild(myexampleright);
	delete myexampleright;

	this->removeChild(myheader);
	delete myheader;
}

void MyScene01::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
