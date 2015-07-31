#pragma once

#include "Component.h"
#include "Triangle.h"
#include "Cube.h"
#include "TriGrid.h"
#include "Ship.h"
#include "Tunnel.h"
#include "CubeWall.h"

class ShipRace :
	public Component
{
public:
	ShipRace();
	~ShipRace();

	void Start();
	void Update();
	void Draw();
	void Stop();

	void MissingObstacle();

private:
	CubeWall* cube1;
	CubeWall* cube2;
	CubeWall* cube3;
	CubeWall* cube4;
	CubeWall* cube5;

	CubeWall* cubeMeasure;

	std::vector <CubeWall*> cubeWallArray;

	D3DXVECTOR3 wallPosition;
	D3DXVECTOR3 currentPos;

	Tunnel* tunnel;
	Ship* ship;

	bool obstaclesReset;
	int missingSide;
};

