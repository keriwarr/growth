#ifndef __PNODE_H__
#define __PNODE_H__
#include "plant.h"

// a node class for a linked list data structure wrapped in the canopy
//  class

class pnode {

		// p,x and y are the relevant data representing a plant at a 
		//  certaing point in the height hierarchy of the linke list
		plant *p;
		int x, y;
		
		// pointer to the next pnode in the linked list
		pnode *next;
		
	public:
	
		// constructor
		pnode(plant *p, int x, int y, pnode* next);
		
		// returns p
		plant *getPlant();
		
		// returns x
		int getX() const;
		
		// returns y
		int getY() const;
		
		// returns next
		pnode *getNext();
		
		// sets next to ns
		void setNext(pnode *n);

};

#endif
