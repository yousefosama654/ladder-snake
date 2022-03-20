#pragma once
#include "Card.h"
#include"CellPosition.h"
class CardSix : public Card
{
	CellPosition to_move_to;
public:
	CardSix();
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	CellPosition GetToMoveTo();
	void SetToMoveTo(CellPosition goingto);
	virtual void Save(ofstream &OutFile,object_type type)  ;	
	virtual GameObject* Load(ifstream &Infile,object_type type)  ;
	virtual ~CardSix(); // A Virtual Destructor
};

