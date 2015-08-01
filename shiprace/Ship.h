#pragma once

#include "PrimitiveModel.h"
#include "CubeWall.h"

class Ship
	: PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();
	void ShipInput();
	void ShipGravity(float angle);

	void ResetObstacles();

	int GetShipAngle(){ return shipAngleDegrees; }

private:
	const float SPEED;
	const float TUNNEL_RADIUS;
	const float DEFAULT_GRAVITY;

	float gravity;
	float shipAngle;
	float shipPosX;
	float shipPosY;

	float shipAngleDegrees;
};

