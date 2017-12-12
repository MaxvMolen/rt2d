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
#include "myperson.h"
#include "mycar.h"
#include "mytree.h"
#include "myufo.h"

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
	static int activescene;

protected:
	unsigned int top_layer;
	std::vector<BasicEntity*> layers;
	std::vector<Text*> text;
private:
	/* add your private declarations */
};

#endif /* CORESCENE_H */
