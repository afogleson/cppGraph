#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>
#include <vector>
#include "arc.h"

using namespace std;

class Node {

    protected:
        string name;
        vector<Arc> adjacent;

    public:
        string getName();
        void setName(string);
        vector<Arc> getAdjacent();
        Node copy();
        void setAdjacent(vector<Arc>);
        bool addArc(string, double);
};

#endif // NODE_H_INCLUDED
