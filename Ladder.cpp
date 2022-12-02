#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
#include "Grid.h"
int Ladder::NumLadders = 0;
Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.VCell() < startCellPos.VCell())
		this->endCellPos = endCellPos;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{

	pGrid->PrintErrorMessage("You have reached a ladder.Click to continue ...");
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	if (pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

void Ladder::Save(ofstream& OutFile)
{
	OutFile << (this->GetPosition()).GetCellNum() << '\t' << (this->GetEndPosition()).GetCellNum() << '\n';
}

int Ladder::GetNumLadders()
{
	return NumLadders;
}

void Ladder::SetNumLadders(int x)
{
	NumLadders = x;
}



void Ladder::Load(ifstream& Infile, Grid* pGrid)
{
	int StartNum, EndNum;
	Infile >> StartNum >> EndNum;
	position = CellPosition::GetCellPositionFromNum(StartNum);
	endCellPos = CellPosition::GetCellPositionFromNum(EndNum);
	pGrid->AddObjectToCell(this);
	Draw(pGrid->GetOutput());
}

bool Ladder::IsOverLapping(GameObject* newObj)
{
	Ladder* newL = dynamic_cast<Ladder*>(newObj);
	Snake* newS = dynamic_cast<Snake*>(newObj);
	if (newL)
		if (newL->GetPosition().VCell() < this->GetPosition().VCell() && newL->GetPosition().VCell() > this->GetEndPosition().VCell())
			return true;
		else
			if (newL->GetPosition().VCell() > this->GetPosition().VCell() && newL->GetEndPosition().VCell() < this->GetPosition().VCell())
				return true;
			else
				if (newL->GetEndPosition() == this->GetPosition())
					return true;
	if (newS)
		if (newS->GetEndPosition() == this->GetPosition())
			return true;
	if (newObj->GetPosition() == this->GetEndPosition())
		return true;
	return false;
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}

