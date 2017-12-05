/**
* This class describes Corescene behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
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

	// create the scene 'tree'
	// add myentity to this Scene as a child.

}
CoreScene::~CoreScene()
{	
	// deconstruct and delete the Tree
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
}

void CoreScene::update(float deltaTime)
{

}
