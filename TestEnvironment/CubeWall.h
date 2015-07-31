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

private:

	float posZ;
	bool missingSide;
};