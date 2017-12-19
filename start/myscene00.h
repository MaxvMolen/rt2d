/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene00.h
 *
 * @brief description of MyScene00 behavior.
 */

#ifndef MYSCENE00_H
#define MYSCENE00_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene00 : public CoreScene
{
public:
	/// @brief Constructor
	MyScene00();
	/// @brief Destructor
	virtual ~MyScene00();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	virtual void collision(float xe, float ye, float re);
protected:
	
private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the light underneath the ufo
	BasicEntity* light;
	/// @brief the header
	BasicEntity* myheader;
	/// @brief the road in the background of the level
	std::vector<BasicEntity*> myroads;
	/// @brief the car in the level that you need to pick up
	std::vector<MyCar*> mycar;
	/// @brief the house in the background of the level
	std::vector<BasicEntity*> myhouse;
	/// @brief the tree in the level that you need to pick up
	std::vector<MyTree*> mytree;
	/// @brief the garden in the background of the level
	std::vector<BasicEntity*> mygarden;
};

#endif /* MYSCENE00_H */
