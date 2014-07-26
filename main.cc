#include "growgame.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
	
	int gridX = 30;
	int gridY = 30;
	float life = 10;
	float num = 8;
	float spread = 3;
	float chance = 70;
	float height = 4;
	float width = 1;
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
		std::cout << "Repeatedly enter any character but 'q' to iterate, enter 't' to iterate 10 times, enter 'h' to iterate 100 times, or enter 'c' for .csv mode" << std::endl;
		std::cin >> c;
			
	}
	
	randMath::seedRand();
	grid *theGrid = grid::getInstance(gridX,gridY);
	genePack::setMutationFactors(20,2,2,2,10,2,2);
	genePack *gp = new genePack(life,num,spread,chance,height,width);
	theGrid->addPlant(gp,1,gridX/2,gridY/2);
	delete gp;
	/*theGrid->addPlant(new genePack(life,num,spread,chance),2,3*gridX/4,3*gridY/4);*/
	theGrid->tick();
	
	if(argc == 2) {
		
		for(int i = 0; i < CSV_ITERATIONS; i++) {
			
			/*if(i%5000==0)*/theGrid->printCSV();
			theGrid->tick();
			
		}
		
	} else {
		
		int iter = 0;
		while(c != 'q') {
			
			theGrid->listPlants(0,1,1);
			std::cout << "Iterations: " << iter << std::endl;
			std::cin >> c; 
			if(c == 't') {
				for(int i = 0; i < 10; i++) {
					theGrid->tick();
				}
				iter += 10;
			} else if(c == 'h') {
				for(int i = 0; i < 100; i++) {
					theGrid->tick();
				}			
				iter += 100;	
			} else if(c != 'q') {
				theGrid->tick();
				iter++;
			}
			
		}
	}
	
	delete theGrid;
	
}
