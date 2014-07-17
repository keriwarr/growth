#ifndef __grid_H__
#define __grid_H__
#include "tile.h"
#include "plant.h"

class grid {
	
		// 2D array of pointers to tile objects
		tile ***tiles;
		
		// 2D array of pointers to plant objects
		plant ***plants;
		
		int width, height, numPlants;	
		
	public:	
	
		// This class is implemented using a singleton design pattern
		// instance is a pointer to the grid which will be used
		static grid *instance;
		
		// prevents more than one grid from ever being created; either
		// returns instance or creates a new grid object
		static grid *getInstance(int x, int y);
		
		// initializes the grid
		grid (int width = 0, int height = 0);
		
		// destructs the grid as well as the arrays of pointers
		~grid();
		
		// creates a plant object with the given characteristics, at the
		// given location, and occupies the corresponding tile
		void addPlant (int lifeTime, int numSeeds, int seedSpread, int germChance, int x, int y);
		
		// deletes a plant object at the given location and de-occupies
		// the tile
		void removePlant (int x, int y);
		
		// increases the age of all plants on the board, removes plants 
		// which have lasted for their full duration and creates new 
		// plants
		void tick ();
		
		// prints out each plant currently on the grid and as well as a 
		// simple graphical representation of the grid
		void listPlants ();		
	
};

#endif
