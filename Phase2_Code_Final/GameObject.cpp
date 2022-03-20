#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}
void GameObject::setPosition(CellPosition x )
{
	position=x;
}
