/**
* This class describes MyScene03 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene03.h"

int totalroads03 = 16;
int totalcar03 = 4;
int n03;

MyScene03::MyScene03() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackgroundTut.tga");
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
	// create logo for the level
	// ###############################################################
	myaclogo = new BasicEntity();
	myaclogo->addSprite("assets/AC-Logo.tga");
	myaclogo->position = Point2(1650-500, 1080-59);
	layers[5]->addChild(myaclogo);
	myaclogo->scale = Point2(0.3f, 0.3f);
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
	text[1]->message("Ufo Game", WHITE);
	text[2]->message("Developer: Max van der molen", WHITE);
	text[3]->message("Art: Max van der molen", WHITE);
	text[4]->message("......................", WHITE);
	//Position text
	text[1]->position = Point2(50, 500 - 90);
	text[2]->position = Point2(50, 500 - 60);
	text[3]->position = Point2(50, 500 - 30);
	text[4]->position = Point2(50, 500 - 0);
	//text will deleted in corescene.cpp
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n03 = 0; n03 < totalroads03; ++n03) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(1790, (n03) * 250 - 267);
		roads->rotation.z = 0;
		layers[1]->addChild(roads);
		if (n03 >= 8) {
			roads->position = Point2(1790-200, (n03-8) * 250 - 267);
			roads->rotation.z = 0;
		}
	}
}


MyScene03::~MyScene03()
{
	// deconstruct and delete the Tree
	for (n03 = 0; n03 < myroads.size(); ++n03) {
		delete myroads[n03];
		myroads[n03] = NULL;
	}
	myroads.clear();

	this->removeChild(myback);
	delete myback;

	this->removeChild(myheader);
	delete myheader;

	this->removeChild(mytext);
	delete mytext;

	this->removeChild(myaclogo);
	delete myaclogo;
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