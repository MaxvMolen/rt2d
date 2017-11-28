/**
* This class describes MyScene behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include <fstream>
#include <sstream>

#include "myscene.h"

int totalroads = 16;
int totalhouses = 3;
<<<<<<< Updated upstream
int totalparking = 16;
int totalcar = 8;
int totaltree = 8;
int n; 
=======
int totalparking = 15;
int totalcar = 8;
int totaltree = 8;
int n;
>>>>>>> Stashed changes

MyScene::MyScene() : CoreScene()
{
	// start the timer.
	t.start();
	myperson = new MyPerson();
<<<<<<< Updated upstream

=======
	myufo = new MyUfo();
>>>>>>> Stashed changes
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n = 0; n < totalroads; ++n) {
		myroads[n] = new BasicEntity();
		myroads[n]->addSprite("assets/StartRoad.tga");
		myroads[n]->position = Point2(125 + n * 250, 125);
		myroads[n]->rotation.z = 1.57;
		if (n>=8) {
			myroads[n]->position = Point2(SWIDTH / 2, (n - 8)* 200 + 352.5);
			myroads[n]->rotation.z = 0;
		}
		if(n>=12) {
			myroads[n]->position = Point2(SWIDTH / 2 + 227.5 +(n-12)*256, SHEIGHT / 2-13);
			myroads[n]->rotation.z = 1.57;
		}
		layers[4]->addChild(myroads[n]);
	}
	// ###############################################################
	// create houses for the level
	// ###############################################################
	for (n = 0; n < totalhouses; ++n) {
		myhouse[n] = new BasicEntity();
		myhouse[n]->addSprite("assets/StartHouse.tga");
		myhouse[n]->position = Point2(n * 260 + 180,395);
		myhouse[n]->sprite()->color.r = 255;
		myhouse[n]->sprite()->color.g = 88;
		myhouse[n]->sprite()->color.b = 30;
		if (n >= 2) {
			myhouse[n]->position = Point2(n* 260 + 180,625);
			myhouse[n]->rotation.z = 1.57;
		}
		layers[4]->addChild(myhouse[n]);
	}
	// ###############################################################
	// create parking sports for the level
	// ###############################################################
	for (n = 0; n < totalparking; ++n) {
		myparking[n] = new BasicEntity();
		myparking[n]->addSprite("assets/StartPark.tga");
		myparking[n]->position = Point2(n* 125 + 1170, 335);
		myparking[n]->rotation.z = 3.14;
		if (n >= 8) {
			myparking[n]->position = Point2((n-4) * 125 + 670, 718);
			myparking[n]->rotation.z = 0;
		}
		layers[4]->addChild(myparking[n]);
	}
	// ###############################################################
	// create car's for the level
	// ###############################################################
	for (n = 0; n < totalcar; ++n) {
		mycar[n] = new MyCar();
		mycar[n]->position = Point2(n * 125 + 1170, 338);
		if (n >= 4) {
			mycar[n]->position = Point2(n * 125 + 670, 715);
			mycar[n]->rotation.z = 3.14;
		}
		layers[5]->addChild(mycar[n]);
	}
	// ###############################################################
	// create tree's for the level
	// ###############################################################
	for (n = 0; n < totaltree; ++n) {
		mytree[n] = new MyTree();
		mytree[n]->position = Point2(n * 200 + 1170, 855);
		if (n >= 4) {
			mytree[n]->position = Point2(n * 200 + 465, 982);
			mytree[n]->rotation.z = 3.14;
		}
		layers[5]->addChild(mytree[n]);
	}

<<<<<<< Updated upstream
	myperson->position = Point2(SWIDTH / 2, SHEIGHT / 2); 
=======
	myufo->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	myperson->position = Point2(SWIDTH / 2, SHEIGHT / 2); 
	layers[6]->addChild(myufo);
>>>>>>> Stashed changes
	layers[5]->addChild(myperson);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myperson);
<<<<<<< Updated upstream
=======
	this->removeChild(myufo);
>>>>>>> Stashed changes

	for (n = 0; n < totalroads; ++n) {
		this->removeChild(myroads[n]);
		delete myroads[n];
	}

	for (n = 0; n < totalhouses; ++n) {
		this->removeChild(myhouse[n]);
		delete myhouse[n];
	}

	for (n = 0; n < totalparking; ++n) {
		this->removeChild(myparking[n]);
		delete myparking[n];
	}

	for (n = 0; n < totalcar; ++n) {
		this->removeChild(mycar[n]);
		delete mycar[n];
	}

	for (n = 0; n < totaltree; ++n) {
		this->removeChild(mytree[n]);
		delete mytree[n];
	}

	// delete myentity from the heap (there was a 'new' in the constructor)
<<<<<<< Updated upstream
	delete myperson;
=======
	delete myufo;
	delete myperson;

>>>>>>> Stashed changes
}

void MyScene::update(float deltaTime)
{	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
<<<<<<< Updated upstream

}
=======
}
>>>>>>> Stashed changes
