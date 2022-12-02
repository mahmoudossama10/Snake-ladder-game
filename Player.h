#pragma once
#include "SpecialAttacks.h"
#include "FireAttack.h"
#include "Poison.h"
#include "IceAttack.h"
#include "LightningAttack.h"
#include "Grid.h"
#include "Cell.h"
class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	SpecialAttacks* pSpecialAttacks;

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells

	int wallet;		       // player's wallet (how many coins he has -- integer)

	int Total_Dept;        // Total Dept Of The Player

	int justRolledDiceNum; // the current dice number which is just rolled by the player

	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet

	bool InPrison;         // Used To See If The Player Is In Prison Or Not

	bool PreventedCard4;   // Used To See If The Player Is Prevented From Playing Because Of Card 4

	int PrisonCount;       // Counter To The How Many Rounds The Player Was Stopped By The Prison

	bool FireUsed;         // Bool To Determine If Fire Attack Is Used Or Not

	bool OnFire;           // Bool To Determine If The Player Is Hit By Fire Or Not

	int Firecount;         // Counter To The How Many Rounds The Player Was Attacked By The Fire
	
	int NumberOfFireAttackers; // How many Attackers on the same time  

	int FirstAttacker;

	int CounterOne;

	int SecondAttacker;

	int CounterTwo;

	int ThirdAttacker;

	int CounterThree;

	int OnFireCounter;     // Number Of Rounds The Player Was Affected By The Fire Attack

	bool IceUsed;          // Bool To Determine If Ice Attack Is Used Or Not

	int Frozen;            // Number Of Ice Attacks Hit The Player

	bool Iced;             // Bool To Check If The Player Was Hit By Ice Attack Or Not

	bool LightningUsed;    // Bool To Determine If Lightning Attack Is Used Or Not

	bool PoisonUsed;       // Bool To Determine If Poison Attack Is Used Or Not

	bool Poisoned;         // Bool To Check If The Player Is Poisoned Or Not

	int PoisonCount;       // Counter To The Number Of Times The Player Was Poisoned

	int SpecialAttackCounter;   // Counter To The Number Of Time A Special Attack Is Used

public:
	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell

	Cell* GetCell() const;			// A getter for the pCell

	int GetPlayerNum() const;

	int Get_justRolledDiceNum();

	void SetOnFire(bool Test);      // A Setter For On Fire

	int GetTurnCount() const;		// A getter for the turnCount

	void SetInPrison(bool Test);    // Change The Data Member InPrison For Card 8

	void SetPrevented(bool Test);   // Change The Data Member Prevented For Card 4

	bool CheckPoisoned();           // Getter For Poisoned Data Member
	 
	void SetPoisoned(bool Test);    // Setter For Poisoned Data Member

	int GetDept();                  // Getter For The Total Dept Of The Player

	void IncreasePoisonCount();     // Increament Poison Count By 1

	// =================================================== //
	// For Cards 9 - 10 - 11 - 12

	Player* GetLessWallet(Player** OtherPlayers, int n); // Gets The Least Player Wallet

	int GetWallet() const;			// a getter for the wallet

	void DecreaseWallet(int Curr);  // Decrease Wallet Amount With Passed Currency

	void IncreaseWallet(int Curr);  // Increase Wallet Amount With Passed Currency

	///TODO: You can add setters and getters for data members here (if needed)

	// =================================================== //

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	void AppendPlayerInfo(string& playersInfo) const; // Appends player's info to the input string, 
													   // for example: P0(wallet, turnCount)
													   // Note : We Added The Total Dept Of The Player And Number Of Special Attacks Left For Each Player

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it

	bool UseSpecialAttack(Grid* pGrid);         // Checks If The User Wants To Use A Special Attack Or Not
								 	            // This Is Done After Checking How Many Special Attacks Used (Should Be Less Than 2)
								               	// If He Wanted To Use A Special Attack, We Ask Him To Enter The Number Of Attack He Wants
									            // We Execute It After Making Sure That He Didn't Use This Attack Before
	void Freeze();                              // Set The Data Member Iced True , And Increase Frozen Counter By 1

	void ResetPlayer();                         // Resets The Player To Initial Position And Statues For New Game

	
};

