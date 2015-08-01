#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
	:collisionChecked(false)
	, currentPos(0, 0, 0)
	, wallPosition(0.f, 30.f, 200.f)
	, missingSide(0)
{
	Textures->LoadTexture(Texture::TITLE_SCREEN, "TitleScreen.jpg");

	//The tunnel and ship are created, and then the wall of cubes
	//is created. The 6th cube, cubeMeasure, is used to check the
	//location of the actual wall and is never seen on-screen.

	tunnel = new Tunnel();
	ship = new Ship();

	cube1 = new CubeWall();
	cube1->SetPosition(10.f, 0.f, 200.f);
	cubeWallArray.push_back(cube1);

	cube2 = new CubeWall();
	cube2->SetRotationZ(15.f);
	cube2->SetPosition(10.f, -10.f, 200.f);
	cubeWallArray.push_back(cube2);

	cube3 = new CubeWall();
	cube3->SetPosition(0.f, -15.f, 200.f);
	cubeWallArray.push_back(cube3);

	cube4 = new CubeWall();
	cube4->SetRotationZ(15.f);
	cube4->SetPosition(-10.f, -10.f, 200.f);
	cubeWallArray.push_back(cube4);

	cube5 = new CubeWall();
	cube5->SetPosition(-10.f, 0.f, 200.f);
	cubeWallArray.push_back(cube5);

	cubeMeasure = new CubeWall();
	cubeMeasure->SetPosition(0.f, 30.f, 200.f);

	//The random generator is initialized.
	srand(time(0));

	//At the start of the game, the MissingObstacle function is called
	//to remove one cube from the wall immediately.
	MissingObstacle();
}

ShipRace::~ShipRace()
{
	delete ship;
	delete tunnel;
	delete cube1;
	delete cube2;
	delete cube3;
	delete cube4;
	delete cube5;
	delete cubeMeasure;

}


void ShipRace::Update()
{
	//The wallPosition vector is simply the location of a cube
	//that is outside the screen and follows the real wall.
	//The collision is checked when the cubes reach the ship
	//and a new missing cube is chosen immediately after.

	wallPosition = cubeMeasure->GetPosition();

	if (wallPosition.z <= 10.f && !collisionChecked)
	{
		CheckCollision();
		collisionChecked = true;
	}

	if (wallPosition.z <= 0.f)
	{
		cubeMeasure->SetPosZ(200.f);
		MissingObstacle();
		collisionChecked = false;
	}
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

void ShipRace::MissingObstacle()
{
	//Every time the cubes reach the location of the camera, a new
	//cube is randomly chose as the "hole" the ship can now go through.
	//Then, all cubes are sent to the back of the tunnel.

	missingSide = rand() % 5;

	for (int i = 0; i < cubeWallArray.size(); i++)
	{
		if (i == missingSide)
		{
			currentPos = cubeWallArray[i]->GetPosition();
			cubeWallArray[i]->SetMissingSide(true);
			cubeWallArray[i]->SetPosition(currentPos.x, currentPos.y, 300.f);
		}
		else
		{
			cubeWallArray[i]->SetPosZ(200.f);
			cubeWallArray[i]->SetMissingSide(false);
		}
	}
}

void ShipRace::CheckCollision()
{
	//When the cube reaches the location of the camera, this function
	//checks whether the ship is within the "safe" angle boundaries.
	// If it is, the game keeps going. If it isn't, it's game over.

	int currentAngle = ship->GetShipAngle();

	switch (missingSide)
	{
	case 0:
		if (currentAngle >= -10.f)
		{
			std::cout << "SAFE! top right" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		else
		{
			std::cout << "> GAMEOVER top right" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		break;
	case 1:
		if (currentAngle <= -30.f && currentAngle >= -55.f)
		{
			std::cout << "SAFE bottom right" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		else
		{
			std::cout << "GAMEOVER bottom right" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		break;
	case 2:
		if (currentAngle <= -75.f && currentAngle >= -105.f)
		{
			std::cout << "SAFE middle" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		else
		{
			std::cout << "GAMEOVER middle" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		break;
	case 3:
		if (currentAngle <= -120.f && currentAngle >= -150.f)
		{
			std::cout << "SAFE bottom left" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		else
		{
			std::cout << "GAMEOVER bottom left" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		break;
	case 4:
		if (currentAngle <= -175.f)
		{
			std::cout << "SAFE top left" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		else
		{
			std::cout << "GAMEOVER top left" << std::endl;
			std::cout << currentAngle << std::endl;
		}
		break;

	default:
		break;
	}

}