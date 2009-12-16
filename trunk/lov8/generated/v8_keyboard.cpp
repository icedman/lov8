#include <v8.h>
#include "../v8Object.h"
#include "../../src/sdlkeyboard/love_sdlkeyboard.h"


// extern

// forward declaractions


void JSlove_sdlkeyboardSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_sdlkeyboardCreateClass();

 

/**
 * love_sdlkeyboard::isDown 
 */
v8::Handle<v8::Value> JSlove_sdlkeyboardIsDown(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int key = args[0]->Int32Value();
	bool ret = (bool)love_sdlkeyboard::isDown(key);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_sdlkeyboardSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("isDown"), v8::FunctionTemplate::New(JSlove_sdlkeyboardIsDown));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_sdlkeyboardCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("keyboard"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_sdlkeyboardSetupClass(js_obj);
	return js_obj;
}



