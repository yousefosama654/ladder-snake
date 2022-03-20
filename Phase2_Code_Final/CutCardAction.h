#pragma once
#include "Action.h"
class CutCardAction :public Action
{
	CellPosition cut_cell;
public:
	CutCardAction(ApplicationManager *pApp);
	~CutCardAction(void);
	
	virtual void ReadActionParameters(); 
	
	virtual void Execute();
};

