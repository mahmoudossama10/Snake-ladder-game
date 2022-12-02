#pragma once
#include "GameObject.h"
#include <fstream>
class Snake :
    public GameObject
{
	static int NumOfSnakes;
	CellPosition endcellpos;


public:
	Snake (const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	void Save(ofstream& OutFile);

	static int GetNumOfSnakes();         // Getter For The Total Number Of Snakes Made In The Grid

	static void SetNumSnakes(int x);

	virtual void Load(ifstream& Infile , Grid* pGrid);

	virtual bool IsOverLapping(GameObject* newObj); // Checks If The New Object Overlap The Old Snake , This Is Done When :
	                                                // If The Start Cell Of The New Snake Is Between The Start Cell And End Cell Of The Old Snake
	                                                // If The End Cell Of The New Snake Is Beneath The Start Cell Of The Old Snake Where The Start Cell Of The New Is Above The Start Of The Old
	                                                // If The End Cell Of The New Object Is The Start Cell Of The Old Snake
	virtual ~Snake(); // Virtual destructor
};

