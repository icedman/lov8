#include "love_sdlkeyboard.h"
#include "mod_sdlkeyboard.h"

// LOVE
#include <love/Core.h>

// SDL
#include <SDL.h>

#include <v8.h>
extern v8::Handle<v8::ObjectTemplate> JSlove_sdlkeyboardCreateClass();

namespace love_sdlkeyboard
{
	bool module_init(int argc, char ** argv, love::Core * core)
	{
		std::cout << "INIT love.keyboard [" << "SDL" << "]" << std::endl;
		
		// Set function pointers and load module.
		{
			love::Keyboard * k = core->getKeyboard();
			k->loaded = true;
		}
		
		return true;
	}

	bool module_quit()
	{
		std::cout << "QUIT love.keyboard [" << "SDL" << "]" << std::endl;
		return true;
	}

	bool module_open(void * vm)
	{
		lua_State * s = (lua_State *)vm;
		if(s == 0)
			return false;
		luaopen_mod_sdlkeyboard(s);
		return true;
	}

	bool module_open_v8(void * vm) {

		v8::Handle<v8::ObjectTemplate> *love = (v8::Handle<v8::ObjectTemplate>*)vm;
		(*love)->Set(v8::String::New("keyboard"), JSlove_sdlkeyboardCreateClass());
		return true;
	}

	bool isDown(int key)
	{
		Uint8 * keystate = SDL_GetKeyState(0);
		return keystate[key] == 1;		
	}

} // love_sdlkeyboard
