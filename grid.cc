#include "grid.h"

grid *grid::instance = 0;

grid *grid::getInstance(int x, int y) {
	
	if(!instance) {
		instance = new grid(x, y);
	}
	return instance;
	
}

grid::grid(int width, int height) : width(width), height(height), canop(new canopy(width, height, NULL)), numPlants(0), totalLife(0.0), totalNum(0.0), totalSpread(0.0), totalChance(0.0), totalHeight(0.0), totalWidth(0) {
	
	this->plants = new plant**[width];
	
	for(int i = 0; i < width; ++i) {
		
		this->plants[i] = new plant*[height];
		
		for(int j = 0; j < height; j++) {
			
			this->plants[i][j] = NULL;
			
		}
	}
	
}

grid::~grid() {
	
	delete canop;
	
	for(int i = 0; i < width; ++i) {
		
		for(int j = 0; j < height; j++) {
			
			delete this->plants[i][j];
			this->plants[i][j] = NULL;
			
		}
		
		delete [] this->plants[i];
		this->plants[i] = NULL;
		
	}
	
	delete [] this->plants;
	this->plants = NULL;
	
	
}

void grid::addPlant(genePack const *gp, int ID, int x, int y) {
	
	if(x >= 0 && y >= 0 && x < width && y < height && !plants[x][y]) {
		
		plants[x][y] = new plant(gp->mutate(), ID);
		
		totalLife += plants[x][y]->getGenePack()->getLifeTime();
		totalNum += plants[x][y]->getGenePack()->getNumSeeds();
		totalSpread += plants[x][y]->getGenePack()->getSeedSpread();
		totalChance += plants[x][y]->getGenePack()->getGermChance();
		totalHeight += plants[x][y]->getGenePack()->getHeight();
		totalWidth += plants[x][y]->getGenePack()->getWidth();
		
		this->numPlants++;
		
		canop->insert(plants[x][y],x,y);
		
	}
	
}

void grid::removePlant(int x, int y) {
	
	totalLife -= plants[x][y]->getGenePack()->getLifeTime();
	totalNum -= plants[x][y]->getGenePack()->getNumSeeds();
	totalSpread -= plants[x][y]->getGenePack()->getSeedSpread();
	totalChance -= plants[x][y]->getGenePack()->getGermChance();
	totalHeight -= plants[x][y]->getGenePack()->getHeight();
	totalWidth -= plants[x][y]->getGenePack()->getWidth();

	canop->remove(x, y);
	delete plants[x][y];
	plants[x][y] = NULL;
	this->numPlants--;
	
}

void grid::tick() {
	
	for(int i = 0; i < width; ++i) {
		
		for(int j = 0; j < height; j++) {
			
			if(plants[i][j] && !plants[i][j]->isJustCreated() && plants[i][j]->incrementAge() >= (int)plants[i][j]->getGenePack()->getLifeTime()) {
				
				vector **seeds = plants[i][j]->spewSeeds();
				genePack *gp = new genePack(plants[i][j]->getGenePack()->getLifeTime(),plants[i][j]->getGenePack()->getNumSeeds(),plants[i][j]->getGenePack()->getSeedSpread(),plants[i][j]->getGenePack()->getGermChance(),plants[i][j]->getGenePack()->getHeight(),plants[i][j]->getGenePack()->getWidth());
				int ID = plants[i][j]->getID();
				bool sameSpace = false;
				
				for(int k = 0; k < (int)gp->getNumSeeds(); k++) {
					
					if(seeds[k]){
						
						if(seeds[k]->getX() == 0 && seeds[k]->getY() == 0) {sameSpace = true;}
						else this->addPlant(gp, ID, i + seeds[k]->getX(), j + seeds[k]->getY());
						
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
	
	canop->update();
	
}

void grid::listPlants(bool individuals, bool wholeGrid, bool averageStats) const {
	
	if(individuals) {
	
		for(int i = 0; i < width; ++i) {
			
			for(int j = 0; j < height; j++) {
				
				if(plants[i][j]) {
					
					std::cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl;
					std::cout << "x: " << i << " | y: " << j;
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
		std::cout << "Average height: " << totalHeight / numPlants << std::endl;
		std::cout << "Average width: " << totalWidth / numPlants << std::endl;
		
	}
	
}

void grid::printCSV() const {
	std::cout << numPlants << "," << totalLife / numPlants << "," << totalNum / numPlants << "," << totalSpread / numPlants << "," << totalChance / numPlants << "," << totalHeight / numPlants << "," << totalWidth / numPlants << "," << std::endl;
}
