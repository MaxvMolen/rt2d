/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"

int totalroads00 = 17;
int totalcar00 = 2;
int n0;

MyScene00::MyScene00() : CoreScene()
{
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n0 = 0; n0 < totalroads00; ++n0) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n0 * 250, 960);
		roads->rotation.z = 1.57;
		layers[4]->addChild(roads);
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n0 = 0; n0 < totalcar00; ++n0) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(-500, 1030);
		car->rotation.z = 1.57;
		layers[5]->addChild(car);
		if (n0 >= 1) {
			car->position = Point2(1950, 890);
			car->rotation.z = 4.7;
		}
		
	}
}

MyScene00::~MyScene00()
{
	for (n0 = 0; n0 < myroads.size(); ++n0) {
		delete myroads[n0];
		myroads[n0] = NULL;
	}
	myroads.clear();

	for (n0 = 0; n0 < mycar.size(); ++n0) {
		delete mycar[n0];
		mycar[n0] = NULL;
	}
	myroads.clear();
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
