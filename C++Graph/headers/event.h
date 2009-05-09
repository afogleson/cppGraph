/*
 * event.h
 *
 *  Created on: May 9, 2009
 *      Author: afogleson
 */

#ifndef EVENT_H_
#define EVENT_H_

enum Event {
	/**
		 * Indicates a Node has been added to the Graph
		 */
		Node_Added,

		/**
		 * Indicates a Node has been removed to the Graph
		 */
		Node_Removed,


		/**
		 * Indicates a Arc has been added to the Graph
		 */
		Arc_Added,

		/**
		 * Indicates a Arc has been removed to the Graph
		 */
		Arc_Removed,

		/**
		 * Removes all Arcs from the Graph
		 */
		Arc_Reset
};

#endif /* EVENT_H_ */
