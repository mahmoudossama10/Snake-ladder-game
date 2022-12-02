#include "IceAttack.h"
#include "Player.h"
IceAttack::IceAttack(Grid* pGrid, Player* pPlayer) : SpecialAttacks(pGrid)
{
	Executer = pPlayer;
}

void IceAttack::Execute()
{
	int PlayerNum;
	do
	{
		pGrid->GetOutput()->PrintMessage("Enter The Number Of Player To Freeze");
		PlayerNum = pGrid->GetInput()->GetInteger(pGrid->GetOutput()) - 1;
		if (PlayerNum != Executer->GetPlayerNum() && (PlayerNum >= 0 && PlayerNum <= 3))
			break;
		else
			pGrid->PrintErrorMessage("You Can't Freeze Yourself");
	} while (1);
	for (int i = 0; i < 4; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum() == PlayerNum)
			pGrid->GetCurrentPlayer()->Freeze();
	}
	//CardFour::Apply(pGrid)
}

IceAttack::~IceAttack()
{
}
