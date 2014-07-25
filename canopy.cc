#include "canopy.h"

#include <iostream>

canopy::canopy(int width, int height, pnode *first) : width(width), height(height), first(first) {}

canopy::~canopy() {delete first;}

void canopy::insert(plant *p, int x, int y) {
				std::cout << "ip1" << std::endl;

	if(this->first == NULL) {
				std::cout << "ip2" << std::endl;
		
		this->first = new pnode(p, x, y, NULL);
				std::cout << "ip3" << std::endl;
		
	} else if(first->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
				std::cout << "ip4" << std::endl;
		
		this->first = new pnode(p, x, y, first->getNext());
				std::cout << "ip5" << std::endl;
		
	} else {
				std::cout << "ip6" << std::endl;
		
		insertHelper(first, p, x, y);
				std::cout << "ip7" << std::endl;
		
	}
				std::cout << "ip8" << std::endl;

}

void canopy::insertHelper(pnode *head, plant *p, int x, int y) {
				std::cout << "ih1" << std::endl;
	
	if(head->getNext() == NULL) {
				std::cout << "ih2" << std::endl;
		
		head->setNext(new pnode(p, x, y, NULL));
				std::cout << "ih3" << std::endl;
		
	} else if(head->getNext()->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
				std::cout << "ih4" << std::endl;
		
		pnode *n = new pnode(p, x, y, head->getNext());
		head->setNext(n);
				std::cout << "ih5" << std::endl;
		
	} else {
				std::cout << "ih6" << std::endl;
		
		insertHelper(head->getNext(), p, x, y);
				std::cout << "ih7" << std::endl;
		
	}
				std::cout << "ih8" << std::endl;
	
}

bool canopy::remove(plant *p) {

	if(first == NULL) {
		
		return false;
		
	} else if(first->getPlant() == p) {
		
		pnode *newFirst = first->getNext();
		delete first;
		first = newFirst;
		
	} else {
	
		return removeHelper(first, p);
	
	}	

}

bool canopy::removeHelper(pnode *head, plant *p) {
	
	if(head->getNext() == NULL) {
		
		return false;
		
	} else if(head->getNext()->getPlant() == p) {
		
		pnode *replace = head->getNext()->getNext();
		delete head->getNext();
		head->setNext(replace);
		
	} else {
		
		return removeHelper(head->getNext(), p);
		
	}
	
}

void canopy::update() {

	int light = width*height;
	bool **sunLight = new bool*[this->width];
	
	for(int i = 0; i < this->width; ++i) {
		
		sunLight[i] = new bool[this->height];
		
		for(int j = 0; j < this->height; j++) {
			
			sunLight[i][j] = true;
			
		}
	}
	
	updateHelper(sunLight, light, this->first);

}

void canopy::updateHelper(bool **sunLight, int light, pnode *head) {

	if(head) {
		
		if(light == 0) {
			
			head->getPlant()->setLight(0);

		} else {
			
			int width = (int)head->getPlant()->getGenePack()->getWidth();
			int x1 = (head->getX() - width);
			int y1 = (head->getY() - width);
			int x2 = (head->getX() + width);
			int y2 = (head->getY() + width);
			x1 = (x1 <= 0) ? 0 : x1;
			y1 = (y1 <= 0) ? 0 : y1;
			x2 = (x2 >= this->width) ? (this->width - 1) : x2;
			y2 = (y2 >= this->height) ? (this->height - 1) : y2;
			
			int l = 0;
			
			for(int i = x1; i <= x2; i++) {
				
				for(int j = y1; j <= y2; j++) {
					
					if(sunLight[i][j]) {
						
						l++;
						light--;
						sunLight[i][j] = false;					
						
					}
					
				}
				
			}
			
			head->getPlant()->setLight(l);
			
		}
		
		updateHelper(sunLight, light, head->getNext());
		
	}	
	
}
