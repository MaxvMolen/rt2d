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
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackgroundTut.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[0]->addChild(myback);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText.tga");
	mytext->position = Point2(SWIDTH / 2 + 25, SHEIGHT / 2 - 50);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(1.0f, 0.6f);
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
	// text instruction
	// ###############################################################
	//messages with instructions gameplay
	text[2]->message("Y", WHITE);
	text[3]->message("N", WHITE);
	text[4]->message("Use arrowkeys to move", WHITE);
	text[5]->message("A,S and D to change form", WHITE);
	text[6]->message("Use W to pickup objects and to go faster", WHITE);
	text[7]->message("In this game your objective is to pickup the right object with the right ufo", WHITE);
	text[8]->message("If you were to use the wrong ufo to pickup and object you will lose points", WHITE);
	//Position text
	text[2]->position = Point2(SWIDTH / 2 + 380, SHEIGHT / 2 - 270);
	text[3]->position = Point2(SWIDTH / 2 + 380, SHEIGHT / 2 + 270);
	text[4]->position = Point2(50, 500);
	text[5]->position = Point2(50, 30 +500);
	text[6]->position = Point2(50, 60 +500);
	text[7]->position = Point2(50, 500-90);
	text[8]->position = Point2(50, 500-60);
	//Scale text
	text[2]->scale = Point2(1.0f, 1.0f);
	text[3]->scale = Point2(1.0f, 1.0f);
}


MyScene01::~MyScene01()
{
	this->removeChild(myback);
	delete myback;

	this->removeChild(mytext);
	delete mytext;

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
