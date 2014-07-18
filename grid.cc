#include "grid.h"
#include "seeddrop.h" 
#include "genepack.h"
#include <iostream>


grid *grid::instance = 0;

grid *grid::getInstance (int x, int y) {
	
	if (!instance) {
		instance = new grid(x, y);
	}
	return instance;
	
}
grid::grid (int width, int height) : width(width), height(height), numPlants(0), totalLife(0), totalNum(0), totalSpread(0), totalChance(0) {
	
	this->tiles = new tile**[width];
	this->plants = new plant**[width];
	
	for(int i = 0; i < width; ++i) {
		
		this->tiles[i] = new tile*[height];
		this->plants[i] = new plant*[height];
		
		for(int j = 0; j < height; j++) {
			
			this->tiles[i][j] = new tile();
			this->plants[i][j] = NULL;
			
		}
	}
}

grid::~grid () {
	
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			delete this->tiles[i][j];
			this->tiles[i][j] = NULL;
			delete this->plants[i][j];
			this->plants[i][j] = NULL;
			
		}
		
		delete [] this->tiles[i];
		this->tiles[i] = NULL;
		delete [] this->plants[i];
		this->plants[i] = NULL;
		
	}
	
	delete [] this->tiles;
	this->tiles = NULL;
	delete [] this->plants;
	this->plants = NULL;
	
}

void grid::addPlant (genePack *gp, int x, int y) {
	
	if(x >= 0 && y >= 0 && x < width && y < height && !plants[x][y]) {
		plants[x][y] = new plant(gp->mutate());
		totalLife += plants[x][y]->getGenePack()->getLifeTime();
		totalNum += plants[x][y]->getGenePack()->getNumSeeds();
		totalSpread += plants[x][y]->getGenePack()->getSeedSpread();
		totalChance += plants[x][y]->getGenePack()->getGermChance();
		tiles[x][y]->toggleOccupied();
		this->numPlants++;
	}
	
}

void grid::removePlant (int x, int y) {
	
	totalLife -= plants[x][y]->getGenePack()->getLifeTime();
	totalNum -= plants[x][y]->getGenePack()->getNumSeeds();
	totalSpread -= plants[x][y]->getGenePack()->getSeedSpread();
	totalChance -= plants[x][y]->getGenePack()->getGermChance();
	delete plants[x][y];
	plants[x][y] = NULL;
	tiles[x][y]->toggleOccupied();
	this->numPlants--;
	
}

void grid::tick (){
	
	for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j] && !plants[i][j]->isJustCreated() && plants[i][j]->incrementAge() >= plants[i][j]->getGenePack()->getLifeTime()) {
				seedDrop **seeds = plants[i][j]->spewSeeds();
				bool sameSpace = false;
				genePack *gp = new genePack(plants[i][j]->getGenePack()->getLifeTime(),plants[i][j]->getGenePack()->getNumSeeds(),plants[i][j]->getGenePack()->getSeedSpread(),plants[i][j]->getGenePack()->getGermChance());
				for(int k = 0; k < gp->getNumSeeds(); k++) {
					if(seeds[k]){
						if(seeds[k]->getX() == 0 && seeds[k]->getY() == 0) {sameSpace = true;}
						this->addPlant(gp, i + seeds[k]->getX(), j + seeds[k]->getY());
					}
					delete seeds[k];
				}
				delete [] seeds;
				this->removePlant(i, j);
				if(sameSpace)this->addPlant(gp,i,j);
				delete gp;
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
	
	/*for(int i = 0; i < width; ++i) {
		for(int j = 0; j < height; j++) {
			if(plants[i][j]) {
				std::cout << "--------------------------------------------------------------" << std::endl;
				plants[i][j]->printPlant();
			}
		}
	}*/
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
	std::cout << "Number of plants: " << numPlants << std::endl;
	std::cout << "Average life time: " << (float)totalLife / (float)numPlants << std::endl;
	std::cout << "Average number of seeds: " << (float)totalNum / (float)numPlants << std::endl;
	std::cout << "Average spread distance: " << (float)totalSpread / (float)numPlants << std::endl;
	std::cout << "Average germination chance: " << (float)totalChance / (float)numPlants << std::endl;
	
}
