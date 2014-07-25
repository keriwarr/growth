#inclide "pnode.h"

pnode::pnode(plant *p, int x, int y, pnode *next) : p(p), x(x), y(y), next(next) {}

pnode::~pnode() {delete next;}

plant *pnode::getPlant() {return this->p;}

int pnode::getX() const {return this->x;}
		
int pnode::getY() const {return this->y;}

pnode *pnode::getNext() {return this->next;}

void pnode::setNext(pnode *n) {
	this->next = n;
}
