#ifndef __PLANT_H__
#define __PLANT_H__

class plant {
		
		int lifeTime, numSeeds, seedSpread, germChance;
		int age;
		bool justCreated;
		
	public:
	
		plant (int lifeTime, int numSeeds, int seedSpread, int germChance);
		int incrementAge ();
		int getLifeTime ();
		int getNumSeeds ();
		int getSeedSpread ();
		int getGermChance ();	
		int getAge ();	
		bool isJustCreated ();
		void notJustCreated ();
		void printPlant ();
		
};

#endif
