#include <v8.h>
#include "../v8Object.h"
#include "../../src/opengl/love_opengl.h"
#include "../../src/opengl/image.h"
#include "../../src/opengl/color.h"
#include "../../src/opengl/font.h"
#include "../../src/opengl/animation.h"

using namespace love_opengl;

// extern

// forward declaractions
v8::Handle<v8::Value> JSPointfWrap(Pointf cppObject);
Pointf JSPointfUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSPointfListWrap(PointfList cppObject);
PointfList JSPointfListUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSRectfWrap(Rectf cppObject);
Rectf JSRectfUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSLineStippleWrap(LineStipple cppObject);
LineStipple JSLineStippleUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSDisplayModeWrap(DisplayMode cppObject);
DisplayMode JSDisplayModeUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSDisplayModeListWrap(DisplayModeList cppObject);
DisplayModeList JSDisplayModeListUnwrap(v8::Handle<v8::Value> value);


void JSpImageSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpImageCreateClass();
v8::Handle<v8::Value> JSpImageWrap(pImage cppObject);
pImage JSpImageUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pImage 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpImageDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pImage> *p = static_cast<WrappedObject<pImage>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpImageCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pImage *obj = 0;
		
	if (!obj)
		obj = new pImage;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * SetupClass
 * Attach methods and properties
 */
void JSpImageSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpImageCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpImageCreateInstance);
		js_func->SetClassName(v8::String::New("Image"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpImageSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpImageWrap(pImage cppObject) {
	WrappedObject<pImage> *p = new WrappedObject<pImage>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpImageSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpImageDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pImage JSpImageUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pImage obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pImage> *p = static_cast<WrappedObject<pImage>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpAnimationSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpAnimationCreateClass();
v8::Handle<v8::Value> JSpAnimationWrap(pAnimation cppObject);
pAnimation JSpAnimationUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pAnimation 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpAnimationDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pAnimation> *p = static_cast<WrappedObject<pAnimation>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpAnimationCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pAnimation *obj = 0;
		
	if (!obj)
		obj = new pAnimation;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pAnimation::addFrame 
 */
v8::Handle<v8::Value> JSpAnimationAddFrame(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
			double w = args[2]->NumberValue();
			double h = args[3]->NumberValue();
			int delay = args[4]->Int32Value();
	obj->addFrame(x,y,w,h,delay);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::setMode 
 */
v8::Handle<v8::Value> JSpAnimationSetMode(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int mode = args[0]->Int32Value();
	obj->setMode(mode);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::play 
 */
v8::Handle<v8::Value> JSpAnimationPlay(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->play();
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::stop 
 */
v8::Handle<v8::Value> JSpAnimationStop(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->stop();
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::reset 
 */
v8::Handle<v8::Value> JSpAnimationReset(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->reset();
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::seek 
 */
v8::Handle<v8::Value> JSpAnimationSeek(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int frame = args[0]->Int32Value();
	obj->seek(frame);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::getCurrentFrame 
 */
v8::Handle<v8::Value> JSpAnimationGetCurrentFrame(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getCurrentFrame();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pAnimation::getSize 
 */
v8::Handle<v8::Value> JSpAnimationGetSize(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getSize();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pAnimation::setDelay 
 */
v8::Handle<v8::Value> JSpAnimationSetDelay(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int frame = args[0]->Int32Value();
			int delay = args[1]->Int32Value();
	obj->setDelay(frame,delay);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::setSpeed 
 */
v8::Handle<v8::Value> JSpAnimationSetSpeed(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int speed = args[0]->Int32Value();
	obj->setSpeed(speed);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::getSpeed 
 */
v8::Handle<v8::Value> JSpAnimationGetSpeed(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getSpeed();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pAnimation::getWidth 
 */
v8::Handle<v8::Value> JSpAnimationGetWidth(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getWidth();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pAnimation::getHeight 
 */
v8::Handle<v8::Value> JSpAnimationGetHeight(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getHeight();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pAnimation::setCenter 
 */
v8::Handle<v8::Value> JSpAnimationSetCenter(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	obj->setCenter(x,y);
		
	}
	return v8::Undefined();
}


/**
 * pAnimation::update 
 */
v8::Handle<v8::Value> JSpAnimationUpdate(const v8::Arguments& args) {
		pAnimation obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pAnimation>(JSpAnimationUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double dt = args[0]->NumberValue();
	obj->update(dt);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpAnimationSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("addFrame"), v8::FunctionTemplate::New(JSpAnimationAddFrame));
	js_obj->Set(v8::String::New("setMode"), v8::FunctionTemplate::New(JSpAnimationSetMode));
	js_obj->Set(v8::String::New("play"), v8::FunctionTemplate::New(JSpAnimationPlay));
	js_obj->Set(v8::String::New("stop"), v8::FunctionTemplate::New(JSpAnimationStop));
	js_obj->Set(v8::String::New("reset"), v8::FunctionTemplate::New(JSpAnimationReset));
	js_obj->Set(v8::String::New("seek"), v8::FunctionTemplate::New(JSpAnimationSeek));
	js_obj->Set(v8::String::New("getCurrentFrame"), v8::FunctionTemplate::New(JSpAnimationGetCurrentFrame));
	js_obj->Set(v8::String::New("getSize"), v8::FunctionTemplate::New(JSpAnimationGetSize));
	js_obj->Set(v8::String::New("setDelay"), v8::FunctionTemplate::New(JSpAnimationSetDelay));
	js_obj->Set(v8::String::New("setSpeed"), v8::FunctionTemplate::New(JSpAnimationSetSpeed));
	js_obj->Set(v8::String::New("getSpeed"), v8::FunctionTemplate::New(JSpAnimationGetSpeed));
	js_obj->Set(v8::String::New("getWidth"), v8::FunctionTemplate::New(JSpAnimationGetWidth));
	js_obj->Set(v8::String::New("getHeight"), v8::FunctionTemplate::New(JSpAnimationGetHeight));
	js_obj->Set(v8::String::New("setCenter"), v8::FunctionTemplate::New(JSpAnimationSetCenter));
	js_obj->Set(v8::String::New("update"), v8::FunctionTemplate::New(JSpAnimationUpdate));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpAnimationCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpAnimationCreateInstance);
		js_func->SetClassName(v8::String::New("Animation"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpAnimationSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpAnimationWrap(pAnimation cppObject) {
	WrappedObject<pAnimation> *p = new WrappedObject<pAnimation>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpAnimationSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpAnimationDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pAnimation JSpAnimationUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pAnimation obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pAnimation> *p = static_cast<WrappedObject<pAnimation>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpFontSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpFontCreateClass();
v8::Handle<v8::Value> JSpFontWrap(pFont cppObject);
pFont JSpFontUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pFont 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpFontDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pFont> *p = static_cast<WrappedObject<pFont>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpFontCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pFont *obj = 0;
		
	if (!obj)
		obj = new pFont;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pFont::getHeight 
 */
v8::Handle<v8::Value> JSpFontGetHeight(const v8::Arguments& args) {
		pFont obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pFont>(JSpFontUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getHeight();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pFont::getWidth 
 */
v8::Handle<v8::Value> JSpFontGetWidth(const v8::Arguments& args) {
		pFont obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pFont>(JSpFontUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* line = *_args0;
	int ret = (int)obj->getWidth(line);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pFont::setLineHeight 
 */
v8::Handle<v8::Value> JSpFontSetLineHeight(const v8::Arguments& args) {
		pFont obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pFont>(JSpFontUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double height = args[0]->NumberValue();
	obj->setLineHeight(height);
		
	}
	return v8::Undefined();
}


/**
 * pFont::getLineHeight 
 */
v8::Handle<v8::Value> JSpFontGetLineHeight(const v8::Arguments& args) {
		pFont obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pFont>(JSpFontUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getLineHeight();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpFontSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getHeight"), v8::FunctionTemplate::New(JSpFontGetHeight));
	js_obj->Set(v8::String::New("getWidth"), v8::FunctionTemplate::New(JSpFontGetWidth));
	js_obj->Set(v8::String::New("setLineHeight"), v8::FunctionTemplate::New(JSpFontSetLineHeight));
	js_obj->Set(v8::String::New("getLineHeight"), v8::FunctionTemplate::New(JSpFontGetLineHeight));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpFontCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpFontCreateInstance);
		js_func->SetClassName(v8::String::New("Font"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpFontSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpFontWrap(pFont cppObject) {
	WrappedObject<pFont> *p = new WrappedObject<pFont>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpFontSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpFontDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pFont JSpFontUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pFont obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pFont> *p = static_cast<WrappedObject<pFont>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpColorSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpColorCreateClass();
v8::Handle<v8::Value> JSpColorWrap(pColor cppObject);
pColor JSpColorUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pColor 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpColorDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pColor> *p = static_cast<WrappedObject<pColor>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpColorCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pColor *obj = 0;
		
	if (!obj)
		obj = new pColor;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * SetupClass
 * Attach methods and properties
 */
void JSpColorSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpColorCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpColorCreateInstance);
		js_func->SetClassName(v8::String::New("Color"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpColorSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpColorWrap(pColor cppObject) {
	WrappedObject<pColor> *p = new WrappedObject<pColor>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpColorSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpColorDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pColor JSpColorUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pColor obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pColor> *p = static_cast<WrappedObject<pColor>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpParticleSystemSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpParticleSystemCreateClass();
v8::Handle<v8::Value> JSpParticleSystemWrap(pParticleSystem cppObject);
pParticleSystem JSpParticleSystemUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pParticleSystem 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpParticleSystemDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pParticleSystem> *p = static_cast<WrappedObject<pParticleSystem>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpParticleSystemCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pParticleSystem *obj = 0;
		
	if (!obj)
		obj = new pParticleSystem;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pParticleSystem::setBufferSize 
 */
v8::Handle<v8::Value> JSpParticleSystemSetBufferSize(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int size = args[0]->Int32Value();
	obj->setBufferSize(size);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSprite 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSprite(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pImage sprite = JSpImageUnwrap(args[0]->ToObject());
	obj->setSprite(sprite);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setEmissionRate 
 */
v8::Handle<v8::Value> JSpParticleSystemSetEmissionRate(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int rate = args[0]->Int32Value();
	obj->setEmissionRate(rate);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setLifetime 
 */
v8::Handle<v8::Value> JSpParticleSystemSetLifetime(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int life = args[0]->Int32Value();
	obj->setLifetime(life);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setParticleLife 
 */
v8::Handle<v8::Value> JSpParticleSystemSetParticleLife(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int life = args[0]->Int32Value();
	obj->setParticleLife(life);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int min = args[0]->Int32Value();
			int max = args[1]->Int32Value();
	obj->setParticleLife(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setPosition 
 */
v8::Handle<v8::Value> JSpParticleSystemSetPosition(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	obj->setPosition(x,y);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setDirection 
 */
v8::Handle<v8::Value> JSpParticleSystemSetDirection(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double direction = args[0]->NumberValue();
	obj->setDirection(direction);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSpread 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSpread(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double spread = args[0]->NumberValue();
	obj->setSpread(spread);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSpeed 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSpeed(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double speed = args[0]->NumberValue();
	obj->setSpeed(speed);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double min = args[0]->NumberValue();
			double max = args[1]->NumberValue();
	obj->setSpeed(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setGravity 
 */
v8::Handle<v8::Value> JSpParticleSystemSetGravity(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double gravity = args[0]->NumberValue();
	obj->setGravity(gravity);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double min = args[0]->NumberValue();
			double max = args[1]->NumberValue();
	obj->setGravity(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setRadialAcceleration 
 */
v8::Handle<v8::Value> JSpParticleSystemSetRadialAcceleration(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double acceleration = args[0]->NumberValue();
	obj->setRadialAcceleration(acceleration);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double min = args[0]->NumberValue();
			double max = args[1]->NumberValue();
	obj->setRadialAcceleration(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setTangentialAcceleration 
 */
v8::Handle<v8::Value> JSpParticleSystemSetTangentialAcceleration(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double acceleration = args[0]->NumberValue();
	obj->setTangentialAcceleration(acceleration);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double min = args[0]->NumberValue();
			double max = args[1]->NumberValue();
	obj->setTangentialAcceleration(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSize 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSize(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double size = args[0]->NumberValue();
	obj->setSize(size);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double start = args[0]->NumberValue();
			double end = args[1]->NumberValue();
	obj->setSize(start,end);
		
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			double start = args[0]->NumberValue();
			double end = args[1]->NumberValue();
			double variation = args[2]->NumberValue();
	obj->setSize(start,end,variation);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSizeVariation 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSizeVariation(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double variation = args[0]->NumberValue();
	obj->setSizeVariation(variation);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setRotation 
 */
v8::Handle<v8::Value> JSpParticleSystemSetRotation(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double rotation = args[0]->NumberValue();
	obj->setRotation(rotation);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double min = args[0]->NumberValue();
			double max = args[1]->NumberValue();
	obj->setRotation(min,max);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSpin 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSpin(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double size = args[0]->NumberValue();
	obj->setSpin(size);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double start = args[0]->NumberValue();
			double end = args[1]->NumberValue();
	obj->setSpin(start,end);
		
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			double start = args[0]->NumberValue();
			double end = args[1]->NumberValue();
			double variation = args[2]->NumberValue();
	obj->setSpin(start,end,variation);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setSpinVariation 
 */
v8::Handle<v8::Value> JSpParticleSystemSetSpinVariation(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double variation = args[0]->NumberValue();
	obj->setSpinVariation(variation);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::setColor 
 */
v8::Handle<v8::Value> JSpParticleSystemSetColor(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pColor color = JSpColorUnwrap(args[0]->ToObject());
	obj->setColor(color);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pColor start = JSpColorUnwrap(args[0]->ToObject());
			pColor end = JSpColorUnwrap(args[1]->ToObject());
	obj->setColor(start,end);
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::getX 
 */
v8::Handle<v8::Value> JSpParticleSystemGetX(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getX();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::getY 
 */
v8::Handle<v8::Value> JSpParticleSystemGetY(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getY();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::getDirection 
 */
v8::Handle<v8::Value> JSpParticleSystemGetDirection(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getDirection();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::getSpread 
 */
v8::Handle<v8::Value> JSpParticleSystemGetSpread(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getSpread();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::count 
 */
v8::Handle<v8::Value> JSpParticleSystemCount(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->count();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::start 
 */
v8::Handle<v8::Value> JSpParticleSystemStart(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->start();
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::stop 
 */
v8::Handle<v8::Value> JSpParticleSystemStop(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->stop();
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::pause 
 */
v8::Handle<v8::Value> JSpParticleSystemPause(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->pause();
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::reset 
 */
v8::Handle<v8::Value> JSpParticleSystemReset(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->reset();
		
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::isActive 
 */
v8::Handle<v8::Value> JSpParticleSystemIsActive(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isActive();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::isEmpty 
 */
v8::Handle<v8::Value> JSpParticleSystemIsEmpty(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isEmpty();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::isFull 
 */
v8::Handle<v8::Value> JSpParticleSystemIsFull(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isFull();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pParticleSystem::update 
 */
v8::Handle<v8::Value> JSpParticleSystemUpdate(const v8::Arguments& args) {
		pParticleSystem obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pParticleSystem>(JSpParticleSystemUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double dt = args[0]->NumberValue();
	obj->update(dt);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpParticleSystemSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("setBufferSize"), v8::FunctionTemplate::New(JSpParticleSystemSetBufferSize));
	js_obj->Set(v8::String::New("setSprite"), v8::FunctionTemplate::New(JSpParticleSystemSetSprite));
	js_obj->Set(v8::String::New("setEmissionRate"), v8::FunctionTemplate::New(JSpParticleSystemSetEmissionRate));
	js_obj->Set(v8::String::New("setLifetime"), v8::FunctionTemplate::New(JSpParticleSystemSetLifetime));
	js_obj->Set(v8::String::New("setParticleLife"), v8::FunctionTemplate::New(JSpParticleSystemSetParticleLife));
	js_obj->Set(v8::String::New("setPosition"), v8::FunctionTemplate::New(JSpParticleSystemSetPosition));
	js_obj->Set(v8::String::New("setDirection"), v8::FunctionTemplate::New(JSpParticleSystemSetDirection));
	js_obj->Set(v8::String::New("setSpread"), v8::FunctionTemplate::New(JSpParticleSystemSetSpread));
	js_obj->Set(v8::String::New("setSpeed"), v8::FunctionTemplate::New(JSpParticleSystemSetSpeed));
	js_obj->Set(v8::String::New("setGravity"), v8::FunctionTemplate::New(JSpParticleSystemSetGravity));
	js_obj->Set(v8::String::New("setRadialAcceleration"), v8::FunctionTemplate::New(JSpParticleSystemSetRadialAcceleration));
	js_obj->Set(v8::String::New("setTangentialAcceleration"), v8::FunctionTemplate::New(JSpParticleSystemSetTangentialAcceleration));
	js_obj->Set(v8::String::New("setSize"), v8::FunctionTemplate::New(JSpParticleSystemSetSize));
	js_obj->Set(v8::String::New("setSizeVariation"), v8::FunctionTemplate::New(JSpParticleSystemSetSizeVariation));
	js_obj->Set(v8::String::New("setRotation"), v8::FunctionTemplate::New(JSpParticleSystemSetRotation));
	js_obj->Set(v8::String::New("setSpin"), v8::FunctionTemplate::New(JSpParticleSystemSetSpin));
	js_obj->Set(v8::String::New("setSpinVariation"), v8::FunctionTemplate::New(JSpParticleSystemSetSpinVariation));
	js_obj->Set(v8::String::New("setColor"), v8::FunctionTemplate::New(JSpParticleSystemSetColor));
	js_obj->Set(v8::String::New("getX"), v8::FunctionTemplate::New(JSpParticleSystemGetX));
	js_obj->Set(v8::String::New("getY"), v8::FunctionTemplate::New(JSpParticleSystemGetY));
	js_obj->Set(v8::String::New("getDirection"), v8::FunctionTemplate::New(JSpParticleSystemGetDirection));
	js_obj->Set(v8::String::New("getSpread"), v8::FunctionTemplate::New(JSpParticleSystemGetSpread));
	js_obj->Set(v8::String::New("count"), v8::FunctionTemplate::New(JSpParticleSystemCount));
	js_obj->Set(v8::String::New("start"), v8::FunctionTemplate::New(JSpParticleSystemStart));
	js_obj->Set(v8::String::New("stop"), v8::FunctionTemplate::New(JSpParticleSystemStop));
	js_obj->Set(v8::String::New("pause"), v8::FunctionTemplate::New(JSpParticleSystemPause));
	js_obj->Set(v8::String::New("reset"), v8::FunctionTemplate::New(JSpParticleSystemReset));
	js_obj->Set(v8::String::New("isActive"), v8::FunctionTemplate::New(JSpParticleSystemIsActive));
	js_obj->Set(v8::String::New("isEmpty"), v8::FunctionTemplate::New(JSpParticleSystemIsEmpty));
	js_obj->Set(v8::String::New("isFull"), v8::FunctionTemplate::New(JSpParticleSystemIsFull));
	js_obj->Set(v8::String::New("update"), v8::FunctionTemplate::New(JSpParticleSystemUpdate));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpParticleSystemCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpParticleSystemCreateInstance);
		js_func->SetClassName(v8::String::New("ParticleSystem"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpParticleSystemSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpParticleSystemWrap(pParticleSystem cppObject) {
	WrappedObject<pParticleSystem> *p = new WrappedObject<pParticleSystem>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpParticleSystemSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpParticleSystemDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pParticleSystem JSpParticleSystemUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pParticleSystem obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pParticleSystem> *p = static_cast<WrappedObject<pParticleSystem>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSlove_openglSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_openglCreateClass();

 

/**
 * love_opengl::newImage 
 */
v8::Handle<v8::Value> JSlove_openglNewImage(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	pImage ret = (pImage)love_opengl::newImage(filename);
	return JSpImageWrap(ret);	
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
			int mode = args[1]->Int32Value();
	pImage ret = (pImage)love_opengl::newImage(filename,mode);
	return JSpImageWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::newAnimation 
 */
v8::Handle<v8::Value> JSlove_openglNewAnimation(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
	pAnimation ret = (pAnimation)love_opengl::newAnimation(image);
	return JSpAnimationWrap(ret);	
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			int fw = args[1]->Int32Value();
			int fh = args[2]->Int32Value();
			int delay = args[3]->Int32Value();
			int frames = args[4]->Int32Value();
	pAnimation ret = (pAnimation)love_opengl::newAnimation(image,fw,fh,delay,frames);
	return JSpAnimationWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::newColor 
 */
v8::Handle<v8::Value> JSlove_openglNewColor(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			int red = args[0]->Int32Value();
			int green = args[1]->Int32Value();
			int blue = args[2]->Int32Value();
			int alpha = args[3]->Int32Value();
	pColor ret = (pColor)love_opengl::newColor(red,green,blue,alpha);
	return JSpColorWrap(ret);	
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			int red = args[0]->Int32Value();
			int green = args[1]->Int32Value();
			int blue = args[2]->Int32Value();
	pColor ret = (pColor)love_opengl::newColor(red,green,blue);
	return JSpColorWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::newFont 
 */
v8::Handle<v8::Value> JSlove_openglNewFont(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	pFont ret = (pFont)love_opengl::newFont(filename);
	return JSpFontWrap(ret);	
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
			int size = args[1]->Int32Value();
	pFont ret = (pFont)love_opengl::newFont(filename,size);
	return JSpFontWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::newImageFont 
 */
v8::Handle<v8::Value> JSlove_openglNewImageFont(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
		v8::String::Utf8Value _args1(args[1]);	char* glyphs = *_args1;
	pFont ret = (pFont)love_opengl::newImageFont(filename,glyphs);
	return JSpFontWrap(ret);	
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
		v8::String::Utf8Value _args1(args[1]);	char* glyphs = *_args1;
			int spacing = args[2]->Int32Value();
	pFont ret = (pFont)love_opengl::newImageFont(filename,glyphs,spacing);
	return JSpFontWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::newParticleSystem 
 */
v8::Handle<v8::Value> JSlove_openglNewParticleSystem(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			int buffer = args[1]->Int32Value();
	pParticleSystem ret = (pParticleSystem)love_opengl::newParticleSystem(image,buffer);
	return JSpParticleSystemWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::checkMode 
 */
v8::Handle<v8::Value> JSlove_openglCheckMode(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			int width = args[0]->Int32Value();
			int height = args[1]->Int32Value();
			bool fullscreen = args[2]->BooleanValue();
	bool ret = (bool)love_opengl::checkMode(width,height,fullscreen);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::setMode 
 */
v8::Handle<v8::Value> JSlove_openglSetMode(const v8::Arguments& args) {
					
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			int width = args[0]->Int32Value();
			int height = args[1]->Int32Value();
			bool fullscreen = args[2]->BooleanValue();
			bool vsync = args[3]->BooleanValue();
			bool fsaa = args[4]->BooleanValue();
	love_opengl::setMode(width,height,fullscreen,vsync,fsaa);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::toggleFullscreen 
 */
v8::Handle<v8::Value> JSlove_openglToggleFullscreen(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_opengl::toggleFullscreen();
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::isCreated 
 */
v8::Handle<v8::Value> JSlove_openglIsCreated(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)love_opengl::isCreated();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getModes 
 */
v8::Handle<v8::Value> JSlove_openglGetModes(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	DisplayModeList ret = (DisplayModeList)love_opengl::getModes();
	return JSDisplayModeListWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::setCaption 
 */
v8::Handle<v8::Value> JSlove_openglSetCaption(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* caption = *_args0;
	love_opengl::setCaption(caption);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setColor 
 */
v8::Handle<v8::Value> JSlove_openglSetColor(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pColor color = JSpColorUnwrap(args[0]->ToObject());
	love_opengl::setColor(color);
		
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			int red = args[0]->Int32Value();
			int green = args[1]->Int32Value();
			int blue = args[2]->Int32Value();
	love_opengl::setColor(red,green,blue);
		
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			int red = args[0]->Int32Value();
			int green = args[1]->Int32Value();
			int blue = args[2]->Int32Value();
			int alpha = args[3]->Int32Value();
	love_opengl::setColor(red,green,blue,alpha);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setBackgroundColor 
 */
v8::Handle<v8::Value> JSlove_openglSetBackgroundColor(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pColor color = JSpColorUnwrap(args[0]->ToObject());
	love_opengl::setBackgroundColor(color);
		
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			int red = args[0]->Int32Value();
			int green = args[1]->Int32Value();
			int blue = args[2]->Int32Value();
	love_opengl::setBackgroundColor(red,green,blue);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setFont 
 */
v8::Handle<v8::Value> JSlove_openglSetFont(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int font = args[0]->Int32Value();
	love_opengl::setFont(font);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
			double size = args[1]->NumberValue();
	love_opengl::setFont(filename,size);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setLineWidth 
 */
v8::Handle<v8::Value> JSlove_openglSetLineWidth(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double width = args[0]->NumberValue();
	love_opengl::setLineWidth(width);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setLineStyle 
 */
v8::Handle<v8::Value> JSlove_openglSetLineStyle(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double style = args[0]->NumberValue();
	love_opengl::setLineStyle(style);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setLine 
 */
v8::Handle<v8::Value> JSlove_openglSetLine(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double width = args[0]->NumberValue();
	love_opengl::setLine(width);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double width = args[0]->NumberValue();
			double type = args[1]->NumberValue();
	love_opengl::setLine(width,type);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setLineStipple 
 */
v8::Handle<v8::Value> JSlove_openglSetLineStipple(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_opengl::setLineStipple();
		
	}
	
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int pattern = args[0]->Int32Value();
	love_opengl::setLineStipple(pattern);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int pattern = args[0]->Int32Value();
			double repeat = args[1]->NumberValue();
	love_opengl::setLineStipple(pattern,repeat);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::getLineWidth 
 */
v8::Handle<v8::Value> JSlove_openglGetLineWidth(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getLineWidth();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getLineStyle 
 */
v8::Handle<v8::Value> JSlove_openglGetLineStyle(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getLineStyle();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getLineStipple 
 */
v8::Handle<v8::Value> JSlove_openglGetLineStipple(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	LineStipple ret = (LineStipple)love_opengl::getLineStipple();
	return JSLineStippleWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::setPointSize 
 */
v8::Handle<v8::Value> JSlove_openglSetPointSize(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double size = args[0]->NumberValue();
	love_opengl::setPointSize(size);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setPointStyle 
 */
v8::Handle<v8::Value> JSlove_openglSetPointStyle(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double style = args[0]->NumberValue();
	love_opengl::setPointStyle(style);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setPoint 
 */
v8::Handle<v8::Value> JSlove_openglSetPoint(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double size = args[0]->NumberValue();
			double style = args[1]->NumberValue();
	love_opengl::setPoint(size,style);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::getPointSize 
 */
v8::Handle<v8::Value> JSlove_openglGetPointSize(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getPointSize();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getPointStyle 
 */
v8::Handle<v8::Value> JSlove_openglGetPointStyle(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getPointStyle();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getMaxPointSize 
 */
v8::Handle<v8::Value> JSlove_openglGetMaxPointSize(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getMaxPointSize();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::setBlendMode 
 */
v8::Handle<v8::Value> JSlove_openglSetBlendMode(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double mode = args[0]->NumberValue();
	love_opengl::setBlendMode(mode);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::setColorMode 
 */
v8::Handle<v8::Value> JSlove_openglSetColorMode(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double mode = args[0]->NumberValue();
	love_opengl::setColorMode(mode);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::getBlendMode 
 */
v8::Handle<v8::Value> JSlove_openglGetBlendMode(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getBlendMode();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getColorMode 
 */
v8::Handle<v8::Value> JSlove_openglGetColorMode(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getColorMode();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getColor 
 */
v8::Handle<v8::Value> JSlove_openglGetColor(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	pColor ret = (pColor)love_opengl::getColor();
	return JSpColorWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getBackgroundColor 
 */
v8::Handle<v8::Value> JSlove_openglGetBackgroundColor(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	pColor ret = (pColor)love_opengl::getBackgroundColor();
	return JSpColorWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getFont 
 */
v8::Handle<v8::Value> JSlove_openglGetFont(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	pFont ret = (pFont)love_opengl::getFont();
	return JSpFontWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getWidth 
 */
v8::Handle<v8::Value> JSlove_openglGetWidth(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getWidth();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::getHeight 
 */
v8::Handle<v8::Value> JSlove_openglGetHeight(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)love_opengl::getHeight();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::setScissor 
 */
v8::Handle<v8::Value> JSlove_openglSetScissor(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
			double width = args[2]->NumberValue();
			double height = args[3]->NumberValue();
	love_opengl::setScissor(x,y,width,height);
		
	}
	
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_opengl::setScissor();
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::getScissor 
 */
v8::Handle<v8::Value> JSlove_openglGetScissor(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Rectf ret = (Rectf)love_opengl::getScissor();
	return JSRectfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_opengl::drawText 
 */
v8::Handle<v8::Value> JSlove_openglDrawText(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
	love_opengl::draw(string,x,y);
		
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
	love_opengl::draw(string,x,y,angle);
		
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
			double s = args[4]->NumberValue();
	love_opengl::draw(string,x,y,angle,s);
		
	}
	
	if (args.Length() == 6) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
			double sx = args[4]->NumberValue();
			double sy = args[5]->NumberValue();
	love_opengl::draw(string,x,y,angle,sx,sy);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::drawImage 
 */
v8::Handle<v8::Value> JSlove_openglDrawImage(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			pImage sprite = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
	love_opengl::draw(sprite,x,y);
		
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			pImage sprite = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
	love_opengl::draw(sprite,x,y,angle);
		
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			pImage sprite = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
			double s = args[4]->NumberValue();
	love_opengl::draw(sprite,x,y,angle,s);
		
	}
	
	if (args.Length() == 6) {
	v8::HandleScope handle_scope;
			pImage sprite = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double angle = args[3]->NumberValue();
			double sx = args[4]->NumberValue();
			double sy = args[5]->NumberValue();
	love_opengl::draw(sprite,x,y,angle,sx,sy);
		
	}
	
	if (args.Length() == 7) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double cx = args[3]->NumberValue();
			double cy = args[4]->NumberValue();
			double w = args[5]->NumberValue();
			double h = args[6]->NumberValue();
	love_opengl::draws(image,x,y,cx,cy,w,h);
		
	}
	
	if (args.Length() == 8) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double cx = args[3]->NumberValue();
			double cy = args[4]->NumberValue();
			double w = args[5]->NumberValue();
			double h = args[6]->NumberValue();
			double angle = args[7]->NumberValue();
	love_opengl::draws(image,x,y,cx,cy,w,h,angle);
		
	}
	
	if (args.Length() == 9) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double cx = args[3]->NumberValue();
			double cy = args[4]->NumberValue();
			double w = args[5]->NumberValue();
			double h = args[6]->NumberValue();
			double angle = args[7]->NumberValue();
			double s = args[8]->NumberValue();
	love_opengl::draws(image,x,y,cx,cy,w,h,angle,s);
		
	}
	
	if (args.Length() == 10) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double cx = args[3]->NumberValue();
			double cy = args[4]->NumberValue();
			double w = args[5]->NumberValue();
			double h = args[6]->NumberValue();
			double angle = args[7]->NumberValue();
			double sx = args[8]->NumberValue();
			double sy = args[9]->NumberValue();
	love_opengl::draws(image,x,y,cx,cy,w,h,angle,sx,sy);
		
	}
	
	if (args.Length() == 12) {
	v8::HandleScope handle_scope;
			pImage image = JSpImageUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double cx = args[3]->NumberValue();
			double cy = args[4]->NumberValue();
			double w = args[5]->NumberValue();
			double h = args[6]->NumberValue();
			double angle = args[7]->NumberValue();
			double sx = args[8]->NumberValue();
			double sy = args[9]->NumberValue();
			double ox = args[10]->NumberValue();
			double oy = args[11]->NumberValue();
	love_opengl::draws(image,x,y,cx,cy,w,h,angle,sx,sy,ox,oy);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::drawParticleSystem 
 */
v8::Handle<v8::Value> JSlove_openglDrawParticleSystem(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			pParticleSystem particles = JSpParticleSystemUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
	love_opengl::draw(particles,x,y);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::drawFormattedText 
 */
v8::Handle<v8::Value> JSlove_openglDrawFormattedText(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			int limit = args[3]->Int32Value();
	love_opengl::drawf(string,x,y,limit);
		
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* string = *_args0;
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			int limit = args[3]->Int32Value();
			int align = args[4]->Int32Value();
	love_opengl::drawf(string,x,y,limit,align);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::point 
 */
v8::Handle<v8::Value> JSlove_openglPoint(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	love_opengl::point(x,y);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::line 
 */
v8::Handle<v8::Value> JSlove_openglLine(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double x1 = args[0]->NumberValue();
			double y1 = args[1]->NumberValue();
			double x2 = args[2]->NumberValue();
			double y2 = args[3]->NumberValue();
	love_opengl::line(x1,y1,x2,y2);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::triangle 
 */
v8::Handle<v8::Value> JSlove_openglTriangle(const v8::Arguments& args) {
					
	if (args.Length() == 7) {
	v8::HandleScope handle_scope;
			double type = args[0]->NumberValue();
			double x1 = args[1]->NumberValue();
			double y1 = args[2]->NumberValue();
			double x2 = args[3]->NumberValue();
			double y2 = args[4]->NumberValue();
			double x3 = args[5]->NumberValue();
			double y3 = args[6]->NumberValue();
	love_opengl::triangle(type,x1,y1,x2,y2,x3,y3);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::rectangle 
 */
v8::Handle<v8::Value> JSlove_openglRectangle(const v8::Arguments& args) {
					
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			double type = args[0]->NumberValue();
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double w = args[3]->NumberValue();
			double h = args[4]->NumberValue();
	love_opengl::rectangle(type,x,y,w,h);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::quad 
 */
v8::Handle<v8::Value> JSlove_openglQuad(const v8::Arguments& args) {
					
	if (args.Length() == 9) {
	v8::HandleScope handle_scope;
			double type = args[0]->NumberValue();
			double x1 = args[1]->NumberValue();
			double y1 = args[2]->NumberValue();
			double x2 = args[3]->NumberValue();
			double y2 = args[4]->NumberValue();
			double x3 = args[5]->NumberValue();
			double y3 = args[6]->NumberValue();
			double x4 = args[7]->NumberValue();
			double y4 = args[8]->NumberValue();
	love_opengl::quad(type,x1,y1,x2,y2,x3,y3,x4,y4);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::circle 
 */
v8::Handle<v8::Value> JSlove_openglCircle(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double type = args[0]->NumberValue();
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double radius = args[3]->NumberValue();
	love_opengl::circle(type,x,y,radius);
		
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			double type = args[0]->NumberValue();
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double radius = args[3]->NumberValue();
			double points = args[4]->NumberValue();
	love_opengl::circle(type,x,y,radius,points);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::polygon 
 */
v8::Handle<v8::Value> JSlove_openglPolygon(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			int type = args[0]->Int32Value();
			PointfList points = JSPointfListUnwrap(args[1]->ToObject());
	love_opengl::polygon(type,points);
		
	}
	return v8::Undefined();
}


/**
 * love_opengl::screenshot 
 */
v8::Handle<v8::Value> JSlove_openglScreenshot(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	love_opengl::screenshot(filename);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_openglSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("newImage"), v8::FunctionTemplate::New(JSlove_openglNewImage));
	js_obj->Set(v8::String::New("newAnimation"), v8::FunctionTemplate::New(JSlove_openglNewAnimation));
	js_obj->Set(v8::String::New("newColor"), v8::FunctionTemplate::New(JSlove_openglNewColor));
	js_obj->Set(v8::String::New("newFont"), v8::FunctionTemplate::New(JSlove_openglNewFont));
	js_obj->Set(v8::String::New("newImageFont"), v8::FunctionTemplate::New(JSlove_openglNewImageFont));
	js_obj->Set(v8::String::New("newParticleSystem"), v8::FunctionTemplate::New(JSlove_openglNewParticleSystem));
	js_obj->Set(v8::String::New("checkMode"), v8::FunctionTemplate::New(JSlove_openglCheckMode));
	js_obj->Set(v8::String::New("setMode"), v8::FunctionTemplate::New(JSlove_openglSetMode));
	js_obj->Set(v8::String::New("toggleFullscreen"), v8::FunctionTemplate::New(JSlove_openglToggleFullscreen));
	js_obj->Set(v8::String::New("isCreated"), v8::FunctionTemplate::New(JSlove_openglIsCreated));
	js_obj->Set(v8::String::New("getModes"), v8::FunctionTemplate::New(JSlove_openglGetModes));
	js_obj->Set(v8::String::New("setCaption"), v8::FunctionTemplate::New(JSlove_openglSetCaption));
	js_obj->Set(v8::String::New("setColor"), v8::FunctionTemplate::New(JSlove_openglSetColor));
	js_obj->Set(v8::String::New("setBackgroundColor"), v8::FunctionTemplate::New(JSlove_openglSetBackgroundColor));
	js_obj->Set(v8::String::New("setFont"), v8::FunctionTemplate::New(JSlove_openglSetFont));
	js_obj->Set(v8::String::New("setLineWidth"), v8::FunctionTemplate::New(JSlove_openglSetLineWidth));
	js_obj->Set(v8::String::New("setLineStyle"), v8::FunctionTemplate::New(JSlove_openglSetLineStyle));
	js_obj->Set(v8::String::New("setLine"), v8::FunctionTemplate::New(JSlove_openglSetLine));
	js_obj->Set(v8::String::New("setLineStipple"), v8::FunctionTemplate::New(JSlove_openglSetLineStipple));
	js_obj->Set(v8::String::New("getLineWidth"), v8::FunctionTemplate::New(JSlove_openglGetLineWidth));
	js_obj->Set(v8::String::New("getLineStyle"), v8::FunctionTemplate::New(JSlove_openglGetLineStyle));
	js_obj->Set(v8::String::New("getLineStipple"), v8::FunctionTemplate::New(JSlove_openglGetLineStipple));
	js_obj->Set(v8::String::New("setPointSize"), v8::FunctionTemplate::New(JSlove_openglSetPointSize));
	js_obj->Set(v8::String::New("setPointStyle"), v8::FunctionTemplate::New(JSlove_openglSetPointStyle));
	js_obj->Set(v8::String::New("setPoint"), v8::FunctionTemplate::New(JSlove_openglSetPoint));
	js_obj->Set(v8::String::New("getPointSize"), v8::FunctionTemplate::New(JSlove_openglGetPointSize));
	js_obj->Set(v8::String::New("getPointStyle"), v8::FunctionTemplate::New(JSlove_openglGetPointStyle));
	js_obj->Set(v8::String::New("getMaxPointSize"), v8::FunctionTemplate::New(JSlove_openglGetMaxPointSize));
	js_obj->Set(v8::String::New("setBlendMode"), v8::FunctionTemplate::New(JSlove_openglSetBlendMode));
	js_obj->Set(v8::String::New("setColorMode"), v8::FunctionTemplate::New(JSlove_openglSetColorMode));
	js_obj->Set(v8::String::New("getBlendMode"), v8::FunctionTemplate::New(JSlove_openglGetBlendMode));
	js_obj->Set(v8::String::New("getColorMode"), v8::FunctionTemplate::New(JSlove_openglGetColorMode));
	js_obj->Set(v8::String::New("getColor"), v8::FunctionTemplate::New(JSlove_openglGetColor));
	js_obj->Set(v8::String::New("getBackgroundColor"), v8::FunctionTemplate::New(JSlove_openglGetBackgroundColor));
	js_obj->Set(v8::String::New("getFont"), v8::FunctionTemplate::New(JSlove_openglGetFont));
	js_obj->Set(v8::String::New("getWidth"), v8::FunctionTemplate::New(JSlove_openglGetWidth));
	js_obj->Set(v8::String::New("getHeight"), v8::FunctionTemplate::New(JSlove_openglGetHeight));
	js_obj->Set(v8::String::New("setScissor"), v8::FunctionTemplate::New(JSlove_openglSetScissor));
	js_obj->Set(v8::String::New("getScissor"), v8::FunctionTemplate::New(JSlove_openglGetScissor));
	js_obj->Set(v8::String::New("drawText"), v8::FunctionTemplate::New(JSlove_openglDrawText));
	js_obj->Set(v8::String::New("drawImage"), v8::FunctionTemplate::New(JSlove_openglDrawImage));
	js_obj->Set(v8::String::New("drawParticleSystem"), v8::FunctionTemplate::New(JSlove_openglDrawParticleSystem));
	js_obj->Set(v8::String::New("drawFormattedText"), v8::FunctionTemplate::New(JSlove_openglDrawFormattedText));
	js_obj->Set(v8::String::New("point"), v8::FunctionTemplate::New(JSlove_openglPoint));
	js_obj->Set(v8::String::New("line"), v8::FunctionTemplate::New(JSlove_openglLine));
	js_obj->Set(v8::String::New("triangle"), v8::FunctionTemplate::New(JSlove_openglTriangle));
	js_obj->Set(v8::String::New("rectangle"), v8::FunctionTemplate::New(JSlove_openglRectangle));
	js_obj->Set(v8::String::New("quad"), v8::FunctionTemplate::New(JSlove_openglQuad));
	js_obj->Set(v8::String::New("circle"), v8::FunctionTemplate::New(JSlove_openglCircle));
	js_obj->Set(v8::String::New("polygon"), v8::FunctionTemplate::New(JSlove_openglPolygon));
	js_obj->Set(v8::String::New("screenshot"), v8::FunctionTemplate::New(JSlove_openglScreenshot));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_openglCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("graphics"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_openglSetupClass(js_obj);
	return js_obj;
}



/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSPointfWrap(Pointf cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("x"),v8::Number::New(cobj.x), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("y"),v8::Number::New(cobj.y), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Pointf JSPointfUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Pointf cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.x = obj->Get(v8::String::New("x"))->NumberValue();
		
		cobj.y = obj->Get(v8::String::New("y"))->NumberValue();
		
	}
	return cobj;
	}
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSPointfListWrap(PointfList cobj) {
		v8::Handle<v8::Array> obj = v8::Array::New();
	
	for(int i = 0; i<cobj.length(); i++) {
		obj->Set(v8::Integer::New(i), JSPointfWrap(cobj.at(i)));
	}
		
	return obj;
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
PointfList JSPointfListUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	PointfList cobj;
	
	cobj.init(0, 0);
	if (value->IsArray()) {
		v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(value);
		if (arr->Length()) {
			cobj.init(new Pointf[arr->Length()],arr->Length());
			for(int i = 0; i<cobj.count; i++) {
				cobj.items[i] = JSPointfUnwrap(arr->Get(v8::Integer::New(i)));
			}
		}
	}
	
	return cobj;
	}
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSRectfWrap(Rectf cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("x"),v8::Number::New(cobj.x), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("y"),v8::Number::New(cobj.y), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("w"),v8::Number::New(cobj.w), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("h"),v8::Number::New(cobj.h), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Rectf JSRectfUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Rectf cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.x = obj->Get(v8::String::New("x"))->NumberValue();
		
		cobj.y = obj->Get(v8::String::New("y"))->NumberValue();
		
		cobj.w = obj->Get(v8::String::New("w"))->NumberValue();
		
		cobj.h = obj->Get(v8::String::New("h"))->NumberValue();
		
	}
	return cobj;
	}
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSLineStippleWrap(LineStipple cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("pattern"),v8::Integer::New(cobj.pattern), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("factor"),v8::Integer::New(cobj.factor), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
LineStipple JSLineStippleUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	LineStipple cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.pattern = obj->Get(v8::String::New("pattern"))->Int32Value();
		
		cobj.factor = obj->Get(v8::String::New("factor"))->Int32Value();
		
	}
	return cobj;
	}
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSDisplayModeWrap(DisplayMode cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("width"),v8::Integer::New(cobj.width), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("height"),v8::Integer::New(cobj.height), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
DisplayMode JSDisplayModeUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	DisplayMode cobj;
		if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
		
		cobj.width = obj->Get(v8::String::New("width"))->Int32Value();
		
		cobj.height = obj->Get(v8::String::New("height"))->Int32Value();
		
	}
	return cobj;
	}
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSDisplayModeListWrap(DisplayModeList cobj) {
		v8::Handle<v8::Array> obj = v8::Array::New();
	
	for(int i = 0; i<cobj.length(); i++) {
		obj->Set(v8::Integer::New(i), JSDisplayModeWrap(cobj.at(i)));
	}
		
	return obj;
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
DisplayModeList JSDisplayModeListUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	DisplayModeList cobj;
	
	cobj.init(0, 0);
	if (value->IsArray()) {
		v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(value);
		if (arr->Length()) {
			cobj.init(new DisplayMode[arr->Length()],arr->Length());
			for(int i = 0; i<cobj.count; i++) {
				cobj.items[i] = JSDisplayModeUnwrap(arr->Get(v8::Integer::New(i)));
			}
		}
	}
	
	return cobj;
	}
