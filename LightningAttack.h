#pragma once
#include "SpecialAttacks.h"
class LightningAttack : public SpecialAttacks
{
public:
	LightningAttack(Grid* pGrid);
	virtual void Execute();
	virtual ~LightningAttack();
};

