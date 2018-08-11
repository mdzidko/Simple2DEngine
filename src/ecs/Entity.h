#pragma once

#include <vector>
#include <array>
#include <memory>
#include <bitset>
#include <assert.h>
#include "UniqueId.h"
#include "Component.h"

class Component;

class Entity
{
public:
	bool IsAlive();
	void Destroy();
	std::bitset<MAX_COMPONENTS> GetMask() const;

	template <typename T> bool HasComponent() const
	{
		return componentsMask[UniqueId::GetUId<T>()];
	};

	template <typename T> T& GetComponent()
	{
		assert(HasComponent<T>());

		auto ptr = componentsArray[UniqueId::GetUId<T>()];
		return *static_cast<T*>(ptr);
	}


	template<typename T, typename... TArgs> T& AddComponent(TArgs&&... args)
	{
		//assert(!HasComponent<T>());

		T* c(new T(std::forward<TArgs>(args)...));
		c->SetParent(this);

		std::unique_ptr<T> uPtr{ c };
		components.push_back(std::move(uPtr));

		componentsArray[UniqueId::GetUId<T>()] = c;
		componentsMask[UniqueId::GetUId<T>()] = true;

		return *c;
	}

	template<typename T> void RemoveComponent()
	{
		//assert(HasComponent<T>());

		delete(componentsArray[UniqueId::GetUId<T>()]);
		componentsArray[UniqueId::GetUId<T>()] = nullptr;
		componentsMask[UniqueId::GetUId<T>()] = false;
	}

private:
	bool alive{ true };
	std::bitset<MAX_COMPONENTS> componentsMask;
	std::vector<std::unique_ptr<Component>> components;
	std::array<Component*, MAX_COMPONENTS> componentsArray;
};

using EntityPtr = std::unique_ptr<Entity>;
