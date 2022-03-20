#pragma once
#include "Card.h"
class CardFive :
    public Card
{
	
public:
	CardFive();
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardFive(); // A Virtual Destructor
	virtual void Save(ofstream &OutFile,object_type type)  ;	
	virtual GameObject* Load(ifstream &Infile,object_type type)  ;	

};

