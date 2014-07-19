#include "randmath.h"

void randMath::seedRand() {
	
	static bool seeded = false;
	
	if(!seeded)	{
		
		srand(time(NULL));
		seeded = true;
		
	}	
	
}

int randMath::getRand(int bot, int top) {
	
	return (rand() % (top - bot + 1)) + bot;
	
}

seedDrop *randMath::getDrop(float range) {
	
	float rad = (range + 1/2) / 100.0 * getRand(0,100);
	float angle = getRand(0,360) / 180.0 * M_PI;
	
	seedDrop *seeddrop = new seedDrop((int) round(cos(angle) * rad),(int) round(sin(angle) * rad));
	return seeddrop;
	
}
