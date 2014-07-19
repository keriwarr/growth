#ifndef __SEEDDROP_H__
#define __SEEDDROP_H__

class seedDrop {
	
		// co-ordinates for where a new seed drops relative to its 
		// parent plant
		int x, y;
	
	public:
	
		seedDrop(int x, int y);
		
		// returns x
		int getX();
		
		// returns y
		int getY();
	
};

#endif
