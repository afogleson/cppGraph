#include "headers/arc.h"
#include <vector>
#include <string>
#include <sstream>

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

string Arc::toString() {
	string s("Head: ");
	s.append(head);
	s.append(" Weight: ");
	stringstream oss;
	oss << s << weight;
	return oss.str();
}

bool Arc::equals(Arc a) {
	if(getHead().compare(a.getHead()) == 0) {
		if(getWeight() == a.getWeight()) {
			return true;
		}
	}
	return false;
}

