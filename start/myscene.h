/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "corescene.h"
#include "myufo.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public CoreScene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	virtual void collision(float xe, float ye, float re);
protected:

private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the person in the level that you need to pick up
	MyPerson* myperson[2];
	/// @brief the car in the level that you need to pick up
	MyCar* mycar[8];
	/// @brief the tree in the level that you need to pick up
	MyTree* mytree[9];
	
	/// @brief the garage in the background of the level
	BasicEntity* mygarage[1];
	/// @brief the bush in the background of the level
	BasicEntity* mybush[3];
	/// @brief the road in the background of the level
	BasicEntity* myroads[16];
	/// @brief the house in the background of the level
	BasicEntity* myhouse[2];
	/// @brief the parkingspot in the background of the level
	BasicEntity* myparking[15];

};

#endif /* SCENE00_H */
