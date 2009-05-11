/*
 * marker.cpp
 *
 *  Created on: May 10, 2009
 *      Author: afogleson
 */
#include "headers/marker.h"

using namespace std;

Marker::Marker() {

}

Marker::Marker(string l) {
	label = l;
}

string Marker::getLabel(){
	return label;
}

void Marker::setLabel(string l) {
	label = l;
}

string Marker::getTail() {
	return tail;
}

void Marker::setTail(string t) {
	tail = t;
}

double Marker::getValue() {
	return value;
}

void Marker::setValue(double v) {
	if(!permanent) {
		value = v;
	}
}

int Marker::getOrder() {
	return order;
}

void Marker::setOrder(int o) {
	order = order;
}

bool Marker::isPermanent() {
	return permanent;
}

void Marker::setPermanent(bool p) {
	permanent = p;
}

