#ifndef __RANDMATH_H__
#define __RANDMATH_H__
#include "seeddrop.h"

class randMath {

	public:

	// calls srand(time(NULL))
	static void seedRand ();

	// generates an integer in between bot and top, inclusive
	static int getRand (int bot, int top);

	// returns a seedDrop object with x & y within radius:range of the 
	// origin plant
	//
	// Note!! caller must delete returned seedDrop
	static seedDrop *getDrop (int range);
	
};

#endif