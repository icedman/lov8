#include <v8.h>
#include "../v8Object.h"
#include "../../src/system/love_system.h"


// extern

// forward declaractions


void JSlove_systemSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_systemCreateClass();

 

/**
 * love_system::getVersion 
 */
v8::Handle<v8::Value> JSlove_systemGetVersion(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	char* ret = (char*)love_system::getVersion();
	return v8::String::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_system::getCodename 
 */
v8::Handle<v8::Value> JSlove_systemGetCodename(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	char* ret = (char*)love_system::getCodename();
	return v8::String::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_system::getPlatform 
 */
v8::Handle<v8::Value> JSlove_systemGetPlatform(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	char* ret = (char*)love_system::getPlatform();
	return v8::String::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_system::exit 
 */
v8::Handle<v8::Value> JSlove_systemExit(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_system::exit();
		
	}
	return v8::Undefined();
}


/**
 * love_system::restart 
 */
v8::Handle<v8::Value> JSlove_systemRestart(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_system::restart();
		
	}
	return v8::Undefined();
}


/**
 * love_system::suspend 
 */
v8::Handle<v8::Value> JSlove_systemSuspend(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_system::suspend();
		
	}
	return v8::Undefined();
}


/**
 * love_system::resume 
 */
v8::Handle<v8::Value> JSlove_systemResume(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_system::resume();
		
	}
	return v8::Undefined();
}


/**
 * love_system::grabInput 
 */
v8::Handle<v8::Value> JSlove_systemGrabInput(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool grab = args[0]->BooleanValue();
	love_system::grabInput(grab);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_systemSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getVersion"), v8::FunctionTemplate::New(JSlove_systemGetVersion));
	js_obj->Set(v8::String::New("getCodename"), v8::FunctionTemplate::New(JSlove_systemGetCodename));
	js_obj->Set(v8::String::New("getPlatform"), v8::FunctionTemplate::New(JSlove_systemGetPlatform));
	js_obj->Set(v8::String::New("exit"), v8::FunctionTemplate::New(JSlove_systemExit));
	js_obj->Set(v8::String::New("restart"), v8::FunctionTemplate::New(JSlove_systemRestart));
	js_obj->Set(v8::String::New("suspend"), v8::FunctionTemplate::New(JSlove_systemSuspend));
	js_obj->Set(v8::String::New("resume"), v8::FunctionTemplate::New(JSlove_systemResume));
	js_obj->Set(v8::String::New("grabInput"), v8::FunctionTemplate::New(JSlove_systemGrabInput));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_systemCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("system"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_systemSetupClass(js_obj);
	return js_obj;
}



