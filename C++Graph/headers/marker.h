#ifndef MARKER_H_
#define MARKER_H_
#include <string>

using namespace std;


class Marker {
	protected:
		string label;
		string tail;
		double value;
		int order;
		bool permanent;

	public:
		Marker();
		Marker(string);
		string getLabel();
		void setLabel(string);
		string getTail();
		void setTail(string);
		double getValue();
		void setValue(double);
		int getOrder();
		void setOrder(int);
		bool isPermament();
		void setPermament(bool);
};

#endif /* MARKER_H_ */
