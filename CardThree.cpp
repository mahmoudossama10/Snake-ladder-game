#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	SetCardNumber(3); // calls the inherited function SetCardNumber to set the member cardNumber to the given value(3)
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("For Being A Good Player, Take Another Roll :)");
	for (int i = 0; i < 3; i++)
		pGrid->AdvanceCurrentPlayer();
}

void CardThree::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\n";
}

void CardThree::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
}


CardThree::~CardThree()
{
}
