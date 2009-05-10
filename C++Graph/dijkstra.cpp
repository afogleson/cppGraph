/*
 * dijkstra.cpp
 *
 *  Created on: May 10, 2009
 *      Author: afogleson
 */
#import "headers/dijkstra.h"
#import "headers/graph.h"
#import "headers/marker.h"

void Dijkstra::setGraph(Graph g) {
	graph = g;
}

Graph Dijkstra::run(string s){
	Graph g;
	return g;
}

vector<Marker> Dijkstra::getMarkers() {
	return markers;
}

void Dijkstra::setupMarker() {

}

void Dijkstra::tempMarker(Node, double) {

}

Marker Dijkstra::ExtractMin() {
	Marker m;
	return m;
}

Marker Dijkstra::find(string) {
	Marker m;
	return m;
}
