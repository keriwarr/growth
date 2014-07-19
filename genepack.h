#ifndef __GENEPACK_H__
#define __GENEPACK_H__
#include "randmath.h"

class genePack {

		// the values govern respectively:
		//		-the duration of the plants life
		//		-the number of seeds the plant will produce
		// 		-the distance which the seeds can spread
		//		-the chance that a seed will form a new plant
		float lifeTime, numSeeds, seedSpread, germChance;

	public:
	
		// initializes using the given values
		genePack(float lifeTime, float numSeeds, float seedSpread, float germChance);
			
		// returns lifeTime
		float getLifeTime();
		
		// returns numSeeds
		float getNumSeeds();
		
		// returns seedSpread
		float getSeedSpread();
		
		// returns germChance
		float getGermChance();
	
		// returns a new genePack which much be deleted by the caller
		genePack *mutate();
		
};

#endif
