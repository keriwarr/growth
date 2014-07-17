#ifndef __TILE_H__
#define __TILE_H__

class tile {
	
		bool occupied;
	public:
		tile ();
		void toggleOccupied ();
		int getOccupied () const;		
	
};

#endif
