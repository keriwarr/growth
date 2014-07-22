#include "plant.h"

plant::plant(genePack *gp, int ID) : gp(gp), ID(ID) {
	
	this->age = 0;
	this->justCreated = true;
	
}

plant::~plant() {delete gp;}

int plant::incrementAge() {
	
	return ++this->age;
	
}

genePack *plant::getGenePack() {return this->gp;}

int plant::getAge() {return this->age;}

int plant::getID() {return this->ID;}

bool plant::isJustCreated() {return this->justCreated;}

void plant::notJustCreated() {this->justCreated = false;}

void plant::printPlant() {
	
	std::cout << "lifeTime: " << this->gp->getLifeTime() << " | numSeeds: " << this->gp->getNumSeeds() << " | seedSpread: " << this->gp->getSeedSpread() << " | germChance: " << this->gp->getGermChance() << " | age: " << this->age << std::endl;
	
}

vector **plant::spewSeeds(float crowdedness) {
		
	vector **seeds = new vector*[(int)this->gp->getNumSeeds()];
	
	for(int i = 0; i < (int)this->gp->getNumSeeds(); ++i) {
		
		if(randMath::getRand(0,100) > (this->gp->getGermChance() - crowdedness)) {
						
			seeds[i] = NULL;
			
		} else {
			
			seeds[i] = randMath::getDrop(this->gp->getSeedSpread());
			
		}
	}
	
	return seeds;
	
}
