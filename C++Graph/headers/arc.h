#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED
#include <string>

using namespace std;

class Arc {
    protected:
        string head;
        double weight;

    public:
        Arc();
        Arc(string, double);
        string getHead();
        double getWeight();
        void setHead(string);
        void setWeight(double);
        Arc copy();

};


#endif // ARC_H_INCLUDED
