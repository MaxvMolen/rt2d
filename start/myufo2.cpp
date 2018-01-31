/**
* This class describes MyUfo2 behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "myufo2.h"

// toggle movement on of
bool MyUfo2::movementonoff = true;

// speed of rotation
int rotationSpeed02 = 10;
// speed of player
int speed02 = 300;

// number of the ufo that corresponds to the number of a object
int MyUfo2::noa02 = 1;

MyUfo2::MyUfo2() : Entity()
{
	this->addSprite("assets/StartUfo2.tga");
	this->sprite()->color.r = 236;
	this->sprite()->color.g = 16;
	this->sprite()->color.b = 18;
}

MyUfo2::~MyUfo2()
{

}

void MyUfo2::update(float deltaTime)
{
	if (movementonoff == true) {
		// ###############################################################
		// Rotate player automatic
		// ###############################################################
		this->rotation.z -= rotationSpeed02 * deltaTime; // 90 deg/sec
		if (this->rotation.z > TWO_PI) {
			this->rotation.z -= TWO_PI;
		}
		// ###############################################################
		// Rotate player faster with W
		// ###############################################################
		if (input()->getKey(KeyCode::KeyPad4)) {
			this->rotation.z -= rotationSpeed02 * deltaTime; // 90 deg/sec
			speed02 = 600;
			if (this->rotation.z > TWO_PI) {
				this->rotation.z -= TWO_PI;
			}
		}
		// Standard speed
		else {
			speed02 = 300;
		}
		// ###############################################################
		// Update Movement
		// ###############################################################
		movement(deltaTime);
		// ###############################################################
		// Update ChangeUfo
		// ###############################################################
		changeUfo();
	}
	// ###############################################################
	// Update Bounderies  width,height
	// ###############################################################
	bounderies(SWIDTH,SHEIGHT);
}

void MyUfo2::movement(float deltaTime) {
	// ###############################################################
	// Move myentity with arrowkeys
	// ###############################################################
	if (input()->getKey(KeyCode::KeyPad5)) {
		this->position.y -= speed02 * deltaTime;
	}
	if (input()->getKey(KeyCode::KeyPad2)) {
		this->position.y += speed02 * deltaTime;
	}
	if (input()->getKey(KeyCode::KeyPad1)) {
		this->position.x -= speed02 * deltaTime;
	}
	if (input()->getKey(KeyCode::KeyPad3)) {
		this->position.x += speed02 * deltaTime;
	}
}

void MyUfo2::changeUfo() {
	// ###############################################################
	// A,S and D changes ufo color and sprite
	// ###############################################################
	if (input()->getKey(KeyCode::KeyPad7)) {
		this->addSprite("assets/StartUfo1.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 255;
		this->sprite()->color.g = 171;
		this->sprite()->color.b = 103;
		noa02 = 2;
	}
	if (input()->getKey(KeyCode::KeyPad8)) {
		this->addSprite("assets/StartUfo2.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 236;
		this->sprite()->color.g = 16;
		this->sprite()->color.b = 18;
		noa02 = 1;
	}
	if (input()->getKey(KeyCode::KeyPad9)) {
		this->addSprite("assets/StartUfo3.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 110;
		this->sprite()->color.g = 156;
		this->sprite()->color.b = 56;
		noa02 = 3;
	}
}

void MyUfo2::bounderies(float width, float height) {
	// ###############################################################
	// Check if player exeeds given position and push it back
	// ###############################################################
	if (this->position.x >= width) {
		this->position.x += -10;
	}
	if (this->position.x <= 0) {
		this->position.x += 10;
	}
	if (this->position.y >= height) {
		this->position.y += -10;
	}
	if (this->position.y <= 0) {
		this->position.y += 10;
	}
}

void MyUfo2::standard() {
	// ###############################################################
	// Sets default sprite
	// ###############################################################
	this->addSprite("assets/StartUfo2.tga");
	this->scale = Point(1.0f, 1.0f);
	this->sprite()->color.r = 236;
	this->sprite()->color.g = 16;
	this->sprite()->color.b = 18;
	noa02 = 1;
}