#pragma once

#include <memory>
#include <map>
#include <assert.h>

template <typename Resource, typename Identifier> class ResourceHolder
{
public:
	void Load(Identifier id, const std::string& filename);

	const Resource& Get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

template <typename Resource, typename Identifier> void ResourceHolder<Resource, Identifier>
	::Load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();

	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	resourceMap.insert(std::make_pair(id, std::move(resource)));
};


template <typename Resource, typename Identifier> const Resource& ResourceHolder<Resource, Identifier>
	::Get(Identifier id) const
{
	auto founded = resourceMap.find(id);
	assert(founded != resourceMap.end());

	return *founded->second;
};

using TexturesHolder = ResourceHolder<sf::Texture, std::string>;