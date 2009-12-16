#include "V8Game.h"

#include "V8Game.h"

// LOVE
#include <love/Exception.h>
#include "../src/system/constants.h"

// STD
#include <iostream>

// Extracts a C string from a V8 Utf8Value.
const char* ToCString(const v8::String::Utf8Value& value) {
	return *value ? *value : "<string conversion failed>";
}

void ReportException(v8::TryCatch* try_catch) {
	v8::HandleScope handle_scope;
	v8::String::Utf8Value exception(try_catch->Exception());
	const char* exception_string = ToCString(exception);
	v8::Handle<v8::Message> message = try_catch->Message();
	if (message.IsEmpty()) {
		// V8 didn't provide any extra information about this error; just
		// print the exception.
		printf("%s\n", exception_string);
	} else {
		// Print (filename):(line number): (message).
		v8::String::Utf8Value filename(message->GetScriptResourceName());
		const char* filename_string = ToCString(filename);
		int linenum = message->GetLineNumber();
		printf("%s:%i: %s\n", filename_string, linenum, exception_string);
		// Print line of source code.
		v8::String::Utf8Value sourceline(message->GetSourceLine());
		const char* sourceline_string = ToCString(sourceline);
		printf("%s\n", sourceline_string);
		// Print wavy underline (GetUnderline is deprecated).
		int start = message->GetStartColumn();
		for (int i = 0; i < start; i++) {
			printf(" ");
		}
		int end = message->GetEndColumn();
		for (int i = start; i < end; i++) {
			printf("^");
		}
		printf("\n");
	}
}

v8::Handle<v8::Value> Print(const v8::Arguments& args) {
	bool first = true;
	for (int i = 0; i < args.Length(); i++) {
		v8::HandleScope handle_scope;
		if (first) {
			first = false;
		} else {
			printf(" ");
		}
		v8::String::Utf8Value str(args[i]);
		const char* cstr = ToCString(str);
		printf("%s", cstr);
	}
	printf("\n");
	fflush(stdout);
	return v8::Undefined();
}


namespace love_system
{
	V8Game::V8Game(love::pFile file, love::Core * core) 
		: Game(file), core(core), loaded(false)
	{
	}

	V8Game::~V8Game()
	{
		unload();
	}

	bool V8Game::load()
	{
		v8::HandleScope handle_scope;
		v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();
		v8::Handle<v8::ObjectTemplate> love = v8::ObjectTemplate::New();

		global->Set(v8::String::New("print"), v8::FunctionTemplate::New(Print), v8::PropertyAttribute::ReadOnly);

		// Install constants.
		for(int i = 0; constants[i].name != 0; i++)
		{
			love->Set(v8::String::New(constants[i].name), v8::Int32::New(constants[i].value), v8::PropertyAttribute::ReadOnly);
		}

		// Rename load. (Prevents the built-in load from 
		// being detected.
		//luaL_dostring(L, "stdload = load; load = nil;");

		// Custom libs.
		if(!core->openV8((void*)&love))
			return false;

		global->Set(v8::String::New("love"), love, v8::PropertyAttribute::ReadOnly);

		// Create a new execution environment containing the built-in
		// functions
		context = v8::Context::New(NULL, global);
		// Enter the newly created execution environment.
		v8::Context::Scope context_scope(context);

		// Load the file serving as the entry point.
		if(!parse(file))
			return false;

		// Check for present functions.
		for(int i =0;i<CALLBACK_SIZE;i++) callbacks[i] = false;
		if(isFunction("load",CALLBACK_LOAD)) callbacks[CALLBACK_LOAD] = true;
		if(isFunction("update",CALLBACK_UPDATE)) callbacks[CALLBACK_UPDATE] = true;
		if(isFunction("draw",CALLBACK_DRAW)) callbacks[CALLBACK_DRAW] = true;
		if(isFunction("keypressed",CALLBACK_KEYPRESSED)) callbacks[CALLBACK_KEYPRESSED] = true;
		if(isFunction("keyreleased",CALLBACK_KEYRELEASED)) callbacks[CALLBACK_KEYRELEASED] = true;
		if(isFunction("mousepressed",CALLBACK_MOUSEPRESSED)) callbacks[CALLBACK_MOUSEPRESSED] = true;
		if(isFunction("mousereleased",CALLBACK_MOUSERELEASED)) callbacks[CALLBACK_MOUSERELEASED] = true;
		if(isFunction("joystickpressed",CALLBACK_JOYSTICKPRESSED)) callbacks[CALLBACK_JOYSTICKPRESSED] = true;
		if(isFunction("joystickreleased",CALLBACK_JOYSTICKRELEASED)) callbacks[CALLBACK_JOYSTICKRELEASED] = true;
		if(isFunction("message",CALLBACK_MESSAGE)) callbacks[CALLBACK_MESSAGE] = true;
		if(isFunction("event",CALLBACK_EVENT)) callbacks[CALLBACK_EVENT] = true;

		// Call load, if present.
		if(callbacks[CALLBACK_LOAD])
		{
			v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("load"));
			if (func->IsFunction()) {
				v8::Function::Cast(*func)->Call(context->Global(), 0, 0);
			}
		}

		// we're loaded
		loaded = true;

		return true;
	}

	void V8Game::unload()
	{
		//v8::V8::Dispose();
		v8::HandleScope handle_scope;
		context->DetachGlobal();
		loaded = false;
	}

	bool V8Game::isLoaded() const
	{
		return loaded;
	}

	void V8Game::update(float dt)
	{
		if(!callbacks[CALLBACK_UPDATE])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("update"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Number::New(dt)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 1, args);
		}
		context->Exit();
	}

	void V8Game::draw()
	{
		if(!callbacks[CALLBACK_DRAW]) 
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("draw"));
		if (func->IsFunction()) {
			v8::Function::Cast(*func)->Call(context->Global(), 0,0);
		}
		context->Exit();
	}

	void V8Game::keyPressed(int key)
	{
		if(!callbacks[CALLBACK_KEYPRESSED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("keypressed"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(key)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 1, args);
		}
		context->Exit();
	}

	void V8Game::keyReleased(int key)
	{
		if(!callbacks[CALLBACK_KEYRELEASED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("keyreleased"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(key)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 1, args);
		}
		context->Exit();
	}

	void V8Game::mousePressed(int x, int y, int button)
	{
		if(!callbacks[CALLBACK_MOUSEPRESSED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("mousepressed"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(x),
				v8::Int32::New(y),
				v8::Int32::New(button)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 3, args);
		}
		context->Exit();
	}

	void V8Game::mouseReleased(int x, int y, int button)
	{
		if(!callbacks[CALLBACK_MOUSERELEASED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("mousereleased"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(x),
				v8::Int32::New(y),
				v8::Int32::New(button)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 3, args);
		}
		context->Exit();
	}

	void V8Game::mouseMoved(int xrel, int yrel)
	{
		if(!callbacks[CALLBACK_MOUSEMOVED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("mousemoved"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(xrel),
				v8::Int32::New(yrel)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 2, args);
		}
		context->Exit();
	}

	void V8Game::joystickPressed(int index, int button)
	{
		if(!callbacks[CALLBACK_JOYSTICKPRESSED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("joystickpressed"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(index),
				v8::Int32::New(button)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 2, args);
		}
		context->Exit();
	}

	void V8Game::joystickReleased(int index, int button)
	{
		if(!callbacks[CALLBACK_JOYSTICKRELEASED])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("joystickreleased"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::Int32::New(index),
				v8::Int32::New(button)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 2, args);
		}
		context->Exit();
	}

	void V8Game::message(const char * msg, int tag)
	{
		if(!callbacks[CALLBACK_MESSAGE])
			return;
		v8::HandleScope scope;
		context->Enter();
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New("message"));
		if (func->IsFunction()) {
			v8::Handle<v8::Value> args[] = {
				v8::String::New(msg),
				v8::Int32::New(tag)
			};
			v8::Function::Cast(*func)->Call(context->Global(), 2, args);
		}
		context->Exit();
	}

	bool V8Game::parse(love::pFile file)
	{
		if(!file->load())
			return false;

		executeString(std::string(file->getData(), file->getSize()));
		return true;
	}

	bool V8Game::isFunction(const std::string function, int i)
	{
		v8::Handle<v8::Value> func = context->Global()->Get(v8::String::New(function.c_str()));
		if ((*func)->IsFunction())
			return true;
		printf("%s is not a function\n", function.c_str());
		return false;
	}

	v8::Handle<v8::Value> V8Game::executeString(const std::string string) {
		v8::HandleScope handle_scope;
		v8::TryCatch try_catch;
		v8::Handle<v8::Script> script = v8::Script::Compile(
			v8::String::New(string.c_str(),string.length()),
			v8::String::New("(v8)"));
		if (script.IsEmpty()) {
			ReportException(&try_catch);
		} else {
			v8::Handle<v8::Value> result = script->Run();
			if (result.IsEmpty()) {
				ReportException(&try_catch);
			} else {
				return result;
			}
		}
		return v8::Undefined();
	}



} // love_system