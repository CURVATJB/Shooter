#pragma once
#include <string>

enum Label
{
	Character,
	HostileShip,
	PlayerProjectile,
	EnnemyProjectile,
	Particles,
};

enum ShootStyle
{
	E_ShootConic,
	E_ShootLinear,
	E_ShootBerserk,
};

enum MoveStyle
{
	E_MoveFar,
	E_MoveCloseTop,
	E_MoveCloseBot,
};