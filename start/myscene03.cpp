/**
* This class describes MyScene03 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene03.h"

int totalroads03 = 16;
int totalcar03 = 8;
int totaltree03 = 18;

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
	myaclogo->position = Point2(1650 - 456, 1080 - 59);
	layers[5]->addChild(myaclogo);
	myaclogo->scale = Point2(0.3f, 0.3f);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText.tga");
	mytext->position = Point2(SWIDTH / 2 - 500, SHEIGHT / 2 - 15);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(0.5f, 0.7f);
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
		roads->position = Point2(1799, (n03) * 250 - 267);
		roads->rotation.z = 0;
		layers[1]->addChild(roads);
		if (n03 >= 8) {
			roads->position = Point2(1790-230, (n03-8) * 250 - 267);
			roads->rotation.z = 0;
		}
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n03 = 0; n03 < totalcar03; ++n03) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(1790 - 290, 1020);
		car->rotation.z = 1.57 + 1.57;
		if (n03 == 1) {
			car->position = Point2(1790 - 175, 900);
			car->rotation.z = 1.57 + 1.57;
		}
		if (n03 == 2) {
			car->position = Point2(1790 + 60 + 9, 900);
			car->rotation.z = 0;
		}
		if (n03 == 3) {
			car->position = Point2(1790 - 60  +9, 1020);
			car->rotation.z = 0;
		}
		if (n03 == 4) {
			car->position = Point2(1790 - 60 + 9, 700);
			car->rotation.z = 0;
		}
		if (n03 == 5) {
			car->position = Point2(1790 - 175, 200);
			car->rotation.z = 1.57 + 1.57;
		}
		if (n03 == 6) {
			car->position = Point2(1790 - 290, 200);
			car->rotation.z = 1.57 + 1.57;
		}
		if (n03 == 7) {
			car->position = Point2(1790 + 60 + 9, 0);
			car->rotation.z = 0;
		}
		layers[3]->addChild(car);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n03 = 0; n03 < totaltree03; ++n03) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(1385, (n03) * 108 + 40);
		if (n03 >= 9) {
			tree->position = Point2(1385-100, (n03 - 9) * 108 + 40);
		}
		layers[2]->addChild(tree);
	}
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

	this->removeChild(myaclogo);
	delete myaclogo;

	for (n03 = 0; n03 < myroads.size(); ++n03) {
		delete myroads[n03];
		myroads[n03] = NULL;
	}
	myroads.clear();

	for (n03 = 0; n03 < mycar.size(); ++n03) {
		delete mycar[n03];
		mycar[n03] = NULL;
	}
	mycar.clear();

	for (n03 = 0; n03 < mytree.size(); ++n03) {
		delete mytree[n03];
		mytree[n03] = NULL;
	}
	mytree.clear();
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
	// ###############################################################
	// Move car over the road
	// ###############################################################
	mycar[0]->position.y += 600 * deltaTime; //driving up
	if (mycar[0]->position.y >= 1180) {
		mycar[0]->position.y = -500;
	}
	mycar[1]->position.y += 800 * deltaTime; //driving up
	if (mycar[1]->position.y >= 1280) {
		mycar[1]->position.y = -100;
	}
	mycar[2]->position.y -= 600 * deltaTime; //driving down
	if (mycar[2]->position.y <= -200) {
		mycar[2]->position.y = 1100;
	}
	mycar[3]->position.y -= 800 * deltaTime; //driving down
	if (mycar[3]->position.y <= -50) {
		mycar[3]->position.y = 1200;
	}
	mycar[4]->position.y -= 800 * deltaTime; //driving down
	if (mycar[4]->position.y <= -50) {
		mycar[4]->position.y = 1200;
	}
	mycar[5]->position.y += 800 * deltaTime; //driving up
	if (mycar[5]->position.y >= 1280) {
		mycar[5]->position.y = -100;
	}
	mycar[6]->position.y += 600 * deltaTime; //driving down
	if (mycar[6]->position.y >= 1180) {
		mycar[6]->position.y = -500;
	}
	mycar[7]->position.y -= 600 * deltaTime; //driving up
	if (mycar[7]->position.y <= -100) {
		mycar[7]->position.y = 1300;
	}
}