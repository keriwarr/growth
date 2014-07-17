#include "growgame.h"
#include <iostream>


int main () {
		
	grid *theGrid = grid::getInstance(25,25);
	theGrid->addPlant(3,4,2,1,4,4);
	theGrid->listPlants();
	for(int i = 0; i < 25; i ++) {
		theGrid->tick();
		theGrid->listPlants();
	}
	delete theGrid;

}
