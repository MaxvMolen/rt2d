/**
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*
* @file mycar.h
*
* @brief description of MyCar behavior.
*/

#ifndef MYCAR_H
#define MYCAR_H

#include <rt2d/entity.h>

/// @brief The MyCar class is the Car implementation.
class MyCar : public Entity
{
public:
	/// @brief Constructor
	MyCar();
	/// @brief Destructor
	virtual ~MyCar();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYCAR_H */
