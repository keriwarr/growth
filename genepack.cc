#include "genepack.h"

int genePack::MUTATION_FACTOR;

int genePack::RELATIVE_LIFETIME_MUTATION_SPEED;
int genePack::RELATIVE_SEED_COUNT_MUTATION_SPEED;
int genePack::RELATIVE_SEED_SPREAD_MUTATION_SPEED;
int genePack::RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED;
int genePack::RELATIVE_HEIGHT_MUTATION_SPEED;
int genePack::RELATIVE_WIDTH_MUTATION_SPEED;

void genePack::setMutationFactors(int overall, int life, int seeds, int spread, int chance, int height, int width) {
	
	MUTATION_FACTOR = overall;
	
	RELATIVE_LIFETIME_MUTATION_SPEED = life;
	RELATIVE_SEED_COUNT_MUTATION_SPEED = seeds;
	RELATIVE_SEED_SPREAD_MUTATION_SPEED = spread;
	RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED = chance;
	RELATIVE_HEIGHT_MUTATION_SPEED = height;
	RELATIVE_WIDTH_MUTATION_SPEED = width;
	
	
}

genePack::genePack(float lifeTime, float numSeeds, float seedSpread, float germChance, float(height), float width) : lifeTime(lifeTime), numSeeds(numSeeds), seedSpread(seedSpread), germChance(germChance), height(height), width(width) {}

float genePack::getLifeTime() const {return this->lifeTime;}

float genePack::getNumSeeds() const {return this->numSeeds;}

float genePack::getSeedSpread() const {return this->seedSpread;}

float genePack::getGermChance() const {return this->germChance;}

float genePack::getHeight() const {return this->height;}

float genePack::getWidth() const {return this->width;}

genePack *genePack::mutate() const {
	
	float newLifeTime = this->lifeTime + (float)(randMath::getRand(-(RELATIVE_LIFETIME_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_LIFETIME_MUTATION_SPEED*MUTATION_FACTOR)))/100.0;
	if(newLifeTime < 1.0) newLifeTime = 1.0;
	
	float newNumSeeds = this->numSeeds + (float)(randMath::getRand(-(RELATIVE_SEED_COUNT_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_SEED_COUNT_MUTATION_SPEED*MUTATION_FACTOR)))/100.0;
	if(newNumSeeds < 0.0) newNumSeeds = 0.0;
	
	float newSeedSpread = this->seedSpread + (float)(randMath::getRand(-(RELATIVE_SEED_SPREAD_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_SEED_SPREAD_MUTATION_SPEED*MUTATION_FACTOR)))/100.0;
	if(newSeedSpread < 0.0) newSeedSpread = 0.0;
	
	float newGermChance = this->germChance + (float)(randMath::getRand(-(RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_GERMINATION_CHANCE_MUTATION_SPEED*MUTATION_FACTOR)))/100.0;
	if(newGermChance < 0.0) newGermChance = 0.0;
	else if(newGermChance > 100.0) newGermChance = 100.0;
	
	float newHeight = this->height + (float)(randMath::getRand(-(RELATIVE_HEIGHT_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_HEIGHT_MUTATION_SPEED*MUTATION_FACTOR)))/100.0;
	if(newHeight < 0.0) newHeight = 0.0;
	
	float newWidth = this->width + (float)(randMath::getRand(-(RELATIVE_WIDTH_MUTATION_SPEED*MUTATION_FACTOR),(RELATIVE_WIDTH_MUTATION_SPEED*MUTATION_FACTOR)))/100;
	if(newWidth < 0) newWidth = 0;
	
	return new genePack(newLifeTime,newNumSeeds,newSeedSpread,newGermChance,newHeight,newWidth);
	
}
