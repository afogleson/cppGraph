#include <iostream>
#include <string>
#include <vector>
#include "headers/graph.h"
#include "headers/node.h"

using namespace std;

void printNodes(vector<Node> nodeMap);

int main()
{
    string name;
    int num;

    Graph g;

    cout << "Number of Nodes?";
    cin >> num;

    for(int i=0; i<num; i++) {
      cout << "Name of node:";
      cin >> name;
      Node n;
      n.setName(name);
      g.addNode(n);
    }

    cout << endl << "name of node to remove:";
    cin >> name;
    cout << endl << endl << "Nodes before removal..." << endl;
    printNodes(g.getNodes());
    g.removeNode(name);
    cout << endl << endl << "Nodes after removal..." << endl;
    printNodes(g.getNodes());
    system("PAUSE");
}

void printNodes(vector<Node> map) {
   for(unsigned int i=0; i<map.size(); i++) {
       Node n = map.at(i);
       cout << n.getName() << endl;
   }
}
