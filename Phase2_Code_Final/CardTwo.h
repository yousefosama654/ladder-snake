#pragma once
#include "Card.h"
class CardTwo :
    public Card
{


public:
	CardTwo();
	CardTwo(const CellPosition& pos); // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream &OutFile,object_type type)  ;	
	virtual GameObject* Load(ifstream &Infile,object_type type)  ;
	virtual ~CardTwo(); // A Virtual Destructor
};

