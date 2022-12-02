#pragma once
#include "Card.h"
class Stations : public Card
{
	// Data Members Are Static So That It Will Be The Same For All Objects Of This Class
	static int StationPrice[3];
	static int FeesToPay[3];
	static Player* Owner[3];
public:
	Stations(const CellPosition& pos, int StationNumber); // Constructor To Initialize Card Position And The Card Number

	static int GetCardPrice(int stationNum);              // Getter For The Card Price

	static void Set_Station_Price(int St_Price, int St_Num); // Setter For The Station Price

	static void Set_Station_Fees(int St_Fees, int St_Num);  // Setter For The Station Fees

	static int GetCardFees(int stationNum);              // Getter For The Card Fees

	static void ChangeOwner(Player* P, int stationNum);   // Change The Owner Of The Station

	static Player* GetCardOwner(int StationNumber);       // Getter For The Card Owner

	virtual void ReadCardParameters(Grid* pGrid);         // First We Check If We Had Read The Parameters Of This Station Before Or Not
	                                                      // If We Didn't, We Ask The User To Enter The Station Price And The Fees To Pay On Stopping On It

	virtual void BuyStation(Grid* pGrid, Player* P);      // Make A Player Own The Station, Decreasing His Wallet With The Station Price

	virtual void Apply(Grid* pGrid, Player* pPlayer);     // First We See If The Station Is Owned By A Player Or Not
	                                                      // If It's Owned We Ask The User If He Wants To Buy The Station Or Not
	                                                      // If He Said Yes, We Check His Wallet To See Whether He Has Enough Money Or Not
	                                                      // If He Had Sufficient Money We Make Him Buy The Station
	                                                      // But If The Station Was Already Owned, We Check If The Player Is The Same As The One That Own The Station Or Not
	                                                      // If He Isn't We Decreament His Wallet With The Fees Of The Station And Add It To The Owner
	
	virtual void Save(ofstream& OutFile);                 // Save The Card Parameters

	virtual void Load(ifstream& Infile, Grid* pGrid);     // Load The Card Parameters

	static void ResetStations();                                 // Reset The Station For A New Game


	virtual ~Stations();
};
