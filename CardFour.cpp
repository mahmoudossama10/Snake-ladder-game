#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(4);
}

void CardFour::Apply(Grid* pGrid , Player* pPlayer)
{
	Card::Apply(pGrid , pPlayer);
	pGrid->PrintErrorMessage("For Bad Behaviour, Stop One Round");
	pPlayer->SetPrevented(true);
}

void CardFour::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardFour::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}


CardFour::~CardFour()
{
}
