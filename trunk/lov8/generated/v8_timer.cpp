#include <v8.h>
#include "../v8Object.h"
#include "../../src/sdltimer/love_sdltimer.h"


// extern

// forward declaractions


void JSlove_sdltimerSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_sdltimerCreateClass();

 

/**
 * love_sdltimer::getFPS 
 */
v8::Handle<v8::Value> JSlove_sdltimerGetFPS(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)love_sdltimer::getFPS();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdltimer::getDelta 
 */
v8::Handle<v8::Value> JSlove_sdltimerGetDelta(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_sdltimer::getDelta();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdltimer::sleep 
 */
v8::Handle<v8::Value> JSlove_sdltimerSleep(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int ms = args[0]->Int32Value();
	love_sdltimer::sleep(ms);
		
	}
	return v8::Undefined();
}


/**
 * love_sdltimer::getTime 
 */
v8::Handle<v8::Value> JSlove_sdltimerGetTime(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_sdltimer::getTime();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_sdltimerSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getFPS"), v8::FunctionTemplate::New(JSlove_sdltimerGetFPS));
	js_obj->Set(v8::String::New("getDelta"), v8::FunctionTemplate::New(JSlove_sdltimerGetDelta));
	js_obj->Set(v8::String::New("sleep"), v8::FunctionTemplate::New(JSlove_sdltimerSleep));
	js_obj->Set(v8::String::New("getTime"), v8::FunctionTemplate::New(JSlove_sdltimerGetTime));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_sdltimerCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("timer"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_sdltimerSetupClass(js_obj);
	return js_obj;
}



