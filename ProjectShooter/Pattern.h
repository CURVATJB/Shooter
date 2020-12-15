#pragma once
#include <string>
#include "I_MoveStyle.h"
#include "I_ShootStyle.h"
#include "Index.h"
#include "Shoot_Conic.h"
#include "Shoot_Linear.h"
#include "Shoot_Berserk.h"
#include "Move_Close_Top.h"
#include "Move_Close_Bot.h"
#include "Move_Far.h"


class Pattern
{
public:
	Pattern();
	~Pattern();
	
	void InitializePattern(std::string _name, ShootStyle _shootStyle, MoveStyle _moveStyle);

	std::string name;
	I_MoveStyle* moveStyle;
	I_ShootStyle* shootStyle;
private:
	void setMoveStyle(MoveStyle _moveStyle);
	void setShootStyle(ShootStyle _shootStyle);
};

