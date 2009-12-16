#include "../../src/sdlmouse/love_sdlmouse.h"

namespace love_sdlmouse

class Mouse { [struct=1]
	double x;
	double y;
}

static class love_sdlmouse { [className=mouse]
	int getX( )   	 Gets the current x-position of the mouse.
	int getY( ) 	Gets the current y-position of the mouse.
		
	Mouse getPosition( ) 	Gets the current position of the mouse.
	void setPosition( int x, int y ) 	Sets the current position of the mouse.
		
	bool isDown( int button ) 	Checks whether a certain button is down.
		
	void setVisible( bool visible ) 	Controls cursor visbility.
	bool isVisible( ) 	Checks cursor visbility. 
}