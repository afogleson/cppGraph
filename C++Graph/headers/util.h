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
		int indexOf(string);
};
#endif /* UTIL_H_ */
