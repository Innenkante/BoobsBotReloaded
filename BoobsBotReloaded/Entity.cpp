#include "stdafx.h"
#include "Entity.h"

Entity* Entity::GetEntity(int id)
{
	return (Entity*)(0x00A08630 + id * 0x000001F8);
}

std::vector<Entity*> Entity::GetEntities(int range)
{
	std::vector<Entity*> entities;
	for (int i = 0;i < 18;i++)
	{
		entities.push_back((Entity*)(0x00A08630 + i * 0x000001F8));
	}
	return entities;
}

bool Entity::IsAlive()
{
	return Alive & 0x01;
}
