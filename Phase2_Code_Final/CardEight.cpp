#include "CardEight.h"
#include"Card.h"
#include "fstream"
CardEight::CardEight()
{
	cardNumber = 8; // default constructor used in OpenGridAction
}
CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
	amount_of_coins = 0;
}

CardEight::~CardEight(void)
{

}
void CardEight::ReadCardParameters(Grid* pGrid)
{
	pGrid->GetOutput()->PrintMessage("New CardEight: Enter amount of coins to get out of prison");
	amount_of_coins = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	(pGrid->GetOutput())->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	//• When a player stops at a Card8 cell, the player should choose either to pay specific
	//	amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
	//	• Input data in design mode :
	//i.The amount of coins needed to go out of the prison
	// i made a function that sets the turncount of player

	Card::Apply(pGrid, pPlayer);
	pGrid->GetOutput()->PrintMessage("New CardEight: Enter 1 to stay in prison or enter 0 to pay fees  ");
	int x= pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();
	
	if (pPlayer->GetWallet()>=amount_of_coins && x==0 )
	{
		pGrid->GetOutput()->PrintMessage("you are free now...");
		pPlayer->DeductWallet(amount_of_coins);
	}
	else if (pPlayer->GetWallet() < amount_of_coins && x == 0)
	{
		pGrid->PrintErrorMessage("Not enough money, you are in prison now... ");
		pPlayer->SetPrisonCount(3);
	}
	else
	{
		pGrid->PrintErrorMessage("Choose to stay, you are in prison now... ");
		pPlayer->SetPrisonCount(3);
	}
	//make the player choose to pay or stay in prison

}

int CardEight::GetAmountOfCoins()
{
	return amount_of_coins;
}

void CardEight::SetAmountOfCoins(int money)
{
	amount_of_coins = money;
}
//CardEight Save
void CardEight::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{
		OutFile<<cardNumber<<" "<<position.GetCellNum()<<" "<<amount_of_coins<<endl;
	}
	else return;
}

//CardEight Load
GameObject* CardEight::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	Infile>>amount_of_coins;
	return this;
}