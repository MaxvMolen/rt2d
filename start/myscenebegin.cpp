/**
* This class describes MySceneBegin behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <fstream>
#include <sstream>
#include "myscenebegin.h"


MySceneBegin::MySceneBegin() : CoreScene()
{
	
}


MySceneBegin::~MySceneBegin()
{

}

void MySceneBegin::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	CoreScene::quit();
}
