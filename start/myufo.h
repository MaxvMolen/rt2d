/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYUFO_H
#define MYUFO_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyUfo : public Entity

{
public:
	/// @brief Constructor
	MyUfo();
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
