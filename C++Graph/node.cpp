#include "headers/node.h"

using namespace std;

Node::Node() {
}

Node::Node(string n) {
	name = n;
}

string Node::getName() {
    return name;
}

void Node::setName(string n) {
    name = n;
}

vector<Arc> Node::getAdjacent() {
    return adjacent;
}

void Node::setAdjacent(vector<Arc> arcs) {
    adjacent = arcs;
}

Node Node::copy() {
    Node n;
    n.setName(getName());
    n.setAdjacent(getAdjacent());
    return n;
}

bool Node::addArc(string head, double weight) {
	Arc a(head, weight);
	adjacent.push_back(a);
	return true;
}
