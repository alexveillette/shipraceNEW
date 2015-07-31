#include "Ship.h"



Ship::Ship()
	: PrimitiveModel(PrimitiveModel::CONE)
	, SPEED(3.f)
	, TUNNEL_RADIUS(7.5f)
	, shipAngle(0.f)
	, DEFAULT_GRAVITY(0.01f)
{
	SetPosition(0.f, 0.f, -30.f);
	gravity = DEFAULT_GRAVITY;
}

Ship::~Ship()
{
}

void Ship::Update()
{
	ShipInput();
}


void Ship::ShipInput()
{
	
	float shipAngleDegrees = shipAngle * 180 / D3DX_PI;

	//Ship movement in the screen. Gravity is reset each time the throttle is used.
	if (gDInput->keyDown(DIK_RIGHT) && shipAngleDegrees <= 10.f)
	{
		shipAngle += SPEED * gTimer->GetDeltaTime();
		gravity = DEFAULT_GRAVITY;

	}
	else if (gDInput->keyDown(DIK_LEFT) && shipAngleDegrees >= -190.f)
	{
		shipAngle -= SPEED * gTimer->GetDeltaTime();
		gravity = DEFAULT_GRAVITY;
	}

	//Calling the gravity function to influence ship movement.
	ShipGravity(shipAngleDegrees);

	//Calculating the vector between the middle of the tunnel and where the ship needs to be.
	shipPosX = TUNNEL_RADIUS * cos(shipAngle);
	shipPosY = TUNNEL_RADIUS * sin(shipAngle);

	//Setting position of the ship after calculating the vector and gravity.
	SetPosition(shipPosX, shipPosY, 0.f);
}
	

void Ship::ShipGravity(float angle)
{
	//Gravity is in effect if the throttle is not used.
	bool throttle = (gDInput->keyDown(DIK_RIGHT) || gDInput->keyDown(DIK_LEFT));

	if (!throttle)
	{
		//Gravity affects the ship if it is not exactly at the bottom of the tunnel.
		gravity += 3 * gTimer->GetDeltaTime();

		if (angle > -90.f)
		{
			shipAngle -= gravity * gTimer->GetDeltaTime();
		}
		else if (angle < -90.f)
		{
			shipAngle += gravity * gTimer->GetDeltaTime();
		}
	}
}

