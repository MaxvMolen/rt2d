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
int totalcar03 = 15;
int totaltree03 = 40;

int n03 = 0;
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
	myaclogo->position = Point2(SWIDTH / 2, 1021);
	layers[5]->addChild(myaclogo);
	myaclogo->scale = Point2(0.3f, 0.3f);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText.tga");
	mytext->position = Point2(SWIDTH / 2 + 155, SHEIGHT / 2 - 15);
	layers[4]->addChild(mytext);
	mytext->scale = Point2(0.5f, 0.7f);
	// ###############################################################
	// text
	// ###############################################################
	text[1]->message("Ufo Game", WHITE);
	text[2]->message("Developer: Max van der Molen", WHITE);
	text[3]->message("Art: Max van der Molen", WHITE);
	text[4]->message("Thanks for playing my game!", WHITE);
	//Position text
	text[1]->position = Point2(665, 410);
	text[2]->position = Point2(665, 470);
	text[3]->position = Point2(665, 500);
	text[4]->position = Point2(665, 560);
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
			roads->position = Point2(1560, (n03-8) * 250 - 267);
			roads->rotation.z = 0;
		}
		// left side
		if (n03 >= 16) {
			roads->position = Point2(128, (n03-16) * 250 - 267);
			roads->rotation.z = 0;
		}
		if (n03 >= 24) {
			roads->position = Point2(359, (n03 - 24) * 250 - 267);
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
		car->position = Point2(1500, 1020);
		car->rotation.z = 3.14;
		if (n03 == 1) {
			car->position = Point2(1615, 900);
			car->rotation.z = 3.14;
		}
		if (n03 == 2) {
			car->position = Point2(1859, 900);
			car->rotation.z = 0;
		}
		if (n03 == 3) {
			car->position = Point2(1739, 1020);
			car->rotation.z = 0;
		}
		if (n03 == 4) {
			car->position = Point2(1739, 700);
			car->rotation.z = 0;
		}
		if (n03 == 5) {
			car->position = Point2(1615, 200);
			car->rotation.z = 3.14;
		}
		if (n03 == 6) {
			car->position = Point2(1500, 200);
			car->rotation.z = 3.14;
		}
		if (n03 == 7) {
			car->position = Point2(1859, 0);
			car->rotation.z = 0;
		}
		// Road left side of the screen
		if (n03 == 8) {
			car->position = Point2(60, 1220);
			car->rotation.z = 3.14;
		}
		if (n03 == 9) {
			car->position = Point2(190, 1100);
			car->rotation.z = 3.14;
		}
		if (n03 == 10) {
			car->position = Point2(420, 1100);
			car->rotation.z = 0;
		}
		if (n03 == 11) {
			car->position = Point2(300, 1220);
			car->rotation.z = 0;
		}
		if (n03 == 12) {
			car->position = Point2(300, 900);
			car->rotation.z = 0;
		}
		if (n03 == 13) {
			car->position = Point2(190, 400);
			car->rotation.z = 3.14;
		}
		if (n03 == 14) {
			car->position = Point2(60, 400);
			car->rotation.z = 3.14;
		}
		layers[3]->addChild(car);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n03 = 0; n03 < totaltree03; ++n03) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(1385, (n03) * 108 + 47);
		if (n03 >= 10) {
			tree->position = Point2(1285, (n03 - 10) * 108 + 47);
		}
		//left side
		if (n03 >= 20) {
			tree->position = Point2(535, (n03 - 20) * 108 + 47);
		}
		if (n03 >= 30) {
			tree->position = Point2(635, (n03 - 30) * 108 + 47);
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
	unufo->position = Point2(580, 250);
	layers[7]->addChild(unufo);
	// ###############################################################
	// create background score counter
	// ###############################################################
	mybscore = new BasicEntity();
	mybscore->addSprite("assets/StartBScore.tga");
	mybscore->position = Point2(95, 0);
	mybscore->scale = Point(1.5f, 1.0f);
	layers[7]->addChild(mybscore);
}

MyScene03::~MyScene03()
{
	// deconstruct and delete the Tree
	this->removeChild(mybscore);
	delete mybscore;

	this->removeChild(unufo);
	delete unufo;

	this->removeChild(light);
	delete light;

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
	// Currentscore counter top right
	// ###############################################################
	std::stringstream cs;
	cs << "Score: " << score.currentscore;
	text[0]->message(cs.str(), YELLOW); // add background so it can be seen better
	text[0]->position.y = 30;
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
	if (unufo->position.y <= 900 && pcount == 0) {
		unufo->position.y += 300 * deltaTime;
		if (unufo->position.y >= 890 && unufo->position.y <= 900) {
			pcount++;
			unufo->addSprite("assets/StartUfo3.tga");
			unufo->sprite()->color.r = 110;
			unufo->sprite()->color.g = 156;
			unufo->sprite()->color.b = 56;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.x <= 1350 && pcount == 1) {
		unufo->position.x += 300 * deltaTime;
		if (unufo->position.x >= 1340 && unufo->position.x <= 1350) {
			pcount++;
			unufo->addSprite("assets/StartUfo1.tga");
			unufo->sprite()->color.r = 255;
			unufo->sprite()->color.g = 171;
			unufo->sprite()->color.b = 103;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.y >= 250 && pcount == 2) {
		unufo->position.y -= 300 * deltaTime;
		if (unufo->position.y >= 240 && unufo->position.y <= 250) {
			pcount++;
			unufo->addSprite("assets/StartUfo2.tga");
			unufo->sprite()->color.r = 236;
			unufo->sprite()->color.g = 16;
			unufo->sprite()->color.b = 18;
			//std::cout << "pcount++";
		}
	}
	if (unufo->position.x >= 580 && pcount == 3) {
		unufo->position.x -= 300 * deltaTime;
		if (unufo->position.x >= 570 && unufo->position.x <= 580) {
			pcount = 0;
			unufo->addSprite("assets/StartUfo1.tga");
			unufo->sprite()->color.r = 255;
			unufo->sprite()->color.g = 171;
			unufo->sprite()->color.b = 103;
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
		mycar[0]->position.y = -100;
	}
	mycar[1]->position.y += 800 * deltaTime; //driving up
	if (mycar[1]->position.y >= 1280) {
		mycar[1]->position.y = -100;
	}
	mycar[2]->position.y -= 600 * deltaTime; //driving down
	if (mycar[2]->position.y <= -100) {
		mycar[2]->position.y = 1200;
	}
	mycar[3]->position.y -= 800 * deltaTime; //driving down
	if (mycar[3]->position.y <= -100) {
		mycar[3]->position.y = 1200;
	}
	mycar[4]->position.y -= 800 * deltaTime; //driving down
	if (mycar[4]->position.y <= -100) {
		mycar[4]->position.y = 1200;
	}
	mycar[5]->position.y += 800 * deltaTime; //driving up
	if (mycar[5]->position.y >= 1280) {
		mycar[5]->position.y = -100;
	}
	mycar[6]->position.y += 600 * deltaTime; //driving down
	if (mycar[6]->position.y >= 1180) {
		mycar[6]->position.y = -100;
	}
	mycar[7]->position.y -= 600 * deltaTime; //driving up
	if (mycar[7]->position.y <= -100) {
		mycar[7]->position.y = 1200;
	}
	//other road
	mycar[8]->position.y += 600 * deltaTime; //driving up
	if (mycar[8]->position.y >= 1180) {
		mycar[8]->position.y = -100;
	}
	mycar[9]->position.y += 800 * deltaTime; //driving up
	if (mycar[9]->position.y >= 1280) {
		mycar[9]->position.y = -100;
	}
	mycar[10]->position.y -= 600 * deltaTime; //driving down
	if (mycar[10]->position.y <= -100) {
		mycar[10]->position.y = 1200;
	}
	mycar[11]->position.y -= 800 * deltaTime; //driving down
	if (mycar[11]->position.y <= -100) {
		mycar[11]->position.y = 1200;
	}
	mycar[12]->position.y -= 800 * deltaTime; //driving down
	if (mycar[12]->position.y <= -100) {
		mycar[12]->position.y = 1200;
	}
	mycar[13]->position.y += 800 * deltaTime; //driving up
	if (mycar[13]->position.y >= 1280) {
		mycar[13]->position.y = -100;
	}
	mycar[14]->position.y += 600 * deltaTime; //driving down
	if (mycar[14]->position.y >= 1180) {
		mycar[14]->position.y = -100;
	}
}