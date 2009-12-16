#include "../../src/sdljoystick/love_sdljoystick.h"

namespace love_sdljoystick

class Ball { [struct=1]
	int x;
	int y;
}

static class love_sdljoystick { [className=joystick]
	char* getName( int joystick )   	 Gets the name of a joystick.
	int getNumJoysticks( ) 	Gets the number of joysticks.
	int getNumAxes( int joystick ) 	Gets the number of axes on a joystick
	int getNumBalls( int joystick ) 	Gets the number of trackballs on a joystick
	int getNumButtons( int joystick ) 	Gets the number buttons on a joystick
	int getNumHats( int joystick ) 	Gets the number viewhats on a joystick
		
	bool isDown( int joystick, int button ) 	Checks if a button is down.
	int getAxis( int joystick, int axis ) 	Gets the state of an axis.
	//getAxes( int joystick ) 	Gets the states of the axes.
	Ball getBall( int joystick, int ball ) 	Gets the relative position of a trackball.
	int getHat( int joystick, int viewhat ) 	Gets the state of a viewhat.
		
	void open( int joystick ) 	Opens a joystick.
	bool isOpen( int joystick ) 	Checks whether a joystick is open.
	void close( int joystick ) 	Closes a joystick 	
}