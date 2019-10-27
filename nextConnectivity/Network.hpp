#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

	#include "Node.hpp"

class Network
{
public:
	Network() : connections(nullptr), size(0) {}
    Network(const int networkSize);
    ~Network();

    Node& getNode(const int index) const;
    bool isValidNetwork() const;
    bool isConnected(Node &p, Node &q);
    bool connectNodes(Node &p, Node &q);

private:
    Node *connections;
    int size;

    bool isSameConnection(Node &p, Node &q);
    bool makeConnection(Node &target, Node &source);
};

#endif //ifndef _NETWORK_HPP_