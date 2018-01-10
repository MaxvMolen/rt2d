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
	/// @brief Constructor
	MyUfo();
	/// @brief Destructor
	virtual ~MyUfo();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	/// @brief movement is automatically called every frame
	/// @brief used to move the player
	/// @return void
	virtual void MyUfo::movement(float deltaTime);
	/// @brief used to change the players look and color
	/// @return void
	virtual void MyUfo::changeUfo();
	/// @brief used to keep the player in the set bounderies
	/// @param width indicates the width of the playroom
	/// @param height indicates the height of the playroom
	/// @return void
	virtual void MyUfo::bounderies(float width, float height);
	/// @brief current number of ship
	static int noa;

private:
	/* add your private declarations */
};

#endif /* MYUFO_H */
