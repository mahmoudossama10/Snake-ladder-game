#include "Player.h"
#include "GameObject.h"
#include "Card.h"
class Stations;
Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	ResetPlayer();
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

void Player::SetInPrison(bool Test)
{
	InPrison = Test;
}

void Player::SetPrevented(bool Test)
{
	PreventedCard4 = Test;
}

void Player::SetPoisoned(bool Test)
{
	Poisoned = Test;
	PoisonCount += 5;
}

Cell* Player::GetCell() const
{
	return pCell;
}

bool Player::CheckPoisoned()
{
	return Poisoned;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetDept()
{
	return Total_Dept;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

int Player::Get_justRolledDiceNum()
{
	return justRolledDiceNum;
}

void Player::SetOnFire(bool Test)
{
	OnFire = Test;
	NumberOfFireAttackers++;
	if (NumberOfFireAttackers == 1)
		FirstAttacker++;
	if (NumberOfFireAttackers == 2)
		SecondAttacker++;
	if (NumberOfFireAttackers == 3)
		ThirdAttacker++;
}

void Player::Freeze()
{
	Iced = true;
	Frozen++;
}


void Player::IncreasePoisonCount()
{
	PoisonCount--;
	if (PoisonCount == 0)
	{
		Poisoned = false;
	}
}

bool Player::UseSpecialAttack(Grid* pGrid)
{
	if (SpecialAttackCounter < 2)
	{
		pGrid->GetOutput()->PrintMessage("Would You Like To Use A Special Attack ?(y,n)");
		string Check = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		if ((Check == "Y" || Check == "y"))
		{
			do
			{
				string Msg = "Press ";
				if (!FireUsed)
					Msg += "(1) For Fire Attack, ";
				if (!IceUsed)
					Msg += "(2) For Ice Attack, ";
				if (!LightningUsed)
					Msg += "(3) For Lightning Attack, ";
				if (!PoisonUsed)
					Msg += "(4) For Posion Attack ";
				pGrid->GetOutput()->PrintMessage(Msg);
				int AttackNum = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
				switch (AttackNum)
				{
				case 1:
					if (!FireUsed)
					{
						pSpecialAttacks = new FireAttack(pGrid);
						pSpecialAttacks->Execute();
						FireUsed = true;
						SpecialAttackCounter++;
					}
					break;
				case 2:
					if (!IceUsed)
					{
						pSpecialAttacks = new IceAttack(pGrid, this);
						pSpecialAttacks->Execute();
						IceUsed = true;
						SpecialAttackCounter++;
					}
					break;
				case 3:
					if (!LightningUsed)
					{
						pSpecialAttacks = new LightningAttack(pGrid);
						pSpecialAttacks->Execute();
						LightningUsed = true;
						SpecialAttackCounter++;
					}
					break;
				case 4:
					if (!PoisonUsed)
					{
						pSpecialAttacks = new Poison(pGrid, this);
						pSpecialAttacks->Execute();
						PoisonUsed = true;
						SpecialAttackCounter++;
					}
					break;
				}
				if (!pSpecialAttacks)
					pGrid->PrintErrorMessage("You Have Already Used This Attack Before");
			} while (pSpecialAttacks == NULL);
			delete pSpecialAttacks;
			pSpecialAttacks = NULL;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


void Player::ResetPlayer()
{
	wallet = 100;

	Total_Dept = 0;

	justRolledDiceNum = 0;

	turnCount = 0;

	InPrison = false;

	PreventedCard4 = false;

	PrisonCount = 0;

	FireUsed = false;

	OnFire = false;

	NumberOfFireAttackers = 0;

	FirstAttacker = 0;

	CounterOne = 0;

	SecondAttacker = 0;

	CounterTwo = 0;

	ThirdAttacker = 0;

	CounterThree = 0;

	Firecount = 0;

	OnFireCounter = 0;

	IceUsed = false;

	Frozen = 0;

	Iced = false;

	LightningUsed = false;

	PoisonUsed = false;

	Poisoned = false;

	PoisonCount = 0;

	SpecialAttackCounter = 0;
}

Player* Player::GetLessWallet(Player** OtherPlayers, int n)
{
	int minWallet = this->GetWallet();
	int minLocation = -1;
	for (int i = 0; i < n; i++)
	{
		if (OtherPlayers[i]->GetWallet() < minWallet)
		{
			minWallet = OtherPlayers[i]->GetWallet();
			minLocation = i;
		}
	}
	if (minLocation == -1)
		return this;
	else
		return OtherPlayers[minLocation];
}



void Player::DecreaseWallet(int Curr)
{
	if (wallet < Curr)
	{
		Total_Dept += Curr - wallet;
		wallet = 0;
	}
	else
		wallet -= Curr;
}

void Player::IncreaseWallet(int Curr)
{
	if (Total_Dept > Curr)
		Total_Dept -= Curr;
	else
	{
		wallet += Curr - Total_Dept;
		Total_Dept = 0;
	}
}


// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	//color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	int CardNum;
	color cellColor;
	Card* C = pCell->HasCard();
	if (C)
		cellColor = UI.CellColor_HasCard[C->GetCardNumber() - 1];
	else
		cellColor = UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	// 3- Set the justRolledDiceNum with the passed diceNumber
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	// 6- Apply() the game object of the reached cell (if any)
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	// ==============================================================================================================================================
	int OldWallet = wallet;
	if (OnFire)
	{
		if (FirstAttacker == 1)
		{
			DecreaseWallet(20);
			CounterOne++;
			if (CounterOne == 3)
				FirstAttacker--;
		}
		if (SecondAttacker == 1)
		{
			DecreaseWallet(20);
			CounterTwo++;
			if (CounterTwo == 3)
				SecondAttacker--;
		}
		if (ThirdAttacker == 1)
		{
			DecreaseWallet(20);
			CounterThree++;
			if (CounterThree == 3)
				ThirdAttacker--;
		}
	}
	turnCount++;
	if (turnCount == 3)
		turnCount = 0;
	justRolledDiceNum = diceNumber;
	pGrid->AdvanceCurrentPlayer();
	if (InPrison)
	{
		PrisonCount++;
		if (PrisonCount == 3)
			InPrison = false;
		return;
	}
	if (PreventedCard4)
	{
		PreventedCard4 = false;
		return;
	}
	if (Iced)
	{
		Frozen--;
		if (Frozen == 0)
		{
			Iced = false;
		}
		return;
	}
	if (OldWallet == 0 && turnCount != 0)
	{
		pGrid->PrintErrorMessage("Unfortunately, You Don't Have Enough Money To Move :(");
		return;
	}
	if (turnCount == 0)
	{
		if (!UseSpecialAttack(pGrid))
			IncreaseWallet(diceNumber * 10);
		pGrid->GetOutput()->ClearStatusBar();
		turnCount = 0;
		return;
	}
	CellPosition Pos = this->GetCell()->GetCellPosition();
	if (Pos.GetCellNum()+diceNumber <= 99)
	{
		Pos.AddCellNum(justRolledDiceNum);
		pGrid->UpdatePlayerCell(this, Pos);
		GameObject* CurrGameObject = this->GetCell()->GetGameObject();
		if (CurrGameObject)
			CurrGameObject->Apply(pGrid, this);
		if (this->GetCell()->GetCellPosition().GetCellNum() == 99)
			pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum + 1) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(Total_Dept) + ", ";
	playersInfo += to_string(turnCount) + ", ";
	playersInfo += to_string(2 - SpecialAttackCounter) + ")";
}