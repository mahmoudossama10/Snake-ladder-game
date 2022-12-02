#pragma once
#include "SpecialAttacks.h"
class Poison : public SpecialAttacks
{
	Player* Executer;
public :
	Poison(Grid* pGrid ,Player* pPlayer);
	virtual void Execute();
	virtual ~Poison();
};

