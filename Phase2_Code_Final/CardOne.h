#pragma once

#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardOne :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardOne();
	CardOne(const CellPosition & pos, int wallet=0); // A Constructor takes card position
	int getwalletamount();
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	virtual ~CardOne(); // A Virtual Destructor
	virtual void Save(ofstream &OutFile,object_type type) ;	       // Saves the GameObject parameters to the file
	virtual GameObject * Load(ifstream &Infile,object_type type) ; // Loads the GameObject parameters to the file
};

