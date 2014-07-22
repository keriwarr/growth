#ifndef __RANDMATH_H__
#define __RANDMATH_H__
#include "vector.h"
#include <ctime>
#include <cstdlib>
#include <cmath>


class randMath {

	public:

		// calls srand(time(NULL)); prevents multiple seedings
		static void seedRand();

		// generates an integer in between bot and top, inclusive
		static int getRand(int bot, int top);

		// returns a seedDrop object with x & y within radius:range of the 
		// origin plant
		//
		// Note!! caller must delete returned seedDrop
		static vector *getDrop(float range);
	
};

#endif
