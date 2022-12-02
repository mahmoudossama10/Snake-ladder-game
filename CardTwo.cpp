
#include "CardTwo.h"
#include "Ladder.h"
CardTwo::CardTwo(const CellPosition& pos):Card(pos)
{
	SetCardNumber(2);
}


void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder*pLadder=pGrid->GetNextLadder(position);
	if (pLadder != NULL)
	{
		pGrid->PrintErrorMessage("Take The Express To The Next Ladder :D");
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
		pLadder->Apply(pGrid, pPlayer);
	}
	else
		pGrid->PrintErrorMessage("No Ladders Ahead :(");
}

void CardTwo::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardTwo::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}

CardTwo::~CardTwo()
{
}
