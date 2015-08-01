#pragma once
#include "PrimitiveModel.h"
class CubeWall :
	public PrimitiveModel
{
public:
	CubeWall();
	~CubeWall();

	void Update();
	
	void SetMissingSide(bool side){ missingSide = side; }
	void SetPosZ(float position) { posZ = position; }

private:

	D3DXVECTOR3 currentPosition;

	float posZ;
	bool missingSide;
};