#ifndef __GENEPACK_H__
#define __GENEPACK_H__
#include "randmath.h"

class genePack {

		static int MUTATION_FACTOR;

		static int RELATIVE_LIFETIME_MUTATION_SPEED;
		static int RELATIVE_SEED_COUNT_MUTATION_SPEED;
		static int RELATIVE_SEED_SPREAD_MUTATION_SPEED;
		static int RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED;
		static int RELATIVE_HEIGHT_MUTATION_SPEED;
		static int RELATIVE_WIDTH_MUTATION_SPEED;

		// the values govern respectively:
		//		-the duration of the plants life
		//		-the number of seeds the plant will produce
		// 		-the distance which the seeds can spread
		//		-the chance that a seed will form a new plant
		//		-height
		//		-width of the plants leaf canopy.
		//		  a plant has a square canopy of area (2*(int)width+1)^2
		float lifeTime, numSeeds, seedSpread, germChance, height, width;

	public:
	
		// sets the rate at which mutations occur
		// overall affects the mutation rate of all categories
		static void setMutationFactors(int overall, int life, int seeds, int spread, int chance, int height, int width);
	
		// initializes using the given values
		genePack(float lifeTime, float numSeeds, float seedSpread, float germChance, float height, float width);
			
		// returns lifeTime
		float getLifeTime() const;
		
		// returns numSeeds
		float getNumSeeds() const;
		
		// returns seedSpread
		float getSeedSpread() const;
		
		// returns germChance
		float getGermChance() const;
		
		// returns height
		float getHeight() const;
		
		// returns width
		float getWidth() const;
	
		// returns a new genePack which much be deleted by the caller
		genePack *mutate() const;
		
};

#endif
