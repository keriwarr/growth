#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector {
	
		// co-ordinates for where a new seed drops relative to its 
		// parent plant
		int x, y;
	
	public:
	
		vector(int x, int y);
		
		// returns x
		int getX();
		
		// returns y
		int getY();
	
};

#endif
