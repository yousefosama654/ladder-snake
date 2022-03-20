#pragma once
#include "Card.h"
class CardSeven :
    public Card
{

public:
	CardSeven();
	CardSeven(const CellPosition& pos); 

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~CardSeven(); // A Virtual Destructor
	virtual void Save(ofstream &OutFile,object_type type)  ;	
	virtual GameObject* Load(ifstream &Infile,object_type type)  ;
};

