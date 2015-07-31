#include "CubeWall.h"


CubeWall::CubeWall()
	: PrimitiveModel(PrimitiveModel::CUBE)
	, posZ(150)
	, missingSide(false)
{
	SetScale(10.f, 10.f, 1.f);
}


CubeWall::~CubeWall()
{
}

void CubeWall::Update()
{
	D3DXVECTOR3 currentPosition = GetPosition();

	posZ -= 100 * gTimer->GetDeltaTime();


	

	if (currentPosition.z <= -10)
	{
		posZ = 150.f;
	}

	if (!missingSide)
	{
		SetPosition(currentPosition.x, currentPosition.y, posZ);
	}
	
	
	//std::cout << currentPosition.z << std::endl;
}