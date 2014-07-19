#include "growgame.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
	
	int gridX = 21;
	int gridY = 21;
	float life = 3;
	float num = 4;
	float spread = 2;
	float chance = 50;
	char c;
	
	int CSV_ITERATIONS = 1000;
	if(argc == 2) CSV_ITERATIONS = atoi(argv[1]);
	else {
		
		std::cout << "Welcome to Growth!" << std::endl << "Enter grid dimensions (int int >= 1): ";
		std::cin >> gridX >> gridY;
		std::cout << "Enter starting plant life time (float >= 1): ";
		std::cin >> life;
		std::cout << "Enter starting number of seeds per plant (float >= 0): ";
		std::cin >> num;
		std::cout << "Enter starting seed spread distance (float >= 0): ";
		std::cin >> spread;
		std::cout << "Enter starting seed germination chance (float[0-100]): ";
		std::cin >> chance;
		std::cout << "Repeatedly enter any character but 'q' to iterate, or enter 'c' for .csv mode" << std::endl;
		std::cin >> c;
		
	}
	
	randMath::seedRand();
	grid *theGrid = grid::getInstance(gridX,gridY);
	theGrid->addPlant(new genePack(life,num,spread,chance),1,gridX/2,gridY/2);
	/*theGrid->addPlant(new genePack(life,num,spread,chance),2,3*gridX/4,3*gridY/4);*/
	theGrid->tick();
	
	if(argc == 2) {
		
		for(int i = 0; i < CSV_ITERATIONS; i++) {
			
			theGrid->printCSV();
			theGrid->tick();
			
		}
		
	} else {
		
		int iter = 0;
		while(c != 'q') {
			
			theGrid->listPlants(0,1,1);
			std::cout << "Iterations: " << iter << std::endl;
			std::cin >> c; 
			theGrid->tick();
			iter++;
			
		}
	}
	
	delete theGrid;

}
