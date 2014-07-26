#ifndef __CANOPY_H__
#define __CANOPY_H__
#include "plant.h"
#include "pnode.h"

// This class is used as a linked list of pnode objects, where each 
//  pnode represents a plant on the grid. The list is sorted in order of
//  plant height. This makes it much easier to determine which plants 
//  will recieve sunlight

class canopy {

		// correspond to the grid fields. Used to determine how much 
		//  sunlight can be distributed
		int width, height;
		
		// the first node in the linked list
		pnode *first;
		
		// Helper functions for the similarly named public functions
		//  below
		void insertHelper(pnode *head, plant *p, int x, int y);
		bool removeHelper(pnode *head, int x, int y);
		void updateHelper(bool **sunLight, int light, pnode *head) const;
		
	public:
	
		// constructor
		canopy(int width, int height, pnode *first);
		
		// destructor
		~canopy();
	
		// inserts a new pnode containing p,x and y such that height 
		//  order is maintained
		void insert(plant *p, int x, int y);
		
		// deletes the pnode with the corresponding x and y values
		//  returns true if successful, false otherwise
		//  caller must delete plant *p elsewhere
		bool remove(int x, int y);
		
		// re-distrbutes sunlight to the plants on the grid
		//  should be called after each game cycle 
		//  returns an int corresponding to the amount of unallocated 
		//  light on the grid
		int update() const;

};

#endif
