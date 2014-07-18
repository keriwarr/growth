#ifndef __PLANT_H__
#define __PLANT_H__
#include "seeddrop.h"
#include "genepack.h"
#include "genepack.h"


class plant {
		
		//
		genePack *gp;
		
		// the current age of the plant
		int age;
		
		// used to prevent plants from being aged on the tick that they
		// are created
		bool justCreated;
		
	public:
	
		// defaults age to 0 and justCreated to true
		plant (genePack *gp);
		
		// destructor
		~plant ();
		
		// increases age by 1 and returns the resulting age
		int incrementAge ();
		
		// returns gp
		genePack *getGenePack ();
		
		//	returns age
		int getAge ();	
		
		// returns justCreated
		bool isJustCreated ();
		
		// sets justCreated to false
		void notJustCreated ();
		
		// prints a description of the current state of the plant
		void printPlant ();
		
		// generates an array of seedDrops with each one corresponding 
		// to a seed from plant which germinates at the given x & y
		//
		// Note!! caller must delete the returned array
		seedDrop **spewSeeds ();
		
};

#endif
