/**
 * Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
 *
 * @brief Description of Ufo Game.
 *
 * @file main.cpp
 *
 * @mainpage Ufo Game
 *
 * @section intro Introduction
 *
 * In this game you play as an ufo. 
 * This ufo can transform with the use of the a,s and d keys. 
 * You use the different forms to pick up different objects for score.
 * But you need to use the right ufo otherwise you'll lose points.
 */
#include <rt2d/core.h>

#include "myscene00.h"
#include "myscene01.h"
#include "myscene02.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	std::vector<CoreScene*> myscenes;

	//myscenes.push_back(new MyScene00());
	myscenes.push_back(new MyScene01());
	myscenes.push_back(new MyScene02());
	int s = myscenes.size();

	// Scene01
	CoreScene* scene = myscenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s-1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s-1; scene->activescene = s-1; }
		scene = myscenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	/*
	MyScene* myscene = new MyScene(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}*/

	//delete all scenes
	for (int i = 0; i < s; i++) {
		delete myscenes[i];
		myscenes[i] = NULL;
	}
	myscenes.clear();
	
	
	/*
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene
	*/
	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
