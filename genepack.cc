#include "genepack.h"
#include "randmath.h"

genePack::genePack (int lifeTime, int numSeeds, int seedSpread, int germChance) : lifeTime(lifeTime), numSeeds(numSeeds), seedSpread(seedSpread), germChance(germChance) {}

int genePack::getLifeTime () {return this->lifeTime;}

int genePack::getNumSeeds () {return this->numSeeds;}

int genePack::getSeedSpread () {return this->seedSpread;}

int genePack::getGermChance () {return this->germChance;}

genePack *genePack::mutate () {
	int newLifeTime = this->lifeTime + randMath::getRand(-1,1);
	if(newLifeTime <= 0) newLifeTime = 1;
	int newNumSeeds = this->numSeeds + randMath::getRand(-1,1);
	if(newNumSeeds < 0) newNumSeeds = 0;
	int newSeedSpread = this->seedSpread + randMath::getRand(-1,1);
	if(newSeedSpread < 0) newSeedSpread = 0;
	int newGermChance = this->germChance + randMath::getRand(-5,5);
	if(newGermChance < 0) newGermChance = 0;
	else if(newGermChance > 100) newGermChance = 100;
	return new genePack(newLifeTime,newNumSeeds,newSeedSpread,newGermChance);
}
