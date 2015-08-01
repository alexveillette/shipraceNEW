#include "Tunnel.h"


Tunnel::Tunnel()
	:PrimitiveModel(PrimitiveModel_Type::CYLINDER)
	, currentRotation(0.f)
{
	SetScale(20.f, 20.f, 100.f);
}


Tunnel::~Tunnel()
{
}

void Tunnel::Update()
{
	//The tunnel's rotation is constantly changed to simulate ship movement.

	currentRotation += 3 * gTimer->GetDeltaTime();
	SetRotationZ(currentRotation);
}
