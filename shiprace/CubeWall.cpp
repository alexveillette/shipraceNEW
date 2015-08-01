#include "CubeWall.h"


CubeWall::CubeWall()
	: PrimitiveModel(PrimitiveModel::CUBE)
	, posZ(200)
	, missingSide(false)
{
	SetScale(10.f, 10.f, 1.f);
}


CubeWall::~CubeWall()
{
}

void CubeWall::Update()
{
	//Each cube in the wall handles its own movement.
	//If it is chosen as the missing side, it does not move.

	currentPosition = GetPosition();

	posZ -= 150 * gTimer->GetDeltaTime();

	if (!missingSide)
	{
		SetPosition(currentPosition.x, currentPosition.y, posZ);
	}
	
}