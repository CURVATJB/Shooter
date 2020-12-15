#include "Pattern.h"

Pattern::Pattern()
{
}

Pattern::~Pattern()
{
	delete this->moveStyle;
	delete this->shootStyle;
}

void Pattern::setMoveStyle(MoveStyle _moveStyle)
{
	switch (_moveStyle)
	{
	case E_MoveCloseTop:
		this->moveStyle = new Move_Close_Top;
		break;
	case E_MoveCloseBot:
		this->moveStyle = new Move_Close_Bot;
		break;
	case E_MoveFar:
		this->moveStyle = new Move_Far;
		break;
	}
}

void Pattern::setShootStyle(ShootStyle _shootStyle)
{
	switch (_shootStyle)
	{
	case E_ShootConic:
		this->shootStyle = new Shoot_Conic;
		break;
	case E_ShootLinear:
		this->shootStyle = new Shoot_Linear;
		break;
	case E_ShootBerserk:
		this->shootStyle = new Shoot_Berserk;
		break;
	}
}

void Pattern::InitializePattern(std::string _name, ShootStyle _shootStyle, MoveStyle _moveStyle)
{
	this->name = _name;
	setShootStyle(_shootStyle);
	setMoveStyle(_moveStyle);
}
