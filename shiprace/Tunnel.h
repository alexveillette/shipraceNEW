#pragma once

#include "PrimitiveModel.h"

class Tunnel :
	public PrimitiveModel
{
public:
	Tunnel();
	~Tunnel();

	void Update();


private:
	float currentRotation;

};

