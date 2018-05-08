#pragma once

#include <bitset>
#include <vector>
#include "UniqueId.h"
#include "Component.h"
#include "Entity.h"

class System
{
public:
	void AddEntity(Entity* entity)
	{
		if (CheckEntityMach(entity))
			AddEntityToContainer(entity);
	};

	virtual void Refresh() = 0;

protected:
	virtual bool CheckEntityMach(Entity* entity) = 0;
	virtual void AddEntityToContainer(Entity* entity) = 0;
};
