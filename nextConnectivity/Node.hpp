#ifndef _NODE_HPP_
#define _NODE_HPP_

class Node
{
public:
	Node() : upLink(nullptr), downLink(nullptr), weight(1) {}
	~Node();

	Node* getDownLink() const { return downLink; }
	Node* getUpLink() const { return upLink; }
	Node& getServer();
	int getWeight();
	void setDownLink(Node *const link);
	void setUpLink(Node *const link);

private:
	Node *upLink;
	Node *downLink;
	int weight;
};

#endif	//ifndef _NODE_HPP_