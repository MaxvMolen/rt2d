/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file myscore.h
*
* @brief description of MyScore behavior.
*/

#ifndef MYSCORE_H
#define MYSCORE_H

#include <rt2d/entity.h>

/// @brief The MyScore class is the Score implementation.
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
	/// @brief keeps track of the current score
	static int currentscore;
	/// @brief add core to the currenscore
	virtual void addscore(float deltaTime);
	/// @brief subtract score from the currenscore
	virtual void subtractscore(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYSCORE_H */
