#include "growgame.h"
#include <iostream>

using namespace std;

int main () {
	grid *theGrid = grid::getInstance(9,9);
	theGrid->addPlant(3,4,2,1,4,4);
	theGrid->listPlants();
	for(int i = 0; i < 20; i ++) {
		theGrid->tick();
		theGrid->listPlants();
	}
	delete theGrid;
}
