/**
* This class describes MyScene03 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene03.h"

// amount of objects
int totalroads03 = 17;
int totalhouses03 = 3;
int totalparking03 = 16;
int totalcar03 = 9;
int totaltree03 = 9;
int totaltgarage03 = 2;
int totaltbush03 = 4;
int totalperson03 = 4;
int totalpath03 = 14;
int totalgarden03 = 3;
int n03;

//myufo
float xa3 = 1; // x position myufo
float ya3 = 1; // y position myufo
float ra3 = 25; // radius myufo

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
	// create roads for the level
	// ###############################################################
	for (n03 = 0; n03 < totalroads03; ++n03) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n03 * 250, 125);
		roads->rotation.z = 1.57;
		if (n03>=8) {
			roads->position = Point2(SWIDTH / 2, (n03 - 8)* 256 + 352.5);
			roads->rotation.z = 0;
		}
		if(n03>=12) {
			roads->position = Point2(SWIDTH / 2 + 227.5 +(n03-12)*256, SHEIGHT / 2-13);
			roads->rotation.z = 1.57;
		}
		layers[4]->addChild(roads);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n03 = 0; n03 < totalhouses03; ++n03) {
		BasicEntity* house = new BasicEntity();
		myhouse.push_back(house);
		house->addSprite("assets/StartHouse.tga");
		house->position = Point2(n03 * 260 + 180,395);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		if (n03 >= 2) {
			house->position = Point2(n03* 260 + 180,635);
			house->rotation.z = 1.57;
		}
		layers[4]->addChild(house);
	}
	// ###############################################################
	// create parking sports for the level
	// ###############################################################
	for (n03 = 0; n03 < totalparking03; ++n03) {
		BasicEntity* park = new BasicEntity();
		myparking.push_back(park);
		park->addSprite("assets/StartPark.tga");
		park->position = Point2(n03* 125 + 1170, 335);
		park->rotation.z = 3.14;
		if (n03 >= 8) {
			park->position = Point2((n03-4) * 125 + 670, 718);
			park->rotation.z = 0;
		}
		layers[4]->addChild(park);
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n03 = 0; n03 < totalcar03; ++n03) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(n03 * 125 + 1170, 338);
		if (n03 >= 2) {
			car->position = Point2(4 * 125 + 1170, 338);
		}
		if (n03 >= 3) {
			car->rotation.z = 3.14;
			car->position = Point2((n03-2) * 125 + 1170, 715);
		}
		if (n03 >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n03 - 1) * 125 + 1170, 715);
		}
		if (n03 >= 4) {
			car->rotation.z = 3.14;
			car->position = Point2((n03 - 1) * 125 + 1170, 715);
		}
		if (n03 >= 7) {
			car->rotation.z = 1.57;
			car->position = Point2(750, 840);
		}
		if (n03 >= 8) {
			car->rotation.z = 1.57;
			car->position = Point2(-79, 60);
		}
		layers[5]->addChild(car);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n03 = 0; n03 < totaltree03; ++n03) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(n03 * 200 + 1170, 855);
		if (n03 >= 4) {
			tree->position = Point2(n03 * 200 + 465, 982);
			tree->rotation.z = 3.14;
		}
		if (n03 >= 8) {
			tree->position = Point2(655,425 );
		}
		layers[6]->addChild(tree);
	}
	// ###############################################################
	// create garages for the level
	// ###############################################################
	for (n03 = 0; n03 < totaltgarage03; ++n03) {
		BasicEntity* garage = new BasicEntity();
		mygarage.push_back(garage);
		garage->addSprite("assets/StartGarage.tga");
		garage->sprite()->color.r = 171;
		garage->sprite()->color.g = 167;
		garage->sprite()->color.b = 154;
		garage->position = Point2(-25, 420);
		garage->scale = Point(0.7f, 0.7f);
		if (n03 >= 1) {
			garage->position = Point2(680, 840);
			garage->rotation.z = 1.57;
		}
		layers[5]->addChild(garage);
	}
	// ###############################################################
	// create bushes for the level
	// ###############################################################
	for (n03 = 0; n03 < totaltbush03; ++n03) {
		BasicEntity* bush = new BasicEntity();
		mybush.push_back(bush);
		bush->addSprite("assets/StartBush.tga");
		bush->sprite()->color.r = 110;
		bush->sprite()->color.g = 156;
		bush->sprite()->color.b = 56;
		bush->position = Point2(n03 * 100 + 615, 310);
		if (n03 >= 2) {
			bush->position = Point2(790, (n03 - 2) * 100 + 370);
		}
		layers[5]->addChild(bush);
	}
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n03 = 0; n03 < totalperson03; ++n03) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(n03 * 218 + 190, 576);
		person->scale = Point(0.7f, 0.7f);
		person->rotation.z = 3.14;
		if (n03 >= 2) {
			person->position = Point2((n03-1) * 190 + 180, 650);
			person->rotation.z = 1.57;
		}
		if (n03 >= 3) {
			person->position = Point2(800,1050);
			person->rotation.z = 4.7;
		}
		layers[6]->addChild(person);
	}
	// ###############################################################
	// create path for the level
	// ###############################################################
	for (n03 = 0; n03 < totalpath03; ++n03) {
		BasicEntity* path = new BasicEntity();
		mypath.push_back(path);
		path->addSprite("assets/StartPRoad.tga");
		path->rotation.z = 1.57;
		path->position = Point2((n03 * -75)+787.5, 1043);
		path->scale = Point(0.7f, 0.7f);
		if (n03 >= 5) {
			path->position = Point2((n03 * -75) + 787.5, 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 3.14;
		}
		if (n03 >= 6) {
			path->position = Point2(((5) * -75) + 787.5,(n03-5)*-75 +1036);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 0;
		}
		if (n03 >= 8) {
			path->position = Point2(((5) * -75) + 787.5, (n03 - 5)*-75 + 1036);
			path->addSprite("assets/StartPRoadCurve.tga");
			path->rotation.z = 6.27;
		}
		if (n03 >= 9) {
			path->position = Point2(((n03 -2.9) * -75) + 787.5, (3.18) * -75 + 1043);
			path->addSprite("assets/StartPRoad.tga");
			path->rotation.z = 1.57;
		}
		layers[5]->addChild(path);
	}
	// ###############################################################
	// create garden for the level
	// ###############################################################
	for (n03 = 0; n03 < totalgarden03; ++n03) {
		BasicEntity* garden = new BasicEntity();
		mygarden.push_back(garden);
		garden->addSprite("assets/StartGarden.tga");
		garden->sprite()->color.r = 205;
		garden->sprite()->color.g = 102;
		garden->sprite()->color.b = 44;
		garden->position = Point2(180, 620);
		garden->scale = Point(0.8f, 0.8f);
		if (n03 >= 1) {
			garden->position = Point2(n03 * 115 +225, 620);
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


MyScene03::~MyScene03()
{
	// deconstruct and delete the Tree
	this->removeChild(myback);
	this->removeChild(myufo);
	this->removeChild(light);

	for (n03 = 0; n03 < myroads.size(); ++n03) {
		delete myroads[n03];
		myroads[n03] = NULL;
	}
	myroads.clear();

	for (n03 = 0; n03 < myhouse.size(); ++n03) {
		delete myhouse[n03];
		myhouse[n03] = NULL;
	}
	myhouse.clear();
	
	for (n03 = 0; n03 < myparking.size(); ++n03) {
		delete myparking[n03];
		myparking[n03] = NULL;
	}
	myparking.clear();
	
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

	for (n03 = 0; n03 < totaltgarage03; ++n03) {
		delete mygarage[n03];
		mygarage[n03] = NULL;
	}

	mygarage.clear();

	for (n03 = 0; n03 < mybush.size(); ++n03) {
		delete mybush[n03];
		mybush[n03] = NULL;
	}
	mybush.clear();
	
	for (n03 = 0; n03 < myperson.size(); ++n03) {
		delete myperson[n03];
		myperson[n03] = NULL;
	}
	myperson.clear();

	for (n03 = 0; n03 < mypath.size(); ++n03) {
		delete mypath[n03];
		mypath[n03] = NULL;
	}
	mypath.clear();

	for (n03 = 0; n03 < mygarden.size(); ++n03) {
		delete mygarden[n03];
		mygarden[n03] = NULL;
	}
	mygarden.clear();

	delete myback;
	delete myufo;
	delete light;

}

void MyScene03::update(float deltaTime)
{
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
		CoreScene::sceneselect(0); // main menu
	}
	// ###############################################################
	// Update X and Y position of light
	// ###############################################################
	light->position.x = myufo->position.x;
	light->position.y = myufo->position.y;
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	xa3 = myufo->position.x;
	ya3 = myufo->position.y;
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Call collision function and set radius of object
	// ###############################################################
	for (n03 = 0; n03 < mycar.size(); ++n03) {
		collision(xa3, ya3, ra3,mycar[n03]->position.x, mycar[n03]->position.y, 125, 1);
	}
	for (n03 = 0; n03 < mytree.size(); ++n03) {
		collision(xa3, ya3, ra3,mytree[n03]->position.x, mytree[n03]->position.y, 50, 2);
	}
	for (n03 = 0; n03 < myperson.size(); ++n03) {
		collision(xa3, ya3, ra3,myperson[n03]->position.x, myperson[n03]->position.y, 25, 3);
	}
	//test
	//collision(myhouse[2]->position.x, myhouse[2]->position.y, 200);
	// ###############################################################
	// Move car over the road + bounderies
	// ###############################################################
	mycar[8]->position.x += 600 * deltaTime;
	
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
			myperson[3]->position.x -= 200 * deltaTime;
		}
	}
	if (myperson[3]->position.x <= 420) {
		myperson[3]->position.y -= 200 * deltaTime;
		myperson[3]->position.x += 200 * deltaTime;
		myperson[3]->rotation.z = 0;
	}
	if (myperson[3]->position.y == 800) {
		myperson[3]->rotation.z = 4.7;
		myperson[3]->position.x -= 200 * deltaTime;
	}
	if (myperson[3]->position.x <= -40) {
		myperson[3]->position.x = 800;
		myperson[3]->position.y = 1050;
	}
}

void MyScene03::collision(float xu, float yu, float ru, float xe, float ye, float re, float no) {
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
					score.addscore(10);
				}
				else {
					score.subtractscore(10);
				}
				//remove object
			}
			else if (no == 2) {
				//collision object
				//std::cout << "Tree";
				//std::cout << "|";
				if (MyUfo::noa == 3) {
					score.addscore(10);
				}
				else {
					score.subtractscore(10);
				}
				//remove object
			}
			else if (no == 3) {
				//collision object
				//std::cout << "Person";
				//std::cout << "|";
				if (MyUfo::noa == 2) {
					score.addscore(10);
				}
				else {
					score.subtractscore(10);
				}/*
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
			*/
			}
		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}