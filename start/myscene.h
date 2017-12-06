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
protected:
	
private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the person in the level that you need to pick up
	//MyPerson* myperson[2];
	std::vector<MyPerson*> myperson;
	/// @brief the car in the level that you need to pick up
	//MyCar* mycar[8];
	std::vector<MyCar*> mycar;
	/// @brief the tree in the level that you need to pick up
	//MyTree* mytree[9];
	std::vector<MyTree*> mytree;
	/// @brief the garage in the background of the level
	//BasicEntity* mygarage[2];
	std::vector<BasicEntity*> mygarage;
	/// @brief the bush in the background of the level
	//BasicEntity* mybush[4];
	std::vector<BasicEntity*> mybush;
	/// @brief the road in the background of the level
	//BasicEntity* myroads[17];
	std::vector<BasicEntity*> myroads;
	/// @brief the house in the background of the level
	//BasicEntity* myhouse[3];
	std::vector<BasicEntity*> myhouse;
	/// @brief the parkingspot in the background of the level
	//BasicEntity* myparking[15];
	std::vector<BasicEntity*> myparking;
};

#endif /* MYSCENE_H */
