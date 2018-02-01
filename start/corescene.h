/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file corescene.h
*
* @brief description of CoreScene behavior.
*/

#ifndef CORESCENE_H
#define CORESCENE_H

#include <vector>
#include <rt2d/entity.h>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "basicentity.h"
#include "myscore.h"
#include "myperson.h"
#include "mycar.h"
#include "mytree.h"
#include "myufo.h"
#include "myufo2.h"

/// @brief The CoreScene class is the Scene implementation.
class CoreScene : public Scene
{
public:
	/// @brief Constructor
	CoreScene();
	/// @brief Destructor
	virtual ~CoreScene();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	/// @brief quit will close the program
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void quit();
	/// @brief keeps track of the current active scene
	static int activescene;
	/// @brief will bring you back to the main menu of the game
	/// @return void
	virtual void sceneselect(int ds);

protected:
	/// @brief the top layer
	unsigned int top_layer;
	/// @brief list of layers
	std::vector<BasicEntity*> layers;
	/// @brief list of text
	std::vector<Text*> text;
	/// @brief the players score
	MyScore score;
	/// @brief the player2 score
	MyScore score2;
private:
	/* add your private declarations */
};

#endif /* CORESCENE_H */
