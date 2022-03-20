#pragma once
#include "Card.h"
class CardEight :
    public Card
{
    int amount_of_coins;
public:
	CardEight();
	CardEight(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	int GetAmountOfCoins();
	void SetAmountOfCoins(int money);
	virtual ~CardEight(); // A Virtual Destructor
	virtual void Save(ofstream &OutFile,object_type type)  ;	// Saves the GameObject parameters to the file
	virtual GameObject* Load(ifstream &Infile,object_type type)  ;	
};

