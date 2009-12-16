#include <v8.h>
#include "../v8Object.h"
#include "../../src/sdljoystick/love_sdljoystick.h"

using namespace love_sdljoystick;

// extern

// forward declaractions
v8::Handle<v8::Value> JSBallWrap(Ball cppObject);
Ball JSBallUnwrap(v8::Handle<v8::Value> value);


void JSlove_sdljoystickSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_sdljoystickCreateClass();

 

/**
 * love_sdljoystick::getName 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetName(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	char* ret = (char*)love_sdljoystick::getName(joystick);
	return v8::String::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getNumJoysticks 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetNumJoysticks(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_sdljoystick::getNumJoysticks();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getNumAxes 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetNumAxes(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	int ret = (int)love_sdljoystick::getNumAxes(joystick);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getNumBalls 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetNumBalls(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	int ret = (int)love_sdljoystick::getNumBalls(joystick);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getNumButtons 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetNumButtons(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	int ret = (int)love_sdljoystick::getNumButtons(joystick);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getNumHats 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetNumHats(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	int ret = (int)love_sdljoystick::getNumHats(joystick);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::isDown 
 */
v8::Handle<v8::Value> JSlove_sdljoystickIsDown(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
			int button = args[1]->Int32Value();
	bool ret = (bool)love_sdljoystick::isDown(joystick,button);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getAxis 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetAxis(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
			int axis = args[1]->Int32Value();
	int ret = (int)love_sdljoystick::getAxis(joystick,axis);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getBall 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetBall(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
			int ball = args[1]->Int32Value();
	Ball ret = (Ball)love_sdljoystick::getBall(joystick,ball);
	return JSBallWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::getHat 
 */
v8::Handle<v8::Value> JSlove_sdljoystickGetHat(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
			int viewhat = args[1]->Int32Value();
	int ret = (int)love_sdljoystick::getHat(joystick,viewhat);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::open 
 */
v8::Handle<v8::Value> JSlove_sdljoystickOpen(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	love_sdljoystick::open(joystick);
		
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::isOpen 
 */
v8::Handle<v8::Value> JSlove_sdljoystickIsOpen(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	bool ret = (bool)love_sdljoystick::isOpen(joystick);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdljoystick::close 
 */
v8::Handle<v8::Value> JSlove_sdljoystickClose(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int joystick = args[0]->Int32Value();
	love_sdljoystick::close(joystick);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_sdljoystickSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getName"), v8::FunctionTemplate::New(JSlove_sdljoystickGetName));
	js_obj->Set(v8::String::New("getNumJoysticks"), v8::FunctionTemplate::New(JSlove_sdljoystickGetNumJoysticks));
	js_obj->Set(v8::String::New("getNumAxes"), v8::FunctionTemplate::New(JSlove_sdljoystickGetNumAxes));
	js_obj->Set(v8::String::New("getNumBalls"), v8::FunctionTemplate::New(JSlove_sdljoystickGetNumBalls));
	js_obj->Set(v8::String::New("getNumButtons"), v8::FunctionTemplate::New(JSlove_sdljoystickGetNumButtons));
	js_obj->Set(v8::String::New("getNumHats"), v8::FunctionTemplate::New(JSlove_sdljoystickGetNumHats));
	js_obj->Set(v8::String::New("isDown"), v8::FunctionTemplate::New(JSlove_sdljoystickIsDown));
	js_obj->Set(v8::String::New("getAxis"), v8::FunctionTemplate::New(JSlove_sdljoystickGetAxis));
	js_obj->Set(v8::String::New("getBall"), v8::FunctionTemplate::New(JSlove_sdljoystickGetBall));
	js_obj->Set(v8::String::New("getHat"), v8::FunctionTemplate::New(JSlove_sdljoystickGetHat));
	js_obj->Set(v8::String::New("open"), v8::FunctionTemplate::New(JSlove_sdljoystickOpen));
	js_obj->Set(v8::String::New("isOpen"), v8::FunctionTemplate::New(JSlove_sdljoystickIsOpen));
	js_obj->Set(v8::String::New("close"), v8::FunctionTemplate::New(JSlove_sdljoystickClose));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_sdljoystickCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("joystick"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_sdljoystickSetupClass(js_obj);
	return js_obj;
}



/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSBallWrap(Ball cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("x"),v8::Integer::New(cobj.x), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("y"),v8::Integer::New(cobj.y), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Ball JSBallUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Ball cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.x = obj->Get(v8::String::New("x"))->Int32Value();
		
		cobj.y = obj->Get(v8::String::New("y"))->Int32Value();
		
	}
	return cobj;
	}
