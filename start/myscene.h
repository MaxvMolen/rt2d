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
	virtual void Bounderies();
protected:
	
private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the person in the level that you need to pick up
	std::vector<MyPerson*> myperson;
	/// @brief the car in the level that you need to pick up
	std::vector<MyCar*> mycar;
	/// @brief the tree in the level that you need to pick up
	std::vector<MyTree*> mytree;
	/// @brief the garage in the background of the level
	std::vector<BasicEntity*> mygarage;
	/// @brief the bush in the background of the level
	std::vector<BasicEntity*> mybush;
	/// @brief the road in the background of the level
	std::vector<BasicEntity*> myroads;
	/// @brief the house in the background of the level
	std::vector<BasicEntity*> myhouse;
	/// @brief the parkingspot in the background of the level
	std::vector<BasicEntity*> myparking;
};

#endif /* MYSCENE_H */
