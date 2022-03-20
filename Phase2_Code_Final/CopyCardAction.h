#pragma once
#include "Card.h"
#include "Action.h"

class CopyCardAction : public Action
{CellPosition source_cell;
public:
	CopyCardAction(ApplicationManager *pApp);
	~CopyCardAction(void);
	void ReadActionParameters();
	void Execute();
};

