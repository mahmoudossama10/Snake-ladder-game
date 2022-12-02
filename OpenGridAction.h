#pragma once
#include "Action.h"
#include <fstream>
class OpenGridAction : public Action
{
	ifstream File;
public :

	OpenGridAction(ApplicationManager* pApp); // Constructor for Initializing The Application Manager Pointer In Action Class

	virtual void ReadActionParameters();      // Here We First Ask The User If He Wants To Load The Grid From The Default File Or Another File
	                                          // If He Wants To Load An External File We Ask Him To Enter Its Name
	                                          // After This We Try To Open The File If This Done We Save It In File To Be Used Later
	                                          // If We Failed Opening The File We Ask The User Again To Enter The File Name
	                                          // If The User Said No At First We Just Open The Main File To Save And Load "Named grid.txt"

	virtual void Execute();                   /* After Reading The Parameters "File To Load From" From The User
											     First We Store The Number Of Ladder Then Looping With Number Of Iterations Equal To It
												 In Each Iteration, We Make A New Ladder, Loading Its Parameters With Virtual Function "Load" In GameObject Class
												 Then We Add It To Its Cell By Using AddObjectToCell Function Located In The Grid
												 Same Thing Happens With The Snakes And Cards
												 After Loading A Grid, We Ask The User Again If He Wants To Load This Grid Or Not
												 If He Wants Another Grid, We Use ClearAllObjectsFunction In The Grid Class To Remove All Game Objects
												 Then We Start The Previous Steps Again Until The User Choose A Grid Or The File Ends
												 If The File Ended Just Display The Initial Grid*/

	virtual ~OpenGridAction();
};

