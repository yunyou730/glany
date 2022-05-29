#include "Entity.h"

NS_AYY_BEGIN

Entity::Entity(EntityID entityId)
	:_entityId(entityId)
{

}

Entity::~Entity()
{

}

void Entity::AddComponent(const std::string& clsName, BaseComponent* component)
{
	_componentMap.insert(std::make_pair(clsName,component));
}

NS_AYY_END
