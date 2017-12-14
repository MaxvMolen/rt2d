/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"

int totalroads00 = 17;
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
}


MyScene00::~MyScene00()
{
	for (n0 = 0; n0 < myroads.size(); ++n0) {
		delete myroads[n0];
		myroads[n0] = NULL;
	}
	myroads.clear();
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
