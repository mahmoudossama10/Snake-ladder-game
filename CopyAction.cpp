#include "CopyAction.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "Stations.h"
#include "CardTwelve.h"
#include "Grid.h"
CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{

}


CopyAction::CopyAction(ApplicationManager* pApp, CellPosition CardPos) : Action(pApp)
{
	ObjectPosition = CardPos;
}


void CopyAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	do 
	{
		pOut->PrintMessage("Copy Card :Please Press On The Card Location In The Grid ...");
		ObjectPosition = pIn->GetCellClicked();
		if (ObjectPosition.IsValidCell() && dynamic_cast<Card*>(pGrid->HasGameObject(ObjectPosition)))
			if (ObjectPosition.GetCellNum() != 1 && ObjectPosition.GetCellNum() != 99)
				break;
		pGrid->PrintErrorMessage("The Selected Cell Has No Card");
	} while (1);

	pOut->ClearStatusBar();
}


void CopyAction::Execute()
{
	if (Card::GetNumCards() > 0)
	{
		if (ObjectPosition.HCell() == -1)
		{
			ReadActionParameters();
		}
		Grid* pGrid = pManager->GetGrid();
		Card* OldCard = dynamic_cast<Card*>(pGrid->HasGameObject(ObjectPosition));
		Card* pNewCard;
		switch (OldCard->GetCardNumber())
		{
		case 1:
			pNewCard = new CardOne(ObjectPosition);
			dynamic_cast<CardOne*>(pNewCard)->Set_Wallet_Amount(dynamic_cast<CardOne*>(OldCard)->Get_Wallet_Amount());
			break;
		case 2:
			pNewCard = new CardTwo(ObjectPosition);
			break;
		case 3:
			pNewCard = new CardThree(ObjectPosition);
			break;
		case 4:
			pNewCard = new CardFour(ObjectPosition);
			break;
		case 5:
			pNewCard = new CardFive(ObjectPosition);
			break;
		case 6:
			pNewCard = new CardSix(ObjectPosition);
			dynamic_cast<CardSix*>(pNewCard)->Set_Destination(dynamic_cast<CardSix*>(OldCard)->Get_Destination());
			break;
		case 7:
			pNewCard = new CardSeven(ObjectPosition);
			break;
		case 8:
			pNewCard = new CardEight(ObjectPosition);
			dynamic_cast<CardEight*>(pNewCard)->SetAmountOfCoins(dynamic_cast<CardEight*>(OldCard)->Get_Amount_Of_Coins());
			break;
		case 9: case 10: case 11:
			pNewCard = new Stations(ObjectPosition, OldCard->GetCardNumber());
			break;
		case 12:
			pNewCard = new CardTwelve(ObjectPosition);
			break;
		}
		Card* Temp = pGrid->GetClipboard();
		pGrid->SetClipboard(pNewCard);
	}
	else
	{
		pManager->GetGrid()->PrintErrorMessage("There Is No Card In The Grid Yet");
	}
}


CopyAction::~CopyAction()
{

}
