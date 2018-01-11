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
int totaltree00 = 24;
int totalgarden00 = 6;
int totalbench00 = 2;
int totalsmallbench00 = 4;
int totalperson00 = 8;
int n00;

int pcounter00 = 0;

bool started00 = false;
bool menu = true;
bool switchs = false;

//myufo
float xa0 = 1; // x position myufo
float ya0 = 1; // y position myufo
float ra0 = 25; // radius myufo

MyScene00::MyScene00() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackground.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[1]->addChild(myback);
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
			roads->position = Point2(465, (n00 - 8) * 250 - 267);
			roads->rotation.z = 0;
		}
		if (n00 >= 13) {
			roads->position = Point2(1980-515, (n00 - 13) * 250 - 267);
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
		if (n00 >= 21) {
			tree->position = Point2(SWIDTH / 2, SHEIGHT / 2 - 260 + (n00 - 21) * 100);
		}
		layers[2]->addChild(tree);
	}
	// ###############################################################
	// create big benches for the level
	// ###############################################################
	for (n00 = 0; n00 < totalbench00; ++n00) {
		BasicEntity* bbench = new BasicEntity();
		mybenchb.push_back(bbench);
		bbench->addSprite("assets/StartBench.tga");
		bbench->sprite()->color.r = 205;
		bbench->sprite()->color.g = 102;
		bbench->sprite()->color.b = 44;
		bbench->position = Point2(0 * 108 + 800, 375);
		if (n00 >= 1) {
			bbench->position = Point2((n00 + 2) * 108 + 800, 375);
		}
		layers[2]->addChild(bbench);
	}
	// ###############################################################
	// create small benches for the level
	// ###############################################################
	for (n00 = 0; n00 < totalsmallbench00; ++n00) {
		BasicEntity* sbench = new BasicEntity();
		mybenchs.push_back(sbench);
		sbench->addSprite("assets/StartSmallBench.tga");
		sbench->sprite()->color.r = 205;
		sbench->sprite()->color.g = 102;
		sbench->sprite()->color.b = 44;
		sbench->position = Point2(675 + 75, (n00) * 550 + 100);
		sbench->rotation.z = -1.57;
		if (n00 >= 2) {
			sbench->rotation.z = -1.57 - 1.57 - 1.57;
			sbench->position = Point2(1250 - 75, (n00 - 2) * 550 + 100);
		}
		layers[2]->addChild(sbench);
	}
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n00 = 0; n00 < totalperson00; ++n00) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(675 + 50, (n00) * 550 + 100);
		person->rotation.z = 1.57;
		person->scale = Point(0.8f, 0.8f);
		if (n00 >= 2) {
			person->rotation.z = 1.57 + 1.57 + 1.57;
			person->position = Point2(1250 - 50, (n00 - 2) * 550 + 100);
		}
		if (n00 >= 4) {
			person->rotation.z = 0;
			person->position = Point2((n00 - 4) * 380 + 770, 432);
		}
		if (n00 >= 6) {
			person->rotation.z = 1.57 + 1.57;
			person->position = Point2((n00 - 6) * 330 + 820, 317);
		}
		layers[2]->addChild(person);
	}
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartHeader.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
	// ###############################################################
	// create Start header
	// ###############################################################
	myheaderstart = new BasicEntity();
	myheaderstart->addSprite("assets/StartHStart.tga");
	myheaderstart->position = Point2(SWIDTH / 2, 335);
	myheaderstart->scale = Point(0.8f, 0.8f);
	layers[5]->addChild(myheaderstart);
	// ###############################################################
	// create Tutorial header
	// ###############################################################
	myheadertutorial = new BasicEntity();
	myheadertutorial->addSprite("assets/StartHTutorial.tga");
	myheadertutorial->position = Point2(SWIDTH / 2, 525);
	myheadertutorial->scale = Point(0.8f, 0.8f);
	layers[5]->addChild(myheadertutorial);
	// ###############################################################
	// create Ufo
	// ###############################################################
	myufo = new MyUfo();
	myufo->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[7]->addChild(myufo);
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
}

MyScene00::~MyScene00()
{
	this->removeChild(myback);
	delete myback;

	this->removeChild(myheader);
	delete myheader;

	this->removeChild(myheaderstart);
	delete myheaderstart;

	this->removeChild(myheadertutorial);
	delete myheadertutorial;

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
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Set Movement off / on
	// ###############################################################
	if (started00 == false) {
		myufo->movementonoff = false;
		if (switchs == true) {
			menu = true;
			switchs = false;
			pcounter00 = 0;
		}
	}
	else {
		myufo->movementonoff = true;
	}
	// ###############################################################
	// Currentscore counter top right
	// ###############################################################
	std::stringstream cs;
	cs << "Score: " << score.currentscore;
	text[0]->message(cs.str());
	text[0]->position.y = 30;
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		started00 = false;
		menu = true;
	}
	// ###############################################################
	// Start game
	// ###############################################################
	if (menu != false) {
		if (input()->getKey(Enter)) {
			myufo->movementonoff = true;
			layers[7]->addChild(myufo);
			myheader->position.x = -500;
			myheaderstart->position.x = -500;
			myheadertutorial->position.x = -500;
			started00 = true;
			menu = false;
		}
		else {
			layers[0]->addChild(myufo);
			myufo->movementonoff = false;
			light->position.x = -100;
			light->position.y = -100;
			myheader->position = Point2(SWIDTH / 2, 125);
			myheaderstart->position = Point2(SWIDTH / 2, 335);
			myheadertutorial->position = Point2(SWIDTH / 2, 525);
		}
		if (input()->getKeyUp(KeyCode::Space)) {
			myufo->movementonoff = true;
			myufo->standard();
			activescene++;
		}
	}
	// ###############################################################
	// Pause game by pressing p
	// ###############################################################
	if (input()->getKeyDown(P) && menu == false) {
		started00 = false;
		myufo->movementonoff = false;
		pcounter00++;
	}
	if (pcounter00 == 2) {
		started00 = true;
		myufo->movementonoff = true;
		pcounter00 = 0;
	}
	std::cout << pcounter00;
	// ##############################################################################################################################
	// last level (for testing)
	// ##############################################################################################################################
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		myufo->movementonoff = true;
		started00 = false;
		switchs = true;
		myufo->standard();
		CoreScene::sceneselect(2);
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Update X and Y position of light
	// ###############################################################
	if (started00 == true) {
		light->position.x = myufo->position.x;
		light->position.y = myufo->position.y;
	}
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	if (started00 == true) {
		xa0 = myufo->position.x;
		ya0 = myufo->position.y;
	}
	// ###############################################################
	// Move car over the road
	// ###############################################################
	if (started00 == true) {
		mycar[0]->position.x += 600 * deltaTime;
		if (mycar[0]->position.x >= 1980) {
			mycar[0]->position.x = -500;
		}
		mycar[1]->position.x -= 600 * deltaTime;
		if (mycar[1]->position.x <= -200) {
			mycar[1]->position.x = 2000;
		}
		mycar[2]->position.x -= 600 * deltaTime;
		if (mycar[2]->position.x <= -200) {
			mycar[2]->position.x = 2000;
		}
		mycar[3]->position.x += 600 * deltaTime;
		if (mycar[3]->position.x >= 1980) {
			mycar[3]->position.x = -500;
		}
	}
	// ###############################################################
	// Call collision function and set radius of object
	// ###############################################################
	if (started00 == true) {
		for (n00 = 0; n00 < mycar.size(); ++n00) {
			collision(xa0, ya0, ra0, mycar[n00]->position.x, mycar[n00]->position.y, 125, 1, deltaTime);
		}
		for (n00 = 0; n00 < mytree.size(); ++n00) {
			collision(xa0, ya0, ra0, mytree[n00]->position.x, mytree[n00]->position.y, 50, 2, deltaTime);
		}
		for (n00 = 0; n00 < myperson.size(); ++n00) {
			collision(xa0, ya0, ra0, myperson[n00]->position.x, myperson[n00]->position.y, 26, 3, deltaTime);
		}
	}
	// ###############################################################
	// Change scene when all items are removed
	// ###############################################################
	if (mytree.size() == 0 && myperson.size() == 0 && mycar.size() == 0 && menu == false) {
		started00 = false;
		switchs = true;
		myufo->standard();
		CoreScene::sceneselect(2); // next level
	}
}

void MyScene00::collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xu - xe)*(xu - xe) + (yu - ye)*(yu - ye) < ru*re) {

		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {
			//std::cout << score.currentscore;
			//std::cout << "|";
			if (no == 1) {
				//collision object
				//std::cout << "Car";
				//std::cout << "|";
				if (MyUfo::noa == 1) {
					score.addscore(deltaTime);
				}
				else {
					score.subtractscore(deltaTime);
				}
				//remove object
			}
			else if (no == 2) {
				//collision object
				//
				//std::cout << "|";
				if (MyUfo::noa == 3) {
					score.addscore(deltaTime);
				}
				else {
					score.subtractscore(deltaTime);
				}
				//remove object
			}
			else if (no == 3) {
				//collision object
				//std::cout << "Person";
				//std::cout << "|";
				if (MyUfo::noa == 2) {
					score.addscore(deltaTime);
				}
				else {
					score.subtractscore(deltaTime);
				}
				//remove object
			}
		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}
