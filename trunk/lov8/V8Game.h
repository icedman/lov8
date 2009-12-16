

#ifndef LOVE_MOD_SYSTEM_V8_GAME_H
#define LOVE_MOD_SYSTEM_V8_GAME_H

// LOVE
#include <love/Game.h>
#include <love/Core.h>
#include <love/File.h>

// STD
#include <vector>

// v8 scripting
#include <v8.h>

namespace love_system
{
	class V8Game : public love::Game
	{
	protected:

		// Pointer to core.
		love::Core * core;

		// The Lua virtual machine. ("LOVE Machine")
		//lua_State * L;

		// v8 context
		v8::Handle<v8::Context> context;

		// Callback constants.
		enum
		{
			CALLBACK_LOAD, 
			CALLBACK_UPDATE, 
			CALLBACK_DRAW, 
			CALLBACK_KEYPRESSED, 
			CALLBACK_KEYRELEASED, 
			CALLBACK_MOUSEPRESSED, 
			CALLBACK_MOUSERELEASED, 
			CALLBACK_MOUSEMOVED,
			CALLBACK_JOYSTICKMOVED,
			CALLBACK_JOYSTICKPRESSED,
			CALLBACK_JOYSTICKRELEASED,
			CALLBACK_MESSAGE,
			CALLBACK_EVENT, 
			CALLBACK_SIZE
		};

		// List of present callback functions.
		bool callbacks[CALLBACK_SIZE];

	public:

		/**
		* Creates a new game.
		**/
		V8Game(love::pFile file, love::Core * core);

		virtual ~V8Game();

		// From Resource.
		bool load();
		void unload();

		// From Game.
		bool isLoaded() const;
		void update(float dt);
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseMoved(int xrel, int yrel);
		void joystickPressed(int index, int button);
		void joystickReleased(int index, int button);

		void message(const char * msg, int tag);

		// Lua AUX functions.

		/**
		* Parses the contents of file as Lua code.
		* @param file A file containing Lua code.
		* @return False if file couldn't be parsed.
		**/
		bool parse(love::pFile file);

		/**
		* Checks if a function exists in the global table.
		**/
		bool isFunction(const std::string function, int i);

	private:
		bool loaded;
		v8::Handle<v8::Value> executeString(const std::string string);
	}; // V8Game

	typedef boost::shared_ptr<V8Game> pV8Game;

} // love_system

#endif // LOVE_MOD_SYSTEM_V8_GAME_H
