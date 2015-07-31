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
	currentRotation += 3 * gTimer->GetDeltaTime();
	SetRotationZ(currentRotation);
}
