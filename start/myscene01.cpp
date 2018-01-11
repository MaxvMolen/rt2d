/**
* This class describes MyScene01 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene01.h"


MyScene01::MyScene01() : CoreScene()
{
	// ###############################################################
	// create background
	// ###############################################################
	myback = new BasicEntity();
	myback->addSprite("assets/StartBackgroundTut.tga");
	myback->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	layers[0]->addChild(myback);
	// ###############################################################
	// create back text
	// ###############################################################
	mytext = new BasicEntity();
	mytext->addSprite("assets/StartText.tga");
	mytext->position = Point2(SWIDTH / 2 + 25, SHEIGHT / 2 - 15);
	layers[1]->addChild(mytext);
	mytext->scale = Point2(1.0f, 0.7f);
	// ###############################################################
	// create myexampleright
	// ###############################################################
	myexampleright = new BasicEntity();
	myexampleright->addSprite("assets/ExampleGameplayRight.tga");
	myexampleright->position = Point2(SWIDTH / 2 + 700, SHEIGHT / 2-270);
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
	text[4]->message("Use arrowkeys to move", WHITE);
	text[5]->message("A,S and D to change form", WHITE);
	text[6]->message("Use W to pickup objects and to go faster.", WHITE);
	text[7]->message("In this game your objective is to pickup the right object with the right ufo.", WHITE);
	text[8]->message("If you were to use the wrong ufo to pickup a object you will lose points.", WHITE);
	text[9]->message("Use the beige ship to pick up humans, use the red ship to pick up", WHITE);
	text[10]->message("car's and use the green ship to pick up trees.", WHITE);
	text[11]->message("_______________________________________________________________________________", WHITE);
	text[12]->message("Use the H key to go back to the menu", WHITE);
	text[13]->message("Use the P key to go pause the game, press p again to resume the game", WHITE);
	//Position text
	text[2]->position = Point2(SWIDTH / 2 + 295, SHEIGHT / 2 - 270);
	text[3]->position = Point2(SWIDTH / 2 + 295, SHEIGHT / 2 + 270);
	text[4]->position = Point2(50, 560);
	text[5]->position = Point2(50, 30 + 560);
	text[6]->position = Point2(50, 60 + 560);
	text[7]->position = Point2(50, 500-90);
	text[8]->position = Point2(50, 500-60);
	text[9]->position = Point2(50, 500 - 30);
	text[10]->position = Point2(50, 500 - 0);
	text[11]->position = Point2(50, 500 + 30);
	text[12]->position = Point2(50, 90 + 560);
	text[13]->position = Point2(50, 120 + 560);
	//Scale text
	text[2]->scale = Point2(1.0f, 1.0f);
	text[3]->scale = Point2(1.0f, 1.0f);
	//text will deleted in corescene.cpp
}


MyScene01::~MyScene01()
{
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
}

void MyScene01::update(float deltaTime)
{
	// ###############################################################
	// Currentscore counter top right
	// ###############################################################
	std::stringstream cs;
	cs << "Score: " << score.currentscore;
	text[0]->message(cs.str());
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
}
