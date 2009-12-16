#include <v8.h>
#include "../v8Object.h"
#include "../../src/sdlmouse/love_sdlmouse.h"

using namespace love_sdlmouse;

// extern

// forward declaractions
v8::Handle<v8::Value> JSMouseWrap(Mouse cppObject);
Mouse JSMouseUnwrap(v8::Handle<v8::Value> value);


void JSlove_sdlmouseSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_sdlmouseCreateClass();

 

/**
 * love_sdlmouse::getX 
 */
v8::Handle<v8::Value> JSlove_sdlmouseGetX(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_sdlmouse::getX();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::getY 
 */
v8::Handle<v8::Value> JSlove_sdlmouseGetY(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_sdlmouse::getY();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::getPosition 
 */
v8::Handle<v8::Value> JSlove_sdlmouseGetPosition(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Mouse ret = (Mouse)love_sdlmouse::getPosition();
	return JSMouseWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::setPosition 
 */
v8::Handle<v8::Value> JSlove_sdlmouseSetPosition(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int x = args[0]->Int32Value();
			int y = args[1]->Int32Value();
	love_sdlmouse::setPosition(x,y);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::isDown 
 */
v8::Handle<v8::Value> JSlove_sdlmouseIsDown(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int button = args[0]->Int32Value();
	bool ret = (bool)love_sdlmouse::isDown(button);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::setVisible 
 */
v8::Handle<v8::Value> JSlove_sdlmouseSetVisible(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool visible = args[0]->BooleanValue();
	love_sdlmouse::setVisible(visible);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmouse::isVisible 
 */
v8::Handle<v8::Value> JSlove_sdlmouseIsVisible(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)love_sdlmouse::isVisible();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_sdlmouseSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getX"), v8::FunctionTemplate::New(JSlove_sdlmouseGetX));
	js_obj->Set(v8::String::New("getY"), v8::FunctionTemplate::New(JSlove_sdlmouseGetY));
	js_obj->Set(v8::String::New("getPosition"), v8::FunctionTemplate::New(JSlove_sdlmouseGetPosition));
	js_obj->Set(v8::String::New("setPosition"), v8::FunctionTemplate::New(JSlove_sdlmouseSetPosition));
	js_obj->Set(v8::String::New("isDown"), v8::FunctionTemplate::New(JSlove_sdlmouseIsDown));
	js_obj->Set(v8::String::New("setVisible"), v8::FunctionTemplate::New(JSlove_sdlmouseSetVisible));
	js_obj->Set(v8::String::New("isVisible"), v8::FunctionTemplate::New(JSlove_sdlmouseIsVisible));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_sdlmouseCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("mouse"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_sdlmouseSetupClass(js_obj);
	return js_obj;
}



/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSMouseWrap(Mouse cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("x"),v8::Number::New(cobj.x), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("y"),v8::Number::New(cobj.y), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Mouse JSMouseUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Mouse cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.x = obj->Get(v8::String::New("x"))->NumberValue();
		
		cobj.y = obj->Get(v8::String::New("y"))->NumberValue();
		
	}
	return cobj;
	}
