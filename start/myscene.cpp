/**
* This class describes MyScene behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene.h"

// amount of objects
int totalroads = 17;
int totalhouses = 3;
int totalparking = 16;
int totalcar = 8;
int totaltree = 9;
int totaltgarage = 2;
int totaltbush = 4;
int totalperson = 2;

int n;

//myufo
float xa = 1; // x position myufo
float ya = 1; // y position myufo
float ra = 25; // radius myufo

MyScene::MyScene() : CoreScene()
{
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n = 0; n < totalroads; ++n) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		//myroads[n] = new BasicEntity();
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n * 250, 125);
		roads->rotation.z = 1.57;
		if (n>=8) {
			roads->position = Point2(SWIDTH / 2, (n - 8)* 200 + 352.5);
			roads->rotation.z = 0;
		}
		if(n>=12) {
			roads->position = Point2(SWIDTH / 2 + 227.5 +(n-12)*256, SHEIGHT / 2-13);
			roads->rotation.z = 1.57;
		}
		layers[4]->addChild(roads);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n = 0; n < totalhouses; ++n) {
		BasicEntity* house = new BasicEntity();
		myhouse.push_back(house);
		house->addSprite("assets/StartHouse.tga");
		house->position = Point2(n * 260 + 180,395);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		if (n >= 2) {
			house->position = Point2(n* 260 + 180,635);
			house->rotation.z = 1.57;
		}
		layers[4]->addChild(house);
	}
	// ###############################################################
	// create parking sports for the level
	// ###############################################################
	for (n = 0; n < totalparking; ++n) {
		BasicEntity* park = new BasicEntity();
		myparking.push_back(park);
		park->addSprite("assets/StartPark.tga");
		park->position = Point2(n* 125 + 1170, 335);
		park->rotation.z = 3.14;
		if (n >= 8) {
			park->position = Point2((n-4) * 125 + 670, 718);
			park->rotation.z = 0;
		}
		layers[4]->addChild(park);
	}

	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n = 0; n < totalcar; ++n) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(n * 125 + 1170, 338);
		if (n >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2(n * 125 + 670, 715);
		}
		layers[5]->addChild(car);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n = 0; n < totaltree; ++n) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(n * 200 + 1170, 855);
		if (n >= 4) {
			tree->position = Point2(n * 200 + 465, 982);
			tree->rotation.z = 3.14;
		}
		if (n >= 8) {
			tree->position = Point2(655,425 );
		}
		layers[5]->addChild(tree);
	}
	// ###############################################################
	// create garages for the level
	// ###############################################################
	for (n = 0; n < totaltgarage; ++n) {
		BasicEntity* garage = new BasicEntity();
		mygarage.push_back(garage);
		garage->addSprite("assets/StartGarage.tga");
		garage->sprite()->color.r = 171;
		garage->sprite()->color.g = 167;
		garage->sprite()->color.b = 154;
		garage->position = Point2(-25, 420);
		garage->scale = Point(0.7f, 0.7f);
		if (n >= 1) {
			garage->position = Point2(680, 840);
			garage->rotation.z = 1.57;
		}
		layers[5]->addChild(garage);
	}
	// ###############################################################
	// create bushes for the level
	// ###############################################################
	for (n = 0; n < totaltbush; ++n) {
		BasicEntity* bush = new BasicEntity();
		mybush.push_back(bush);
		bush->addSprite("assets/StartBush.tga");
		bush->sprite()->color.r = 78;
		bush->sprite()->color.g = 203;
		bush->sprite()->color.b = 22;
		bush->position = Point2(n * 100 + 615, 310);
		if (n >= 2) {
			bush->position = Point2(790, (n - 2) * 100 + 370);
		}
		layers[5]->addChild(bush);
	}
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n = 0; n < totalperson; ++n) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(n * 125 + 200, 700);
		layers[5]->addChild(person);
	}

	// ###############################################################
	// create ufo for the level
	// ###############################################################
	myufo = new MyUfo();
	myufo->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[6]->addChild(myufo);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myufo);

	for (n = 0; n < myroads.size(); ++n) {
		delete myroads[n];
		myroads[n] = NULL;
	}
	myroads.clear();

	for (n = 0; n < myhouse.size(); ++n) {
		delete myhouse[n];
		myhouse[n] = NULL;
	}
	myhouse.clear();
	
	for (n = 0; n < myparking.size(); ++n) {
		delete myparking[n];
		myparking[n] = NULL;
	}
	myparking.clear();
	
	for (n = 0; n < mycar.size(); ++n) {
		delete mycar[n];
		mycar[n] = NULL;
	}
	mycar.clear();

	for (n = 0; n < mytree.size(); ++n) {
		delete mytree[n];
		mytree[n] = NULL;
	}
	mytree.clear();

	for (n = 0; n < totaltgarage; ++n) {
		this->removeChild(mygarage[n]);
		delete mygarage[n];
	}

	for (n = 0; n < mybush.size(); ++n) {
		delete mybush[n];
		mybush[n] = NULL;
	}
	mybush.clear();

	for (n = 0; n < myperson.size(); ++n) {
		delete myperson[n];
		myperson[n] = NULL;
	}
	myperson.clear();

	delete myufo;

}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	xa = myufo->position.x;
	ya = myufo->position.y;
	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	// ###############################################################
	// Update X and Y position and set radius
	// ###############################################################
	for (n = 0; n < mycar.size(); ++n) {
		collision(mycar[n]->position.x, mycar[n]->position.y, 125);
	}

	for (n = 0; n < mytree.size(); ++n) {
		collision(mytree[n]->position.x, mytree[n]->position.y, 50);
	}

	for (n = 0; n < myperson.size(); ++n) {
		collision(myperson[n]->position.x, myperson[n]->position.y, 25);
	}

}

void MyScene::collision(float xe, float ye, float re) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xa - xe)*(xa - xe) + (ya - ye)*(ya - ye) < ra*re) {
		myufo->sprite()->color.r = 0;
		myufo->sprite()->color.g = 255;
		myufo->sprite()->color.b = 0;

		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {
			
		}
		else {
			// lock the ufo in place on collision of object 
			if (myufo->position.x >= xe) {
				myufo->position.x += -10;
			}
			if (myufo->position.x <= xe) {
				myufo->position.x += 10;
			}
			if (myufo->position.y >= ye) {
				myufo->position.y += -10;
			}
			if (myufo->position.y <= ye) {
				myufo->position.y += 10;
			}
		}
	}
}
