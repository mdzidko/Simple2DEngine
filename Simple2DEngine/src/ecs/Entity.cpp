#include "Entity.h"

bool Entity::IsAlive()
{ 
	return alive; 
};

void Entity::Destroy()
{ 
	alive = false; 
};

std::bitset<MAX_COMPONENTS> Entity::GetMask() const
{
	return componentsMask;
}