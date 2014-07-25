#include "canopy.h"

canopy::canopy(int width, int height, plant *first) : width(width), height(height), first(first) {}

canopy::~canopy() {delete first;}

void canopy::insert(plant *p, int x, int y) {

	if(this->first == NULL) {
		
		first = new pnode(p, x, y, NULL);
		
	} else if(first->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
		
		first = new pnode(p, x, y, first->getNext());
		
	} else {
		
		insertHelper(first, p, x, y);
		
	}

}

void canopy::insertHelper(pnode *head, plant *p, int x, int y) {
	
	if(head->getNext() == NULL) {
		
		head->getNext() = new pnode(p, x, y, NULL);
		
	} else if(head->getNext()->getPlant()->getGenePack()->getHeight() < p->getGenePack()->getHeight()) {
		
		pnode *n = new pnode(p, x, y, head->getNext());
		head->setNext(n);
		
	} else {
		
		insertHelper(head->next(), p, x, y);
		
	}
	
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
		
			int x1 = (head->getX() - head->getPlant()->getGenePack()->getWidth());
			int y1 = (head->getY() - head->getPlant()->getGenePack()->getHeight());
			int x2 = (head->getX() + head->getPlant()->getGenePack()->getWidth());
			int y2 = (head->getY() + head->getPlant()->getGenePack()->getHeight());
			x1 = (x1 <= 0) ? 0 : x1;
			y1 = (y1 <= 0) ? 0 : y1;
			x2 = (x2 >= this->width) ? (this->width - 1) : x2;
			y2 = (y2 >= this->height) ? (thi->height - 1) : y2;
			
			int l = 0;
			
			for(int i = x1; i <= x2; i++) {
				
				for(int j = y1; j <= y2; j++) {
					
					if(sunLight[i][j]) {
						
						l++;
						light--;
						sunlight[i][j] = false;					
						
					}
					
				}
				
			}
			
			head->getPlant()->setLight(l);
			
		}
		
		updateHelper(sunLight, light, head->getNext());
		
	}	
	
}
