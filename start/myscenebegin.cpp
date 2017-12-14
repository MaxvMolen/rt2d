/**
* This class describes MySceneBegin behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscenebegin.h"


MySceneBegin::MySceneBegin() : CoreScene()
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
}


MySceneBegin::~MySceneBegin()
{
	this->removeChild(myexamplewrong);
	delete myexamplewrong;

	this->removeChild(myexampleright);
	delete myexampleright;
}

void MySceneBegin::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
