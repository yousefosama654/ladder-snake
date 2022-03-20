#pragma once
#include "action.h"
class InputDiceValueAction :public Action
{
	int Dice_Value;
public:
	InputDiceValueAction(ApplicationManager *pApp);
	~InputDiceValueAction(void);
	void ReadActionParameters() ;
	void Execute();
};

