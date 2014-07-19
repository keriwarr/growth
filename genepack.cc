#include "genepack.h"

genePack::genePack(float lifeTime, float numSeeds, float seedSpread, float germChance) : lifeTime(lifeTime), numSeeds(numSeeds), seedSpread(seedSpread), germChance(germChance) {}

float genePack::getLifeTime() {return this->lifeTime;}

float genePack::getNumSeeds() {return this->numSeeds;}

float genePack::getSeedSpread() {return this->seedSpread;}

float genePack::getGermChance() {return this->germChance;}

genePack *genePack::mutate() {
	
	float newLifeTime = this->lifeTime + (float)(randMath::getRand(-50,50))/100.0;
	if(newLifeTime < 1.0) newLifeTime = 1.0;
	
	float newNumSeeds = this->numSeeds + (float)(randMath::getRand(-50,50))/100.0;
	if(newNumSeeds < 0.0) newNumSeeds = 0.0;
	
	float newSeedSpread = this->seedSpread + (float)(randMath::getRand(-50,50))/100.0;
	if(newSeedSpread < 0.0) newSeedSpread = 0.0;
	
	float newGermChance = this->germChance + (float)(randMath::getRand(-250,250))/100.0;
	if(newGermChance < 0.0) newGermChance = 0.0;
	else if(newGermChance > 100.0) newGermChance = 100.0;
	
	return new genePack(newLifeTime,newNumSeeds,newSeedSpread,newGermChance);
	
}
