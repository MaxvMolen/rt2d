/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "myufo.h"

int rotationSpeed = 12; // speed of rotation
int speed = 10; // speed of player

MyUfo::MyUfo() : Entity()
{
	this->addSprite("assets/StartUfo2.tga");
	this->sprite()->color.r = 255;
	this->sprite()->color.g = 0;
	this->sprite()->color.b = 0;
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
		if (this->rotation.z > TWO_PI) {
			this->rotation.z -= TWO_PI;
		}
	}

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
		this->sprite()->color.r = 255;
		this->sprite()->color.g = 0;
		this->sprite()->color.b = 0;
	}
	if (input()->getKey('D')) {
		this->addSprite("assets/StartUfo3.tga");
		this->scale = Point(1.0f, 1.0f);
		this->sprite()->color.r = 0;
		this->sprite()->color.g = 255;
		this->sprite()->color.b = 0;
	}

}
