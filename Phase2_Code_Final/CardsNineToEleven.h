#pragma once
#include "Card.h"
class CardsNineToEleven : public Card
{
	// CardNineToEleven Parameters:
	static int CardPrice ; // The value of card that the player steps on 
	static int Fees;
	static Player* Owner;
	
public:
	CardsNineToEleven(const CellPosition& pos,int cardNumber); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNineToEleven which is: (walletAmount)

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNineToEleven on the passed Player
													  // (by decrementing the player's wallet by the walletAmount data member)

	virtual ~CardsNineToEleven(); // A Virtual Destructor

	int getCardPrice();
	int getFees();
	Player* getOwner();
	void setOwner(Player* owner);
	void setCardPrice(int StationPrice);
	void setFees(int PassingFees);
};
