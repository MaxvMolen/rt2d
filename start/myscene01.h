/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene01.h
 *
 * @brief description of MyScene01 behavior.
 */

#ifndef MYSCENE01_H
#define MYSCENE01_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene01 : public CoreScene
{
public:
	/// @brief Constructor
	MyScene01();
	/// @brief Destructor
	virtual ~MyScene01();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
protected:
	
private:
	/// @brief example gameplay right
	BasicEntity* myexampleright;
	/// @brief example gameplay wrong
	BasicEntity* myexamplewrong;
	/// @brief the header
	BasicEntity* myheader;
	/// @brief the background
	BasicEntity* myback;
};

#endif /* MYSCENE01_H */
