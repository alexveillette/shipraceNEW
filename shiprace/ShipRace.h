#pragma once

#include "Component.h"
#include "Triangle.h"
#include "Cube.h"
#include "TriGrid.h"
#include "Ship.h"
#include "Tunnel.h"
#include "CubeWall.h"
#include "TitleScreen.h"

class ShipRace :
	public Component
{
public:
	ShipRace();
	~ShipRace();

	void Update();
	void Draw();
	void Stop();

	void MissingObstacle();
	void CheckCollision();

private:

	TitleScreen* titleScreen;

	Tunnel* tunnel;
	Ship* ship;

	CubeWall* cube1;
	CubeWall* cube2;
	CubeWall* cube3;
	CubeWall* cube4;
	CubeWall* cube5;

	CubeWall* cubeMeasure;

	std::vector <CubeWall*> cubeWallArray;

	D3DXVECTOR3 wallPosition;
	D3DXVECTOR3 currentPos;

	bool collisionChecked;
	int missingSide;
};

