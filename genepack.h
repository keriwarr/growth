#ifndef __GENEPACK_H__
#define __GENEPACK_H__

class genePack {

		// the values govern respectively:
		//		-the duration of the plants life
		//		-the number of seeds the plant will produce
		// 		-the distance which the seeds can spread
		//		-the chance that a seed will form a new plant
		int lifeTime, numSeeds, seedSpread, germChance;

	public:
	
		// initializes using the given values
		genePack (int lifeTime, int numSeeds, int seedSpread, int germChance);
			
		// returns lifeTime
		int getLifeTime ();
		
		// returns numSeeds
		int getNumSeeds ();
		
		// returns seedSpread
		int getSeedSpread ();
		
		// returns germChance
		int getGermChance ();
	
		// returns a new genePack which much be deleted by the caller
		genePack *mutate ();
		
};

#endif
