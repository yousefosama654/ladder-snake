#pragma once
#include "CellPosition.h"
#include "Action.h"

class DeleteGameObject : public Action
{CellPosition object_position;
public:
	DeleteGameObject(ApplicationManager *pApp);
	~DeleteGameObject(void);
	void ReadActionParameters();
	void Execute();
};

