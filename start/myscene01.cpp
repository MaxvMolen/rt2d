/**
* This class describes MyScene01 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene01.h"

// amount of objects
int totalpath01 = 16;
int totalroads01 = 8;
int totalcar01 = 2;
int totaltree01 = 1;
int totalperson01 = 2;

int n01 = 0;
// pause counter if its 0 its not paused if its 1 the game is paused
int pcounter01 = 0;

// has the game started yes or no
bool started01 = true;
// switch movement on and of
bool switchs01 = false;

//myufo
float xa1 = 1; // x position myufo
float ya1 = 1; // y position myufo
float ra1 = 25; // radius myufo

MyScene01::MyScene01() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackgroundTut.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[1]->addChild(myback);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText2.tga");
	mytext->position = Point2(SWIDTH / 2+5, SHEIGHT / 2 -75);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(1.0f, 1.0f);
	// ###############################################################
	// create myexampleright
	// ###############################################################
	myexampleright = new BasicEntity();
	myexampleright->addSprite("assets/ExampleGameplayRight.tga");
	myexampleright->position = Point2(1475, 140);
	myexampleright->scale = Point(0.5f, 0.5f);
	layers[7]->addChild(myexampleright);
	// ###############################################################
	// create examplewrong
	// ###############################################################
	myexamplewrong = new BasicEntity();
	myexamplewrong->addSprite("assets/ExampleGameplayWrong.tga");
	myexamplewrong->position = Point2(1775, 140);
	myexamplewrong->scale = Point(0.5f, 0.5f);
	layers[7]->addChild(myexamplewrong);
	// ###############################################################
	// create header for the level
	// ###############################################################
	myheader = new BasicEntity();
	myheader->addSprite("assets/StartHeaderTutorial.tga");
	myheader->position = Point2(SWIDTH / 2, 125);
	layers[5]->addChild(myheader);
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
	// ###############################################################
	// text instruction
	// ###############################################################
	//messages with instructions gameplay
	text[2]->message("Right", GREEN);
	text[3]->message("Wrong", RED);
	text[4]->message("Use arrowkeys to move.", WHITE);
	text[5]->message("A,S and D to change form.", WHITE);
	text[6]->message("Use W to pickup objects and to go faster.", WHITE);
	text[7]->message("In this game your objective is to pickup the right object with the right ufo.", WHITE);
	text[8]->message("If you were to use the wrong ufo to pickup a object you will lose points.", WHITE);
	text[9]->message("Use the beige ship to pick up humans, use the red ship to pick up", WHITE);
	text[10]->message("car's and use the green ship to pick up trees.", WHITE);
	text[11]->message("_______________________________________________________________________________", WHITE);
	text[12]->message("Use the H key to go back to the menu.", WHITE);
	text[13]->message("Use the P key to pause the game, press p again to resume the game.", WHITE);
	//Position text
	text[2]->position = Point2(SWIDTH / 2 + 450, SHEIGHT / 2 - 270);
	text[3]->position = Point2(SWIDTH / 2 + 750, SHEIGHT / 2 - 270);
	text[4]->position = Point2(50, 485);
	text[5]->position = Point2(50, 515);
	text[6]->position = Point2(50, 545);
	text[7]->position = Point2(50, 335);
	text[8]->position = Point2(50, 365);
	text[9]->position = Point2(50, 395);
	text[10]->position = Point2(50, 425);
	text[11]->position = Point2(50, 455);
	text[12]->position = Point2(50, 575);
	text[13]->position = Point2(50, 605);
	//Scale text
	text[2]->scale = Point2(1.0f, 1.0f);
	text[3]->scale = Point2(1.0f, 1.0f);
	//text will deleted in corescene.cpp
	// ###############################################################
	// create pause
	// ###############################################################
	mypause = new BasicEntity();
	mypause->addSprite("assets/StartPause.tga");
	mypause->position = Point2(SWIDTH / 1 - 75, 75);
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
	// create  example home and pause buttons
	// ###############################################################
	// home button
	examplehomebutton = new BasicEntity();
	examplehomebutton->addSprite("assets/StartHomeButton.tga");
	examplehomebutton->position = Point2(660, 575);
	examplehomebutton->scale = Point(0.3f, 0.3f);
	layers[2]->addChild(examplehomebutton);
	// pause button
	examplepausebutton = new BasicEntity();
	examplepausebutton->addSprite("assets/StartPauseButton.tga");
	examplepausebutton->position = Point2(1120, 605);
	examplepausebutton->scale = Point(0.3f, 0.3f);
	layers[2]->addChild(examplepausebutton);
	// ###############################################################
	// create persons for the level
	// ###############################################################
	for (n01 = 0; n01 < totalperson01; ++n01) {
		MyPerson* person = new MyPerson();
		myperson.push_back(person);
		person->position = Point2(1625, 450);
		person->scale = Point(0.7f, 0.7f);
		person->rotation.z = 0;
		if (n01 >= 1) {
			person->position = Point2(575, 780);
			person->rotation.z = 1.57;
		}
		layers[6]->addChild(person);
	}
	// ###############################################################
	// create trees	for the level
	// ###############################################################
	for (n01 = 0; n01 < totaltree01; ++n01) {
		MyTree* tree = new MyTree();
		mytree.push_back(tree);
		tree->position = Point2(1625, 350);
		layers[6]->addChild(tree);
	}
	// ###############################################################
	// create cars for the level
	// ###############################################################
	for (n01 = 0; n01 < totalcar01; ++n01) {
		MyCar* car = new MyCar();
		mycar.push_back(car);
		car->position = Point2(1625, 575);
		if (n01 >= 1) {
			car->position = Point2(300, 900);
			car->rotation.z = -1.57;
		}
		layers[5]->addChild(car);
	}
	// ###############################################################
	// create roads for the level
	// ###############################################################
	for (n01 = 0; n01 < totalroads01; ++n01) {
		BasicEntity* roads = new BasicEntity();
		myroads.push_back(roads);
		roads->addSprite("assets/StartRoad.tga");
		roads->position = Point2(125 + n01 * 250, 960);
		roads->rotation.z = 1.57;
		layers[1]->addChild(roads);
	}
	// ###############################################################
	// create paths for the level
	// ###############################################################
	for (n01 = 0; n01 < totalpath01; ++n01) {
		BasicEntity* path = new BasicEntity();
		mypath.push_back(path);
		path->addSprite("assets/StartPRoad.tga");
		path->position = Point2(n01 * 125, 780);
		path->rotation.z = 1.57;
		layers[1]->addChild(path);
	}
	// ###############################################################
	// create small back
	// ###############################################################
	mysmallback = new BasicEntity();
	mysmallback->addSprite("assets/StartBackSmall.tga");
	mysmallback->scale = Point(0.5f, 0.75f);
	mysmallback->position = Point2(1625, 490);
	layers[4]->addChild(mysmallback);
}

MyScene01::~MyScene01() 
{
	this->removeChild(mysmallback);
	delete mysmallback;

	this->removeChild(examplehomebutton);
	delete examplehomebutton;

	this->removeChild(examplepausebutton);
	delete examplepausebutton;

	this->removeChild(myhomebutton);
	delete myhomebutton;

	this->removeChild(mypausebutton);
	delete mypausebutton;

	this->removeChild(mybscore);
	delete mybscore;

	this->removeChild(myufo);
	delete myufo;

	this->removeChild(light);
	delete light;

	this->removeChild(myback);
	delete myback;

	this->removeChild(mytext);
	delete mytext;

	this->removeChild(myexamplewrong);
	delete myexamplewrong;

	this->removeChild(myexampleright);
	delete myexampleright;

	this->removeChild(myheader);
	delete myheader;

	this->removeChild(mypause);
	delete mypause;

	for (n01 = 0; n01 < mycar.size(); ++n01) {
		delete mycar[n01];
		mycar[n01] = NULL;
	}
	mycar.clear();

	for (n01 = 0; n01 < mytree.size(); ++n01) {
		delete mytree[n01];
		mytree[n01] = NULL;
	}
	mytree.clear();

	for (n01 = 0; n01 < myperson.size(); ++n01) {
		delete myperson[n01];
		myperson[n01] = NULL;
	}
	myperson.clear();
}

void MyScene01::update(float deltaTime)
{
	// ###############################################################
	// Set Movement off / on
	// ###############################################################
	if (started01 == false) {
		myufo->movementonoff = false;
		if (switchs01 == true) {
			switchs01 = false;
			pcounter01 = 0;
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
	text[0]->message(cs.str(), YELLOW);
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
	if (started01 == true) {
		xa1 = myufo->position.x;
		ya1 = myufo->position.y;
	}
	// ###############################################################
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		myufo->standard();
		score.setscore(deltaTime, score.storedscore);
		CoreScene::sceneselect(0);
	}
	// ###############################################################
	// Pause game by pressing p
	// ###############################################################
	// paused the game
	if (input()->getKeyDown(P)) {
		started01 = false;
		myufo->movementonoff = false;
		pcounter01++;
		layers[8]->addChild(mypause);
	}
	// resume game
	if (pcounter01 == 2) {
		started01 = true;
		myufo->movementonoff = true;
		pcounter01 = 0;
		layers[0]->addChild(mypause);
	}
	// ###############################################################
	// Update mouse position
	// ###############################################################
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mousepos = Point2(mousex, mousey);
	// ###############################################################
	// Game buttons
	// ###############################################################
	//myhomebutton | home button
	if (mousepos.y >= myhomebutton->position.y - 30 && mousepos.y <= myhomebutton->position.y + 30 && mousepos.x <= myhomebutton->position.x + 30 && mousepos.x >= myhomebutton->position.x - 30 && input()->getMouseDown(0)) {
		myufo->standard();
		score.setscore(deltaTime, score.storedscore);
		CoreScene::sceneselect(0);
	}
	//mypausebutton | pause button
	if (mousepos.y >= mypausebutton->position.y - 30 && mousepos.y <= mypausebutton->position.y + 30 && mousepos.x <= mypausebutton->position.x + 30 && mousepos.x >= mypausebutton->position.x - 30 && input()->getMouseDown(0)) {
		started01 = false;
		myufo->movementonoff = false;
		pcounter01++;
		layers[8]->addChild(mypause);
	}
	// ###############################################################
	// Call collision function and set radius of object
	// ###############################################################
	if (started01 == true) {
		for (n01 = 0; n01 < mycar.size(); ++n01) {
			collision(xa1, ya1, ra1, mycar[n01]->position.x, mycar[n01]->position.y, 125, 1, deltaTime);
		}
		for (n01 = 0; n01 < mytree.size(); ++n01) {
			collision(xa1, ya1, ra1, mytree[n01]->position.x, mytree[n01]->position.y, 50, 2, deltaTime);
		}
		for (n01 = 0; n01 < myperson.size(); ++n01) {
			collision(xa1, ya1, ra1, myperson[n01]->position.x, myperson[n01]->position.y, 25, 3, deltaTime);
		}
	}
	// ###############################################################
	// Move car over the road
	// ###############################################################
	if (started01 == true) {
		mycar[1]->position.x -= 600 * deltaTime;

		if (mycar[1]->position.x <= -100) {
			mycar[1]->position.x = 2000;
		}
	}
	// ###############################################################
	// Move person over the path
	// ###############################################################
	if (started01 == true) {
		myperson[1]->position.x += 200 * deltaTime;

		if (myperson[1]->position.x >= 2000) {
			myperson[1]->position.x = -100;
		}
	}
}

void MyScene01::collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime) {
	// ###############################################################
	// Collision ufo
	// ###############################################################
	if ((xu - xe)*(xu - xe) + (yu - ye)*(yu - ye) < ru*re) {
		// use w to break the lock and pick the item up
		if (input()->getKey('W')) {
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
			}
		}
		else {
			// lock the ufo in place on collision of object 
			myufo->position.x = xe;
			myufo->position.y = ye;
		}
	}
}
