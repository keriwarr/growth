#ifndef __PLANT_H__
#define __PLANT_H__

class plant {
		
		// the values govern respectively:
		//		-the duration of the plants life
		//		-the number of seeds the plant will produce
		// 		-the distance which the seeds can spread
		//		-the chance that a seed will form a new plant
		int lifeTime, numSeeds, seedSpread, germChance;
		
		// the current age of the plant
		int age;
		
		// used to prevent plants from being aged on the tick that they are created
		bool justCreated;
		
	public:
	
		// defaults age to 0 and justCreated to true
		plant (int lifeTime, int numSeeds, int seedSpread, int germChance);
		
		// increases age by 1 and returns the resulting age
		int incrementAge ();
		
		// returns lifeTime
		int getLifeTime ();
		
		// returns numSeeds
		int getNumSeeds ();
		
		// returns seedSpread
		int getSeedSpread ();
		
		// returns germChance
		int getGermChance ();
		
		//	returns age
		int getAge ();	
		
		// returns justCreated
		bool isJustCreated ();
		
		// sets justCreated to false
		void notJustCreated ();
		
		// prints a description of the current state of the plant
		void printPlant ();
		
};

#endif
