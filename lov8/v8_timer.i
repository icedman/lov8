#include "../../src/sdltimer/love_sdltimer.h"

static class love_sdltimer { [className=timer]
	double getFPS( )   	 Gets the current FPS.
	int getDelta( ) 	ret the current timestep.
	void sleep( int ms ) 	Delays exection for an amount of time.
	int getTime( ) 	Gets approximate time since startup. 
}