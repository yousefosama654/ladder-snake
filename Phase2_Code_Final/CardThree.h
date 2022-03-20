#pragma once
#include "Card.h"
class CardThree :
    public Card
{
	public:
		CardThree();
		CardThree(const CellPosition& pos);

		virtual void ReadCardParameters(Grid* pGrid);

		virtual void Apply(Grid* pGrid, Player* pPlayer);

		virtual ~CardThree(); // A Virtual Destructor

		virtual void Save(ofstream &OutFile,object_type type)  ;	
	    virtual GameObject* Load(ifstream &Infile,object_type type)  ;
	};



