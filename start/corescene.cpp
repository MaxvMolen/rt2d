/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "corescene.h"

CoreScene::CoreScene() : Scene()
{

	top_layer = 7; // 8 layers (0-7)

	for (unsigned int i = 0; i <= top_layer; i++) {
		BasicEntity* layer = new BasicEntity();
		layers.push_back(layer);
		this->addChild(layer);
	}

	for (unsigned int i = 0; i < 16; i++) {
		Text* line = new Text();
		line->scale = Point2(0.5f, 0.5f);

		text.push_back(line);
		line->position = Point2(15, 0+i*27);
		layers[top_layer]->addChild(line);
	}

	text[1]->message("<ESC> quit game",YELLOW);
	text[2]->message("Score: 0", YELLOW);
	
	myufo = new MyUfo();
	myufo->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	layers[6]->addChild(myufo);

}
CoreScene::~CoreScene()
{	
	// deconstruct and delete the Tree
	this->removeChild(myufo);
	int ls = layers.size();
	for (int i = 0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = NULL;
	}
	layers.clear();

	int ts = text.size();
	for (int i = 0; i<ts; i++) {
		this->removeChild(text[i]);
		delete text[i];
		text[i] = NULL;
	}
	text.clear();

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myufo;
}

void CoreScene::update(float deltaTime)
{

}
