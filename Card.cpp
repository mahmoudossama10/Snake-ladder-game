#include "Card.h"
#include "Ladder.h"
#include "Snake.h"
int Card::NumOfCards = 0;
Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
}
// ===================================================================================================================== //
Card::~Card()
{
}
// ===================================================================================================================== //
void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 12)
	{
		cardNumber = cnum; 
	}
}
// ===================================================================================================================== //
int Card::GetCardNumber()
{
	return cardNumber;
}
// ===================================================================================================================== //
int Card::GetNumCards()
{
	return NumOfCards;
}
void Card::SetNumCards(int x)
{
	NumOfCards = x;
}

// ===================================================================================================================== //
void Card::Set_Position(CellPosition A)
{
	if (A.IsValidCell())
		position = A;
}
// ===================================================================================================================== //
void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
}
// ===================================================================================================================== //
bool Card::IsOverLapping(GameObject* newObj)
{
	return false;
}
// ===================================================================================================================== //
void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}
// ===================================================================================================================== //
void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}
// ===================================================================================================================== //
void Card::Save(ofstream& OutFile)
{
	OutFile << cardNumber << "\t" << GameObject::GetPosition().GetCellNum();
}
// ===================================================================================================================== //
void Card::Load(ifstream& Infile, Grid* pGrid)
{
	int CellNum;
	Infile >> CellNum;
	position = position.GetCellPositionFromNum(CellNum);
	pGrid->AddObjectToCell(this);
	Draw(pGrid->GetOutput());
}



