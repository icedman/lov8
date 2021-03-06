/*
* LOVE: Totally Awesome 2D Gaming.
* Website: http://love.sourceforge.net
* Licence: ZLIB/libpng
* Copyright (c) 2006-2008 LOVE Development Team
* 
* This is the executable. It does the following:
*
* - Inits SDL. 
* - Creates a love::Core.
* - Inserts all the modules into the core.
* - And finally enters update/render loop.
* 
* @author Anders Ruud
* @date 2008-03-15
*/

// STD
#include <iostream>
#include <fstream>

// SDL
#include <SDL.h>

// LOVE
#include <love/Core.h>
#include <love/Game.h>
#include <love/Exception.h>
#include <love/version.h>
#include <love/events.h>

// This neat macro makes static module 
// configuration prettier.
#define STATIC_MOD_EXTERN(ns) \
	namespace ns { \
		extern bool module_init(int argc, char ** argv, love::Core * core); \
		extern bool module_quit(); \
		extern bool module_open(void * vm); \
		extern bool module_open_v8(void * vm); \
	} \

// This other neat macro makes static module
// initialization prettier.
#define STATIC_MOD_INIT(ns) \
	if(!core->insmod(ns::module_init, ns::module_quit, ns::module_open, 0)) \
		return 1; \

#define STATIC_MOD_INIT_V8(ns) \
	if(!core->insmod(ns::module_init, ns::module_quit, ns::module_open, ns::module_open_v8)) \
		return 1; \

// Static module conf.
STATIC_MOD_EXTERN(love_physfs);
STATIC_MOD_EXTERN(love_opengl);
STATIC_MOD_EXTERN(love_sdlmixer);
STATIC_MOD_EXTERN(love_sdltimer);
STATIC_MOD_EXTERN(love_sdlmouse);
STATIC_MOD_EXTERN(love_sdlkeyboard);
STATIC_MOD_EXTERN(love_box2d);
//STATIC_MOD_EXTERN(love_luasocket);
STATIC_MOD_EXTERN(love_sdljoystick);
STATIC_MOD_EXTERN(love_system);

using namespace love;

int main(int argc, char* argv[])
{	
	// Create a core.
	pCore core(new Core());

	// Init SDL.
	if(SDL_Init(0))
	{
		std::cerr << "Could not init SDL. " << SDL_GetError() << std::endl;
		return false;
	}

	// Print welcome message.
	std::cout << "This is LOVE " << LOVE_VERSION_FULL_STR << "." << std::endl << std::endl;

	// Set command line arguments.
	core->setArgs(argc, argv);

	// Add modules. (Modules are immediately inited, so the order is important).
	STATIC_MOD_INIT_V8(love_physfs);
	STATIC_MOD_INIT_V8(love_opengl);
	STATIC_MOD_INIT_V8(love_sdlmixer);
	STATIC_MOD_INIT_V8(love_sdltimer);
	STATIC_MOD_INIT_V8(love_sdlmouse);
	STATIC_MOD_INIT_V8(love_sdlkeyboard);
	STATIC_MOD_INIT_V8(love_box2d);
	//STATIC_MOD_INIT(love_luasocket);
	STATIC_MOD_INIT_V8(love_sdljoystick);

	// System shoud even go after dynamic modules, since it
	// creates the Lua VM, etc.
	STATIC_MOD_INIT_V8(love_system);

	// Verifies that all required function pointers 
	// have been set for the standard modules.
	if(!core->verify())
	{
		std::cerr << "Core verification FAILED." << std::endl;
		return 1;
	}

	// Get pointers to the devices we use.
	Timer * timer = core->getTimer();
	Graphics * graphics = core->getGraphics();
	System * system = core->getSystem();

	/**
	* Main loop section.
	**/
	
	// Enable UNICODE. This is needed for input to work properly.
	SDL_EnableUNICODE(1);

	// The union used to get SDL events. 
	SDL_Event e;

	bool running = true;

	while(running)
	{
		const pGame & game = system->getGame();
		if(!game)
		{
			std::cerr << "ERROR! No game." << std::endl;
			return 1;
		}

		timer->step();
		game->update(timer->getDelta());
		graphics->clear();
		game->draw();		

		while(SDL_PollEvent(&e))
		{
			// Do events.
			switch(e.type)
			{
				case SDL_KEYDOWN:			
					game->keyPressed(e.key.keysym.sym);
					break;
				case SDL_KEYUP:
					game->keyReleased(e.key.keysym.sym);
					break;
				case SDL_MOUSEBUTTONDOWN:
					game->mousePressed(e.button.x, e.button.y, e.button.button);
					break;
				case SDL_MOUSEBUTTONUP:
					game->mouseReleased(e.button.x, e.button.y, e.button.button);
					break;
				case SDL_MOUSEMOTION:
					game->mouseMoved(e.button.x, e.button.y);
					break;
				//case SDL_JOYAXISMOTION:
				//	game->gamepadAxisMoved(e.jaxis.which, e.jaxis.axis, e.jaxis.value);
				//	break;
				case SDL_JOYBUTTONDOWN:
					game->joystickPressed(e.jbutton.which, e.jbutton.button);
					break;
				case SDL_JOYBUTTONUP:
					game->joystickReleased(e.jbutton.which, e.jbutton.button);
					break;
				//case SDL_JOYBALLMOTION:
				//	game->gamepadBallMoved(e.jball.which, e.jball.ball, e.jball.xrel, e.jball.yrel);
				//	break;
				//case SDL_JOYHATMOTION:
				//	game->gamepadHatMoved(e.jhat.which, e.jhat.hat, e.jhat.value);
				//	break;
				case SDL_QUIT:
					running = false; // Bye bye.
					break;
				case EVENT_RESTART:
					// Restarting must happen here, since we don't want to
					// be in the middle of a Lua call while restarting.
					if(!game->reload())
					{
						std::cerr << "An error occurred while reloading." << std::endl;
						running = false;
					}
					break;
				default:
					break;
			}
		}

		graphics->present();
	}

	// Destroy the core.
	core.reset();

	SDL_Quit();

	return 0;
} // main
