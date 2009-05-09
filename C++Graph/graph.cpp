#include "headers/graph.h"
#include "headers/graphObserver.h"

using namespace std;

Graph::Graph() {
    nuNodes = 0;
    nuArcs  = 0;
    version = 0;
}

Graph::Graph(GraphObserver go) {
    nuNodes = 0;
    nuArcs  = 0;
    version = 0;

}

int Graph::getNuArcs() {
    return nuArcs;
}

int Graph::getNuNodes() {
    return nuNodes;
}

int Graph::getVersion() {
    return version;
}

void Graph::addNode(Node n) {
    nodeMap.push_back(n);
    nuNodes++;
	version++;
}

bool Graph::removeNode(Node n) {
    string name = n.getName();
    return removeNode(name);
}

bool Graph::removeNode(string name) {
    removeRef(name);
    for(unsigned int i=0; i<nodeMap.size(); i++) {
        Node n = nodeMap.at(i);
        if(name.compare(n.getName()) == 0 ) {
            nodeMap.erase(nodeMap.begin() + i);
            nuNodes--;
            version++;
            return true;
        }
    }
    return false;
}

vector<Node> Graph::getNodes() {
    return nodeMap;
}

bool Graph::addArc(Node tail, Node head, double weight) {
    string h = head.getName();
    string t = tail.getName();
    return addArc(t, h, weight);
}

bool Graph::addArc(string tail, string head, double weight) {
    nuArcs++;
    version++;
    return false;
}

bool Graph::removeArc(Node head, Node tail) {
    string h = head.getName();
    string t = tail.getName();
    return removeArc(h, t);
}

bool Graph::removeArc(string head, string tail) {
    nuArcs--;
    version++;
    return false;
}

void Graph::removeRef(string name) {
    for(unsigned int i=0; i<nodeMap.size(); i++) {
        Node n = nodeMap.at(i);
        vector<Arc> adjacent = n.getAdjacent();
        for(unsigned int j=0; j<adjacent.size(); j++) {
            Arc arc = adjacent.at(j);
            if(arc.getHead().compare(name) == 0) {
                adjacent.erase(adjacent.begin() + j);
                nuArcs--;
            }
        }
        n.setAdjacent(adjacent);
    }
}

void Graph::resetArcs() {
    for (unsigned int i = 0; i < nodeMap.size(); i++) {
        Node n = nodeMap.at(i);
        vector<Arc> arcs = n.getAdjacent();
        arcs.clear();
        n.setAdjacent(arcs);
    }
	nuArcs = 0;
}

bool Graph::contains(string label) {
    for (unsigned int i = 0; i < nodeMap.size(); i++) {
        Node n = nodeMap.at(i);
        if (n.getName().compare(label) == 0) {
				return true;
        }
    }
    return false;
}

void Graph::setGraphObserver(GraphObserver go) {
    observer = go;
}

GraphObserver Graph::getGraphObserver() {
    return observer;
}
