#pragma once
#include "Card.h"
#include "Action.h"
class PasteCardAction : public Action
{CellPosition paste_cell;
public:
	PasteCardAction(ApplicationManager *pApp);
	~PasteCardAction(void);
	void ReadActionParameters();
	void Execute();
};

