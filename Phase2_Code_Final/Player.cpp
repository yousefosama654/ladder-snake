#include "Player.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum) 
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Needed initialization or validations
	PlayerStations=new Card*[3];
	current_stations_number=0;
	PrisonCount = 0;

	//Bonus initializations
	FireCount=0;
	PoisonCount=0;
	
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{   // Make any needed validations
	if (wallet < 0)
	{
		return;
	}
	this->wallet = wallet;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int turn)
{
	if (turn >= 0 && turn <= 3)
		turnCount = turn;
}

int Player::GetPlayerNum()
{
	return playerNum;
}

void Player::SetPrisonCount(int prisoncount)
{
	PrisonCount = prisoncount;
}

int Player::GetPrisonCount()
{
	return PrisonCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	
		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		turnCount++;
		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		if (FireCount > 0 )
		{
			this->DeductWallet(20);
			FireCount--;
		}
		if (PoisonCount > 0)
		{
			diceNumber--;
			PoisonCount--;
		}

		if (PrisonCount == 0 )
		{
		if (turnCount == 4)
		{
			turnCount = 0;
			pOut->PrintMessage("Enter 1 to recharge wallet else you'll launch a special attack");
			int choice;
			choice = pIn->GetInteger(pOut);
			if (choice == 1)
			{   
				int CurrentNumber;
				wallet = wallet + diceNumber * 10;
				CurrentNumber = pGrid->getCurrentPlayerNumber();
				pGrid->PrintErrorMessage("P" + to_string(CurrentNumber) + " won't play this turn and " + to_string(diceNumber * 10) + " is added to his wallet, Click to Continue ...");
				return;
			}
			pOut->PrintMessage("Enter:  1->Ice, 2->Fire, 3->Poison, 4->Lightning");
			choice = pIn->GetInteger(pOut);
			switch (choice)
			{
			case 1:
				if (SpecialAttack.GetIce() == 0 && SpecialAttack.GetUniqueSpecialAttackCount() < 2)
				{   SpecialAttack.IncrementIce();
				    SpecialAttack.IncrementUniqueSpecialAttackCount();
					//Choose a player to prevent from rolling the next turn [easier]
					int choose;
					pOut->PrintMessage("Choose a player to prevent from rolling the next turn , Enter an integer to Continue ...");
					choose = pIn->GetInteger(pOut);
					Player* P1 = pGrid->GetPlayer(choose);
					if (P1 != NULL && P1 != this)
					{
						P1->SetPrisonCount(1);
						pOut->PrintMessage("He won't play next turn, Click to Continue ...");
						pIn->GetCellClicked();
					}
					else
					{
						pOut->PrintMessage("Invalid Input, Click to Continue ...");
						pIn->GetCellClicked();
					}
					
				}
				else 
				{
					pOut->PrintMessage("You are either out of Ice or UniqueSpecialAttacks, Click to Continue ...");
					pIn->GetCellClicked();
				}
				break;
			case 2: if (SpecialAttack.GetFire() == 0 && SpecialAttack.GetUniqueSpecialAttackCount() < 2)
			{       SpecialAttack.IncrementFire();
				    SpecialAttack.IncrementUniqueSpecialAttackCount();
				//Choose a player to burn. Deduct 20 coins from his wallet for his next 3 turns (total 60 coins) [hardest]
				int choose2;
				pOut->PrintMessage("Choose a player to burn, Enter an integer to Continue ...");
				choose2 = pIn->GetInteger(pOut);
				Player* P2 = pGrid->GetPlayer(choose2);
				if (P2 != NULL && P2 != this)
				{
					P2->FireCount = 3 ;
					pOut->PrintMessage("He will be deducted 20 coins the next 3 turns, Click to Continue ...");
					pIn->GetCellClicked();
				}
				else
				{
					pOut->PrintMessage("Invalid Input, Click to Continue ...");
					pIn->GetCellClicked();
				}
				
				
				pIn->GetCellClicked();
			}
			else
			{
				pOut->PrintMessage("You are either out of Fire or UniqueSpecialAttacks, Click to Continue ...");
				pIn->GetCellClicked();
			}
				  break;
			case 3: if (SpecialAttack.GetPoison() == 0 && SpecialAttack.GetUniqueSpecialAttackCount() < 2)
			{   
				//Increment Poison and UniqueSpecialAttack counters
				SpecialAttack.IncrementPoison();
				SpecialAttack.IncrementUniqueSpecialAttackCount();
				//Choose a player to poison. For 5 turns, deduct 1 number from his dice roll. [hardest]
				int choose3;
				pOut->PrintMessage("Choose a player to poison, Enter an integer to Continue ...");
				choose3 = pIn->GetInteger(pOut);
				Player* P3 = pGrid->GetPlayer(choose3);
				if (P3 != NULL && P3 != this)
				{
					P3->PoisonCount = 5;
					pOut->PrintMessage("Next 5 turn deducted 1 number from dice roll, Click to Continue ...");
					pIn->GetCellClicked();
				}
				else
				{
					pOut->PrintMessage("Invalid Input, Click to Continue ...");
					pIn->GetCellClicked();
				}

				
				pIn->GetCellClicked();
			}
			else
			{
				pOut->PrintMessage("You are either out of Poison or UniqueSpecialAttacks, Click to Continue ...");
				pIn->GetCellClicked();
			}
				  break;
			case 4:
				if (SpecialAttack.GetLightning() == 0 && SpecialAttack.GetUniqueSpecialAttackCount() < 2)
				{   
					//Increment Lightning and UniqueSpecialAttack counters
					SpecialAttack.IncrementLightning();
				    SpecialAttack.IncrementUniqueSpecialAttackCount();
					//Deduct 20 coins from all other players 
					SpecialAttack.LightningAttack(pGrid, 20);
					pOut->PrintMessage("20 coins will be deducted from all other players, Click to Continue ...");
					pIn->GetCellClicked();
				}
				else
				{
					pOut->PrintMessage("You are either out of Lightning or UniqueSpecialAttacks, Click to Continue ...");
					pIn->GetCellClicked();
				}
				break;
			    default:
				pOut->PrintMessage("You Entered Wrong value, You won't play this turn, Click to Continue ...");
				pIn->GetCellClicked();
			}
			pOut->ClearStatusBar();
			return;
		}
		// 3- Set the justRolledDiceNum with the passed diceNumber
		justRolledDiceNum = diceNumber;

		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		// GetCellNumFromPosition
		CellPosition  pos(pCell->GetCellPosition());
		if (pCell->GetCellPosition().GetCellNum() + diceNumber == 100)
		{
			pGrid->UpdatePlayerCell(this, 99);
			//Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
			pGrid->SetEndGame(true);
			//pGrid->PrintErrorMessage("you are the winner,Click To Start a New Game.....");
		}
		else if (pCell->GetCellPosition().GetCellNum() + diceNumber > 100)
		{
			//stay as it is
			pOut->PrintMessage("You will stay in the same place (rolled more than 100), Click to Continue ...");
			pIn->GetCellClicked();
		}
		else 
		{
			
			pos.AddCellNum(diceNumber);

			// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
			//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

			pGrid->UpdatePlayerCell(this, pos);
		}
		// 6- Apply() the game object of the reached cell (if any)
		
		CellPosition BeforeObj = pCell->GetCellPosition();
		GameObject* pObj = this->pCell->GetGameObject();
		if (pObj)
		{
			pObj->Apply(pGrid, this);
			while (BeforeObj.GetCellNum() != pCell->GetCellPosition().GetCellNum() && this->pCell->GetGameObject() != NULL)
			{
				pObj = this->pCell->GetGameObject();
				BeforeObj = pCell->GetCellPosition();
				pObj->Apply(pGrid, this);
			}
		}
		}
	    else
		{
			if (turnCount == 4)
			{
				turnCount = 0;
			}
			pOut->PrintMessage("You won't move this turn, Click to Continue ...");
			pIn->GetCellClicked();
			PrisonCount--;
		}
		pOut->ClearStatusBar();
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::DeductWallet(int deduction)
{  
	if (wallet>=deduction)
	{
		wallet = wallet - deduction;
	}
	else
	{
		wallet = 0;
	}
	
}

void Player::ResetPlayer(Grid * pGrid)
{

	pGrid->UpdatePlayerCell(this, 1);
	this->wallet =100;
	this->turnCount = 0;
	
	for (int i = 0; i < current_stations_number; i++)
	{
		
		switch (PlayerStations[i]->GetCardNumber())
		{
		case 9: 
			((CardNine*)PlayerStations[i])->setOwner(NULL);
			break;
		case 10: 
			((CardTen*)PlayerStations[i])->setOwner(NULL);
			break;
		case 11: 
			((CardEleven*)PlayerStations[i])->setOwner(NULL);
			break;
		}
		PlayerStations[i] = NULL;

	}
	current_stations_number = 0;
	
}

void Player::incrementWallet(int increment)
{
	wallet+=increment;
}

int Player::getjustRolledDiceNum()
{
	return justRolledDiceNum;
}

void Player::AddStation(Card * pCard )
{
    PlayerStations[current_stations_number] = pCard;
    current_stations_number++;
}

Player::~Player()
{
	delete [] PlayerStations;
}

Card* Player::get_most_expensive_station()
{
    int max=0,MaxIndex=-1;
    for (int i = 0; i < current_stations_number; i++)
    {
        switch (PlayerStations[i]->GetCardNumber())
        {

        case 9:
         {
            if (((CardNine*)PlayerStations[i])->getCardPrice() > max)
            {
                max = ((CardNine*)PlayerStations[i])->getCardPrice();
				MaxIndex = i;

            }
            break;
         }
        case 10:
        {
            if (((CardTen*)PlayerStations[i])->getCardPrice() > max)
            {
                max = ((CardTen*)PlayerStations[i])->getCardPrice();
				MaxIndex = i;
            }
            break;
        }

        case 11:
        {
            if (((CardEleven*)PlayerStations[i])->getCardPrice() > max)
            {
                max = ((CardEleven*)PlayerStations[i])->getCardPrice();
				MaxIndex = i;

            }
            break;

        }
        }
    }


    // i have the k which is the index of the most expensive station
    if(MaxIndex !=-1)
    return PlayerStations[MaxIndex];
    return NULL;
}
