#pragma once

const int MAX_COMPONENTS{ 32 };

class Entity;

class Component
{
public:
	void SetParent(Entity* _parent);
	Entity& GetParent();

protected:
	Entity* parent{ nullptr };
};


enum class RenderLayers
{
	BACK = 1,
	MIDDLE = 2,
	FRONT = 3
};
