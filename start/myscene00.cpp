/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"

int totalroads00 = 18;
int totalcar00 = 2;
int totalhouses00 = 6;

int n00;

MyScene00::MyScene00() : CoreScene()
{
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n00 = 0; n00 < totalroads00; ++n00) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n00 * 250, 960);
		roads->rotation.z = 1.57;
		if (n00 >= 8) {
			roads->position = Point2(465, (n00 - 8) * 200 - 68);
			roads->rotation.z = 0;
		}
		if (n00 >= 13) {
			roads->position = Point2(1980-515, (n00 - 13) * 200 - 68);
			roads->rotation.z = 0;
		}
		layers[1]->addChild(roads);
	}

	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n00 = 0; n00 < totalcar00; ++n00) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(-500, 1030);
		car->rotation.z = 1.57;
		if (n00 >= 1) {
			car->position = Point2(1950, 890);
			car->rotation.z = 4.7;
		}
		layers[3]->addChild(car);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n00 = 0; n00 < totalhouses00; ++n00) {
		BasicEntity* house = new BasicEntity();
		myhouse.push_back(house);
		house->addSprite("assets/StartHouse.tga");
		house->position = Point2(200, n00 * 260 +150);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		house->rotation.z = 1.57;
		if (n00 >= 3) {
			house->position = Point2(1980-250, (n00-3) * 260 +150);
			house->rotation.z = 4.7;
		}
		layers[2]->addChild(house);
	}
}

MyScene00::~MyScene00()
{
	for (n00 = 0; n00 < myroads.size(); ++n00) {
		delete myroads[n00];
		myroads[n00] = NULL;
	}
	myroads.clear();

	for (n00 = 0; n00 < mycar.size(); ++n00) {
		delete mycar[n00];
		mycar[n00] = NULL;
	}
	myroads.clear();

	for (n00 = 0; n00 < myhouse.size(); ++n00) {
		delete myhouse[n00];
		myhouse[n00] = NULL;
	}
	myhouse.clear();
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();

	// ###############################################################
	// Move car over the road
	// ###############################################################
	mycar[0]->position.x += 6;
	if (mycar[0]->position.x >= 1980) {
		mycar[0]->position.x = -500;
	}

	mycar[1]->position.x -= 6;
	if (mycar[1]->position.x <= -200) {
		mycar[1]->position.x = 2000;
	}
}
