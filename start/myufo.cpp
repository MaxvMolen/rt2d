/**
* This class describes MyUfo behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include "myufo.h"

int rotationSpeed = 10; // speed of rotation
int speed = 5; // speed of player

MyUfo::MyUfo() : Entity()
{
	this->addSprite("assets/StartUfo2.tga");
	this->sprite()->color.r = 236;
	this->sprite()->color.g = 16;
	this->sprite()->color.b = 18;
}

MyUfo::~MyUfo()
{

}

void MyUfo::update(float deltaTime)
{
	// ###############################################################
	// Rotate player automatic
	// ###############################################################
	this->rotation.z -= rotationSpeed * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
	// ###############################################################
	// Rotate player faster with W
	// ###############################################################
	if (input()->getKey('W')) {
		this->rotation.z -= rotationSpeed * deltaTime; // 90 deg/sec
		speed = 10;
		if (this->rotation.z > TWO_PI) {
			this->rotation.z -= TWO_PI;
		}
	}
	else {
		speed = 5;
	}
	// ###############################################################
	// Slow down rotation with E slows down to 0 if W isnt held
	// ###############################################################
	if (input()->getKey('E')) {
		this->rotation.z += rotationSpeed * deltaTime; // 90 deg/sec
		if (this->rotation.z > TWO_PI) {
			this->rotation.z += TWO_PI;
		}
	}
	// ###############################################################
	// Update Movement
	// ###############################################################
	movement();
	// ###############################################################
	// Update ChangeUfo
	// ###############################################################
	changeUfo();
	// ###############################################################
	// Update Bounderies  width,height
	// ###############################################################
	bounderies(1920,1080);
}

void MyUfo::movement() {
	// ###############################################################
	// Move myentity with arrowkeys
	// ###############################################################
	if (input()->getKey(KeyCode::Up)) {
		this->position.y -= speed;
	}
	if (input()->getKey(KeyCode::Down)) {
		this->position.y += speed;
	}
	if (input()->getKey(KeyCode::Left)) {
		this->position.x -= speed;
	}
	if (input()->getKey(KeyCode::Right)) {
		this->position.x += speed;
	}
}

void MyUfo::changeUfo() {
	// ###############################################################
	// A,S and D changes ufo color and sprite
	// ###############################################################
	if (input()->getKey('A')) {
		this->addSprite("assets/StartUfo1.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 255;
		this->sprite()->color.g = 171;
		this->sprite()->color.b = 103;
	}
	if (input()->getKey('S')) {
		this->addSprite("assets/StartUfo2.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 236;
		this->sprite()->color.g = 16;
		this->sprite()->color.b = 18;
	}
	if (input()->getKey('D')) {
		this->addSprite("assets/StartUfo3.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 110;
		this->sprite()->color.g = 156;
		this->sprite()->color.b = 56;
	}
}

void MyUfo::bounderies(float width, float height) {
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
