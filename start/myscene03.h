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
	/// @brief the background of the scene
	BasicEntity* myback;
	/// @brief the background of the text
	BasicEntity* mytext;
	/// @brief the header for start
	BasicEntity* myheader;
	/// @brief the logo for the level
	BasicEntity* mylogo;
};

#endif /* MYSCENE03_H */
