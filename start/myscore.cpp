/**
* This class describes MyScore behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "myscore.h"

int MyScore::currentscore = 0;
int MyScore::storedscore = 0;

MyScore::MyScore() : Entity()
{


}

MyScore::~MyScore()
{

}

void MyScore::update(float deltaTime)
{

}

void MyScore::addscore(float deltaTime) {
	// ###############################################################
	// Add to the currentscore
	// ###############################################################
	currentscore += 10;
}

void MyScore::subtractscore(float deltaTime) {
	// ###############################################################
	// Subtract from the currentscore
	// ###############################################################
	currentscore -= 10;
}

void MyScore::setscore(float deltaTime, int num) {
	// ###############################################################
	// Set the currentscore
	// ###############################################################
	currentscore = num;
}
