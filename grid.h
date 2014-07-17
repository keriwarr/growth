#ifndef __grid_H__
#define __grid_H__
#include "tile.h"
#include "plant.h"

class grid {
	
		tile ***tiles;
		plant ***plants;
		int width, height, numPlants;	
		
	public:	
	
		static grid *instance;
		static grid *getInstance(int x, int y);
		grid (int width = 0, int height = 0);
		~grid();
		void addPlant (int lifeTime, int numSeeds, int seedSpread, int germChance, int x, int y);
		void removePlant (int x, int y);
		void tick ();
		
		void listPlants ();		
	
};

#endif
