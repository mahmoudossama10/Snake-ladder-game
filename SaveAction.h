#pragma once
#include "Action.h"
#include <fstream>
class SaveAction : public Action
{
	ofstream Outfile;
	string Check;
public :

	SaveAction(ApplicationManager* pApp); // initialize The Application Manager Pointer In Action Class
	                                      // It Also Opens The File That We Would Save The Grid In

	virtual void ReadActionParameters();  // Checks If The User Wants To Save The Grid Or Not

	virtual void Execute();               // If Yes, We Create Four Array Of Pointers
	                                      // At First We Create Array Of GameObject Pointers With The Size Of The Sum Of Ladders, Snaker And Cards
	                                      // Then We Send It To The Grid To Get All The GameObjects
	                                      // After This We Deattach Ladder, Snakes And Cards All On His Own
	                                      // Then We Upload The Data Of The Ladders Then Snakes Then Cards Using The Virtual Function Save In GameObject Class

	virtual ~SaveAction();                // Closes The File After Finishing
};

