#include "OpenGridAction.h"
#include "Ladder.h"
#include "Snake.h"
#include "Action.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}


OpenGridAction::~OpenGridAction(void)
{
}

void OpenGridAction::ReadActionParameters() 
{
	Grid * pGrid=pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the file name of the grid");
	string file_name=pIn->GetSrting(pOut);
	file_name+=".txt";
	input_file.open(file_name,ios::in);
}

void OpenGridAction::Execute() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    ReadActionParameters();
	if (!input_file.is_open())
    {
        pOut->PrintMessage("Couldn't open the file, Click to Continue ...");
        pIn->GetCellClicked();
        pOut->ClearStatusBar();
        return;
    }
	pGrid->Clear(); // to Clear the  Current Grid before loading another one
    int num_of_ladders = 0;
    input_file >> num_of_ladders;
    for (int i = 1; i <= num_of_ladders; i++)
    {
        Ladder* pladder = new Ladder(CellPosition(0), CellPosition(0));
        GameObject* pObj = pladder->Load(input_file, ladder);
        pGrid->AddObjectToCell(pObj);
    }
    int num_of_snakes = 0;
    input_file >> num_of_snakes;
    for (int i = 1; i <= num_of_snakes; i++)
    {
        Snake* pSnake = new Snake(CellPosition(0), CellPosition(0));
        GameObject* pObj = pSnake->Load(input_file, snake);
        pGrid->AddObjectToCell(pObj);
    }

    int num_of_cards = 0;
    input_file >> num_of_cards;
    for (int i = 1; i <= num_of_cards; i++)
    {
        Card* pCard;
        GameObject* pObj;
        int cardnumber = 0;
        input_file >> cardnumber;
        switch (cardnumber) {
        case 1:
            pCard = new CardOne();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 2:
            pCard = new CardTwo();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 3:
            pCard = new CardThree();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 4:
            pCard = new CardFour();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 5:
            pCard = new CardFive();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 6:
            pCard = new CardSix();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 7:
            pCard = new CardSeven();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 8:
            pCard = new CardEight();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 9:
            pCard = new CardNine();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 10:
            pCard = new CardTen();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 11:
            pCard = new CardEleven();
            pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;
        case 12:
            Card * pCard = new CardTwelve();
            GameObject* pObj = pCard->Load(input_file, cards);
            pGrid->AddObjectToCell(pObj);
            break;

        }
    }
	input_file.close();
   
}

 

 
 
 
