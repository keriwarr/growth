#ifndef __PLANT_H__
#define __PLANT_H__
#include "seeddrop.h"
#include "genepack.h"
#include "randmath.h"
#include <iostream>


class plant {
		
		// containa all of the information which makes this plant unique
		// life durations, number of seeds produced, how far the seeds 
		// spread, chance for a seed to germinate
		genePack *gp;
		
		// the current age of the plant
		int age;
		
		// used to prevent plants from being aged on the tick that they
		// are created
		bool justCreated;
		
		// an ID which is unique to a plants genetic tree
		int ID;
		
	public:
	
		// defaults age to 0 and justCreated to true
		plant(genePack *gp, int ID);
		
		// destructor
		~plant();
		
		// increases age by 1 and returns the resulting age
		int incrementAge();
		
		// returns gp
		genePack *getGenePack();
		
		//	returns age
		int getAge();	
		
		// returns ID
		int getID();
		
		// returns justCreated
		bool isJustCreated();
		
		// sets justCreated to false
		void notJustCreated();
		
		// prints a description of the current state of the plant
		void printPlant ();
		
		// generates an array of seedDrops with each one corresponding 
		// to a seed from this plant which germinates at the given x & y
		//
		// as crowdedness approaches the germination chance, the odds of
		// a seed germinating approaches zero
		//
		// Note!! caller must delete the returned array
		seedDrop **spewSeeds(float crowdedness);
		
};

#endif
