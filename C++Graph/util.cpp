#include "headers/util.h"
#include "headers/graph.h"

Util::Util() {
}

Util::Util(const Graph &g) {
	graph = g;
}

void Util::setGraph(Graph g) {
	graph = g;
}

Graph Util::getGraph() {
	return graph;
}

void Util::undirected() {
	Graph Un;

	Node d;
	Node E;
	for (unsigned int i = 0; i < graph.getNodeMap().size(); i++) {
		Un.addNode(graph.getNodeMap().at(i));
	}

	for (unsigned int h = 0; h < graph.getNodeMap().size(); h++) {
		d = graph.getNodeMap().at(h);
		for (unsigned int l = 0; l < d.getAdjacent().size(); l++) {
			E = find(d.getAdjacent().at(l).getHead());
			Un.addArc(E.getName(), d.getName(), d.getAdjacent().at(l).getWeight());
		}
	}
	graph = Un;
}

Node Util::find(string c) {
	for (unsigned int i = 0; i < graph.getNodeMap().size(); i++) {
		if (graph.getNodeMap().at(i).getName().compare(c) == 0) {
			return graph.getNodeMap().at(i);
		}
	}
	Node node;
	return node;
}

Graph Util::reverseGraph() {

	Graph Rev;
	Node d;
	Node E;

	for (unsigned int i = 0; i < graph.getNodeMap().size(); i++) {
		Rev.addNode(graph.getNodeMap().at(i).getName());
	}

	for (unsigned int h = 0; h < graph.getNodeMap().size(); h++) {
		d = graph.getNodeMap().at(h);
		for (unsigned int l = 0; l < d.getAdjacent().size(); l++) {
			E = find(d.getAdjacent().at(l).getHead());
			Rev.addArc(E.getName(), d.getName(), d.getAdjacent().at(l).getWeight());
		}
	}
	return Rev;
}

Graph Util::getPath(string s, string f) {
	Graph path;
	Node Current = graph.getNode(f);
	Node Next;

	while ((Current.getName().compare(s) != 0)) {
		path.addNode(Current);
		Next = graph.getNode(Current.getAdjacent().at(0).getHead());
		path.addNode(Next);
		graph.addArc(Next, Current, Current.getAdjacent().at(0).getWeight());
		Current = Next;
	}
	return path;
}

int Util::indexOf(string name) {
	for (unsigned int i = 0; i < graph.getNodeMap().size(); i++) {
		if (graph.getNodeMap().at(i).getName().compare(name) == 0) {
			return i;
		}
	}
	return -1;
}
