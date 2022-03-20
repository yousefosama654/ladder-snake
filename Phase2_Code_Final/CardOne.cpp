#include "CardOne.h"
#include "Input.h"
#include "Output.h"
#include <fstream>
#include <iostream>
CardOne::CardOne()
{
	cardNumber = 1; // default constructor used in OpenGridAction
}
CardOne::CardOne(const CellPosition & pos,int wallet) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
	walletAmount=wallet;
}

CardOne::~CardOne(void)
{
}
int CardOne::getwalletamount()
{
	return walletAmount;
}
void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	int amount;
	//This loop doesn't exit until he enters valid input
	do 
	{
		pOut->PrintMessage("New CardOne: Enter its wallet amount ...");
		amount = pIn->GetInteger(pOut);
		if (amount > 0)
			walletAmount = amount;
		else
		{
			pOut->PrintMessage("Invalid Wallet Amount, Click to try again ...");
			pIn->GetCellClicked();
		}
	} while (amount <= 0);


	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
	pOut->ClearStatusBar();
	// 3- Clear the status bar

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->DeductWallet(walletAmount);
}

//CardOne Save
void CardOne::Save(ofstream &OutFile,object_type type)
{
	if(type==cards)
	{  
		if(OutFile.is_open())
		{
			OutFile<<1<<" "<<position.GetCellNum()<<" "<<walletAmount<<endl;
		}
	}
	else
	return;
}   

//CardOne Load
GameObject* CardOne::Load(ifstream &Infile,object_type type) 
{
	int cell_num,wallet_amount;
	Infile>>cell_num>>wallet_amount;
	position=CellPosition(cell_num);
	walletAmount=wallet_amount;
	return this;
}	