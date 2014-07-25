#include "randmath.h"

void randMath::seedRand() {
	
	static bool seeded = false;
	
	if(!seeded)	{
		
		srand(time(NULL));
		seeded = true;
		
	}	
	
}

int randMath::getRand(const int bot, const int top) {
	
	return (rand() % (top - bot + 1)) + bot;
	
}

vector *randMath::getDrop(const float range) {
	
	float rad = (range + 1/2) / 100.0 * getRand(0,100);
	float angle = getRand(0,360) / 180.0 * M_PI;
	
	vector *vect = new vector((int) round(cos(angle) * rad),(int) round(sin(angle) * rad));
	return vect;
	
}
