#include "AddCardAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
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

AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	cardNumber = -1;
}


AddCardAction::~AddCardAction()
{
}


void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card: Please Enter its Number ...");
	cardNumber = pIn->GetInteger(pOut);
	if (cardNumber < 1 || cardNumber > 12)
	{
		pGrid->PrintErrorMessage("Card Number Should Be Between 1 & 12");
		Valid = false;
		return;
	}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	// 4- Make the needed validations on the read parameters
	pOut->PrintMessage("Please Press On Its Location In The Grid ...");
	cardPosition = pIn->GetCellClicked();
	if (!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Selected Cell Is Invalid");
		Valid = false;
	}
	if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("You Cannot Add Card To The First Or Last Cell In The Grid");
		Valid = false;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}


void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	Card* pCard;
	bool Check;
	Grid* pGrid = pManager->GetGrid();
	
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	if (Valid)
	{
		pCard = new Card(cardPosition);
		// 2- Switch case on cardNumber data member and create the appropriate card object type
		pCard = NULL; // will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9: case 10: case 11:
			pCard = new Stations(cardPosition, cardNumber);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		}

		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// A- We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);
			// C- Add the card object to the GameObject of its Cell:
			bool check = pGrid->AddObjectToCell(pCard);
			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			if (!check)
				pGrid->PrintErrorMessage("Cannot Add The Card To The Cell , Press To Continue ...");
			else
				pCard->SetNumCards(pCard->GetNumCards() + 1);
		}

		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
	}
}
