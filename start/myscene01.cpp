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
	myexampleright->position = Point2(SWIDTH / 2 + 700, SHEIGHT / 2-270);
	layers[7]->addChild(myexampleright);
	// ###############################################################
	// create examplewrong
	// ###############################################################
	myexamplewrong = new BasicEntity();
	myexamplewrong->addSprite("assets/ExampleGameplayWrong.tga");
	myexamplewrong->position = Point2(SWIDTH / 2 + 700, SHEIGHT / 2+270);
	layers[7]->addChild(myexamplewrong);
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartHeaderTutorial.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
	// ###############################################################
	// Text instruction
	// ###############################################################
	text[2]->message("Y", RED);
	text[3]->message("N", RED);
	text[4]->message("Use arrowkeys to move", RED);
	text[5]->message("A,S and D to change form", RED);
	text[6]->message("Use W to pickup objects and to go faster", RED);
	//Position text
	text[2]->position = Point2(SWIDTH / 2 + 380, SHEIGHT / 2 - 270);
	text[3]->position = Point2(SWIDTH / 2 + 380, SHEIGHT / 2 + 270);
	text[4]->position = Point2(50, 500);
	text[5]->position = Point2(50, 30 +500);
	text[6]->position = Point2(50, 60 +500);
	//Scale text
	text[2]->scale = Point2(1.0f, 1.0f);
	text[3]->scale = Point2(1.0f, 1.0f);
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
