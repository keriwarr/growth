#ifndef __CANOPY_H__
#define __CANOPY_H__

#include "plant.h"
#include "pnode.h"

#include <iostream>

class canopy {

		int width, height;
		
		pnode *first;
		
		int length;
		
		void insertHelper(pnode *head, plant *p, int x, int y);
		bool removeHelper(pnode *head, int x, int y);
		void updateHelper(bool **sunLight, int light, pnode *head);
		
	public:
	
		canopy(int width, int height, pnode *first);
		
		~canopy();
	
		void insert(plant *p, int x, int y);
		
		// returns true if successful
		// caller must delete plant *p elsewhere
		bool remove(int x, int y);
		
		void update();
		
		int getLength();
		
		void printCanopy();

};

#endif
