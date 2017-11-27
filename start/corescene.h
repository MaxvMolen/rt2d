/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file myentity.h
*
* @brief description of MyEntity behavior.
*/

#ifndef CORESCENE_H
#define CORESCENE_H

#include <vector>
#include <rt2d/entity.h>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "basicentity.h"
// objects
#include "myufo.h"
#include "myperson.h"
#include "mycar.h"
#include "mytree.h"

/*
struct Player
{
	int mouseclicks = 0;
};
*/

/// @brief The MyEntity class is the Entity implementation.
class CoreScene : public Scene
{
public:
	/// @brief Constructor
	CoreScene();
	/// @brief Destructor
	virtual ~CoreScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	static int activescene;

protected:
	unsigned int top_layer;
	std::vector<BasicEntity*> layers;
	std::vector<Text*> text;
private:
	MyUfo* myufo;
	Timer fpstimer;
	/* add your private declarations */
};

#endif /* CORESCENE_H */
