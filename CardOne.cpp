#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	SetCardNumber(1); // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	pOut->PrintMessage("Please Enter The Amount Of Coins To Be Decreased ...");
	int n =pIn->GetInteger(pOut);

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	walletAmount = n;
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->ClearStatusBar();

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

}

int CardOne::Get_Wallet_Amount()
{
	return walletAmount;
}

void CardOne::Set_Wallet_Amount(int WA)
{
	walletAmount = WA;
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Your Wallet Will Be Decreameanted By " + to_string(walletAmount));
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	pPlayer->DecreaseWallet(walletAmount);
	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

}

void CardOne::Save(ofstream& OutFile)
{
	Card::Save(OutFile);
	OutFile << "\t" << walletAmount << "\n";
}

void CardOne::Load(ifstream& Infile, Grid* pGrid)
{
	Card::Load(Infile, pGrid);
	Infile >> walletAmount;
}


