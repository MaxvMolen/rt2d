/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file myentity.h
*
* @brief description of MyEntity behavior.
*/

#ifndef MYTREE_H
#define MYTREE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class MyTree : public Entity
{
public:
	/// @brief Constructor
	MyTree(float x1, float y1, float r);
	/// @brief Destructor
	virtual ~MyTree();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYPICKUP_H */
