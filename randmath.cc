#include "randmath.h"
#include "seeddrop.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

void randMath::seedRand () {
	srand(time(NULL));
}

int randMath::getRand (int bot, int top) {
	return (rand() % (top - bot + 1)) + bot;
}

seedDrop *randMath::getDrop (int range) {
	float rad = (range + 1/2) / 100.0 * getRand(0,100);
	float angle = getRand(0,360) / 180.0 * M_PI;
	seedDrop *seeddrop = new seedDrop((int) round(cos(angle) * rad),(int) round(sin(angle) * rad));
	return seeddrop;
}
