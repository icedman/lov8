#include "love_sdlmouse.h"
#include "mod_sdlmouse.h"

// LOVE
#include <love/Core.h>

// SDL
#include <SDL.h>

#include <v8.h>
extern v8::Handle<v8::ObjectTemplate> JSlove_sdlmouseCreateClass();

namespace love_sdlmouse
{
	bool module_init(int argc, char ** argv, love::Core * core)
	{
		std::cout << "INIT love.mouse [" << "SDL" << "]" << std::endl;
		
		// Set function pointers and load module.
		{
			love::Mouse * m = core->getMouse();
			m->loaded = true;
		}

		return true;
	}

	bool module_quit()
	{
		std::cout << "QUIT love.mouse [" << "SDL" << "]" << std::endl;
		return true;
	}

	bool module_open(void * vm)
	{
		lua_State * s = (lua_State *)vm;
		if(s == 0)
			return false;
		luaopen_mod_sdlmouse(s);
		return true;
	}

	bool module_open_v8(void * vm) {

		v8::Handle<v8::ObjectTemplate> *love = (v8::Handle<v8::ObjectTemplate>*)vm;
		(*love)->Set(v8::String::New("mouse"), JSlove_sdlmouseCreateClass());
		return true;
	}

	float getX()
	{
		int x;
		SDL_GetMouseState(&x, 0);
		return (float)x;
	}

	float getY()
	{
		int y;
		SDL_GetMouseState(0, &y);
		return (float)y;
	}

	void setPosition(float x, float y)
	{
		SDL_WarpMouse((int)x, (int)y);
	}

	bool isDown(int button)
	{
		return (SDL_GetMouseState(0, 0) & SDL_BUTTON(button)) != 0;
	}

	void setVisible(bool visible)
	{
		SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
	}

	bool isVisible()
	{
		return (SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE) ? true : false;
	}

	int getPosition(lua_State * L)
	{
		int n = lua_gettop(L);

		if( n != 0 )
			return luaL_error(L, "Funtion does not take parameters.");

		lua_pushnumber(L, getX());
		lua_pushnumber(L, getY());

		return 2;
	}

	Mouse getPosition()
	{
		Mouse m;
		m.x = getX();
		m.y = getY();
		return m;
	}

} // love_sdlmouse
