#include "Node.hpp"
#include <iostream>

using namespace std;

Node::~Node()
{
	delete downLink;
	downLink = nullptr;
}

Node& Node::getServer()
{
	Node *server = this;

	while(server->upLink != nullptr) server = server->upLink;

	return *server;
}

int Node::getWeight()
{
	return getServer().weight;
}

void Node::setDownLink(Node *const link)
{
	downLink = link;
}

void Node::setUpLink(Node *const link)
{
	upLink = link;
}