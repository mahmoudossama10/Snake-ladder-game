#include "CardSeven.h"
#include "Player.h"
#include "Grid.h"
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	SetCardNumber(7);
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition FirstCell(1);
	int NumberOfPlayers = 0;
	Player** P = pGrid->GetNextPlayer(pPlayer->GetCell()->GetCellPosition() , NumberOfPlayers);
	if (P)
	{
		pGrid->PrintErrorMessage("You Are Now A Black Hole , Pull The Next Player/s In Front Of You To Cell Num 1");
		for (int i = 0; i < NumberOfPlayers; i++)
			pGrid->UpdatePlayerCell(P[i], FirstCell);
	}
	else
		pGrid->PrintErrorMessage("No Players Detected");

}

void CardSeven::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardSeven::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}

CardSeven::~CardSeven()
{
}