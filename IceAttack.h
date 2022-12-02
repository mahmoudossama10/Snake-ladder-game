#pragma once
#include "SpecialAttacks.h"
#include "Player.h"
class IceAttack : public SpecialAttacks
{
	Player* Executer;
public:
	IceAttack(Grid* pGrid ,Player* pPlayer);
	virtual void Execute();
	virtual ~IceAttack();
};

