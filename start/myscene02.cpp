/**
* This class describes MyScene02 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene02.h"

// amount of objects
int totalroads02 = 17;
int totalhouses02 = 3;
int totalparking02 = 16;
int totalcar02 = 9;
int totaltree02 = 9;
int totaltgarage02 = 2;
int totaltbush02 = 4;
int totalperson02 = 4;
int totalpath02 = 14;
int totalgarden02 = 3;
int n02;

int pcounter02;

bool started02 = true;

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
		roads->position = Point2(125 + n02 * 250, 125);
		roads->rotation.z = 1.57;
		if (n02>=8) {
			roads->position = Point2(SWIDTH / 2, (n02 - 8)* 256 + 352.5);
			roads->rotation.z = 0;
		}
		if(n02>=12) {
			roads->position = Point2(SWIDTH / 2 + 227.5 +(n02-12)*256, SHEIGHT / 2-13);
			roads->rotation.z = 1.57;
		}
		layers[4]->addChild(roads);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n02 = 0; n02 < totalhouses02; ++n02) {
		BasicEntity* house = new BasicEntity();
		myhouse.push_back(house);
		house->addSprite("assets/StartHouse.tga");
		house->position = Point2(n02 * 260 + 180,395);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		if (n02 >= 2) {
			house->position = Point2(n02* 260 + 180,635);
			house->rotation.z = 1.57;
		}
		layers[4]->addChild(house);
	}
	// ###############################################################
	// create parking sports for the level
	// ###############################################################
	for (n02 = 0; n02 < totalparking02; ++n02) {
		BasicEntity* park = new BasicEntity();
		myparking.push_back(park);
		park->addSprite("assets/StartPark.tga");
		park->position = Point2(n02* 125 + 1170, 335);
		park->rotation.z = 3.14;
		if (n02 >= 8) {
			park->position = Point2((n02-4) * 125 + 670, 718);
			park->rotation.z = 0;
		}
		layers[4]->addChild(park);
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n02 = 0; n02 < totalcar02; ++n02) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(n02 * 125 + 1170, 338);
		if (n02 >= 2) {
			car->position = Point2(4 * 125 + 1170, 338);
		}
		if (n02 >= 3) {
			car->rotation.z = 3.14;
			car->position = Point2((n02-2) * 125 + 1170, 715);
		}
		if (n02 >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n02 - 1) * 125 + 1170, 715);
		}
		if (n02 >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n02 - 1) * 125 + 1170, 715);
		}
		if (n02 >= 7) {
			car->rotation.z = 1.57;
			car->position = Point2(750, 840);
		}
		if (n02 >= 8) {
			car->rotation.z = 1.57;
			car->position = Point2(-79, 60);
		}
		layers[5]->addChild(car);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n02 = 0; n02 < totaltree02; ++n02) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(n02 * 200 + 1170, 855);
		if (n02 >= 4) {
			tree->position = Point2(n02 * 200 + 465, 982);
			tree->rotation.z = 3.14;
		}
		if (n02 >= 8) {
			tree->position = Point2(655,425 );
		}
		layers[6]->addChild(tree);
	}
	// ###############################################################
	// create garages for the level
	// ###############################################################
	for (n02 = 0; n02 < totaltgarage02; ++n02) {
		BasicEntity* garage = new BasicEntity();
		mygarage.push_back(garage);
		garage->addSprite("assets/StartGarage.tga");
		garage->sprite()->color.r = 171;
		garage->sprite()->color.g = 167;
		garage->sprite()->color.b = 154;
		garage->position = Point2(-25, 420);
		garage->scale = Point(0.7f, 0.7f);
		if (n02 >= 1) {
			garage->position = Point2(680, 840);
			garage->rotation.z = 1.57;
		}
		layers[5]->addChild(garage);
	}
	// ###############################################################
	// create bushes for the level
	// ###############################################################
	for (n02 = 0; n02 < totaltbush02; ++n02) {
		BasicEntity* bush = new BasicEntity();
		mybush.push_back(bush);
		bush->addSprite("assets/StartBush.tga");
		bush->sprite()->color.r = 110;
		bush->sprite()->color.g = 156;
		bush->sprite()->color.b = 56;
		bush->position = Point2(n02 * 100 + 615, 310);
		if (n02 >= 2) {
			bush->position = Point2(790, (n02 - 2) * 100 + 370);
		}
		layers[5]->addChild(bush);
	}
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n02 = 0; n02 < totalperson02; ++n02) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(n02 * 218 + 190, 576);
		person->scale = Point(0.7f, 0.7f);
		person->rotation.z = 3.14;
		if (n02 >= 2) {
			person->position = Point2((n02-1) * 190 + 180, 650);
			person->rotation.z = 1.57;
		}
		if (n02 >= 3) {
			person->position = Point2(800,1050);
			person->rotation.z = 4.7;
		}
		layers[6]->addChild(person);
	}
	// ###############################################################
	// create path for the level
	// ###############################################################
	for (n02 = 0; n02 < totalpath02; ++n02) {
		BasicEntity* path = new BasicEntity();
		mypath.push_back(path);
		path->addSprite("assets/StartPRoad.tga");
		path->rotation.z = 1.57;
		path->position = Point2((n02 * -75)+787.5, 1043);
		path->scale = Point(0.7f, 0.7f);
		if (n02 >= 5) {
			path->position = Point2((n02 * -75) + 787.5, 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 3.14;
		}
		if (n02 >= 6) {
			path->position = Point2(((5) * -75) + 787.5,(n02-5)*-75 +1036);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 0;
		}
		if (n02 >= 8) {
			path->position = Point2(((5) * -75) + 787.5, (n02 - 5)*-75 + 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 6.27;
		}
		if (n02 >= 9) {
			path->position = Point2(((n02 -2.9) * -75) + 787.5, (3.18) * -75 + 1043);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 1.57;
		}
		layers[5]->addChild(path);
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
		garden->position = Point2(180, 620);
		garden->scale = Point(0.8f, 0.8f);
		if (n02 >= 1) {
			garden->position = Point2(n02 * 115 +225, 620);
			garden->addSprite("assets/StartGardenAlt.tga");
			garden->sprite()->color.r = 205;
			garden->sprite()->color.g = 102;
			garden->sprite()->color.b = 44;
			garden->rotation.z = 3.14;
		}
		layers[5]->addChild(garden);
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
	// deconstruct and delete the Tree
	this->removeChild(myback);
	delete myback;

	this->removeChild(myufo);
	delete myufo;

	this->removeChild(light);
	delete light;

	for (n02 = 0; n02 < myroads.size(); ++n02) {
		delete myroads[n02];
		myroads[n02] = NULL;
	}
	myroads.clear();

	for (n02 = 0; n02 < myhouse.size(); ++n02) {
		delete myhouse[n02];
		myhouse[n02] = NULL;
	}
	myhouse.clear();
	
	for (n02 = 0; n02 < myparking.size(); ++n02) {
		delete myparking[n02];
		myparking[n02] = NULL;
	}
	myparking.clear();
	
	for (n02 = 0; n02 < mycar.size(); ++n02) {
		delete mycar[n02];
		mycar[n02] = NULL;
	}
	mycar.clear();

	for (n02 = 0; n02 < mytree.size(); ++n02) {
		delete mytree[n02];
		mytree[n02] = NULL;
	}
	mytree.clear();

	for (n02 = 0; n02 < totaltgarage02; ++n02) {
		delete mygarage[n02];
		mygarage[n02] = NULL;
	}

	mygarage.clear();

	for (n02 = 0; n02 < mybush.size(); ++n02) {
		delete mybush[n02];
		mybush[n02] = NULL;
	}
	mybush.clear();
	
	for (n02 = 0; n02 < myperson.size(); ++n02) {
		delete myperson[n02];
		myperson[n02] = NULL;
	}
	myperson.clear();

	for (n02 = 0; n02 < mypath.size(); ++n02) {
		delete mypath[n02];
		mypath[n02] = NULL;
	}
	mypath.clear();

	for (n02 = 0; n02 < mygarden.size(); ++n02) {
		delete mygarden[n02];
		mygarden[n02] = NULL;
	}
	mygarden.clear();
}

void MyScene02::update(float deltaTime)
{
	// ###############################################################
	// Set Movement off / on
	// ###############################################################
	if (started02 == false) {
		myufo->movementonoff = false;
	}
	else{
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
	// Change scene when all items are removed
	// ###############################################################
	if (mytree.size() == 0 && myperson.size() == 0 && mycar.size() == 0) {
		myufo->standard();
		CoreScene::sceneselect(0); // main menu
	}
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		myufo->standard();
		CoreScene::sceneselect(0);
	}
	// ###############################################################
	// Pause game by pressing p
	// ###############################################################
	if (input()->getKeyDown(P)) {
		started02 = false;
		myufo->movementonoff = false;
		pcounter02++;
	}
	if (pcounter02 == 2) {
		started02 = true;
		myufo->movementonoff = true;
		pcounter02 = 0;
	}
	// ###############################################################
	// Update X and Y position of light
	// ###############################################################
	if (started02 == true) {
		light->position.x = myufo->position.x;
		light->position.y = myufo->position.y;
	}
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	if (started02 == true) {
		xa2 = myufo->position.x;
		ya2 = myufo->position.y;
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Call collision function and set radius of object
	// ###############################################################
	if (started02 == true) {
		for (n02 = 0; n02 < mycar.size(); ++n02) {
			collision(xa2, ya2, ra2, mycar[n02]->position.x, mycar[n02]->position.y, 125, 1, deltaTime);
		}
		for (n02 = 0; n02 < mytree.size(); ++n02) {
			collision(xa2, ya2, ra2, mytree[n02]->position.x, mytree[n02]->position.y, 50, 2, deltaTime);
		}
		for (n02 = 0; n02 < myperson.size(); ++n02) {
			collision(xa2, ya2, ra2, myperson[n02]->position.x, myperson[n02]->position.y, 25, 3, deltaTime);
		}
	}
	// ###############################################################
	// Move car over the road + bounderies
	// ###############################################################
	if (started02 == true) {
		mycar[8]->position.x += 600 * deltaTime;

		if (mycar[8]->position.x >= 1980) {
			mycar[8]->position.x = -79;
		}
		if (mycar[8]->position.x <= -80) {
			mycar[8]->position.x = 1980;
		}
	}
	// ###############################################################
	// Move person over the road
	// ###############################################################
	if (started02 == true) {
		if (myperson[3]->position.x != 420 && myperson[3]->position.y >= 810) {
			myperson[3]->rotation.z = 4.7;
			myperson[3]->position.x -= 200 * deltaTime;
		}
		if (myperson[3]->position.y >= 800 && myperson[3]->position.x <= 415) {
			myperson[3]->position.y -= 200 * deltaTime;
			myperson[3]->position.x += 200 * deltaTime;
			myperson[3]->rotation.z = 0;
		}
		if (myperson[3]->position.y >= 800 && myperson[3]->position.y <= 810) {
			myperson[3]->position.y += 200 * deltaTime;
			myperson[3]->position.x -= 200 * deltaTime;
			myperson[3]->rotation.z = 4.7;
		}
		if (myperson[3]->position.x <= -40) {
			myperson[3]->position.x = 800;
			myperson[3]->position.y = 1050;
		}
	}
}

void MyScene02::collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xu - xe)*(xu - xe) + (yu - ye)*(yu - ye) < ru*re) {

		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {
			//std::cout << score.currentscore;
			//std::cout << "|";
			if (no == 1){
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
				//std::cout << "Tree";
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
				}//
				std::vector<MyPerson*>::iterator it = myperson.begin();
				while (it != myperson.end()){
					if (no == 2) { // causes the problems if the same as the object 3
						*it;
						delete(*it);
						it = myperson.erase(it);
					}
					else {
						++it;
					}
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