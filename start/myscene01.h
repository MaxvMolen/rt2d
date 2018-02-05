/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @file myscene01.h
 *
 * @brief description of MyScene01 behavior.
 */

#ifndef MYSCENE01_H
#define MYSCENE01_H

#include <rt2d/scene.h>
#include "corescene.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene01 : public CoreScene
{
public:
	/// @brief Constructor
	MyScene01();
	/// @brief Destructor
	virtual ~MyScene01();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	/// @brief this function turns myufo red on collision with the given object.
	/// @brief it also will lock the player on the object it collided with.
	/// @brief the player can free itself with the w key.
	/// @param xu the x-position of the ufo
	/// @param yu the y-position of the ufo
	/// @param ru the radius of the ufo
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @param no the number specific to the object
	/// @return void
	virtual void collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime);
	/// @brief this function turns myufo red on collision with the given object.
	/// @brief it also will lock the player on the object it collided with.
	/// @brief the player can free itself with the w key.
	/// @param xu the x-position of the ufo
	/// @param yu the y-position of the ufo
	/// @param ru the radius of the ufo
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @param no the number specific to the object
	/// @return void
	virtual void collision2(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime);
	
private:
	/// @brief the background for the score counter
	std::vector<BasicEntity*> mybscore;
	/// @brief the rotating ufo you play in the game
	MyUfo* myufo;
	/// @brief the second player
	MyUfo2* myufo2;
	/// @brief the light underneath the ufo
	std::vector<BasicEntity*> light;
	/// @brief the name plate of the player
	std::vector<BasicEntity*> myplate;
	/// @brief example gameplay right
	BasicEntity* myexampleright;
	/// @brief example gameplay wrong
	BasicEntity* myexamplewrong;
	/// @brief the header
	BasicEntity* myheader;
	/// @brief the background of the scene
	BasicEntity* myback;
	/// @brief the background of the text
	BasicEntity* mytext;
	/// @brief the pause icon
	BasicEntity* mypause;
	/// @brief the home button
	BasicEntity* myhomebutton;
	/// @brief the pause button
	BasicEntity* mypausebutton;
	/// @brief the example home button
	BasicEntity* examplehomebutton;
	/// @brief the example pause button
	BasicEntity* examplepausebutton;
	/// @brief small background
	BasicEntity* mysmallback;
	/// @brief the person in the level that you need to pick up
	std::vector<MyPerson*> myperson;
	/// @brief the car in the level that you need to pick up
	std::vector<MyCar*> mycar;
	/// @brief the tree in the level that you need to pick up
	std::vector<MyTree*> mytree;
	/// @brief the road in the background of the level
	std::vector<BasicEntity*> myroads;
	/// @brief the footpath in the background of the level
	std::vector<BasicEntity*> mypath;
};

#endif /* MYSCENE01_H */
