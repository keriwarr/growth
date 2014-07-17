#include "plant.h"
#include <iostream>


plant::plant (int lifeTime, int numSeeds, int seedSpread, int germChance) : lifeTime(lifeTime), numSeeds(numSeeds), seedSpread(seedSpread), germChance(germChance) {
	this->age = 0;
	this->justCreated = true;
}

int plant::incrementAge () {
	return ++this->age;
}

int plant::getLifeTime () {return this->lifeTime;}

int plant::getNumSeeds () {return this->numSeeds;}

int plant::getSeedSpread () {return this->seedSpread;}

int plant::getGermChance () {return this->germChance;}	

int plant::getAge () {return this->age;}

bool plant::isJustCreated () {return this->justCreated;}

void plant::notJustCreated () {this->justCreated = false;}

void plant::printPlant () {
	std::cout << "lifeTime: " << this->lifeTime << " | numSeeds: " << this->numSeeds << " | seedSpread: " << this->seedSpread << " | germChance: " << this->germChance << " | age: " << this->age << std::endl;
}
