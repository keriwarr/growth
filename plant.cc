#include "plant.h"
#include "seeddrop.h"
#include "randmath.h"
#include "genepack.h"
#include <iostream>


plant::plant (genePack *gp) : gp(gp) {
	this->age = 0;
	this->justCreated = true;
}

plant::~plant () {delete gp;}

int plant::incrementAge () {
	return ++this->age;
}

genePack *plant::getGenePack () {return this->gp;}

int plant::getAge () {return this->age;}

bool plant::isJustCreated () {return this->justCreated;}

void plant::notJustCreated () {this->justCreated = false;}

void plant::printPlant () {
	std::cout << "lifeTime: " << this->gp->getLifeTime() << " | numSeeds: " << this->gp->getNumSeeds() << " | seedSpread: " << this->gp->getSeedSpread() << " | germChance: " << this->gp->getGermChance() << " | age: " << this->age << std::endl;
}

seedDrop **plant::spewSeeds () {
	seedDrop **seeds = new seedDrop*[this->gp->getNumSeeds()];
	for(int i = 0; i < this->gp->getNumSeeds(); ++i) {
		if (randMath::getRand(0,100) > this->gp->getGermChance()) {
			seeds[i] = NULL;
		} else {
			seeds[i] = randMath::getDrop(this->gp->getSeedSpread());
		}
	}
	return seeds;
}
