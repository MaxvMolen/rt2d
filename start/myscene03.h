/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene03.h
 *
 * @brief description of MyScene03 behavior.
 */

#ifndef MYSCENE03_H
#define MYSCENE03_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene03 : public CoreScene
{
public:
	/// @brief Constructor
	MyScene03();
	/// @brief Destructor
	virtual ~MyScene03();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
private:
	/// @brief the background for the score counter
	std::vector<BasicEntity*> mybscore;
	/// @brief the light underneath the ufo
	BasicEntity* unufo;
	/// @brief the light underneath the ufo
	BasicEntity* light;
	/// @brief the background of the scene
	BasicEntity* myback;
	/// @brief the background of the text
	BasicEntity* mytext;
	/// @brief the header for start
	BasicEntity* myheader;
	/// @brief the logo for the level
	BasicEntity* mylogo;
	/// @brief AC-Logo
	BasicEntity* myaclogo;
	/// @brief the road in the background of the level
	std::vector<BasicEntity*> myroads;
	/// @brief the car in the level
	std::vector<MyCar*> mycar;
	/// @brief the tree in the level
	std::vector<MyTree*> mytree;
	/// @brief the home button
	BasicEntity* myhomebutton;
	/// @brief the pause icon
	BasicEntity* mypause;
	/// @brief the pause button
	BasicEntity* mypausebutton;
};

#endif /* MYSCENE03_H */
