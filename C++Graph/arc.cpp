#include "headers/arc.h"
#include <vector>
#include <string>

using namespace std;

Arc::Arc() {

}

Arc::Arc(string head, double d) {
    head = head;
    weight = d;
}


Arc Arc::copy() {
    Arc a;
    a.setHead(getHead());
    a.setWeight(getWeight());
    return a;
}

string Arc::getHead() {
    return head;
}

void Arc::setHead(string name) {
    head = name;
}

double Arc::getWeight() {
    return weight;
}

void Arc::setWeight(double w) {
    weight = w;
}
