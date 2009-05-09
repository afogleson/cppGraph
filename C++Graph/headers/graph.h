#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <string>
#include "graphObserver.h"
#include "node.h"

using namespace std;

class Graph {

    protected:
        vector<Node> nodeMap;
        int nuNodes;
        int nuArcs;
        int version;
        GraphObserver observer;

    public:
        Graph();
        Graph(GraphObserver);
        int getNuNodes();
        int getNuArcs();
        int getVersion();
        void addNode(Node);
        bool removeNode(Node);
        bool removeNode(string);
        vector<Node> getNodes();
        bool addArc(Node , Node , double );
        bool addArc(string, string, double);
        bool removeArc(Node, Node);
        bool removeArc(string, string);
        void removeRef(string);
        void resetArcs();
        bool contains(string);
        void setGraphObserver(GraphObserver);
        GraphObserver getGraphObserver();
};

#endif // GRAPH_H_INCLUDED
