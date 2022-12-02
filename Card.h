#pragma once

#include "GameObject.h"
#include "Player.h"
#include <fstream>
// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
	
	static int NumOfCards; // Number Of Total Card Made In The Grid

protected:
	
	int cardNumber; // an integer representing the card number

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it , And Increment The Number Of Cards
	
	virtual ~Card();                // A Virtual Destructor To Decrement The Number Of Cards

	// ===================================================================================================================== //

	// Setters And Getters :-
	void SetCardNumber(int cnum);   // The setter of card number

	int GetCardNumber();            // The getter of card number

	static int GetNumCards();       // Getter For The Total Number Of Cards Made In The Grid

	static void SetNumCards(int x);

	void Set_Position(CellPosition A); // Setter For The Position Of The Card (Used In Copy Action)

	// ===================================================================================================================== //

	// Main Card Functions :-

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual bool IsOverLapping(GameObject* newObj);    // This Function Has No Meaning Here But If It Wasn't Implemented This Class Would Be Abstract Class


	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)

	// ===================================================================================================================== //

	// Save And Load Function :-

	virtual void Save(ofstream& OutFile);              // Virtual Function To Save The Card Parameters


	virtual void Load(ifstream& Infile, Grid* pGrid);  // Virtual Function To Load The Card Parameters "Read The Cell Number From The File Then Add The Card To That Cell"


};

