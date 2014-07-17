#include "grid.h"
#include <iostream>


grid *grid::instance = 0;

grid *grid::getInstance (int x, int y) {
	
	if (!instance) {
		instance = new grid(x, y);
	}
	return instance;
	
}
grid::grid (int width, int height) : width(width), height(height), numPlants(0) {
	
	tile ***tiles = new tile**[width];
	plant ***plants = new plant**[width];
	
	for(int i = 0; i < width; ++i) {
		
		tiles[i] = new tile*[height];
		plants[i] = new plant*[height];
		
		for(int j = 0; j < height; j++) {
			
			tiles[i][j] = new tile();
			plants[i][j] = NULL;
			
		}
	}
	
	this->tiles = tiles;
	this->plants = plants;

}

grid::~grid () {
	
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			
			delete tiles[i][j];
			tiles[i][j] = NULL;
			delete plants[i][j];
			plants[i][j] = NULL;
			
		}
		
		delete [] tiles[i];
		tiles[i] = NULL;
		delete [] plants[i];
		plants[i] = NULL;
		
	}
	
	delete [] tiles;
	tiles = NULL;
	delete [] plants;
	plants = NULL;
	
}

void grid::addPlant (int lifeTime, int numSeeds, int seedSpread, int germChance, int x, int y) {
	
	if(x >= 0 && y >= 0 && x < width && y < height && !plants[x][y]) {
		plants[x][y] = new plant(lifeTime, numSeeds, seedSpread, germChance);
		tiles[x][y]->toggleOccupied();
		numPlants++;
	}
	
}

void grid::removePlant (int x, int y) {
	
	delete plants[x][y];
	plants[x][y] = NULL;
	tiles[x][y]->toggleOccupied();
	numPlants--;
	
}

void grid::tick (){
	
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j] && !plants[i][j]->isJustCreated() && plants[i][j]->incrementAge() >= plants[i][j]->getLifeTime()) {
				this->addPlant(plants[i][j]->getLifeTime(), plants[i][j]->getNumSeeds(), plants[i][j]->getSeedSpread(), plants[i][j]->getGermChance(), i + 1, j);
				this->addPlant(plants[i][j]->getLifeTime(), plants[i][j]->getNumSeeds(), plants[i][j]->getSeedSpread(), plants[i][j]->getGermChance(), i - 1, j);
				this->addPlant(plants[i][j]->getLifeTime(), plants[i][j]->getNumSeeds(), plants[i][j]->getSeedSpread(), plants[i][j]->getGermChance(), i, j - 1);
				this->addPlant(plants[i][j]->getLifeTime(), plants[i][j]->getNumSeeds(), plants[i][j]->getSeedSpread(), plants[i][j]->getGermChance(), i, j + 1);
				this->removePlant(i, j);
			}
		}
	}
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j]) {
				plants[i][j]->notJustCreated();
			}
		}
	}
	
}

void grid::listPlants (){
	
	std::cout << "Number of plants: " << numPlants << std::endl;
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j]) {
				std::cout << "---------------------------------------" << std::endl;
				plants[i][j]->printPlant();
			}
		}
	}
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j]) {
				std::cout << plants[i][j]->getAge();
			}else {
				std::cout << "_";
			}
		}
		std::cout << std::endl;
	}
	
}
