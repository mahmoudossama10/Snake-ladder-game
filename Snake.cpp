#include "Snake.h"
#include "Player.h"
#include "Ladder.h"
int Snake::NumOfSnakes = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) :GameObject(startCellPos)
{
	this->endcellpos = endCellPos;
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endcellpos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a Snake.Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endcellpos);
	if (pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
}

CellPosition Snake::GetEndPosition() const
{
	return endcellpos;
}

void Snake::Save(ofstream& OutFile)
{
	OutFile << (this->GetPosition()).GetCellNum() << '\t' << (this->GetEndPosition()).GetCellNum() << '\n';
}

int Snake::GetNumOfSnakes()
{
	return NumOfSnakes;
}

void Snake::SetNumSnakes(int x)
{
	NumOfSnakes = x;
}

void Snake::Load(ifstream& Infile, Grid* pGrid)
{
	int StartNum, EndNum;
	Infile >> StartNum >> EndNum;
	position = CellPosition::GetCellPositionFromNum(StartNum);
	endcellpos = CellPosition::GetCellPositionFromNum(EndNum);
	pGrid->AddObjectToCell(this);
	Draw(pGrid->GetOutput());
}

bool Snake::IsOverLapping(GameObject* newObj)
{
	Snake* newS = dynamic_cast<Snake*>(newObj);
	Ladder* newL = dynamic_cast<Ladder*>(newObj);
	if (newS && newS->GetPosition().HCell() == this->GetPosition().HCell())
	{
		if (newS->GetPosition().VCell() > this->GetPosition().VCell() && newS->GetPosition().VCell() < this->GetEndPosition().VCell())
			return true;
		if (newS->GetPosition().VCell() < this->GetPosition().VCell() && newS->GetEndPosition().VCell() > this->GetPosition().VCell())
			return true;
		if (newS->GetEndPosition() == this->GetPosition())
			return true;
	}
	if (newL)
		if (newL->GetEndPosition() == this->GetPosition())
			return true;
	if (newObj->GetPosition() == this->GetEndPosition() || newObj->GetPosition() == this->GetPosition())
		return true;
	return false;
}

Snake::~Snake()
{
}
