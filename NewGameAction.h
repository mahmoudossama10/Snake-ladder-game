#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
#include "Stations.h"
class NewGameAction : public Action
{
	bool Check;
public :
	NewGameAction(ApplicationManager* pApp);           // Constructor To Initialize The Application Manager Pointer In Action Class
	 
	NewGameAction(ApplicationManager* pApp , bool Ok); // OverLoaded Consturctor Will Be Used In ToDesignMode Action

	virtual void ReadActionParameters();               // Check If The User Want To Start A New Game


	virtual void Execute();                            // After Checking The User, And If He Wanted To Start A New Game
	                                                   // We Reset The Player To Their Start Location With Their With Their Initial Statues
	                                                   // Initial Statues Of Player Is Cell Num "1" And Wallet "100" And The Turn Is On Player 0
                                                       // This Is Done By Calling ResetPlayer From Player Class
	                                                   // Then We Should Also Reset The Station To Its Initial Statues (No Owner For The Station)
	                                                   // This Is Done By Calling (ResetStation) from Stations Class

	                               
	virtual ~NewGameAction();  // Virtual Destructor
};

