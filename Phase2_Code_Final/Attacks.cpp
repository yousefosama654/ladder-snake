#include "Attacks.h"
#include "Player.h"
Attacks::Attacks()
	: IceCount(0) , FireCount(0) , PoisonCount(0) , LightningCount(0) , UniqueSpecialAttackCount(0)
{
}

int Attacks::GetIce()
{
	return IceCount;
}

int Attacks::GetFire()
{
	return FireCount;
}

int Attacks::GetPoison()
{
	return PoisonCount;
}

int Attacks::GetLightning()
{
	return LightningCount;
}

int Attacks::GetUniqueSpecialAttackCount()
{
	return UniqueSpecialAttackCount;
}

void Attacks::IncrementIce()
{
	if (IceCount == 0)
		IceCount++;
}

void Attacks::IncrementFire()
{
	if (FireCount == 0)
		FireCount++;
}

void Attacks::IncrementPoison()
{
	if (PoisonCount == 0)
		PoisonCount++;
}

void Attacks::IncrementLightning()
{
	if (LightningCount == 0)
		LightningCount++;
}

void Attacks::IncrementUniqueSpecialAttackCount()
{
	if (UniqueSpecialAttackCount < 2)
	{
		UniqueSpecialAttackCount++;
	}
}

void Attacks::LightningAttack(Grid* pGrid, int deduction)
{
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->DeductWallet(deduction);
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->DeductWallet(deduction);
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->DeductWallet(deduction);
	pGrid->AdvanceCurrentPlayer();
}
