#include "plant.h"

plant::plant(genePack *gp, int ID) : gp(gp), ID(ID), age(0), justCreated(true), light(0) {}

plant::~plant() {delete gp; gp = NULL;}

int plant::incrementAge() {
	
	return ++this->age;
	
}

genePack *plant::getGenePack() const {return this->gp;}

int plant::getAge() const {return this->age;}

int plant::getID() const {return this->ID;}

bool plant::isJustCreated() const {return this->justCreated;}

void plant::notJustCreated() {this->justCreated = false;}

void plant::setLight(int l) {this->light = l;}

void plant::printPlant() const {
	
	std::cout << " | lifeTime: " << this->gp->getLifeTime() << " | numSeeds: " << this->gp->getNumSeeds() << " | seedSpread: " << this->gp->getSeedSpread() << " | germChance: " << this->gp->getGermChance() << " | age: " << this->age << " | height: " << this->gp->getHeight() << " | width: " << this->gp->getWidth() << " | light: " << this->light << std::endl;
	
}

vector **plant::spewSeeds() const {
		
	vector **seeds = new vector*[(int)this->gp->getNumSeeds()];
	
	for(int i = 0; i < (int)this->gp->getNumSeeds(); ++i) {
		
		int x = ((int)this->getGenePack()->getWidth()*2)+1;
		
		if(randMath::getRand(0,100) > ((this->gp->getGermChance() * (1 + ((float)this->light / (float)(x*x)))) - 100)) {
						
			seeds[i] = NULL;
			
		} else {
			
			seeds[i] = randMath::getDrop(this->gp->getSeedSpread());
			
		}
	}
	
	return seeds;
	
}
