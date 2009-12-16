#include "../../src/system/love_system.h"

static class love_system { [className=system]
	char* getVersion()   	 Gets the current LOVE version.
	char* getCodename() 	Gets the codename of the current LOVE version.
	char* getPlatform() 	Gets the current platform.
		
	void exit() 	Exits LOVE.
	void restart() 	Restarts the current game.
	void suspend() 	Takes LOVE to the error handler.
	void resume() 	Takes LOVE back to the main game.
		
	void grabInput(bool grab) 	Sends as much input as possible to LOVE. 
}