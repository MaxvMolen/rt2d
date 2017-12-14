/**
* This class describes MyScene00 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscene00.h"


MyScene00::MyScene00() : CoreScene()
{

}


MyScene00::~MyScene00()
{

}

void MyScene00::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
