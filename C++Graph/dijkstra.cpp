/*
 * dijkstra.cpp
 *
 *  Created on: May 10, 2009
 *      Author: afogleson
 */
#import "headers/dijkstra.h"
#import "headers/graph.h"
#import "headers/marker.h"

#define MAX_VALUE 1.7976931348623158e+308

void Dijkstra::setGraph(Graph g) {
	graph = g;
}

Graph Dijkstra::run(string start){
	Graph g;
	Marker Current = find(start);
	Current.setOrder(0);
	Current.setValue(0);
	Current.setPermanent(true);
	g.addNode(Current.getLabel());

	for(unsigned int n=1; n<markers.size()+1; n++){
		tempMarker(graph.getNode(Current.getLabel()),Current.getValue());
		Current = ExtractMin();
		Current.setOrder(n);
		Current.setPermanent(true);
	}

	Marker m;
	for(unsigned int j = 0; j<markers.size(); j++){
		m = markers.at(j);
		if(m.getTail().empty() == true){
			g.addArc(markers.at(j).getTail(), markers.at(j).getLabel(), 1, true);
		}
		else {
			g.addNode(m.getLabel());
		}
	}
	return g;
}

vector<Marker> Dijkstra::getMarkers() {
	return markers;
}

void Dijkstra::setupMarker() {
	for(unsigned int i = 0; i<graph.getNodeMap().size(); i++){
		Marker m(graph.getNodeMap().at(i).getName());
		markers.push_back(m);
	}

}

void Dijkstra::tempMarker(Node n, double d) {
	vector<Arc> c = n.getAdjacent();
	Arc CurrentArc;
	Marker CurrentMarker;
	for(unsigned int i = 0; i<c.size();i++){
		CurrentArc = c.at(i);
		CurrentMarker = find(CurrentArc.getHead());
		if(CurrentMarker.getValue() > d + CurrentArc.getWeight()){
			CurrentMarker.setTail(n.getName());
			CurrentMarker.setValue(d + CurrentArc.getWeight());
		}
	}

}

Marker Dijkstra::ExtractMin() {
	double minsofar;
	minsofar = MAX_VALUE;
	Marker focus;
	string name("");
	vector<Marker> list;

	for(unsigned int u=0; u<markers.size(); u++){
		list.push_back(markers.at(u));
	}

	for(unsigned int i=0; i<=list.size() -1; i++) {
		focus = list.at(i);
		double focus_weight = focus.getValue();
		if(focus_weight<minsofar && focus.isPermanent() != true) {
			minsofar = focus_weight;
			name = focus.getLabel();
		}
	}
	return find(name);
}

Marker Dijkstra::find(string c) {
	Marker m;
	for(unsigned int i = 0 ; i<markers.size();i++){
		if(markers.at(i).getLabel().compare(c) == 0){
			return markers.at(i);
		}
	}
	return m;
}
