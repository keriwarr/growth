#include "plant.h"
#include <iostream>

using namespace std;

plant::plant (int lifeTime, int numSeeds, int seedSpread, int germChance) : lifeTime(lifeTime), numSeeds(numSeeds), seedSpread(seedSpread), germChance(germChance) {
	this->age = 0;
	this->justCreated = true;
}
int plant::incrementAge () {
	return ++this->age;
}
int plant::getLifeTime () {return lifeTime;}
int plant::getNumSeeds () {return numSeeds;}
int plant::getSeedSpread () {return seedSpread;}
int plant::getGermChance () {return germChance;}	
int plant::getAge () {return age;}
bool plant::isJustCreated () {return justCreated;}
void plant::notJustCreated () {justCreated = false;}
void plant::printPlant () {
	cout << "ID: " << this << endl;
	cout << "lifeTime: " << this->lifeTime << " | numSeeds: " << this->numSeeds << " | seedSpread: " << this->seedSpread << " | germChance: " << this->germChance << " | age: " << this->age << endl;
}
