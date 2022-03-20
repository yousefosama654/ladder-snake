#include"CardNine.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "fstream"
// intitializing the static data members
Player* CardNine::Owner = NULL;
int CardNine::Fees = 0;
int CardNine::CardPrice = 0;
bool CardNine::IsSaved=false;
int CardNine::counter=0;
CardNine::CardNine()
{
	cardNumber = 9; // default constructor used in OpenGridAction
	counter++;
}

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
	counter++;
}

CardNine::~CardNine(void)
{counter--;
}

int CardNine::getCardPrice()
{
	return CardPrice;
}

int CardNine::getFees()
{
	return Fees;
}

void CardNine::setOwner(Player* owner)
{
	Owner = owner;
}

void CardNine::setCardPrice(int StationPrice)
{
	CardPrice = StationPrice;
}

void CardNine::setFees(int PassingFees)
{
	Fees = PassingFees;
}

void CardNine::Reset()
{
	CardPrice = 0; 
	Fees = 0;
	Owner = NULL;
	IsSaved = false;
}

Player* CardNine::getOwner()
{
	return Owner;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the Card_Price parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardsNineToEleven: Enter its Card Price ..."
	if (Fees==0)
	{
		bool ValidStationInput=false;
		do {
			pOut->PrintMessage("Enter Station Price");
			CardPrice = pIn->GetInteger(pOut);
			
			// 4- Read an Integer from the user using the Input class and set the Fees parameter with it
			//    Don't forget to first print to a descriptive message to the user like:"New CardsNineToEleven: Enter its Fees by passing players ..."
			pOut->PrintMessage("Enter fees paid by passing players");
			Fees = pIn->GetInteger(pOut);
			if (CardPrice <= 0 || Fees <= 0)
			{
				pOut->PrintMessage("Invalid Station Input, Click to try again ...");
				pIn->GetCellClicked();
			}
			else
			{
				ValidStationInput = true;
			}
		} while (!ValidStationInput);
		// [ Note ]:
		// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
		// to be able to perform his Apply() action
	}
	
	
	// 4- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
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
				pPlayer->AddStation(this);
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
//CardNine Save
void CardNine::Save(ofstream& OutFile, object_type type)
{
	if(type==cards)
	{ OutFile<<cardNumber<<" "<<position.GetCellNum()<<" ";
		if(IsSaved==false)
		{
			IsSaved=true;
			OutFile<<CardPrice<<" "<<Fees;
			
		}
		OutFile<<endl;
	
	}
	else return;
}
//CardNine Load
GameObject* CardNine::Load(ifstream& Infile, object_type type)
{
	int cell_num;
	Infile>>cell_num;
	position=CellPosition(cell_num);
	if(Fees==0)
	{
		Infile>>CardPrice>>Fees;
	}
	
	return this;
}
int CardNine::getcounter()
{
	return counter;
}