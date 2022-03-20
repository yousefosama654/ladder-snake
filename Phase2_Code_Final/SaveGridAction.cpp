#include "SaveGridAction.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "GameObject.h"
#include "objectType.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{
}


SaveGridAction::~SaveGridAction(void)
{
}
void SaveGridAction::ReadActionParameters()
{
	Grid * pGrid=pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name you want to save the grid in it ...");
	string file_name=pIn->GetSrting(pOut);
	file_name+=".txt";
	pOut->ClearStatusBar();
	outfile.open(file_name,ios::out);
}
	
void SaveGridAction::Execute()
{
	Grid * pGrid=pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!outfile.is_open())
	{
		pOut->PrintMessage("The file name doesn't exist");
		return;
	}
	pGrid->SaveAll(outfile,ladder);
	pGrid->SaveAll(outfile,snake);
	pGrid->SaveAll(outfile,cards);
	outfile.close();

}