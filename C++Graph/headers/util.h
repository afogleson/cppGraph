#ifndef UTIL_H_
#define UTIL_H_

#include "graph.h"

class Util {

	protected:
		Graph graph;

	public:
		Util();
		Util(const Graph &);
		void setGraph(Graph);
		Graph getGraph();
		void undirected();
		Node find(string);
		Graph reverseGraph();
		Graph getPath(string s, string f);
		long indexOf(string);
		Graph prune(string);
		vector<vector<int> > getAdjacentMatrix();
		vector<vector<int> > getNumPathNLong(int);
		vector<float> getEigenVectorCentrality();
		Graph prim();
		Graph dijkstra(string, string);
		Graph nodeNeighbourHood(string);
		void save(string);
		Graph open(string);
		Graph importGraph(string);
};
#endif /* UTIL_H_ */
