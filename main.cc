#include "growgame.h"
#include <iostream>


int main () {
	
	randMath::seedRand();
	grid *theGrid = grid::getInstance(13,13);
	theGrid->addPlant(new genePack(5,3,4,50),6,6);
	theGrid->tick();
	char c;
	std::cout << "Repeatedly enter any character but 'q' to iterate" << std::endl;
	std::cin >> c;
	int iter = 0;
	while(c != 'q'){
		theGrid->listPlants();
		std::cout << "Iterations: " << iter << std::endl;
		std::cin >> c; 
		theGrid->tick();
		iter++;
	}
	delete theGrid;

}
