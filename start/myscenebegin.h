/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscenebegin.h
 *
 * @brief description of MySceneBegin behavior.
 */

#ifndef MYSCENEBEGIN_H
#define MYSCENEBEGIN_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MySceneBegin : public CoreScene
{
public:
	/// @brief Constructor
	MySceneBegin();
	/// @brief Destructor
	virtual ~MySceneBegin();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
protected:
	
private:
	BasicEntity* myexampleright;
	BasicEntity* myexamplewrong;
};

#endif /* MYSCENEBEGIN_H */
