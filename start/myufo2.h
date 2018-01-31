/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myufo2.h
 *
 * @brief description of MyUfo2 behavior.
 */

#ifndef MYUFO2_H
#define MYUFO2_H

#include <rt2d/entity.h>

/// @brief The MyUfo class is the Ufo implementation.
class MyUfo2 : public Entity

{
public:
	/// @brief Constructor
	MyUfo2();
	/// @brief Destructor
	virtual ~MyUfo2();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	/// @brief movement is automatically called every frame
	/// @brief used to move the player
	/// @return void
	virtual void MyUfo2::movement(float deltaTime);
	/// @brief used to change the players look and color
	/// @return void
	virtual void MyUfo2::changeUfo();
	/// @brief used to keep the player in the set bounderies
	/// @param width indicates the width of the playroom
	/// @param height indicates the height of the playroom
	/// @return void
	virtual void MyUfo2::bounderies(float width, float height);
	/// @brief sets standard form
	virtual void MyUfo2::standard();
	/// @brief current number of ship
	static int noa02;
	/// @brief movement on off
	static bool movementonoff;

private:
	/* add your private declarations */
};

#endif /* MYUFO2_H */
