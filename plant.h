#ifndef __PLANT_H__
#define __PLANT_H__
#include "vector.h"
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
	
		int light;
	
		// defaults age to 0 and justCreated to true
		plant(genePack *gp, int ID);
		
		// destructor
		~plant();
		
		// increases age by 1 and returns the resulting age
		int incrementAge();
		
		// returns gp
		genePack *getGenePack() const;
		
		//	returns age
		int getAge() const;	
		
		// returns ID
		int getID() const;
		
		// returns justCreated
		bool isJustCreated() const;
		
		// sets justCreated to false
		void notJustCreated();
		
		//
		void setLight(int l);
		
		// prints a description of the current state of the plant
		void printPlant () const;
		
		// generates an array of seedDrops with each one corresponding 
		// to a seed from this plant which germinates at the given x & y
		//
		// as crowdedness approaches the germination chance, the odds of
		// a seed germinating approaches zero
		//
		// Note!! caller must delete the returned array
		vector **spewSeeds(float crowdedness) const;
		
};

#endif
