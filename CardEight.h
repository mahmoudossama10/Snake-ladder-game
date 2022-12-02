#pragma once
#include "Output.h"
#include "Input.h"
#include "Grid.h"
#include "Card.h"
class CardEight : public Card
{
	int AmountOfCoins;
public :
	CardEight(const CellPosition& pos); // Constructor To Initialize The Position Of The Card And Its Number "8"

	virtual void ReadCardParameters(Grid* pGrid); // Reads From The User The Amount Of Coins To Exit The Prison

	void SetAmountOfCoins(int x);                 // Setter For The Amount Of Coins => Will Be Used In Copy Action

	int Get_Amount_Of_Coins();                    // Getter For The Amount Of Coins

	virtual void Apply(Grid* pGrid, Player* pPlayer); /* When A Player Stop On The Card, First We Check His Wallet
													     If His Wallet Was Greater Than Or Equal To The Amount Of Coins :
														 We Ask Him If He Wants To Pay The Fees And Exit The Prison Or Enter The Prison
														 If He Wanted To Pay , We Decreament His Wallet By The Fees
														 if He Didn't Want To Pay , We Set The Boolean (InPrison) In This Player Object With True.
														 But If His Wallet Was Less Than The Amount Of Coins, We Set InPrison True Without Asking Him*/

	virtual void Save(ofstream& OutFile);             /* Save The Amount Of Coins In The File Sent As A Parameter */

	virtual void Load(ifstream& Infile, Grid* pGrid); /* Load The Amount Of Coins Red From The File*/

	virtual ~CardEight();                           // Destructor
};

