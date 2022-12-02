#pragma once
#include "Card.h"
#include "Player.h"
class CardTwelve : public Card
{
public :
	CardTwelve(const CellPosition& pos); // Constructor To Initialize The Cell Position Of The Card And Its Number

	virtual void Apply(Grid* pGrid, Player* pPlayer); /* First We Get The Four Players Including The Current Player
													     Then, By Using GetLessWallet Function We Can Get The Least Player Wallet
														 After Getting The Least Player Wallet We Check The Stations Owners
														 We Count The Number Of Stations That The Current Player Have
														 If He Has One At Least, We Create A New Int Storage With The Size Of The Number Of Stations
														 This Will Be Used To Save Stations Number (9-10-11)
														 By Comparing The Station Price Of Each One We Can Get The Most Valuable Station
														 After All Of This, We Change The Ownership Of The Most Valuable Station To The LeastPlayerWallet*/

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardTwelve(); // Virtual Destructor
};

