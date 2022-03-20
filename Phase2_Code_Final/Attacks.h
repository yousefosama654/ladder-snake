#pragma once
#include "Grid.h"
class Player;
class Attacks
{
	int IceCount;
	int FireCount;
	int PoisonCount;
	int LightningCount;
	int UniqueSpecialAttackCount;
public:
	Attacks();
	int GetIce();
	int GetFire();
	int GetPoison();
	int GetLightning();
	int GetUniqueSpecialAttackCount();
	void IncrementIce();
	void IncrementFire();
	void IncrementPoison();
	void IncrementLightning();
	void IncrementUniqueSpecialAttackCount();
	void LightningAttack(Grid* pGrid, int deduction);
};

