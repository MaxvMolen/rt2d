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
	/// @brief keeps track of the current score of player 1
	static int currentscore;
	static int storedscore;
	/// @brief keeps track of the current score of player 2
	static int currentscore2;
	static int storedscore2;
	/// @brief add core to the currenscore of player 1
	virtual void addscore(float deltaTime);
	/// @brief add core to the currenscore of player 2
	virtual void addscore2(float deltaTime);
	/// @brief subtract score from the currenscore of player 1
	virtual void subtractscore(float deltaTime);
	/// @brief subtract score from the currenscore of player 2
	virtual void subtractscore2(float deltaTime);
	/// @brief set the current score of player 1
	virtual void setscore(float deltaTime, int num);
	/// @brief set the current score of player 2
	virtual void setscore2(float deltaTime, int num);

private:
	/* add your private declarations */
};

#endif /* MYSCORE_H */
