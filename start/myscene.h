/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "corescene.h"
<<<<<<< Updated upstream
=======
#include "myufo.h"

>>>>>>> Stashed changes
/// @brief The MyScene class is the Scene implementation.
class MyScene : public CoreScene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

protected:

private:
	/// @brief the rotating square in the middle of the screen
<<<<<<< Updated upstream
	MyPerson* myperson;
	MyCar* mycar[8];
	MyTree* mytree[8];
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	BasicEntity* myroads[16];
	BasicEntity* myhouse[3];
	BasicEntity* myparking[16];
=======
	MyUfo* myufo;
	MyPerson* myperson;
	MyCar* mycar[8];
	MyTree* mytree[7];
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	
	BasicEntity* myroads[16];
	BasicEntity* myhouse[3];
	BasicEntity* myparking[14];

>>>>>>> Stashed changes
};

#endif /* SCENE00_H */
