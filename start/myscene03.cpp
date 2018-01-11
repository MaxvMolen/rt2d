/**
* This class describes MyScene03 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene03.h"

MyScene03::MyScene03() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackground.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[0]->addChild(myback);
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartCredits.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText.tga");
	mytext->position = Point2(SWIDTH / 2 + 25, SHEIGHT / 2 - 15);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(1.0f, 0.7f);
	// ###############################################################
	// text
	// ###############################################################
	text[1]->message(".....................................................", WHITE);
	text[2]->message(".....................................................", WHITE);
	text[3]->message(".....................................................", WHITE);
	text[4]->message(".....................................................", WHITE);
	//Position text
	text[1]->position = Point2(50, 500 - 90);
	text[2]->position = Point2(50, 500 - 60);
	text[3]->position = Point2(50, 500 - 30);
	text[4]->position = Point2(50, 500 - 0);
	//text will deleted in corescene.cpp
}


MyScene03::~MyScene03()
{
	// deconstruct and delete the Tree
	this->removeChild(myback);
	delete myback;

	this->removeChild(myheader);
	delete myheader;

	this->removeChild(mytext);
	delete mytext;
}

void MyScene03::update(float deltaTime)
{
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		CoreScene::sceneselect(0);
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}