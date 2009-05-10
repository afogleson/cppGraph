/*
 * dijkstra.h
 *
 *  Created on: May 10, 2009
 *      Author: afogleson
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <string>
#include <vector>
#include "graph.h"
#include "marker.h"

using namespace std;

class Dijkstra {
protected:
	Graph graph;
	vector<Marker> markers;

public:
	void setGraph(Graph);
	Graph run(string);
	vector<Marker> getMarkers();

private:
	void setupMarker();
	void tempMarker(Node, double);
	Marker ExtractMin();
	Marker find(string);
};
#endif /* DIJKSTRA_H_ */
