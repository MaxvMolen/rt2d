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

int n00 = 0;
// total moved
int tm00 = 0;
// pause counter if its 0 its not paused if its 1 the game is paused
int pcounter00 = 0;

// has the game started yes or no
bool started00 = false;
// are you on the menu yes or no

bool menu = true;
// switch movement on and of
bool switchs = false;

bool tree00 = false;
bool car00 = false;
bool person00 = false;
//myufo
float xa0 = 1; // x position myufo
float ya0 = 1; // y position myufo
float ra0 = 25; // radius myufo

//myufo2
float xa02 = 1; // x position myufo2
float ya02 = 1; // y position myufo2
float ra02 = 25; // radius myufo2

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
			roads->position = Point2(1465, (n00 - 13) * 250 - 267);
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
		house->position = Point2(200, n00 * 260 + 150);
		house->sprite()->color.r = 255;
		house->sprite()->color.g = 88;
		house->sprite()->color.b = 30;
		house->rotation.z = 1.57;
		if (n00 >= 3) {
			house->position = Point2(1730, (n00-3) * 260 +150);
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
		bbench->position = Point2(800, 375);
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
		sbench->position = Point2(750, (n00) * 550 + 100);
		sbench->rotation.z = -1.57;
		if (n00 >= 2) {
			sbench->rotation.z = -4.71;
			sbench->position = Point2(1175, (n00 - 2) * 550 + 100);
		}
		layers[2]->addChild(sbench);
	}
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n00 = 0; n00 < totalperson00; ++n00) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(725, (n00) * 550 + 100);
		person->rotation.z = 1.57;
		person->scale = Point(0.8f, 0.8f);
		if (n00 >= 2) {
			person->rotation.z = 4.71;
			person->position = Point2(1200, (n00 - 2) * 550 + 100);
		}
		if (n00 >= 4) {
			person->rotation.z = 0;
			person->position = Point2((n00 - 4) * 380 + 770, 432);
		}
		if (n00 >= 6) {
			person->rotation.z = 3.14;
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
	// create Credits header
	// ###############################################################
	mycredits = new BasicEntity();
	mycredits->addSprite("assets/StartCreditsM.tga");
	mycredits->position = Point2(SWIDTH / 2, 715);
	mycredits->scale = Point(0.8f, 0.8f);
	layers[5]->addChild(mycredits);
	// ###############################################################
	// create Ufo
	// ###############################################################
	myufo = new MyUfo();
	myufo->position = Point2(SWIDTH / 2-100, SHEIGHT / 2);
	layers[7]->addChild(myufo);
	// ###############################################################
	// create player 2
	// ###############################################################
	myufo2 = new MyUfo2();
	myufo2->position = Point2(SWIDTH / 2+100, SHEIGHT / 2);
	layers[7]->addChild(myufo2);
	// ###############################################################
	// create light for both players
	// ###############################################################
	for (n00 = 0; n00 < 2; ++n00) {
		BasicEntity* mylight = new BasicEntity();
		light.push_back(mylight);
		mylight->addSprite("assets/StartUfoLight.tga");
		mylight->scale = Point(0.7f, 0.7f);
		mylight->sprite()->color.r = 181;
		mylight->sprite()->color.g = 181;
		mylight->sprite()->color.b = 181;
		layers[6]->addChild(mylight);
	}
	// ###############################################################
	// create pause
	// ###############################################################
	mypause = new BasicEntity();
	mypause->addSprite("assets/StartPause.tga");
	mypause->position = Point2(SWIDTH / 1-75, 75);
	mypause->sprite()->color.r = 255;
	mypause->sprite()->color.g = 223;
	mypause->sprite()->color.b = 5;
	layers[0]->addChild(mypause);
	// ###############################################################
	// create background score counter
	// ###############################################################
	mybscore = new BasicEntity();
	mybscore->addSprite("assets/StartBScore.tga");
	mybscore->position = Point2(85, 0);
	mybscore->scale = Point(2.0f, 1.0f);
	layers[7]->addChild(mybscore);
	// ###############################################################
	// create home and pause buttons
	// ###############################################################
	// home button
	myhomebutton = new BasicEntity();
	myhomebutton->addSprite("assets/StartHomeButton.tga");
	myhomebutton->position = Point2(40, 110);
	myhomebutton->scale = Point(0.5f, 0.5f);
	layers[7]->addChild(myhomebutton);
	// pause button
	mypausebutton = new BasicEntity();
	mypausebutton->addSprite("assets/StartPauseButton.tga");
	mypausebutton->position = Point2(40, 180);
	mypausebutton->scale = Point(0.5f, 0.5f);
	layers[7]->addChild(mypausebutton);
	// ###############################################################
	// create name plate for both players
	// ###############################################################
	for (n00 = 0; n00 < 2; ++n00) {
		BasicEntity* myplates = new BasicEntity();
		myplate.push_back(myplates);
		myplates->addSprite("assets/name.tga");
		myplates->sprite()->color.r = 181;
		myplates->sprite()->color.g = 181;
		myplates->sprite()->color.b = 181;
		if (n00 > 0) {
			myplates->addSprite("assets/namep2.tga");
			myplates->sprite()->color.r = 181;
			myplates->sprite()->color.g = 181;
			myplates->sprite()->color.b = 181;
		}
		layers[6]->addChild(myplates);
	}
}

MyScene00::~MyScene00()
{
	this->removeChild(myhomebutton);
	delete myhomebutton;

	this->removeChild(mypausebutton);
	delete mypausebutton;

	this->removeChild(mybscore);
	delete mybscore;

	this->removeChild(myufo);
	delete myufo;

	this->removeChild(myufo2);
	delete myufo2;

	this->removeChild(myback);
	delete myback;

	this->removeChild(myheader);
	delete myheader;

	this->removeChild(myheaderstart);
	delete myheaderstart;

	this->removeChild(myheadertutorial);
	delete myheadertutorial;

	this->removeChild(mycredits);
	delete mycredits;

	this->removeChild(mypause);
	delete mypause;

	for (n00 = 0; n00 < light.size(); ++n00) {
		delete light[n00];
		light[n00] = NULL;
	}
	light.clear();

	for (n00 = 0; n00 < myplate.size(); ++n00) {
		delete myplate[n00];
		myplate[n00] = NULL;
	}
	myplate.clear();

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

	for (n00 = 0; n00 < mybenchb.size(); ++n00) {
		delete mybenchb[n00];
		mybenchb[n00] = NULL;
	}
	mybenchb.clear();

	for (n00 = 0; n00 < mybenchs.size(); ++n00) {
		delete mybenchs[n00];
		mybenchs[n00] = NULL;
	}
	mybenchs.clear();
}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Set Movement off / on
	// ###############################################################
	if (started00 == false) {
		myufo->movementonoff = false;
		myufo2->movementonoff = false;
		if (switchs == true) {
			menu = true;
			switchs = false;
			pcounter00 = 0;
		}
	}
	else {
		myufo->movementonoff = true;
		myufo2->movementonoff = true;
	}
	// ###############################################################
	// Currentscore counter top right
	// ###############################################################
	std::stringstream cs;
	cs << "Score: " << score.currentscore;
	text[0]->message(cs.str(), YELLOW);
	text[0]->position.y = 30;
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		layers[0]->addChild(mypause);
		started00 = false;
		menu = true;
	}
	// ###############################################################
	// Start game
	// ###############################################################
	if (menu != false) {
		// game started
		if (input()->getKey(Enter)) {
			pcounter00 = 0;
			layers[0]->addChild(mypause);
			myufo->movementonoff = true;
			myufo2->movementonoff = true;
			layers[7]->addChild(myufo);
			layers[7]->addChild(myufo2);
			myheader->position.x = -500;
			myheaderstart->position.x = -500;
			myheadertutorial->position.x = -500;
			mycredits->position.x = -500;
			myhomebutton->position = Point2(40, 110);
			mypausebutton->position = Point2(40, 180);
			started00 = true;
			menu = false;
		}
		// game not started / menu
		else {
			layers[0]->addChild(myufo);
			myufo->movementonoff = false;
			layers[0]->addChild(myufo2);
			myufo2->movementonoff = false;
			light[0]->position.x = -100;
			light[0]->position.y = -100;
			light[1]->position.x = -100;
			light[1]->position.y = -100;
			myplate[0]->position.x = -100;
			myplate[0]->position.y = -100;
			myplate[1]->position.x = -100;
			myplate[1]->position.y = -100;
			myhomebutton->position.x = -500;
			mypausebutton->position.x = -500;
			myheader->position = Point2(SWIDTH / 2, 125);
			myheaderstart->position = Point2(SWIDTH / 2, 335);
			myheadertutorial->position = Point2(SWIDTH / 2, 525);
			mycredits->position = Point2(SWIDTH / 2, 715);
		}
		// go to tutorial
		if (input()->getKeyUp(KeyCode::Space)) {
			myufo->standard();
			myufo2->standard();
			layers[0]->addChild(mypause);
			activescene++;
			score.storedscore == score.currentscore;
			score.setscore(deltaTime, 0);
		}
		// go to credits
		if (input()->getKeyUp(KeyCode::RightShift)) {
			myufo->standard();
			myufo2->standard();
			layers[0]->addChild(mypause);
			CoreScene::sceneselect(3);
		}
		// go to credits
		if (input()->getKeyUp(KeyCode::LeftShift)) {
			myufo->standard();
			myufo2->standard();
			layers[0]->addChild(mypause);
			CoreScene::sceneselect(3);
		}
	}
	// ###############################################################
	// Pause game by pressing p
	// ###############################################################
	// paused the game
	if (input()->getKeyDown(P) && menu == false) {
		started00 = false;
		myufo->movementonoff = false;
		myufo2->movementonoff = false;
		pcounter00++;
		layers[8]->addChild(mypause);
	}
	// resume game
	if (pcounter00 == 2) {
		started00 = true;
		myufo->movementonoff = true;
		myufo2->movementonoff = true;
		pcounter00 = 0;
		layers[0]->addChild(mypause);
	}
	// ##############################################################################################################################
	// last level (for testing)
	// ##############################################################################################################################
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		myufo->movementonoff = true;
		myufo2->movementonoff = true;
		started00 = false;
		switchs = true;
		myufo->standard();
		myufo2->standard();
		layers[0]->addChild(mypause);
		CoreScene::sceneselect(2);
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
	// ###############################################################
	// Update X and Y position of light for player 1 and player 2
	// ###############################################################
	if (started00 == true) {
		light[0]->position.x = myufo->position.x;
		light[0]->position.y = myufo->position.y;
	}
	if (started00 == true) {
		light[1]->position.x = myufo2->position.x;
		light[1]->position.y = myufo2->position.y;
	}
	// ###############################################################
	// Update X and Y position of plate for player 1 and player 2
	// ###############################################################
	if (started00 == true) {
		myplate[0]->position.x = myufo->position.x;
		myplate[0]->position.y = myufo->position.y - 70;
	}
	if (started00 == true) {
		myplate[1]->position.x = myufo2->position.x;
		myplate[1]->position.y = myufo2->position.y - 70;
	}
	// ###############################################################
	// Update X and Y position of myufo
	// ###############################################################
	if (started00 == true) {
		xa0 = myufo->position.x;
		ya0 = myufo->position.y;
	}
	// ###############################################################
	// Update X and Y position of myufo2
	// ###############################################################
	if (started00 == true) {
		xa02 = myufo2->position.x;
		ya02 = myufo2->position.y;
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

		// collision player 2 
		// on collision with an object currently player 1 will be teleported to that point and player 2 will not be affected.
		for (n00 = 0; n00 < mycar.size(); ++n00) {
			collision(xa02, ya02, ra02, mycar[n00]->position.x, mycar[n00]->position.y, 125, 1, deltaTime);
		}
		for (n00 = 0; n00 < mytree.size(); ++n00) {
			collision(xa02, ya02, ra02, mytree[n00]->position.x, mytree[n00]->position.y, 50, 2, deltaTime);
		}
		for (n00 = 0; n00 < myperson.size(); ++n00) {
			collision(xa02, ya02, ra02, myperson[n00]->position.x, myperson[n00]->position.y, 26, 3, deltaTime);
		}
	}
	// ###############################################################
	// Update mouse position
	// ###############################################################
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mousepos = Point2(mousex, mousey);
	// ###############################################################
	// Buttons menu
	// ###############################################################
	if (menu == true) {
		//myheaderstart | start button
		if (mousepos.y >= myheaderstart->position.y - 90 && mousepos.y <= myheaderstart->position.y + 90 &&  mousepos.x <= myheaderstart->position.x + 210 && mousepos.x >= myheaderstart->position.x-210 && input()->getMouseDown(0)) {
			pcounter00 = 0;
			layers[0]->addChild(mypause);
			myufo->movementonoff = true;
			layers[7]->addChild(myufo);
			myufo2->movementonoff = true;
			layers[7]->addChild(myufo2);
			myhomebutton->position = Point2(40, 110);
			mypausebutton->position = Point2(40, 180);
			myheader->position.x = -500;
			myheaderstart->position.x = -500;
			myheadertutorial->position.x = -500;
			mycredits->position.x = -500;
			started00 = true;
			menu = false;
		}
		//myheadertutorial | tutorial button
		if (mousepos.y >= myheadertutorial->position.y - 90 && mousepos.y <= myheadertutorial->position.y + 90 && mousepos.x <= myheadertutorial->position.x + 210 && mousepos.x >= myheadertutorial->position.x - 210 && input()->getMouseDown(0)) {
			myufo->standard();
			myufo2->standard();
			layers[0]->addChild(mypause);
			activescene++;
			score.storedscore = score.currentscore;
			score.setscore(deltaTime, 0);
		}
		//mycredits | credits button
		if (mousepos.y >= mycredits->position.y - 90 && mousepos.y <= mycredits->position.y + 90 && mousepos.x <= mycredits->position.x + 210 && mousepos.x >= mycredits->position.x - 210 && input()->getMouseDown(0)) {
			myufo->standard();
			myufo2->standard();
			layers[0]->addChild(mypause);
			CoreScene::sceneselect(3);
		}
	}
	else {
		//myhomebutton | home button
		if (mousepos.y >= myhomebutton->position.y - 30 && mousepos.y <= myhomebutton->position.y + 30 && mousepos.x <= myhomebutton->position.x + 30 && mousepos.x >= myhomebutton->position.x - 30 && input()->getMouseDown(0)) {
			layers[0]->addChild(mypause);
			started00 = false;
			menu = true;
		}
		//mypausebutton | pause button
		if (mousepos.y >= mypausebutton->position.y - 30 && mousepos.y <= mypausebutton->position.y + 30 && mousepos.x <= mypausebutton->position.x + 30 && mousepos.x >= mypausebutton->position.x - 30 && input()->getMouseDown(0)) {
			started00 = false;
			myufo->movementonoff = false;
			myufo2->movementonoff = false;
			pcounter00++;
			layers[8]->addChild(mypause);
		}
	}
	// ###############################################################
	// Change scene when all items are moved
	// ###############################################################
	if (menu == false && tm00 == 36) {
		myufo->standard();
		myufo2->standard();
		layers[0]->addChild(mypause);
		menu = true;
		CoreScene::sceneselect(2); // level 2
	}
}

void MyScene00::collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xu - xe)*(xu - xe) + (yu - ye)*(yu - ye) < ru*re) {
		// use w to break the lock and pick the item up
		if (input()->getKey('Q')) {
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
				std::vector<MyCar*>::iterator it = mycar.begin();
				while (it != mycar.end()) {
					if ((*it)->position.y == ye && (*it)->position.x == xe) {
						(*it)->position.y = -200;
						tm00++;
					}
					else {
						++it;
					}
				}
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
				std::vector<MyTree*>::iterator it = mytree.begin();
				while (it != mytree.end()) {
					if ((*it)->position.y == ye && (*it)->position.x == xe) {
						(*it)->position.y = -200;
						tm00++;
					}
					else {
						++it;
					}
				}
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
				std::vector<MyPerson*>::iterator it = myperson.begin();
				while (it != myperson.end()) {
					if ((*it)->position.y == ye && (*it)->position.x == xe) {
						(*it)->position.y = -200;
						tm00++;
					}
					else {
						++it;
					}
				}
			}
		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}