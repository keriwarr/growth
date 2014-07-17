#ifndef __TILE_H__
#define __TILE_H__

class tile {

		// represents whether a plant currently occupies this tile
		bool occupied;
		
	public:
	
		// defaults occupied to false
		tile ();
		
		// negates the value of occupied
		void toggleOccupied ();
		
		// returns the value of occupied
		int getOccupied () const;

};

#endif
