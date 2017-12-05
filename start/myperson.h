/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file myperson.h
*
* @brief description of MyPerson behavior.
*/

#ifndef MYPERSON_H
#define MYPERSON_H

#include <rt2d/entity.h>

/// @brief The MyPerson class is the Person implementation.
class MyPerson : public Entity
{
public:
	/// @brief Constructor
	MyPerson();
	/// @brief Destructor
	virtual ~MyPerson();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYPERSON_H */
