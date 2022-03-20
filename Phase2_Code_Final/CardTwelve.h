#pragma once
#include "Card.h"
#include "fstream"
class CardTwelve : public Card
{
	// CardTwelve Parameters:
	

public:
	CardTwelve();
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNineToEleven which is: (walletAmount)

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNineToEleven on the passed Player
													  // (by decrementing the player's wallet by the walletAmount data member)

	virtual ~CardTwelve(); // A Virtual Destructor
	virtual GameObject* Load(ifstream& Infile, object_type type);
	void Save(ofstream& OutFile, object_type type);
};