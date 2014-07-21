#ifndef __GENEPACK_H__
#define __GENEPACK_H__
#include "randmath.h"

class genePack {

		static int MUTATION_FACTOR;

		static int RELATIVE_LIFETIME_MUTATION_SPEED;
		static int RELATIVE_SEED_COUNT_MUTATION_SPEED;
		static int RELATIVE_SEED_SPREAD_MUTATION_SPEED;
		static int RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED;

		// the values govern respectively:
		//		-the duration of the plants life
		//		-the number of seeds the plant will produce
		// 		-the distance which the seeds can spread
		//		-the chance that a seed will form a new plant
		float lifeTime, numSeeds, seedSpread, germChance;

	public:
	
		// sets the rate at which mutations occur
		// overall affects the mutation rate of all categories
		static void setMutationFactors(int overall, int life, int seeds, int spread, int chance);
	
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
