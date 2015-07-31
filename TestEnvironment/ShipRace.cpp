#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
	:obstaclesReset(false)
	, currentPos(0, 0, 0)
	, wallPosition(0.f, 30.f, 150.f)
	, missingSide(0)
{
	tunnel = new Tunnel();
	ship = new Ship();

	cube1 = new CubeWall();
	cube1->SetPosition(10.f, 0.f, 150.0f);
	cubeWallArray.push_back(cube1);

	cube2 = new CubeWall();
	cube2->SetRotationZ(15.f);
	cube2->SetPosition(10.f, -10.f, 150.0f);
	cubeWallArray.push_back(cube2);

	cube3 = new CubeWall();
	cube3->SetPosition(0.f, -15.f, 150.0f);
	cubeWallArray.push_back(cube3);

	cube4 = new CubeWall();
	cube4->SetRotationZ(-15.f);
	cube4->SetPosition(-10.f, -10.f, 150.0f);

	cubeWallArray.push_back(cube4);

	cube5 = new CubeWall();
	cube5->SetPosition(-10.f, 0.f, 150.0f);
	cubeWallArray.push_back(cube5);

	cubeMeasure = new CubeWall();
	cubeMeasure->SetPosition(0.f, 30.f, 150.f);
	MissingObstacle();

	srand(time(0));
}

ShipRace::~ShipRace()
{

}

void ShipRace::Start()
{

}

void ShipRace::Update()
{

}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

void ShipRace::MissingObstacle()
{
	missingSide = rand() % 5;

	for (int i = 0; i < cubeWallArray.size(); i++)
	{
		if (i == missingSide)
		{
			cubeWallArray[i]->SetMissingSide(true);
			currentPos = cubeWallArray[i]->GetPosition();
			cubeWallArray[i]->SetPosition(currentPos.x, currentPos.y, 150);
		}
		else
		{
			cubeWallArray[i]->SetMissingSide(false);
			currentPos = cubeWallArray[i]->GetPosition();
			cubeWallArray[i]->SetPosition(currentPos.x, currentPos.y, 150);
		}
	}
}