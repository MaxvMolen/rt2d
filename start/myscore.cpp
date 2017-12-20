/**
* This class describes MyScore behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "myscore.h"

int MyScore::currentscore = 0;

MyScore::MyScore() : Entity()
{


}

MyScore::~MyScore()
{

}

void MyScore::update(float deltaTime)
{

}

void MyScore::addscore(int amount) {
	// ###############################################################
	// Add to the currentscore
	// ###############################################################
	currentscore += amount;
}

void MyScore::subtractscore(int amount) {
	// ###############################################################
	// Subtract from the currentscore
	// ###############################################################
	currentscore -= amount;
}
