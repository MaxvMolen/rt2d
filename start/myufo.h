/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myufo.h
 *
 * @brief description of MyUfo behavior.
 */

#ifndef MYUFO_H
#define MYUFO_H

#include <rt2d/entity.h>

/// @brief The MyUfo class is the Ufo implementation.
class MyUfo : public Entity

{
public:
	MyUfo();
	/// @brief Constructor
	//MyUfo();
	/// @brief Destructor
	virtual ~MyUfo();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
