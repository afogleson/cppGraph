#include "headers/util.h"
#include "headers/graph.h"
#include "headers/dijkstra.h"

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

long Util::indexOf(string name) {
	for (unsigned int i = 0; i < graph.getNodeMap().size(); i++) {
		if (graph.getNodeMap().at(i).getName().compare(name) == 0) {
			return i;
		}
	}
	return -1;
}

vector<vector<int> > Util::getAdjacentMatrix() {
	vector<vector<int> > array;
	for(unsigned int i = 0; i<graph.getNodeMap().size();i++) {
		vector<int> row;
		row.assign(graph.getNodeMap().size(), 0);
		array.push_back(row);
	}
	Node Current;
	for(unsigned int i = 0; i<graph.getNodeMap().size();i++){
		Current = graph.getNodeMap().at(i);
		vector<int> row = array.at(i);
		for(unsigned int j = 0; j<Current.getAdjacent().size();j++){
			int k = indexOf(Current.getAdjacent().at(j).getHead());
			row[k] = 1;
		}
		array[i] = row;
	}
	return array;
}

Graph Util::prune(string start) {
	Graph k;
	vector<string> nodes;
	Node Current;
	nodes.push_back(start);
	Node newNode;
	while (nodes.size() >= 1) {
		Current = find(nodes.at(0));
		k.addNode(Current.getName());
		for (unsigned int i = 0; i < Current.getAdjacent().size(); i++) {
			k.addNode(Current.getAdjacent().at(i).getHead());
			nodes.push_back(Current.getAdjacent().at(i).getHead());
			if (find(Current.getAdjacent().at(i).getHead()).equals(newNode)) {
				nodes.push_back(Current.getAdjacent().at(i).getHead());
			}
			k.addArc(Current.getName(), Current.getAdjacent().at(i).getHead(), Current.getAdjacent().at(i).getWeight());
		}
		nodes.erase(nodes.begin());
	}
	return k;
}

vector<vector<int> > Util::getNumPathNLong(int) {
	vector<vector<int> > path;

 	return path;
}

vector<float> Util::getEigenVectorCentrality() {
	vector<float> evc;
	return evc;
}

Graph Util::prim() {
	Graph g;
	return g;
}

Graph Util::dijkstra(string start, string end) {
	Dijkstra d;
	d.setGraph(graph);
	Graph g = d.run(start);
	Util util;
	util.setGraph(g);
	g = util.reverseGraph();
	util.setGraph(g);
	return util.getPath(start, end);
}

Graph Util::nodeNeighbourHood(string start) {
	Graph g;
	Node n = find(start);
	g.addNode(n);
	for (unsigned int i = 0; i < n.getAdjacent().size(); i++) {
		g.addArc(n.getName(), n.getAdjacent().at(i).getHead(), n.getAdjacent().at(i).getWeight(), true);
	}
	return g;
}

void  Util::save(string filename) {

}

Graph Util::open(string filename) {
	Graph g;
	return g;
}

Graph Util::importGraph(string filename) {
	Graph g;
	return g;
}

