/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file myentity.h
*
* @brief description of MyEntity behavior.
*/

#ifndef MYSCORE_H
#define MYSCORE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyScore : public Entity
{
public:
	/// @brief Constructor
	MyScore();
	/// @brief Destructor
	virtual ~MyScore();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYPICKUP_H */
