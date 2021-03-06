#include "love_sdltimer.h"
#include "mod_sdltimer.h"

// LOVE
#include <love/Core.h>

// SDL
#include <SDL.h>

#include <v8.h>
extern v8::Handle<v8::ObjectTemplate> JSlove_sdltimerCreateClass();

namespace love_sdltimer
{

	// Timing vars for benchmarking.
	Uint32 time_init = 0;
	
	// Frame delta vars.
	Uint32 currTime = 0;
	Uint32 prevTime;
	Uint32 prevFpsUpdate = 0;

	// Updated with a certain frequency.
	float fps = 0;

	// The frequency by which to update the FPS.
	float fpsUpdateFrequency = 1;

	// Frames since last FPS update.
	int frames = 0;

	// The current timestep.
	float dt = 0;

	bool module_init(int argc, char ** argv, love::Core * core)
	{
		std::cout << "INIT love.timer [" << "SDL" << "]" << std::endl;
		
		// Init the SDL timer system.
		if(SDL_InitSubSystem(SDL_INIT_TIMER) < 0)
		{
			std::cerr << "Could not init SDL_TIMER: " << SDL_GetError() << std::endl;
			return false;
		}
		
		// Set function pointers and load module.
		{
			love::Timer * t = core->getTimer();
			t->getDelta = love_sdltimer::getDelta;
			t->step = love_sdltimer::step;
			t->loaded = true;
		}

		time_init = SDL_GetTicks();

		return true;
	}

	bool module_quit()
	{
		SDL_QuitSubSystem(SDL_INIT_TIMER);
		std::cout << "QUIT love.timer [" << "SDL" << "]" << std::endl;
		return true;
	}

	bool module_open(void * vm)
	{
		lua_State * s = (lua_State *)vm;
		if(s == 0)
			return false;
		luaopen_mod_sdltimer(s);
		return true;
	}

	bool module_open_v8(void * vm) {

		v8::Handle<v8::ObjectTemplate> *love = (v8::Handle<v8::ObjectTemplate>*)vm;
		(*love)->Set(v8::String::New("timer"), JSlove_sdltimerCreateClass());
		return true;
	}

	void step()
	{
		// Frames rendered
		frames++;
			
		// "Current" time is previous time by now.
		prevTime = currTime;

		// Get ticks from SDL
		currTime = SDL_GetTicks();

		// Convert to number of seconds
		dt = (currTime - prevTime)/1000.0f;

		// Update FPS?
		if((currTime - prevFpsUpdate)/1000.0f > fpsUpdateFrequency)
		{
			fps = frames/fpsUpdateFrequency;
			prevFpsUpdate = currTime;
			frames = 0;
		}

		if(dt < 0)
			printf("Timer: WTF: %f: \n", dt);
	}

	float getDelta()
	{
		return dt;
	}

	float getFPS()
	{
		return fps;
	}

	void sleep(int ms)
	{		
		SDL_Delay((unsigned int)ms);
	}

	float getTime()
	{
		return (SDL_GetTicks() - time_init)/1000.0f;
	}

} // love_sdltimer
