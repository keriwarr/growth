#include "tile.h"

tile::tile () : occupied(false) {
}

void tile::toggleOccupied () {
	if (this->occupied) {this->occupied = false;}
	else {this->occupied = true;}
}

int tile::getOccupied () const {
	return this->occupied;
}
