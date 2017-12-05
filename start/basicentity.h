/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 */

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <rt2d/entity.h>

 /// @brief The BasicEntity class is the Entity implementation.
class BasicEntity: public Entity
{
	public:
		/// @brief Constructor
		BasicEntity();
		/// @brief Destructor
		virtual ~BasicEntity();

		/// @brief update is automatically called every frame
		/// @param deltaTime the elapsed time in seconds
		/// @return void
		virtual void update(float deltaTime);

	private:
		/* add your private declarations */
};

#endif /* BASICENTITY_H */
