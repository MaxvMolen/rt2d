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
int totalcar = 9;
int totaltree = 9;
int totaltgarage = 2;
int totaltbush = 4;
int totalperson = 4;
int totalpath = 14;
int totalGarden = 3;

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
		if (n >= 2) {
			car->position = Point2(4 * 125 + 1170, 338);
		}
		if (n >= 3) {
			car->rotation.z = 3.14;
			car->position = Point2((n-2) * 125 + 1170, 715);
		}
		if (n >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n - 1) * 125 + 1170, 715);
		}
		if (n >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n - 1) * 125 + 1170, 715);
		}
		if (n >= 7) {
			car->rotation.z = 1.57;
			car->position = Point2(750, 840);
		}
		if (n >= 8) {
			car->rotation.z = 1.57;
			car->position = Point2(-79, 60);
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
		layers[6]->addChild(tree);
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
		bush->sprite()->color.r = 110;
		bush->sprite()->color.g = 156;
		bush->sprite()->color.b = 56;
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
		person->position = Point2(n * 218 + 190, 576);
		person->scale = Point(0.7f, 0.7f);
		person->rotation.z = 3.14;
		if (n >= 2) {
			person->position = Point2((n-1) * 190 + 180, 650);
			person->rotation.z = 1.57;
		}
		if (n >= 3) {
			person->position = Point2(800,1050);
			person->rotation.z = 4.7;
		}
		layers[6]->addChild(person);
	}
	// ###############################################################
	// create path for the level
	// ###############################################################
	for (n = 0; n < totalpath; ++n) {
		BasicEntity* path = new BasicEntity();
		mypath.push_back(path);
		path->addSprite("assets/StartPRoad.tga");
		path->rotation.z = 1.57;
		path->position = Point2((n * -75)+787.5, 1043);
		path->scale = Point(0.7f, 0.7f);
		if (n >= 5) {
			path->position = Point2((n * -75) + 787.5, 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 3.14;
		}
		if (n >= 6) {
			path->position = Point2(((5) * -75) + 787.5,(n-5)*-75 +1036);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 0;
		}
		if (n >= 8) {
			path->position = Point2(((5) * -75) + 787.5, (n - 5)*-75 + 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 6.27;
		}
		if (n >= 9) {
			path->position = Point2(((n -2.9) * -75) + 787.5, (3.18) * -75 + 1043);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 1.57;
		}
		layers[5]->addChild(path);
	}
	// ###############################################################
	// create garden for the level
	// ###############################################################
	for (n = 0; n < totalGarden; ++n) {
		BasicEntity* garden = new BasicEntity();
		mygarden.push_back(garden);
		garden->addSprite("assets/StartGarden.tga");
		garden->sprite()->color.r = 205;
		garden->sprite()->color.g = 102;
		garden->sprite()->color.b = 44;
		garden->position = Point2(180, 620);
		garden->scale = Point(0.8f, 0.8f);
		if (n >= 1) {
			garden->position = Point2(n * 115 +225, 620);
			garden->addSprite("assets/StartGardenAlt.tga");
			garden->sprite()->color.r = 205;
			garden->sprite()->color.g = 102;
			garden->sprite()->color.b = 44;
			garden->rotation.z = 3.14;
		}
		layers[5]->addChild(garden);
	}
	// ###############################################################
	// create ufo light for the level
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


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myufo);
	this->removeChild(light);

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

	for (n = 0; n < mypath.size(); ++n) {
		delete mypath[n];
		mypath[n] = NULL;
	}
	mypath.clear();

	for (n = 0; n < mygarden.size(); ++n) {
		delete mygarden[n];
		mygarden[n] = NULL;
	}
	mygarden.clear();

	delete myufo;
	delete light;

}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Update X and Y position of light
	// ###############################################################
	light->position.x = myufo->position.x;
	light->position.y = myufo->position.y;
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	xa = myufo->position.x;
	ya = myufo->position.y;
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Call collision function and set radius of object
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
	// ###############################################################
	// Move car over the road
	// ###############################################################
	// movement car + the speed
	mycar[8]->position.x += 6;
	
	// bounderies car
	// if car reaches bounderies it gets placed at its starting point
	if (mycar[8]->position.x >= 1980) {
		mycar[8]->position.x = -79;
	}
	if (mycar[8]->position.x <= -80) {
		mycar[8]->position.x = 1980;
	}
	// ###############################################################
	// Move person over the road
	// ###############################################################
	if (myperson[3]->position.x != 420) {
		myperson[3]->rotation.z = 4.7;
		if (myperson[3]->position.y >= 810) {
			myperson[3]->position.x -= 2;
		}
	}
	if (myperson[3]->position.x == 420) {
		myperson[3]->position.y -= 2;
		myperson[3]->rotation.z = 0;
	}
	if (myperson[3]->position.y == 800) {
		myperson[3]->rotation.z = 4.7;
		myperson[3]->position.x -= 2;
	}
	if (myperson[3]->position.x <= -40) {
		myperson[3]->position.x = 800;
		myperson[3]->position.y = 1050;
	}
}

void MyScene::collision(float xe, float ye, float re) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xa - xe)*(xa - xe) + (ya - ye)*(ya - ye) < ra*re) {
		myufo->sprite()->color.r = 255;
		myufo->sprite()->color.g = 0;
		myufo->sprite()->color.b = 0;

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
