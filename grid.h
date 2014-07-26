#ifndef __grid_H__
#define __grid_H__
#include "plant.h"
#include "genepack.h"
#include "vector.h" 
#include "canopy.h"
#include <iostream>

class grid {
		
		// 2D array of pointers to plant objects
		plant ***plants;
		
		//
		canopy *canop;
		
		int width, height, numPlants;	
		
		// sum of characteristics of all plants on the grid
		float totalLife, totalNum, totalSpread, totalChance, totalHeight, totalWidth;
		
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
		
		// creates a plant object with the given gene pack, at the
		// given location, and occupies the corresponding tile
		void addPlant (genePack const *gp, int ID, int x, int y);
		
		// deletes a plant object at the given location and de-occupies
		// the tile
		void removePlant (int x, int y);
		
		// increases the age of all plants on the board, removes plants 
		// which have lasted for their full duration and creates new 
		// plants
		void tick ();
		
		// if (individuals) prints stats for each plant on the grid
		// if (wholeGrid) prints a ASCII representation of the grid
		// if (averageStats) prints average stats of all the plants
		void listPlants (bool individuals, bool wholeGrid, bool averageStats) const;		
		
		// prints the current averages of all of the stats for all the 
		// plants currently on the grid, separated by commas
		void printCSV () const;
	
};

#endif
