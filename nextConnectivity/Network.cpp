#include "Network.hpp"
#include <iostream>

Network::Network(const int networkSize)
{
	connections = new Node[networkSize];
	size = networkSize;
}

Network::~Network()
{
	delete[] connections;
	connections = nullptr;
}

Node& Network::getNode(const int index) const
{
	if(index >= 0 && index < size) return connections[index];
	else {
		std::out_of_range("Node is out of network range!");
		return connections[0];
	}
}

bool Network::isValidNetwork() const
{
	if(connections) return true;
	else
	{
		std::cerr << "Not a valid network!\n";
		return false;
	}
}

bool Network::isSameConnection(Node &p, Node &q)
{
	const Node &pServer = p.getServer();
	const Node &qServer = q.getServer();

	if(pServer.getDownLink() == qServer.getDownLink())
		if(pServer.getDownLink() != nullptr) return true;
	
	return false;
}

bool Network::isConnected(Node &p, Node &q)
{
	bool result = false;

	if(isValidNetwork())
	{
		if(isSameConnection(p, q)) result = true;
	}

	return result;
}

bool Network::connectNodes(Node &p, Node &q)
{
	bool result = false;
	Node &pServer = p.getServer();
	Node &qServer = q.getServer();

	if(isValidNetwork()) {
		if(qServer.getWeight() <= pServer.getWeight()) result = makeConnection(pServer, qServer);
		else result = makeConnection(qServer, pServer);
	}

	return result;
}

bool Network::makeConnection(Node &target, Node &source)
{
	bool result = false;

	if(target.getDownLink() == nullptr) target.setDownLink(new Node);

	source.setUpLink(&target);

	result = true;

	return result;
}
