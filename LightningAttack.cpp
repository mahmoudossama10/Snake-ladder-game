#include "LightningAttack.h"
#include "Player.h"
LightningAttack::LightningAttack(Grid* pGrid) : SpecialAttacks(pGrid)
{
}

void LightningAttack::Execute()
{
	for (int i = 0; i < 3; i++)
	{
		pGrid->GetCurrentPlayer()->DecreaseWallet(20);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->AdvanceCurrentPlayer();
}

LightningAttack::~LightningAttack()
{
}
