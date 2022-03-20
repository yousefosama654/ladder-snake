#include "CardsNineToEleven.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
// intitializing the static data members because to be not to x

Player* CardsNineToEleven::Owner = NULL;
int CardsNineToEleven::Fees = 0;
int CardsNineToEleven::CardPrice = 0;

CardsNineToEleven::CardsNineToEleven(const CellPosition& pos,int CardNumber) : Card(pos) // set the cell position of the card
{
	cardNumber = CardNumber; // set the inherited cardNumber data member with the card number (9->11 here)

}

CardsNineToEleven::~CardsNineToEleven(void)
{

}

int CardsNineToEleven::getCardPrice()
{
	return CardPrice;
}

int CardsNineToEleven::getFees()
{
	return Fees;
}

void CardsNineToEleven::setOwner(Player* owner)
{
	Owner = owner;
}

void CardsNineToEleven::setCardPrice(int StationPrice)
{
	CardPrice = StationPrice;
}

void CardsNineToEleven::setFees(int PassingFees)
{
	Fees = PassingFees;
}

Player* CardsNineToEleven::getOwner()
{
	return Owner;
}

void CardsNineToEleven::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the Card_Price parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardsNineToEleven: Enter its Card Price ..."
	if (pGrid->IfCardOnGrid(cardNumber) == NULL)
	{
		pOut->PrintMessage("Enter Station Price");
		CardPrice = pIn->GetInteger(pOut);
		// 4- Read an Integer from the user using the Input class and set the Fees parameter with it
		//    Don't forget to first print to a descriptive message to the user like:"New CardsNineToEleven: Enter its Fees by passing players ..."
		pOut->PrintMessage("Enter fees paid by passing players");
		Fees = pIn->GetInteger(pOut);
		// [ Note ]:
		// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
		// to be able to perform his Apply() action
	}
	else
	{
		CardPrice =( (CardsNineToEleven* )(pGrid->IfCardOnGrid(cardNumber)))->getCardPrice();
		Fees = ( (CardsNineToEleven*) pGrid->IfCardOnGrid(cardNumber) )->getFees();

	}
	// 4- Clear the status bar
	pOut->ClearStatusBar();
}

void CardsNineToEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Ask Player if he wants to buy this station if not owed by someone and if he agrees deduct Card price from him
	if (Owner == NULL)
	{
		pOut->PrintMessage("Enter 1 if you want to buy this station");
		int ifAgree = pIn->GetInteger(pOut);
		if (ifAgree == 1)
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{
				Owner = pPlayer;
				pPlayer->DeductWallet(CardPrice);
				pOut->PrintMessage("You purchased the station successfully, Click to continue ...");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
			}
			else
			{
				pOut->PrintMessage("Transaction Failed ... Not enough money, Click to continue ...");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
			}
		}
		else
		{
			pOut->PrintMessage("Transaction Failed ... You refused the offer, Click to continue ...");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
	}
	else
		// 3- Decrement Fees from the wallet of pPlayer by the walletAmount if it's not his station and owed by someone else
	{
		if (Owner == pPlayer)
		{

		}
		else
		{
			pPlayer->DeductWallet(Fees);
			pOut->PrintMessage("You paid fees because you stepped on another player's property, Click to continue ...");
			pIn->GetCellClicked();
		}
	}

	pOut->ClearStatusBar();
}