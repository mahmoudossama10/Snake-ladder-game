#include "Poison.h"
#include "Player.h"
Poison::Poison(Grid* pGrid , Player* pPlayer) : SpecialAttacks(pGrid)
{
	Executer = pPlayer;
}

void Poison::Execute()
{
	int PlayerNum;
	do
	{
		pGrid->GetOutput()->PrintMessage("Enter The Number Of Player To Poison");
		PlayerNum = pGrid->GetInput()->GetInteger(pGrid->GetOutput()) - 1;
		if (PlayerNum != Executer->GetPlayerNum() && (PlayerNum >= 0 && PlayerNum <= 3))
			break;
		else
			pGrid->PrintErrorMessage("You Can't Poison Yourself");
	} while (1);
	for (int i = 0; i < 4; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum() == PlayerNum)
			pGrid->GetCurrentPlayer()->SetPoisoned(true);
	}
}

Poison::~Poison()
{
}
