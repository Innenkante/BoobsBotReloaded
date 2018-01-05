#include "stdafx.h"
#include "Client.h"

Client * Client::GetClient(int id)
{
	return (Client*)(0x009FC748 + id * 0x560);
}

std::vector<Client*> Client::GetClients(int range)
{
	std::vector<Client*> clients;
	for (int i = 0; i < range; i++)
		clients.push_back((Client*)(0x009FC748 + i * 0x560));

	return clients;
}

