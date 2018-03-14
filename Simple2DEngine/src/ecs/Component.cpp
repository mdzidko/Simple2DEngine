#include "Component.h"

void Component::SetParent(Entity* _parent)
{
	parent = _parent;
}

Entity& Component::GetParent()
{
	return *parent;
}