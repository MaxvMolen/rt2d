/**
* This class describes MyScene01 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene01.h"

// pause counter if its 0 its not paused if its 1 the game is paused
int pcounter01 = 0;

// has the game started yes or no
bool started01 = true;
// switch movement on and of
bool switchs01 = false;

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
	mytext->position = Point2(SWIDTH / 2+5, SHEIGHT / 2 +10);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(1.0f, 1.0f);
	// ###############################################################
	// create myexampleright
	// ###############################################################
	myexampleright = new BasicEntity();
	myexampleright->addSprite("assets/ExampleGameplayRight.tga");
	myexampleright->position = Point2(SWIDTH / 2 + 700, SHEIGHT / 2 - 270);
	layers[7]->addChild(myexampleright);
	// ###############################################################
	// create examplewrong
	// ###############################################################
	myexamplewrong = new BasicEntity();
	myexamplewrong->addSprite("assets/ExampleGameplayWrong.tga");
	myexamplewrong->position = Point2(SWIDTH / 2 + 700, SHEIGHT / 2+270);
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
	text[2]->message("Right", WHITE);
	text[3]->message("Wrong", WHITE);
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
	text[2]->position = Point2(SWIDTH / 2 + 295, SHEIGHT / 2 - 270);
	text[3]->position = Point2(SWIDTH / 2 + 295, SHEIGHT / 2 + 270);
	text[4]->position = Point2(50, 560);
	text[5]->position = Point2(50, 590);
	text[6]->position = Point2(50, 620);
	text[7]->position = Point2(50, 410);
	text[8]->position = Point2(50, 440);
	text[9]->position = Point2(50, 470);
	text[10]->position = Point2(50, 500);
	text[11]->position = Point2(50, 530);
	text[12]->position = Point2(50, 650);
	text[13]->position = Point2(50, 680);
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
	mybscore->position = Point2(95, 0);
	mybscore->scale = Point(1.5f, 1.0f);
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
}


MyScene01::~MyScene01()
{
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
	// Menu
	// ###############################################################
	if (input()->getKeyUp(KeyCode::H)) {
		myufo->standard();
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
		CoreScene::sceneselect(0);
	}
	//mypausebutton | pause button
	if (mousepos.y >= mypausebutton->position.y - 30 && mousepos.y <= mypausebutton->position.y + 30 && mousepos.x <= mypausebutton->position.x + 30 && mousepos.x >= mypausebutton->position.x - 30 && input()->getMouseDown(0)) {
		started01 = false;
		myufo->movementonoff = false;
		pcounter01++;
		layers[8]->addChild(mypause);
	}
}
