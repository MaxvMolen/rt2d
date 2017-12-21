/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene02.h
 *
 * @brief description of MyScene02 behavior.
 */

#ifndef MYSCENE02_H
#define MYSCENE02_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene02 : public CoreScene
{
public:
	/// @brief Constructor
	MyScene02();
	/// @brief Destructor
	virtual ~MyScene02();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	/// @brief this function turns myufo red on collision with the given object.
	/// @brief it also will lock the player on the object it collided with.
	/// @brief the player can free itself with the w key.
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @return void
	virtual void collision(float xe, float ye, float re);
protected:
	
private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the light underneath the ufo
	BasicEntity* light;
	/// @brief the road in the background of the level
	std::vector<BasicEntity*> myroads;
	/// @brief the car in the level that you need to pick up
	std::vector<MyCar*> mycar;
	/// @brief the person in the level that you need to pick up
	std::vector<MyPerson*> myperson;
	/// @brief the house in the background of the level
	std::vector<BasicEntity*> myhouse;
	/// @brief the tree in the level that you need to pick up
	std::vector<MyTree*> mytree;
	/// @brief the garden in the background of the level
	std::vector<BasicEntity*> mygarden;
	/// @brief the big bench in the background of the level
	std::vector<BasicEntity*> mybenchb;
	/// @brief the small bench in the background of the level
	std::vector<BasicEntity*> mybenchs;
	/// @brief the background
	BasicEntity* myback;
};

#endif /* MYSCENE02_H */
