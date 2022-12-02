#pragma once
#include "SpecialAttacks.h"
class FireAttack : public SpecialAttacks
{
public :
	FireAttack(Grid* pGrid);
	virtual void Execute();
	virtual ~FireAttack();
};

