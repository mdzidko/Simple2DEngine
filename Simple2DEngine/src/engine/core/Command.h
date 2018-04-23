#pragma once

class Entity;

class Command
{
public:
	virtual void execute(Entity* entity) = 0;

	virtual ~Command() {};
};

