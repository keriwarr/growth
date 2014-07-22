#include "grid.h"

grid *grid::instance = 0;

grid *grid::getInstance(int x, int y) {
	
	if(!instance) {
		instance = new grid(x, y);
	}
	return instance;
	
}

grid::grid(int width, int height) : width(width), height(height), numPlants(0), totalLife(0.0), totalNum(0.0), totalSpread(0.0), totalChance(0.0) {
	
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

grid::~grid() {
	
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

void grid::addPlant(genePack *gp, int ID, int x, int y) {
	
	if(x >= 0 && y >= 0 && x < width && y < height && !plants[x][y]) {
		
		plants[x][y] = new plant(gp->mutate(), ID);
		
		totalLife += plants[x][y]->getGenePack()->getLifeTime();
		totalNum += plants[x][y]->getGenePack()->getNumSeeds();
		totalSpread += plants[x][y]->getGenePack()->getSeedSpread();
		totalChance += plants[x][y]->getGenePack()->getGermChance();
		
		tiles[x][y]->toggleOccupied();
		this->numPlants++;
		
	}
	
}

void grid::removePlant(int x, int y) {
	
	totalLife -= plants[x][y]->getGenePack()->getLifeTime();
	totalNum -= plants[x][y]->getGenePack()->getNumSeeds();
	totalSpread -= plants[x][y]->getGenePack()->getSeedSpread();
	totalChance -= plants[x][y]->getGenePack()->getGermChance();
	
	delete plants[x][y];
	plants[x][y] = NULL;
	tiles[x][y]->toggleOccupied();
	this->numPlants--;
	
}

void grid::tick() {
	
	for(int i = 0; i < width; ++i) {
		
		for(int j = 0; j < height; j++) {
			
			if(plants[i][j] && !plants[i][j]->isJustCreated() && plants[i][j]->incrementAge() >= (int)plants[i][j]->getGenePack()->getLifeTime()) {
				
				float crowdedness = 0;
				
				for(int h = -2; h < 3; h++) {
					
					for(int k = -2; k < 3; k++) {
						
						if((h+i) < 0 || (h+i) >= width || (k+j) < 0 || (k+j) >= height || plants[h+i][k+j]) {
							if(h == 0 && k == 0) crowdedness += 0.0;
							else if(h >= -1 && h <= 1 && k >= -1 && k <= 1) crowdedness += 3.0;
							else crowdedness += 1.0;
						}
						
					}
					
				}
				
				crowdedness *= 5.0/2.0;
				
				vector **seeds = plants[i][j]->spewSeeds(crowdedness);
				genePack *gp = new genePack(plants[i][j]->getGenePack()->getLifeTime(),plants[i][j]->getGenePack()->getNumSeeds(),plants[i][j]->getGenePack()->getSeedSpread(),plants[i][j]->getGenePack()->getGermChance());
				int ID = plants[i][j]->getID();
				bool sameSpace = false;
				
				for(int k = 0; k < (int)gp->getNumSeeds(); k++) {
					
					if(seeds[k]){
						
						if(seeds[k]->getX() == 0 && seeds[k]->getY() == 0) {sameSpace = true;}
						this->addPlant(gp, ID, i + seeds[k]->getX(), j + seeds[k]->getY());
						
					}
					
					delete seeds[k];
				}
				
				delete [] seeds;
				this->removePlant(i, j);
				if(sameSpace)this->addPlant(gp,ID,i,j);
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

void grid::listPlants(bool individuals, bool wholeGrid, bool averageStats) {
	
	if(individuals) {
	
		for(int i = 0; i < width; ++i) {
			
			for(int j = 0; j < height; j++) {
				
				if(plants[i][j]) {
					
					std::cout << "--------------------------------------------------------------" << std::endl;
					plants[i][j]->printPlant();
					
				}
			}
		}
	}
	
	if(wholeGrid) {
	
		for(int i = 0; i < width; ++i) {
			
			for(int j = 0; j < height; j++) {
				
				if(plants[i][j]) {std::cout << plants[i][j]->getID();}
				else {std::cout << "_";}
				
			}
			
			std::cout << std::endl;
			
		}		
	}
	
	if(averageStats) {
	
		std::cout << "Number of plants: " << numPlants << std::endl;
		std::cout << "Average life time: " << totalLife / numPlants << std::endl;
		std::cout << "Average number of seeds: " << totalNum / numPlants << std::endl;
		std::cout << "Average spread distance: " << totalSpread / numPlants << std::endl;
		std::cout << "Average germination chance: " << totalChance / numPlants << std::endl;
		
	}
	
}

void grid::printCSV() {
	std::cout << totalLife / numPlants << "," << totalNum / numPlants << "," << totalSpread / numPlants << "," << totalChance / numPlants << "," << std::endl;
}
