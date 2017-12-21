/**
* This class describes MyScene02 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene02.h"

// amount of objects
int totalroads02 = 18;
int totalcar02 = 4;
int totalhouses02 = 6;
int totaltree02 = 21;
int totalgarden02 = 6;
int totalbench02 = 2;
int totalsmallbench02 = 4;
int n02;

//myufo
float xa2 = 1; // x position myufo
float ya2 = 1; // y position myufo
float ra2 = 25; // radius myufo

MyScene02::MyScene02() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackground.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[0]->addChild(myback);
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n02 = 0; n02 < totalroads02; ++n02) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n02 * 250, 960);
		roads->rotation.z = 1.57;
		if (n02 >= 8) {
			roads->position = Point2(465, (n02 - 8) * 250 - 267);
			roads->rotation.z = 0;
		}
		if (n02 >= 13) {
			roads->position = Point2(1980 - 515, (n02 - 13) * 250 - 267);
			roads->rotation.z = 0;
		}
		layers[1]->addChild(roads);
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n02 = 0; n02 < totalcar02; ++n02) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(-500, 1020);
		car->rotation.z = 1.57;
		if (n02 >= 1) {
			car->position = Point2(1950, 900);
			car->rotation.z = 4.7;
		}
		if (n02 >= 2) {
			car->position = Point2(500, 900);
			car->rotation.z = 4.7;
		}
		if (n02 >= 3) {
			car->position = Point2(700, 1020);
			car->rotation.z = 1.57;
		}
		layers[3]->addChild(car);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n02 = 0; n02 < totalhouses02; ++n02) {
		BasicEntity* house = new BasicEntity();
		myhouse.push_back(house);
		house->addSprite("assets/StartHouse.tga");
		house->position = Point2(200, n02 * 260 + 150);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		house->rotation.z = 1.57;
		if (n02 >= 3) {
			house->position = Point2(1980 - 250, (n02 - 3) * 260 + 150);
			house->rotation.z = 4.7;
		}
		layers[2]->addChild(house);
	}
	// ###############################################################
	// create garden for the level
	// ###############################################################
	for (n02 = 0; n02 < totalgarden02; ++n02) {
		BasicEntity* garden = new BasicEntity();
		mygarden.push_back(garden);
		garden->addSprite("assets/StartGarden.tga");
		garden->sprite()->color.r = 205;
		garden->sprite()->color.g = 102;
		garden->sprite()->color.b = 44;
		garden->position = Point2(-20, n02 * 260 + 150);
		garden->scale = Point(0.8f, 0.8f);
		if (n02 >= 3) {
			garden->position = Point2(1980 - 30, (n02 - 3) * 260 + 150);
			garden->rotation.z = 3.14;
		}
		layers[2]->addChild(garden);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n02 = 0; n02 < totaltree02; ++n02) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(n02 * 108 + 640, 780);
		if (n02 >= 7) {
			tree->position = Point2(640, (n02 - 7) * 108 + 40);
		}
		if (n02 >= 14) {
			tree->position = Point2(1290, (n02 - 14) * 108 + 40);
		}
		layers[2]->addChild(tree);
	}
	// ###############################################################
	// create big benches for the level
	// ###############################################################
	for (n02 = 0; n02 < totalbench02; ++n02) {
		BasicEntity* bbench = new BasicEntity();
		mybenchb.push_back(bbench);
		bbench->addSprite("assets/StartBench.tga");
		bbench->sprite()->color.r = 205;
		bbench->sprite()->color.g = 102;
		bbench->sprite()->color.b = 44;
		bbench->position = Point2(0 * 108 + 800, 375);
		if (n02 >= 1) {
			bbench->position = Point2((n02+2) * 108 + 800, 375);
		}
		layers[2]->addChild(bbench);
	}
	// ###############################################################
	// create small benches for the level
	// ###############################################################
	for (n02 = 0; n02 < totalsmallbench02; ++n02) {
		BasicEntity* sbench = new BasicEntity();
		mybenchs.push_back(sbench);
		sbench->addSprite("assets/StartSmallBench.tga");
		sbench->sprite()->color.r = 205;
		sbench->sprite()->color.g = 102;
		sbench->sprite()->color.b = 44;
		sbench->position = Point2(675, (n02) * 550 + 100);
		sbench->rotation.z = 1.57;
		if (n02 >= 2) {
			sbench->rotation.z = 1.57 + 1.57 + 1.57;
			sbench->position = Point2(1250, (n02 - 2) * 550 + 100);
		}
		layers[2]->addChild(sbench);
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
}


MyScene02::~MyScene02()
{
	this->removeChild(myback);
	this->removeChild(myufo);
	this->removeChild(light);
	for (n02 = 0; n02 < myroads.size(); ++n02) {
		delete myroads[n02];
		myroads[n02] = NULL;
	}
	myroads.clear();

	for (n02 = 0; n02 < mycar.size(); ++n02) {
		delete mycar[n02];
		mycar[n02] = NULL;
	}
	myroads.clear();

	for (n02 = 0; n02 < myhouse.size(); ++n02) {
		delete myhouse[n02];
		myhouse[n02] = NULL;
	}
	myhouse.clear();

	for (n02 = 0; n02 < mytree.size(); ++n02) {
		delete mytree[n02];
		mytree[n02] = NULL;
	}
	mytree.clear();

	for (n02 = 0; n02 < mybenchb.size(); ++n02) {
		delete mybenchb[n02];
		mybenchb[n02] = NULL;
	}
	mybenchb.clear();

	for (n02 = 0; n02 < mybenchs.size(); ++n02) {
		delete mybenchs[n02];
		mybenchs[n02] = NULL;
	}
	mybenchs.clear();

	for (n02 = 0; n02 < mygarden.size(); ++n02) {
		delete mygarden[n02];
		mygarden[n02] = NULL;
	}
	mygarden.clear();

	delete myback;
	delete myufo;
	delete light;
}

void MyScene02::update(float deltaTime)
{
	// ###############################################################
	// Currentscore counter top right
	// ###############################################################
	std::stringstream cs;
	cs << "Score: " << score.currentscore;
	text[0]->message(cs.str());
	text[0]->position.y = 30;
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
	xa2 = myufo->position.x;
	ya2 = myufo->position.y;
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
	for (n02 = 0; n02 < mycar.size(); ++n02) {
		collision(mycar[n02]->position.x, mycar[n02]->position.y, 125);
	}
	for (n02 = 0; n02 < mytree.size(); ++n02) {
		collision(mytree[n02]->position.x, mytree[n02]->position.y, 50);
	}
}

void MyScene02::collision(float xe, float ye, float re) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xa2 - xe)*(xa2 - xe) + (ya2 - ye)*(ya2 - ye) < ra2*re) {

		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {
			std::cout << score.currentscore;
			std::cout << "|";
			//if right ufo
			score.addscore(10);
			//if wrong ufo
			//score.subtractscore(10);
			//delete object
			//std::cout << "Delete";
		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}

