#pragma once

#include "Action.h"

class AddSnakeAction: public Action
{
	CellPosition startPos; 
	CellPosition endPos; 

public:
	AddSnakeAction(ApplicationManager *pApp);
	virtual ~AddSnakeAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};

