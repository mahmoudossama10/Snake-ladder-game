#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos):Card(pos)
{
	SetCardNumber(5);
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("The Way Is Closed Turn Back");
	int NewCellNum = position.GetCellNum() - pPlayer->Get_justRolledDiceNum();
	if (NewCellNum < 1)
		NewCellNum = 1;
	CellPosition NewPos(NewCellNum);
	pGrid->UpdatePlayerCell(pPlayer, NewPos);
	if (pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
}

void CardFive::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardFive::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}



CardFive::~CardFive()
{
}
