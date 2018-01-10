/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file mytree.h
*
* @brief description of MyTree behavior.
*/

#ifndef MYTREE_H
#define MYTREE_H

#include <rt2d/entity.h>

/// @brief The MyTree class is the Tree implementation.
class MyTree : public Entity
{
public:
	/// @brief Constructor
	MyTree();
	/// @brief Destructor
	virtual ~MyTree();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYTREE_H */
