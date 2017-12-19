/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"

// amount of objects
int totalroads00 = 18;
int totalcar00 = 4;
int totalhouses00 = 6;
int totaltree00 = 21;
int totalgarden00 = 6;
int n00;

//myufo
float xa0 = 1; // x position myufo
float ya0 = 1; // y position myufo
float ra0 = 25; // radius myufo

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
		car->position = Point2(-500, 1020);
		car->rotation.z = 1.57;
		if (n00 >= 1) {
			car->position = Point2(1950, 900);
			car->rotation.z = 4.7;
		}
		if (n00 >= 2) {
			car->position = Point2(500, 900);
			car->rotation.z = 4.7;
		}
		if (n00 >= 3) {
			car->position = Point2(700, 1020);
			car->rotation.z = 1.57;
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
	// ###############################################################
	// create garden for the level
	// ###############################################################
	for (n00 = 0; n00 < totalgarden00; ++n00) {
		BasicEntity* garden = new BasicEntity();
		mygarden.push_back(garden);
		garden->addSprite("assets/StartGarden.tga");
		garden->sprite()->color.r = 205;
		garden->sprite()->color.g = 102;
		garden->sprite()->color.b = 44;
		garden->position = Point2(-20, n00 * 260 + 150);
		garden->scale = Point(0.8f, 0.8f);
		if (n00 >= 3) {
			garden->position = Point2(1980 - 30, (n00 - 3) * 260 + 150);
			garden->rotation.z = 3.14;
		}
		layers[2]->addChild(garden);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n00 = 0; n00 < totaltree00; ++n00) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(n00 * 108 + 640, 780);
		if (n00 >= 7) {
			tree->position = Point2(640, (n00-7) * 108 + 40);
		}
		if (n00 >= 14) {
			tree->position = Point2(1290, (n00 - 14) * 108 + 40);
		}
		layers[2]->addChild(tree);
	}
	// ###############################################################
	// create light for underneath the ufo
	// ###############################################################
	light = new BasicEntity();
	light->addSprite("assets/StartUfoLight.tga");
	light->scale = Point(0.7f, 0.7f);
	light->sprite()->color.r = 181;
	light->sprite()->color.g = 181;
	light->sprite()->color.b = 181;
	layers[6]->addChild(light);
	// ###############################################################
	// create ufo for the level
	// ###############################################################
	myufo = new MyUfo();
	myufo->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[7]->addChild(myufo);
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartHeader.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
}

MyScene00::~MyScene00()
{
	this->removeChild(myufo);
	this->removeChild(light);
	this->removeChild(myheader);

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

	for (n00 = 0; n00 < mytree.size(); ++n00) {
		delete mytree[n00];
		mytree[n00] = NULL;
	}
	mytree.clear();

	for (n00 = 0; n00 < mygarden.size(); ++n00) {
		delete mygarden[n00];
		mygarden[n00] = NULL;
	}
	mygarden.clear();

	delete myufo;
	delete light;
	delete myheader;
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Update X and Y position of light
	// ###############################################################
	light->position.x = myufo->position.x;
	light->position.y = myufo->position.y;
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	xa0 = myufo->position.x;
	ya0 = myufo->position.y;
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
	mycar[2]->position.x -= 6;
	if (mycar[2]->position.x <= -200) {
		mycar[2]->position.x = 2000;
	}
	mycar[3]->position.x += 6;
	if (mycar[3]->position.x >= 1980) {
		mycar[3]->position.x = -500;
	}
	// ###############################################################
	// Call collision function and set radius of object
	// ###############################################################
	for (n00 = 0; n00 < mycar.size(); ++n00) {
		collision(mycar[n00]->position.x, mycar[n00]->position.y, 125);
	}
	for (n00 = 0; n00 < mytree.size(); ++n00) {
		collision(mytree[n00]->position.x, mytree[n00]->position.y, 50);
	}
}

void MyScene00::collision(float xe, float ye, float re) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xa0 - xe)*(xa0 - xe) + (ya0 - ye)*(ya0 - ye) < ra0*re) {

		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {

		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}
