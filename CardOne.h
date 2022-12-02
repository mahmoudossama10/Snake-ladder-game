#pragma once

#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardOne :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardOne(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	int Get_Wallet_Amount();           // Getter For The Wallet Amount

	void Set_Wallet_Amount(int WA);    // Setter For The Wallet Amount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardOne(); // A Virtual Destructor
};

