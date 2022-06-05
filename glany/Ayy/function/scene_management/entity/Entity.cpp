#include "Entity.h"

NS_AYY_BEGIN

Entity::Entity(EntityID entityId)
	:_entityId(entityId)
{

}

Entity::~Entity()
{
	for (auto it : _componentMap)
	{
		BaseComponent* comp = it.second;
		SAFE_DEL(comp);
	}
}

NS_AYY_END
