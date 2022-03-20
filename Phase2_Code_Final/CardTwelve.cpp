#include "CardTwelve.h"
#include"CardTen.h"
#include"CardNine.h"
#include"CardEleven.h"
#include "Input.h"
#include "Output.h"

//Note that Insert Prece and Fees of Card(9->11) is only done once

CardTwelve::CardTwelve()
{
	cardNumber = 12; // default constructor used in OpenGridAction
}

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (9->11 here)
}

CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	//no card parameters
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	/*  This card moves the ownership of the most expensive station that the current user owns
		from the current user to the player that has the least amount of coins in his wallet.
	    1-Search the most expensive at the current player
	    2-Get this station
		2-Search for the player whoe has the least amount of money 
		3-Get this player and make him own this station*/

	Player* playerlist[4];
	playerlist[0] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[1] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[2] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[3] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	Player* Poorest = playerlist[1];
	for (int i = 2; i < 4; i++)
	{
		if (playerlist[i]->GetWallet() < Poorest->GetWallet()) 
			Poorest = playerlist[i];
	}
		if (pPlayer->get_most_expensive_station() != NULL)
		{
			switch (pPlayer->get_most_expensive_station()->GetCardNumber())
			{
			case 9:
				((CardNine*)pPlayer->get_most_expensive_station())->setOwner(Poorest);
				break;
			case 10:
				((CardTen*)pPlayer->get_most_expensive_station())->setOwner(Poorest);
				break;
			case 11:
				((CardEleven*)pPlayer->get_most_expensive_station())->setOwner(Poorest);
				break;

			}

		}
		pOut->ClearStatusBar();
}

//CardTwelve Save
void CardTwelve::Save(ofstream& OutFile, object_type type)
{
	if (type == cards)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
	else return;
}

//CardTwelve Load
GameObject* CardTwelve::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile >> cell_num;
	position = CellPosition(cell_num);

	return this;
}