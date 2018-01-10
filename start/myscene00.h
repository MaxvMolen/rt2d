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
	/// @brief this function turns myufo red on collision with the given object.
	/// @brief it also will lock the player on the object it collided with.
	/// @brief the player can free itself with the w key.
	/// @param xu the x-position of the ufo
	/// @param yu the y-position of the ufo
	/// @param ru the radius of the ufo
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @param no the number specific to the object
	/// @return void
	virtual void collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime);
protected:
	
private:
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the light underneath the ufo
	BasicEntity* light;
	/// @brief the header
	BasicEntity* myheader;
	/// @brief the header for start
	BasicEntity* myheaderstart;
	/// @brief the header for tutorial
	BasicEntity* myheadertutorial;
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

#endif /* MYSCENE00_H */
