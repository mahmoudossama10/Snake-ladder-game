#include "FireAttack.h"
#include "Grid.h"
#include "Player.h"
FireAttack::FireAttack(Grid* pGrid) : SpecialAttacks(pGrid)
{
}

void FireAttack::Execute()
{
	for (int i = 0; i < 3; i++)
	{
		pGrid->GetCurrentPlayer()->SetOnFire(true);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->AdvanceCurrentPlayer();
}

FireAttack::~FireAttack()
{
}
