/**
* This class describes MyScene03 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene03.h"


// amount of objects
int totalroads03 = 32;
int totalcar03 = 8;
int totaltree03 = 18;

int n03;
// location ufo
int pcount = 0;

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
	layers[3]->addChild(mytext);
	mytext->scale = Point2(0.5f, 0.7f);
	// ###############################################################
	// text
	// ###############################################################
	text[1]->message("Ufo Game", WHITE);
	text[2]->message("Developer: Max van der molen", WHITE);
	text[3]->message("Art: Max van der molen", WHITE);
	text[4]->message("Thanks for playing my game!", WHITE);
	//Position text
	text[1]->position = Point2(50, 500 - 90);
	text[2]->position = Point2(50, 500 - 30);
	text[3]->position = Point2(50, 500 - 0);
	text[4]->position = Point2(50, 500 + 60);
	//Scale text
	text[1]->scale = Point2(0.7f, 0.7f);
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
		if (n03 >= 8) {
			roads->position = Point2(1790-230, (n03-8) * 250 - 267);
			roads->rotation.z = 0;
		}
		if (n03 >= 16) {
			roads->position = Point2(128, (n03-16) * 250 - 267);
			roads->rotation.z = 0;
		}
		if (n03 >= 24) {
			roads->position = Point2(384-25, (n03 - 24) * 250 - 267);
			roads->rotation.z = 0;
		}
		layers[1]->addChild(roads);
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
	// ###############################################################
	// create light
	// ###############################################################
	light = new BasicEntity();
	light->addSprite("assets/StartUfoLight.tga");
	light->scale = Point(0.7f, 0.7f);
	light->sprite()->color.r = 181;
	light->sprite()->color.g = 181;
	light->sprite()->color.b = 181;
	layers[6]->addChild(light);
	// ###############################################################
	// create unufo this ufo is is not controllable by the player
	// ###############################################################
	unufo = new BasicEntity();
	unufo->addSprite("assets/StartUfo2.tga");
	unufo->sprite()->color.r = 236;
	unufo->sprite()->color.g = 16;
	unufo->sprite()->color.b = 18;
	unufo->position = Point2(-300, 325);
	layers[7]->addChild(unufo);
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
	// unufo automatic rotation
	// ###############################################################
	unufo->rotation.z -= 10 * deltaTime; // 90 deg/sec
	if (unufo->rotation.z > TWO_PI) {
		unufo->rotation.z -= TWO_PI;
	}
	// ###############################################################
	// unufo move allong path
	// ###############################################################
	if (unufo->position.x <= 1000 && pcount == 0) {
		unufo->position.x += 300 * deltaTime;
		if (unufo->position.x >= 990 && unufo->position.x <= 1000) {
			pcount++;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.x >= 990 && pcount == 1) {
		unufo->position.y += 300 * deltaTime;
		if (unufo->position.y >= 800 && unufo->position.y <= 810) {
			pcount++;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.y >= 800 && pcount == 2) {
		unufo->position.x -= 300 * deltaTime;
		if (unufo->position.x >= -500 && unufo->position.x <= -490) {
			pcount++;
			unufo->position = Point2(1400, -300);
			unufo->addSprite("assets/StartUfo1.tga");
			unufo->sprite()->color.r = 255;
			unufo->sprite()->color.g = 171;
			unufo->sprite()->color.b = 103;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.y <= 1200 && pcount == 3) {
		unufo->position.y += 300 * deltaTime;
		if (unufo->position.y >= 1190 && unufo->position.y <= 1200) {
			pcount = 0;
			unufo->position = Point2(-300, 325);
			unufo->addSprite("assets/StartUfo2.tga");
			unufo->sprite()->color.r = 236;
			unufo->sprite()->color.g = 16;
			unufo->sprite()->color.b = 18;
			//std::cout << "pcount = 0";
		}
	}
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		CoreScene::sceneselect(0);
	}
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
	light->position.x = unufo->position.x;
	light->position.y = unufo->position.y;
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