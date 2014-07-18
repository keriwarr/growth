#include "growgame.h"
#include <iostream>
#include <cstdlib>


int main (int argc, char *argv[]) {
	
	int gridX = 21;
	int gridY = 21;
	int life = 3;
	int num = 3;
	int spread = 5;
	int chance = 50;
	char c;
	
	int CSV_ITERATIONS = 1000;
	if(argc == 2) CSV_ITERATIONS = atoi(argv[1]);
	else {
		std::cout << "Welcome to Growth!" << std::endl << "Enter grid dimensions (int int >= 1): ";
		std::cin >> gridX >> gridY;
		std::cout << "Enter starting plant life time (int >= 1): ";
		std::cin >> life;
		std::cout << "Enter starting number of seeds per plant (int >= 0): ";
		std::cin >> num;
		std::cout << "Enter starting seed spread distance (int >= 0): ";
		std::cin >> spread;
		std::cout << "Enter starting seed germination chance (int[0-100]): ";
		std::cin >> chance;
		std::cout << "Repeatedly enter any character but 'q' to iterate, or enter 'c' for .csv mode" << std::endl;
		std::cin >> c;
	}
	
	randMath::seedRand();
	grid *theGrid = grid::getInstance(gridX,gridY);
	theGrid->addPlant(new genePack(life,num,spread,chance),gridX/2,gridY/2);
	theGrid->tick();
	
	if(argc == 2){
		for(int i = 0; i < CSV_ITERATIONS; i++){
			theGrid->printCSV();
			theGrid->tick();
		}
	} else {
		int iter = 0;
		while(c != 'q'){
			theGrid->listPlants();
			std::cout << "Iterations: " << iter << std::endl;
			std::cin >> c; 
			theGrid->tick();
			iter++;
		}
	}
	delete theGrid;

}
