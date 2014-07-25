#include "canopy.h"

#include <iostream>

canopy::canopy(int width, int height, pnode *first) : width(width), height(height), length(0), first(first) {}

canopy::~canopy() {
	
	pnode *n = first;
	while(n) {
		
		pnode *o = n->getNext();
		delete n;
		n = o;
		
	}
	
}

void canopy::insert(plant *p, int x, int y) {

	if(this->first == NULL) {
		
		this->first = new pnode(p, x, y, NULL);
		
	} else if(first->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
		
		this->first = new pnode(p, x, y, first);
		
	} else {
		
		insertHelper(first, p, x, y);
		
	}
	
	length++;

}

void canopy::insertHelper(pnode *head, plant *p, int x, int y) {
	
	if(head->getNext() == NULL) {
		
		pnode *n = new pnode(p, x, y, NULL);
		head->setNext(n);
		
	} else if(head->getNext()->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
		
		pnode *n = new pnode(p, x, y, head->getNext());
		head->setNext(n);
		
	} else {
		
		insertHelper(head->getNext(), p, x, y);
		
	}
	
}

bool canopy::remove(int x, int y) {

	if(first == NULL) {
		
		return false;
		
	} else if(first->getX() == x && first->getY() == y) {
		
		pnode *newFirst = first->getNext();
		delete first;
		first = newFirst;
		return true;
		length--;
		
	} else {
	
		return removeHelper(first, x, y);
	
	}	

}

bool canopy::removeHelper(pnode *head, int x, int y) {
	
	if(head->getNext() == NULL) {
		
		return false;
		
	} else if(head->getNext()->getX() == x && head->getNext()->getY() == y) {
		
		pnode *replace = head->getNext()->getNext();
		delete head->getNext();
		head->setNext(replace);
		return true;
		length--;
		
	} else {
		
		return removeHelper(head->getNext(), x, y);
		
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
	
	for(int i = 0; i < width; ++i) {
		
		delete [] sunLight[i];
		sunLight[i] = NULL;
		
	}
	
	delete [] sunLight;
	sunLight = NULL;

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

int canopy::getLength() {return this->length;}

void canopy::printCanopy() {
	
	pnode *current = first;
	
	
	while(current) {
		
		std::cout << "(" << current->getX() << "," << current->getY() << ")->";
		current = current->getNext();
		
	}
	
	std::cout << "NULL" << std::endl;
	
}
