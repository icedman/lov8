#include <v8.h>
#include "../v8Object.h"
#include "../../src/box2d/love_box2d.h"

using namespace love_box2d;

// extern

// forward declaractions
v8::Handle<v8::Value> JSVec2dfWrap(Vec2df cppObject);
Vec2df JSVec2dfUnwrap(v8::Handle<v8::Value> value);
v8::Handle<v8::Value> JSVec2dfListWrap(Vec2dfList cppObject);
Vec2dfList JSVec2dfListUnwrap(v8::Handle<v8::Value> value);


void JSpWorldSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpWorldCreateClass();
v8::Handle<v8::Value> JSpWorldWrap(pWorld cppObject);
pWorld JSpWorldUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pWorld 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpWorldDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pWorld> *p = static_cast<WrappedObject<pWorld>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpWorldCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pWorld *obj = 0;
		
	if (!obj)
		obj = new pWorld;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pWorld::update 
 */
v8::Handle<v8::Value> JSpWorldUpdate(const v8::Arguments& args) {
		pWorld obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pWorld>(JSpWorldUnwrap(self));		
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
 * pWorld::setGravity 
 */
v8::Handle<v8::Value> JSpWorldSetGravity(const v8::Arguments& args) {
		pWorld obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pWorld>(JSpWorldUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	obj->setGravity(x,y);
		
	}
	return v8::Undefined();
}


/**
 * pWorld::getGravity 
 */
v8::Handle<v8::Value> JSpWorldGetGravity(const v8::Arguments& args) {
		pWorld obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pWorld>(JSpWorldUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getGravity();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pWorld::getBodyCount 
 */
v8::Handle<v8::Value> JSpWorldGetBodyCount(const v8::Arguments& args) {
		pWorld obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pWorld>(JSpWorldUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getBodyCount();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pWorld::getJointCount 
 */
v8::Handle<v8::Value> JSpWorldGetJointCount(const v8::Arguments& args) {
		pWorld obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pWorld>(JSpWorldUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getJointCount();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpWorldSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("update"), v8::FunctionTemplate::New(JSpWorldUpdate));
	js_obj->Set(v8::String::New("setGravity"), v8::FunctionTemplate::New(JSpWorldSetGravity));
	js_obj->Set(v8::String::New("getGravity"), v8::FunctionTemplate::New(JSpWorldGetGravity));
	js_obj->Set(v8::String::New("getBodyCount"), v8::FunctionTemplate::New(JSpWorldGetBodyCount));
	js_obj->Set(v8::String::New("getJointCount"), v8::FunctionTemplate::New(JSpWorldGetJointCount));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpWorldCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpWorldCreateInstance);
		js_func->SetClassName(v8::String::New("World"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpWorldSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpWorldWrap(pWorld cppObject) {
	WrappedObject<pWorld> *p = new WrappedObject<pWorld>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpWorldSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpWorldDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pWorld JSpWorldUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pWorld obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pWorld> *p = static_cast<WrappedObject<pWorld>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpContactSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpContactCreateClass();
v8::Handle<v8::Value> JSpContactWrap(pContact cppObject);
pContact JSpContactUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pContact 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpContactDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pContact> *p = static_cast<WrappedObject<pContact>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpContactCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pContact *obj = 0;
		
	if (!obj)
		obj = new pContact;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pContact::getFriction 
 */
v8::Handle<v8::Value> JSpContactGetFriction(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getFriction();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pContact::getRestitution 
 */
v8::Handle<v8::Value> JSpContactGetRestitution(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getRestitution();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pContact::getSeparation 
 */
v8::Handle<v8::Value> JSpContactGetSeparation(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getSeparation();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pContact::getPosition 
 */
v8::Handle<v8::Value> JSpContactGetPosition(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getPosition();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pContact::getVelocity 
 */
v8::Handle<v8::Value> JSpContactGetVelocity(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getVelocity();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pContact::getNormal 
 */
v8::Handle<v8::Value> JSpContactGetNormal(const v8::Arguments& args) {
		pContact obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pContact>(JSpContactUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getNormal();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpContactSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getFriction"), v8::FunctionTemplate::New(JSpContactGetFriction));
	js_obj->Set(v8::String::New("getRestitution"), v8::FunctionTemplate::New(JSpContactGetRestitution));
	js_obj->Set(v8::String::New("getSeparation"), v8::FunctionTemplate::New(JSpContactGetSeparation));
	js_obj->Set(v8::String::New("getPosition"), v8::FunctionTemplate::New(JSpContactGetPosition));
	js_obj->Set(v8::String::New("getVelocity"), v8::FunctionTemplate::New(JSpContactGetVelocity));
	js_obj->Set(v8::String::New("getNormal"), v8::FunctionTemplate::New(JSpContactGetNormal));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpContactCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpContactCreateInstance);
		js_func->SetClassName(v8::String::New("Contact"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpContactSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpContactWrap(pContact cppObject) {
	WrappedObject<pContact> *p = new WrappedObject<pContact>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpContactSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpContactDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pContact JSpContactUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pContact obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pContact> *p = static_cast<WrappedObject<pContact>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpBodySetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpBodyCreateClass();
v8::Handle<v8::Value> JSpBodyWrap(pBody cppObject);
pBody JSpBodyUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pBody 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpBodyDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pBody> *p = static_cast<WrappedObject<pBody>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpBodyCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pBody *obj = 0;
		
	if (!obj)
		obj = new pBody;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pBody::getX 
 */
v8::Handle<v8::Value> JSpBodyGetX(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
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
 * pBody::getY 
 */
v8::Handle<v8::Value> JSpBodyGetY(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
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
 * pBody::getPosition 
 */
v8::Handle<v8::Value> JSpBodyGetPosition(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getPosition();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getVelocity 
 */
v8::Handle<v8::Value> JSpBodyGetVelocity(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getVelocity();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getAngle 
 */
v8::Handle<v8::Value> JSpBodyGetAngle(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getAngle();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getSpin 
 */
v8::Handle<v8::Value> JSpBodyGetSpin(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getSpin();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getMass 
 */
v8::Handle<v8::Value> JSpBodyGetMass(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMass();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getInertia 
 */
v8::Handle<v8::Value> JSpBodyGetInertia(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getInertia();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getDamping 
 */
v8::Handle<v8::Value> JSpBodyGetDamping(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getDamping();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getAngularDamping 
 */
v8::Handle<v8::Value> JSpBodyGetAngularDamping(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getAngularDamping();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getWorldCenter 
 */
v8::Handle<v8::Value> JSpBodyGetWorldCenter(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getWorldCenter();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getLocalCenter 
 */
v8::Handle<v8::Value> JSpBodyGetLocalCenter(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getLocalCenter();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getWorldPoint 
 */
v8::Handle<v8::Value> JSpBodyGetWorldPoint(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getWorldPoint(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getWorldVector 
 */
v8::Handle<v8::Value> JSpBodyGetWorldVector(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getWorldVector(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getLocalPoint 
 */
v8::Handle<v8::Value> JSpBodyGetLocalPoint(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getLocalPoint(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getLocalVector 
 */
v8::Handle<v8::Value> JSpBodyGetLocalVector(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getLocalVector(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getVelocityWorldPoint 
 */
v8::Handle<v8::Value> JSpBodyGetVelocityWorldPoint(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getVelocityWorldPoint(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::getVelocityLocalPoint 
 */
v8::Handle<v8::Value> JSpBodyGetVelocityLocalPoint(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	Vec2df ret = (Vec2df)obj->getVelocityLocalPoint(x,y);
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::applyImpulse 
 */
v8::Handle<v8::Value> JSpBodyApplyImpulse(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double jx = args[0]->NumberValue();
			double jy = args[1]->NumberValue();
	obj->applyImpulse(jx,jy);
		
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double jx = args[0]->NumberValue();
			double jy = args[1]->NumberValue();
			double rx = args[2]->NumberValue();
			double ry = args[3]->NumberValue();
	obj->applyImpulse(jx,jy,rx,ry);
		
	}
	return v8::Undefined();
}


/**
 * pBody::applyForce 
 */
v8::Handle<v8::Value> JSpBodyApplyForce(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double fx = args[0]->NumberValue();
			double fy = args[1]->NumberValue();
	obj->applyForce(fx,fy);
		
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
			double rx = args[2]->NumberValue();
			double ry = args[3]->NumberValue();
	obj->applyForce(x,y,rx,ry);
		
	}
	return v8::Undefined();
}


/**
 * pBody::applyTorque 
 */
v8::Handle<v8::Value> JSpBodyApplyTorque(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double t = args[0]->NumberValue();
	obj->applyTorque(t);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setX 
 */
v8::Handle<v8::Value> JSpBodySetX(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
	obj->setX(x);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setY 
 */
v8::Handle<v8::Value> JSpBodySetY(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double y = args[0]->NumberValue();
	obj->setY(y);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setPosition 
 */
v8::Handle<v8::Value> JSpBodySetPosition(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
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
 * pBody::setVelocity 
 */
v8::Handle<v8::Value> JSpBodySetVelocity(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	obj->setVelocity(x,y);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setAngle 
 */
v8::Handle<v8::Value> JSpBodySetAngle(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double angle = args[0]->NumberValue();
	obj->setAngle(angle);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setSpin 
 */
v8::Handle<v8::Value> JSpBodySetSpin(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double spin = args[0]->NumberValue();
	obj->setSpin(spin);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setMassFromShapes 
 */
v8::Handle<v8::Value> JSpBodySetMassFromShapes(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	obj->setMassFromShapes();
		
	}
	return v8::Undefined();
}


/**
 * pBody::setMass 
 */
v8::Handle<v8::Value> JSpBodySetMass(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
			double m = args[2]->NumberValue();
			double i = args[3]->NumberValue();
	obj->setMass(x,y,m,i);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setDamping 
 */
v8::Handle<v8::Value> JSpBodySetDamping(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double damping = args[0]->NumberValue();
	obj->setDamping(damping);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setAngularDamping 
 */
v8::Handle<v8::Value> JSpBodySetAngularDamping(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double amping = args[0]->NumberValue();
	obj->setAngularDamping(amping);
		
	}
	return v8::Undefined();
}


/**
 * pBody::isBullet 
 */
v8::Handle<v8::Value> JSpBodyIsBullet(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isBullet();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::setBullet 
 */
v8::Handle<v8::Value> JSpBodySetBullet(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool bullet = args[0]->BooleanValue();
	obj->setBullet(bullet);
		
	}
	return v8::Undefined();
}


/**
 * pBody::isStatic 
 */
v8::Handle<v8::Value> JSpBodyIsStatic(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isStatic();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::isDynamic 
 */
v8::Handle<v8::Value> JSpBodyIsDynamic(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isDynamic();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::isFrozen 
 */
v8::Handle<v8::Value> JSpBodyIsFrozen(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isFrozen();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::isSleeping 
 */
v8::Handle<v8::Value> JSpBodyIsSleeping(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isSleeping();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pBody::setAllowSleep 
 */
v8::Handle<v8::Value> JSpBodySetAllowSleep(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool allow = args[0]->BooleanValue();
	obj->setAllowSleep(allow);
		
	}
	return v8::Undefined();
}


/**
 * pBody::setSleep 
 */
v8::Handle<v8::Value> JSpBodySetSleep(const v8::Arguments& args) {
		pBody obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pBody>(JSpBodyUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool sleep = args[0]->BooleanValue();
	obj->setSleep(sleep);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpBodySetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getX"), v8::FunctionTemplate::New(JSpBodyGetX));
	js_obj->Set(v8::String::New("getY"), v8::FunctionTemplate::New(JSpBodyGetY));
	js_obj->Set(v8::String::New("getPosition"), v8::FunctionTemplate::New(JSpBodyGetPosition));
	js_obj->Set(v8::String::New("getVelocity"), v8::FunctionTemplate::New(JSpBodyGetVelocity));
	js_obj->Set(v8::String::New("getAngle"), v8::FunctionTemplate::New(JSpBodyGetAngle));
	js_obj->Set(v8::String::New("getSpin"), v8::FunctionTemplate::New(JSpBodyGetSpin));
	js_obj->Set(v8::String::New("getMass"), v8::FunctionTemplate::New(JSpBodyGetMass));
	js_obj->Set(v8::String::New("getInertia"), v8::FunctionTemplate::New(JSpBodyGetInertia));
	js_obj->Set(v8::String::New("getDamping"), v8::FunctionTemplate::New(JSpBodyGetDamping));
	js_obj->Set(v8::String::New("getAngularDamping"), v8::FunctionTemplate::New(JSpBodyGetAngularDamping));
	js_obj->Set(v8::String::New("getWorldCenter"), v8::FunctionTemplate::New(JSpBodyGetWorldCenter));
	js_obj->Set(v8::String::New("getLocalCenter"), v8::FunctionTemplate::New(JSpBodyGetLocalCenter));
	js_obj->Set(v8::String::New("getWorldPoint"), v8::FunctionTemplate::New(JSpBodyGetWorldPoint));
	js_obj->Set(v8::String::New("getWorldVector"), v8::FunctionTemplate::New(JSpBodyGetWorldVector));
	js_obj->Set(v8::String::New("getLocalPoint"), v8::FunctionTemplate::New(JSpBodyGetLocalPoint));
	js_obj->Set(v8::String::New("getLocalVector"), v8::FunctionTemplate::New(JSpBodyGetLocalVector));
	js_obj->Set(v8::String::New("getVelocityWorldPoint"), v8::FunctionTemplate::New(JSpBodyGetVelocityWorldPoint));
	js_obj->Set(v8::String::New("getVelocityLocalPoint"), v8::FunctionTemplate::New(JSpBodyGetVelocityLocalPoint));
	js_obj->Set(v8::String::New("applyImpulse"), v8::FunctionTemplate::New(JSpBodyApplyImpulse));
	js_obj->Set(v8::String::New("applyForce"), v8::FunctionTemplate::New(JSpBodyApplyForce));
	js_obj->Set(v8::String::New("applyTorque"), v8::FunctionTemplate::New(JSpBodyApplyTorque));
	js_obj->Set(v8::String::New("setX"), v8::FunctionTemplate::New(JSpBodySetX));
	js_obj->Set(v8::String::New("setY"), v8::FunctionTemplate::New(JSpBodySetY));
	js_obj->Set(v8::String::New("setPosition"), v8::FunctionTemplate::New(JSpBodySetPosition));
	js_obj->Set(v8::String::New("setVelocity"), v8::FunctionTemplate::New(JSpBodySetVelocity));
	js_obj->Set(v8::String::New("setAngle"), v8::FunctionTemplate::New(JSpBodySetAngle));
	js_obj->Set(v8::String::New("setSpin"), v8::FunctionTemplate::New(JSpBodySetSpin));
	js_obj->Set(v8::String::New("setMassFromShapes"), v8::FunctionTemplate::New(JSpBodySetMassFromShapes));
	js_obj->Set(v8::String::New("setMass"), v8::FunctionTemplate::New(JSpBodySetMass));
	js_obj->Set(v8::String::New("setDamping"), v8::FunctionTemplate::New(JSpBodySetDamping));
	js_obj->Set(v8::String::New("setAngularDamping"), v8::FunctionTemplate::New(JSpBodySetAngularDamping));
	js_obj->Set(v8::String::New("isBullet"), v8::FunctionTemplate::New(JSpBodyIsBullet));
	js_obj->Set(v8::String::New("setBullet"), v8::FunctionTemplate::New(JSpBodySetBullet));
	js_obj->Set(v8::String::New("isStatic"), v8::FunctionTemplate::New(JSpBodyIsStatic));
	js_obj->Set(v8::String::New("isDynamic"), v8::FunctionTemplate::New(JSpBodyIsDynamic));
	js_obj->Set(v8::String::New("isFrozen"), v8::FunctionTemplate::New(JSpBodyIsFrozen));
	js_obj->Set(v8::String::New("isSleeping"), v8::FunctionTemplate::New(JSpBodyIsSleeping));
	js_obj->Set(v8::String::New("setAllowSleep"), v8::FunctionTemplate::New(JSpBodySetAllowSleep));
	js_obj->Set(v8::String::New("setSleep"), v8::FunctionTemplate::New(JSpBodySetSleep));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpBodyCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpBodyCreateInstance);
		js_func->SetClassName(v8::String::New("Body"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpBodySetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpBodyWrap(pBody cppObject) {
	WrappedObject<pBody> *p = new WrappedObject<pBody>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpBodySetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpBodyDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pBody JSpBodyUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pBody obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pBody> *p = static_cast<WrappedObject<pBody>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpCircleShapeSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpCircleShapeCreateClass();
v8::Handle<v8::Value> JSpCircleShapeWrap(pCircleShape cppObject);
pCircleShape JSpCircleShapeUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pCircleShape 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpCircleShapeDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pCircleShape> *p = static_cast<WrappedObject<pCircleShape>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpCircleShapeCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pCircleShape *obj = 0;
		
	if (!obj)
		obj = new pCircleShape;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pCircleShape::getType 
 */
v8::Handle<v8::Value> JSpCircleShapeGetType(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getType();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::getFriction 
 */
v8::Handle<v8::Value> JSpCircleShapeGetFriction(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getFriction();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::getRestitution 
 */
v8::Handle<v8::Value> JSpCircleShapeGetRestitution(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getRestituion();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::getCategoryBits 
 */
v8::Handle<v8::Value> JSpCircleShapeGetCategoryBits(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getCategoryBits();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::getMaskBits 
 */
v8::Handle<v8::Value> JSpCircleShapeGetMaskBits(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getMaskBits();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::isSensor 
 */
v8::Handle<v8::Value> JSpCircleShapeIsSensor(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isSensor();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::setFriction 
 */
v8::Handle<v8::Value> JSpCircleShapeSetFriction(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double friction = args[0]->NumberValue();
	obj->setFriction(friction);
		
	}
	return v8::Undefined();
}


/**
 * pCircleShape::setRestitution 
 */
v8::Handle<v8::Value> JSpCircleShapeSetRestitution(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double restitution = args[0]->NumberValue();
	obj->setRestitution(restitution);
		
	}
	return v8::Undefined();
}


/**
 * pCircleShape::setCategoryBits 
 */
v8::Handle<v8::Value> JSpCircleShapeSetCategoryBits(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int bits = args[0]->Int32Value();
	obj->setCategoryBits(bits);
		
	}
	return v8::Undefined();
}


/**
 * pCircleShape::setMaskBits 
 */
v8::Handle<v8::Value> JSpCircleShapeSetMaskBits(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int bits = args[0]->Int32Value();
	obj->setMaskBits(bits);
		
	}
	return v8::Undefined();
}


/**
 * pCircleShape::setSensor 
 */
v8::Handle<v8::Value> JSpCircleShapeSetSensor(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool sensor = args[0]->BooleanValue();
	obj->setSensor(sensor);
		
	}
	return v8::Undefined();
}


/**
 * pCircleShape::testPoint 
 */
v8::Handle<v8::Value> JSpCircleShapeTestPoint(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	bool ret = (bool)obj->testPoint(x,y);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pCircleShape::getRadius 
 */
v8::Handle<v8::Value> JSpCircleShapeGetRadius(const v8::Arguments& args) {
		pCircleShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pCircleShape>(JSpCircleShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getRadius();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpCircleShapeSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getType"), v8::FunctionTemplate::New(JSpCircleShapeGetType));
	js_obj->Set(v8::String::New("getFriction"), v8::FunctionTemplate::New(JSpCircleShapeGetFriction));
	js_obj->Set(v8::String::New("getRestitution"), v8::FunctionTemplate::New(JSpCircleShapeGetRestitution));
	js_obj->Set(v8::String::New("getCategoryBits"), v8::FunctionTemplate::New(JSpCircleShapeGetCategoryBits));
	js_obj->Set(v8::String::New("getMaskBits"), v8::FunctionTemplate::New(JSpCircleShapeGetMaskBits));
	js_obj->Set(v8::String::New("isSensor"), v8::FunctionTemplate::New(JSpCircleShapeIsSensor));
	js_obj->Set(v8::String::New("setFriction"), v8::FunctionTemplate::New(JSpCircleShapeSetFriction));
	js_obj->Set(v8::String::New("setRestitution"), v8::FunctionTemplate::New(JSpCircleShapeSetRestitution));
	js_obj->Set(v8::String::New("setCategoryBits"), v8::FunctionTemplate::New(JSpCircleShapeSetCategoryBits));
	js_obj->Set(v8::String::New("setMaskBits"), v8::FunctionTemplate::New(JSpCircleShapeSetMaskBits));
	js_obj->Set(v8::String::New("setSensor"), v8::FunctionTemplate::New(JSpCircleShapeSetSensor));
	js_obj->Set(v8::String::New("testPoint"), v8::FunctionTemplate::New(JSpCircleShapeTestPoint));
	js_obj->Set(v8::String::New("getRadius"), v8::FunctionTemplate::New(JSpCircleShapeGetRadius));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpCircleShapeCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpCircleShapeCreateInstance);
		js_func->SetClassName(v8::String::New("CircleShape"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpCircleShapeSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpCircleShapeWrap(pCircleShape cppObject) {
	WrappedObject<pCircleShape> *p = new WrappedObject<pCircleShape>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpCircleShapeSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpCircleShapeDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pCircleShape JSpCircleShapeUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pCircleShape obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pCircleShape> *p = static_cast<WrappedObject<pCircleShape>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpPolygonShapeSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpPolygonShapeCreateClass();
v8::Handle<v8::Value> JSpPolygonShapeWrap(pPolygonShape cppObject);
pPolygonShape JSpPolygonShapeUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pPolygonShape 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpPolygonShapeDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pPolygonShape> *p = static_cast<WrappedObject<pPolygonShape>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpPolygonShapeCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pPolygonShape *obj = 0;
		
	if (!obj)
		obj = new pPolygonShape;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pPolygonShape::getType 
 */
v8::Handle<v8::Value> JSpPolygonShapeGetType(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	int ret = (int)obj->getType();
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::getFriction 
 */
v8::Handle<v8::Value> JSpPolygonShapeGetFriction(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getFriction();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::getRestitution 
 */
v8::Handle<v8::Value> JSpPolygonShapeGetRestitution(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getRestituion();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::isSensor 
 */
v8::Handle<v8::Value> JSpPolygonShapeIsSensor(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isSensor();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::setFriction 
 */
v8::Handle<v8::Value> JSpPolygonShapeSetFriction(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double friction = args[0]->NumberValue();
	obj->setFriction(friction);
		
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::setRestitution 
 */
v8::Handle<v8::Value> JSpPolygonShapeSetRestitution(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double restitution = args[0]->NumberValue();
	obj->setRestitution(restitution);
		
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::setSensor 
 */
v8::Handle<v8::Value> JSpPolygonShapeSetSensor(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool sensor = args[0]->BooleanValue();
	obj->setSensor(sensor);
		
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::testPoint 
 */
v8::Handle<v8::Value> JSpPolygonShapeTestPoint(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	bool ret = (bool)obj->testPoint(x,y);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPolygonShape::getPoints 
 */
v8::Handle<v8::Value> JSpPolygonShapeGetPoints(const v8::Arguments& args) {
		pPolygonShape obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPolygonShape>(JSpPolygonShapeUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2dfList ret = (Vec2dfList)obj->getPoints();
	return JSVec2dfListWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpPolygonShapeSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getType"), v8::FunctionTemplate::New(JSpPolygonShapeGetType));
	js_obj->Set(v8::String::New("getFriction"), v8::FunctionTemplate::New(JSpPolygonShapeGetFriction));
	js_obj->Set(v8::String::New("getRestitution"), v8::FunctionTemplate::New(JSpPolygonShapeGetRestitution));
	js_obj->Set(v8::String::New("isSensor"), v8::FunctionTemplate::New(JSpPolygonShapeIsSensor));
	js_obj->Set(v8::String::New("setFriction"), v8::FunctionTemplate::New(JSpPolygonShapeSetFriction));
	js_obj->Set(v8::String::New("setRestitution"), v8::FunctionTemplate::New(JSpPolygonShapeSetRestitution));
	js_obj->Set(v8::String::New("setSensor"), v8::FunctionTemplate::New(JSpPolygonShapeSetSensor));
	js_obj->Set(v8::String::New("testPoint"), v8::FunctionTemplate::New(JSpPolygonShapeTestPoint));
	js_obj->Set(v8::String::New("getPoints"), v8::FunctionTemplate::New(JSpPolygonShapeGetPoints));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpPolygonShapeCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpPolygonShapeCreateInstance);
		js_func->SetClassName(v8::String::New("PolygonShape"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpPolygonShapeSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpPolygonShapeWrap(pPolygonShape cppObject) {
	WrappedObject<pPolygonShape> *p = new WrappedObject<pPolygonShape>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpPolygonShapeSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpPolygonShapeDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pPolygonShape JSpPolygonShapeUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pPolygonShape obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pPolygonShape> *p = static_cast<WrappedObject<pPolygonShape>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpDistanceJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpDistanceJointCreateClass();
v8::Handle<v8::Value> JSpDistanceJointWrap(pDistanceJoint cppObject);
pDistanceJoint JSpDistanceJointUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pDistanceJoint 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpDistanceJointDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pDistanceJoint> *p = static_cast<WrappedObject<pDistanceJoint>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpDistanceJointCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pDistanceJoint *obj = 0;
		
	if (!obj)
		obj = new pDistanceJoint;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pDistanceJoint::getLength 
 */
v8::Handle<v8::Value> JSpDistanceJointGetLength(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getLength();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pDistanceJoint::getFrequency 
 */
v8::Handle<v8::Value> JSpDistanceJointGetFrequency(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getFrequency();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pDistanceJoint::getDamping 
 */
v8::Handle<v8::Value> JSpDistanceJointGetDamping(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getDamping();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pDistanceJoint::setLength 
 */
v8::Handle<v8::Value> JSpDistanceJointSetLength(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double length = args[0]->NumberValue();
	obj->setLength(length);
		
	}
	return v8::Undefined();
}


/**
 * pDistanceJoint::setFrequency 
 */
v8::Handle<v8::Value> JSpDistanceJointSetFrequency(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double hz = args[0]->NumberValue();
	obj->setFrequency(hz);
		
	}
	return v8::Undefined();
}


/**
 * pDistanceJoint::setDamping 
 */
v8::Handle<v8::Value> JSpDistanceJointSetDamping(const v8::Arguments& args) {
		pDistanceJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pDistanceJoint>(JSpDistanceJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double d = args[0]->NumberValue();
	obj->setDamping(d);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpDistanceJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getLength"), v8::FunctionTemplate::New(JSpDistanceJointGetLength));
	js_obj->Set(v8::String::New("getFrequency"), v8::FunctionTemplate::New(JSpDistanceJointGetFrequency));
	js_obj->Set(v8::String::New("getDamping"), v8::FunctionTemplate::New(JSpDistanceJointGetDamping));
	js_obj->Set(v8::String::New("setLength"), v8::FunctionTemplate::New(JSpDistanceJointSetLength));
	js_obj->Set(v8::String::New("setFrequency"), v8::FunctionTemplate::New(JSpDistanceJointSetFrequency));
	js_obj->Set(v8::String::New("setDamping"), v8::FunctionTemplate::New(JSpDistanceJointSetDamping));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpDistanceJointCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpDistanceJointCreateInstance);
		js_func->SetClassName(v8::String::New("DistanceJoint"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpDistanceJointSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpDistanceJointWrap(pDistanceJoint cppObject) {
	WrappedObject<pDistanceJoint> *p = new WrappedObject<pDistanceJoint>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpDistanceJointSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpDistanceJointDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pDistanceJoint JSpDistanceJointUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pDistanceJoint obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pDistanceJoint> *p = static_cast<WrappedObject<pDistanceJoint>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpRevoluteJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpRevoluteJointCreateClass();
v8::Handle<v8::Value> JSpRevoluteJointWrap(pRevoluteJoint cppObject);
pRevoluteJoint JSpRevoluteJointUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pRevoluteJoint 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpRevoluteJointDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pRevoluteJoint> *p = static_cast<WrappedObject<pRevoluteJoint>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpRevoluteJointCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pRevoluteJoint *obj = 0;
		
	if (!obj)
		obj = new pRevoluteJoint;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pRevoluteJoint::getAngle 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetAngle(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getAngle();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getSpeed 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetSpeed(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
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
 * pRevoluteJoint::isMotorEnabled 
 */
v8::Handle<v8::Value> JSpRevoluteJointIsMotorEnabled(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isMotorEnabled();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getMaxMotorTorque 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetMaxMotorTorque(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMaxMotorTorque();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getMotorSpeed 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetMotorSpeed(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMotorSpeed();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getMotorTorque 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetMotorTorque(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMotorTorque();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::isLimitsEnabled 
 */
v8::Handle<v8::Value> JSpRevoluteJointIsLimitsEnabled(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isLimitsEnabled();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getLowerLimit 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetLowerLimit(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getLowerLimit();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::getUpperLimit 
 */
v8::Handle<v8::Value> JSpRevoluteJointGetUpperLimit(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getUpperLimit();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setMotorEnabled 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetMotorEnabled(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool motor = args[0]->BooleanValue();
	obj->setMotorEnabled(motor);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setMaxMotorTorque 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetMaxMotorTorque(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double torque = args[0]->NumberValue();
	obj->setMaxMotorTorque(torque);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setMotorSpeed 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetMotorSpeed(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double speed = args[0]->NumberValue();
	obj->setMotorSpeed(speed);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setLimitsEnabled 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetLimitsEnabled(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool limit = args[0]->BooleanValue();
	obj->setLimitsEnabled(limit);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setUpperLimit 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetUpperLimit(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double upper = args[0]->NumberValue();
	obj->setUpperLimit(upper);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setLowerLimit 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetLowerLimit(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double lower = args[0]->NumberValue();
	obj->setLowerLimit(lower);
		
	}
	return v8::Undefined();
}


/**
 * pRevoluteJoint::setLimits 
 */
v8::Handle<v8::Value> JSpRevoluteJointSetLimits(const v8::Arguments& args) {
		pRevoluteJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pRevoluteJoint>(JSpRevoluteJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double lower = args[0]->NumberValue();
			double upper = args[1]->NumberValue();
	obj->setLimits(lower,upper);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpRevoluteJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getAngle"), v8::FunctionTemplate::New(JSpRevoluteJointGetAngle));
	js_obj->Set(v8::String::New("getSpeed"), v8::FunctionTemplate::New(JSpRevoluteJointGetSpeed));
	js_obj->Set(v8::String::New("isMotorEnabled"), v8::FunctionTemplate::New(JSpRevoluteJointIsMotorEnabled));
	js_obj->Set(v8::String::New("getMaxMotorTorque"), v8::FunctionTemplate::New(JSpRevoluteJointGetMaxMotorTorque));
	js_obj->Set(v8::String::New("getMotorSpeed"), v8::FunctionTemplate::New(JSpRevoluteJointGetMotorSpeed));
	js_obj->Set(v8::String::New("getMotorTorque"), v8::FunctionTemplate::New(JSpRevoluteJointGetMotorTorque));
	js_obj->Set(v8::String::New("isLimitsEnabled"), v8::FunctionTemplate::New(JSpRevoluteJointIsLimitsEnabled));
	js_obj->Set(v8::String::New("getLowerLimit"), v8::FunctionTemplate::New(JSpRevoluteJointGetLowerLimit));
	js_obj->Set(v8::String::New("getUpperLimit"), v8::FunctionTemplate::New(JSpRevoluteJointGetUpperLimit));
	js_obj->Set(v8::String::New("setMotorEnabled"), v8::FunctionTemplate::New(JSpRevoluteJointSetMotorEnabled));
	js_obj->Set(v8::String::New("setMaxMotorTorque"), v8::FunctionTemplate::New(JSpRevoluteJointSetMaxMotorTorque));
	js_obj->Set(v8::String::New("setMotorSpeed"), v8::FunctionTemplate::New(JSpRevoluteJointSetMotorSpeed));
	js_obj->Set(v8::String::New("setLimitsEnabled"), v8::FunctionTemplate::New(JSpRevoluteJointSetLimitsEnabled));
	js_obj->Set(v8::String::New("setUpperLimit"), v8::FunctionTemplate::New(JSpRevoluteJointSetUpperLimit));
	js_obj->Set(v8::String::New("setLowerLimit"), v8::FunctionTemplate::New(JSpRevoluteJointSetLowerLimit));
	js_obj->Set(v8::String::New("setLimits"), v8::FunctionTemplate::New(JSpRevoluteJointSetLimits));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpRevoluteJointCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpRevoluteJointCreateInstance);
		js_func->SetClassName(v8::String::New("RevoluteJoint"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpRevoluteJointSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpRevoluteJointWrap(pRevoluteJoint cppObject) {
	WrappedObject<pRevoluteJoint> *p = new WrappedObject<pRevoluteJoint>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpRevoluteJointSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpRevoluteJointDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pRevoluteJoint JSpRevoluteJointUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pRevoluteJoint obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pRevoluteJoint> *p = static_cast<WrappedObject<pRevoluteJoint>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpPrismaticJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpPrismaticJointCreateClass();
v8::Handle<v8::Value> JSpPrismaticJointWrap(pPrismaticJoint cppObject);
pPrismaticJoint JSpPrismaticJointUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pPrismaticJoint 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpPrismaticJointDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pPrismaticJoint> *p = static_cast<WrappedObject<pPrismaticJoint>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpPrismaticJointCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pPrismaticJoint *obj = 0;
		
	if (!obj)
		obj = new pPrismaticJoint;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pPrismaticJoint::getTranslation 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetTranslation(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getTranslation();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getSpeed 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetSpeed(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
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
 * pPrismaticJoint::isMotorEnabled 
 */
v8::Handle<v8::Value> JSpPrismaticJointIsMotorEnabled(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isMotorEnabled();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getMaxMotorForce 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetMaxMotorForce(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMaxMotorForce();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getMotorSpeed 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetMotorSpeed(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMotorSpeed();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getMotorForce 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetMotorForce(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMotorForce();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::isLimitsEnabled 
 */
v8::Handle<v8::Value> JSpPrismaticJointIsLimitsEnabled(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)obj->isLimitsEnabled();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getLowerLimit 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetLowerLimit(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getLowerLimit();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::getUpperLimit 
 */
v8::Handle<v8::Value> JSpPrismaticJointGetUpperLimit(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getUpperLimit();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setMotorEnabled 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetMotorEnabled(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool motor = args[0]->BooleanValue();
	obj->setMotorEnabled(motor);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setMaxMotorForce 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetMaxMotorForce(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double force = args[0]->NumberValue();
	obj->setMaxMotorForce(force);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setMotorSpeed 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetMotorSpeed(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double speed = args[0]->NumberValue();
	obj->setMotorSpeed(speed);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setLimitsEnabled 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetLimitsEnabled(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			bool limit = args[0]->BooleanValue();
	obj->setLimitsEnabled(limit);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setUpperLimit 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetUpperLimit(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double upper = args[0]->NumberValue();
	obj->setUpperLimit(upper);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setLowerLimit 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetLowerLimit(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double lower = args[0]->NumberValue();
	obj->setLowerLimit(lower);
		
	}
	return v8::Undefined();
}


/**
 * pPrismaticJoint::setLimits 
 */
v8::Handle<v8::Value> JSpPrismaticJointSetLimits(const v8::Arguments& args) {
		pPrismaticJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pPrismaticJoint>(JSpPrismaticJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double lower = args[0]->NumberValue();
			double upper = args[1]->NumberValue();
	obj->setLimits(lower,upper);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpPrismaticJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getTranslation"), v8::FunctionTemplate::New(JSpPrismaticJointGetTranslation));
	js_obj->Set(v8::String::New("getSpeed"), v8::FunctionTemplate::New(JSpPrismaticJointGetSpeed));
	js_obj->Set(v8::String::New("isMotorEnabled"), v8::FunctionTemplate::New(JSpPrismaticJointIsMotorEnabled));
	js_obj->Set(v8::String::New("getMaxMotorForce"), v8::FunctionTemplate::New(JSpPrismaticJointGetMaxMotorForce));
	js_obj->Set(v8::String::New("getMotorSpeed"), v8::FunctionTemplate::New(JSpPrismaticJointGetMotorSpeed));
	js_obj->Set(v8::String::New("getMotorForce"), v8::FunctionTemplate::New(JSpPrismaticJointGetMotorForce));
	js_obj->Set(v8::String::New("isLimitsEnabled"), v8::FunctionTemplate::New(JSpPrismaticJointIsLimitsEnabled));
	js_obj->Set(v8::String::New("getLowerLimit"), v8::FunctionTemplate::New(JSpPrismaticJointGetLowerLimit));
	js_obj->Set(v8::String::New("getUpperLimit"), v8::FunctionTemplate::New(JSpPrismaticJointGetUpperLimit));
	js_obj->Set(v8::String::New("setMotorEnabled"), v8::FunctionTemplate::New(JSpPrismaticJointSetMotorEnabled));
	js_obj->Set(v8::String::New("setMaxMotorForce"), v8::FunctionTemplate::New(JSpPrismaticJointSetMaxMotorForce));
	js_obj->Set(v8::String::New("setMotorSpeed"), v8::FunctionTemplate::New(JSpPrismaticJointSetMotorSpeed));
	js_obj->Set(v8::String::New("setLimitsEnabled"), v8::FunctionTemplate::New(JSpPrismaticJointSetLimitsEnabled));
	js_obj->Set(v8::String::New("setUpperLimit"), v8::FunctionTemplate::New(JSpPrismaticJointSetUpperLimit));
	js_obj->Set(v8::String::New("setLowerLimit"), v8::FunctionTemplate::New(JSpPrismaticJointSetLowerLimit));
	js_obj->Set(v8::String::New("setLimits"), v8::FunctionTemplate::New(JSpPrismaticJointSetLimits));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpPrismaticJointCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpPrismaticJointCreateInstance);
		js_func->SetClassName(v8::String::New("PrismaticJoint"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpPrismaticJointSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpPrismaticJointWrap(pPrismaticJoint cppObject) {
	WrappedObject<pPrismaticJoint> *p = new WrappedObject<pPrismaticJoint>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpPrismaticJointSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpPrismaticJointDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pPrismaticJoint JSpPrismaticJointUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pPrismaticJoint obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pPrismaticJoint> *p = static_cast<WrappedObject<pPrismaticJoint>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpMouseJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpMouseJointCreateClass();
v8::Handle<v8::Value> JSpMouseJointWrap(pMouseJoint cppObject);
pMouseJoint JSpMouseJointUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pMouseJoint 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpMouseJointDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pMouseJoint> *p = static_cast<WrappedObject<pMouseJoint>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpMouseJointCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pMouseJoint *obj = 0;
		
	if (!obj)
		obj = new pMouseJoint;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pMouseJoint::getTarget 
 */
v8::Handle<v8::Value> JSpMouseJointGetTarget(const v8::Arguments& args) {
		pMouseJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pMouseJoint>(JSpMouseJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	Vec2df ret = (Vec2df)obj->getTarget();
	return JSVec2dfWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * pMouseJoint::getMaxForce 
 */
v8::Handle<v8::Value> JSpMouseJointGetMaxForce(const v8::Arguments& args) {
		pMouseJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pMouseJoint>(JSpMouseJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	double ret = (double)obj->getMaxForce();
	return v8::Number::New(ret);	
	}
	return v8::Undefined();
}


/**
 * pMouseJoint::setTarget 
 */
v8::Handle<v8::Value> JSpMouseJointSetTarget(const v8::Arguments& args) {
		pMouseJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pMouseJoint>(JSpMouseJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();
	obj->setTarget(x,y);
		
	}
	return v8::Undefined();
}


/**
 * pMouseJoint::setMaxForce 
 */
v8::Handle<v8::Value> JSpMouseJointSetMaxForce(const v8::Arguments& args) {
		pMouseJoint obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pMouseJoint>(JSpMouseJointUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			double force = args[0]->NumberValue();
	obj->setMaxForce(force);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpMouseJointSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getTarget"), v8::FunctionTemplate::New(JSpMouseJointGetTarget));
	js_obj->Set(v8::String::New("getMaxForce"), v8::FunctionTemplate::New(JSpMouseJointGetMaxForce));
	js_obj->Set(v8::String::New("setTarget"), v8::FunctionTemplate::New(JSpMouseJointSetTarget));
	js_obj->Set(v8::String::New("setMaxForce"), v8::FunctionTemplate::New(JSpMouseJointSetMaxForce));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpMouseJointCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpMouseJointCreateInstance);
		js_func->SetClassName(v8::String::New("MouseJoint"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpMouseJointSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpMouseJointWrap(pMouseJoint cppObject) {
	WrappedObject<pMouseJoint> *p = new WrappedObject<pMouseJoint>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpMouseJointSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpMouseJointDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pMouseJoint JSpMouseJointUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pMouseJoint obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pMouseJoint> *p = static_cast<WrappedObject<pMouseJoint>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSlove_box2dSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_box2dCreateClass();

 

/**
 * love_box2d::newWorld 
 */
v8::Handle<v8::Value> JSlove_box2dNewWorld(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			double w = args[0]->NumberValue();
			double h = args[1]->NumberValue();
	pWorld ret = (pWorld)love_box2d::newWorld(w,h);
	return JSpWorldWrap(ret);	
	}
	
	if (args.Length() == 7) {
	v8::HandleScope handle_scope;
			double lx = args[0]->NumberValue();
			double ly = args[1]->NumberValue();
			double ux = args[2]->NumberValue();
			double uy = args[3]->NumberValue();
			double gx = args[4]->NumberValue();
			double gy = args[5]->NumberValue();
			bool sleep = args[6]->BooleanValue();
	pWorld ret = (pWorld)love_box2d::newWorld(lx,ly,ux,uy,gx,gy,sleep);
	return JSpWorldWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newBody 
 */
v8::Handle<v8::Value> JSlove_box2dNewBody(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pWorld world = JSpWorldUnwrap(args[0]->ToObject());
	pBody ret = (pBody)love_box2d::newBody(world);
	return JSpBodyWrap(ret);	
	}
	
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			pWorld world = JSpWorldUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
	pBody ret = (pBody)love_box2d::newBody(world,x,y);
	return JSpBodyWrap(ret);	
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			pWorld world = JSpWorldUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double m = args[3]->NumberValue();
	pBody ret = (pBody)love_box2d::newBody(world,x,y,m);
	return JSpBodyWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newCircleShape 
 */
v8::Handle<v8::Value> JSlove_box2dNewCircleShape(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double radius = args[1]->NumberValue();
	pCircleShape ret = (pCircleShape)love_box2d::newCircleShape(body,radius);
	return JSpCircleShapeWrap(ret);	
	}
	
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double radius = args[3]->NumberValue();
	pCircleShape ret = (pCircleShape)love_box2d::newCircleShape(body,x,y,radius);
	return JSpCircleShapeWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newRectangleShape 
 */
v8::Handle<v8::Value> JSlove_box2dNewRectangleShape(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double w = args[1]->NumberValue();
			double h = args[2]->NumberValue();
	pPolygonShape ret = (pPolygonShape)love_box2d::newRectangleShape(body,w,h);
	return JSpPolygonShapeWrap(ret);	
	}
	
	if (args.Length() == 5) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double w = args[3]->NumberValue();
			double h = args[4]->NumberValue();
	pPolygonShape ret = (pPolygonShape)love_box2d::newRectangleShape(body,x,y,w,h);
	return JSpPolygonShapeWrap(ret);	
	}
	
	if (args.Length() == 6) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
			double w = args[3]->NumberValue();
			double h = args[4]->NumberValue();
			double angle = args[5]->NumberValue();
	pPolygonShape ret = (pPolygonShape)love_box2d::newRectangleShape(body,x,y,w,h,angle);
	return JSpPolygonShapeWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newDistanceJoint 
 */
v8::Handle<v8::Value> JSlove_box2dNewDistanceJoint(const v8::Arguments& args) {
					
	if (args.Length() == 6) {
	v8::HandleScope handle_scope;
			pBody body1 = JSpBodyUnwrap(args[0]->ToObject());
			pBody body2 = JSpBodyUnwrap(args[1]->ToObject());
			double x1 = args[2]->NumberValue();
			double y1 = args[3]->NumberValue();
			double x2 = args[4]->NumberValue();
			double y2 = args[5]->NumberValue();
	pDistanceJoint ret = (pDistanceJoint)love_box2d::newDistanceJoint(body1,body2,x1,y1,x2,y2);
	return JSpDistanceJointWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newRevoluteJoint 
 */
v8::Handle<v8::Value> JSlove_box2dNewRevoluteJoint(const v8::Arguments& args) {
					
	if (args.Length() == 4) {
	v8::HandleScope handle_scope;
			pBody body1 = JSpBodyUnwrap(args[0]->ToObject());
			pBody body2 = JSpBodyUnwrap(args[1]->ToObject());
			double x = args[2]->NumberValue();
			double y = args[3]->NumberValue();
	pRevoluteJoint ret = (pRevoluteJoint)love_box2d::newRevoluteJoint(body1,body2,x,y);
	return JSpRevoluteJointWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newPrismaticJoint 
 */
v8::Handle<v8::Value> JSlove_box2dNewPrismaticJoint(const v8::Arguments& args) {
					
	if (args.Length() == 6) {
	v8::HandleScope handle_scope;
			pBody body1 = JSpBodyUnwrap(args[0]->ToObject());
			pBody body2 = JSpBodyUnwrap(args[1]->ToObject());
			double x = args[2]->NumberValue();
			double y = args[3]->NumberValue();
			double ax = args[4]->NumberValue();
			double ay = args[5]->NumberValue();
	pPrismaticJoint ret = (pPrismaticJoint)love_box2d::newPrismaticJoint(body1,body2,x,y,ax,ay);
	return JSpPrismaticJointWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_box2d::newMouseJoint 
 */
v8::Handle<v8::Value> JSlove_box2dNewMouseJoint(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			pBody body = JSpBodyUnwrap(args[0]->ToObject());
			double x = args[1]->NumberValue();
			double y = args[2]->NumberValue();
	pMouseJoint ret = (pMouseJoint)love_box2d::newMouseJoint(body,x,y);
	return JSpMouseJointWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_box2dSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("newWorld"), v8::FunctionTemplate::New(JSlove_box2dNewWorld));
	js_obj->Set(v8::String::New("newBody"), v8::FunctionTemplate::New(JSlove_box2dNewBody));
	js_obj->Set(v8::String::New("newCircleShape"), v8::FunctionTemplate::New(JSlove_box2dNewCircleShape));
	js_obj->Set(v8::String::New("newRectangleShape"), v8::FunctionTemplate::New(JSlove_box2dNewRectangleShape));
	js_obj->Set(v8::String::New("newDistanceJoint"), v8::FunctionTemplate::New(JSlove_box2dNewDistanceJoint));
	js_obj->Set(v8::String::New("newRevoluteJoint"), v8::FunctionTemplate::New(JSlove_box2dNewRevoluteJoint));
	js_obj->Set(v8::String::New("newPrismaticJoint"), v8::FunctionTemplate::New(JSlove_box2dNewPrismaticJoint));
	js_obj->Set(v8::String::New("newMouseJoint"), v8::FunctionTemplate::New(JSlove_box2dNewMouseJoint));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_box2dCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("physics"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_box2dSetupClass(js_obj);
	return js_obj;
}



/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JSVec2dfWrap(Vec2df cobj) {
		v8::Handle<v8::Object> obj = v8::Object::New();

		
	obj->Set(v8::String::New("x"),v8::Number::New(cobj.x), v8::ReadOnly); 
	
		
	obj->Set(v8::String::New("y"),v8::Number::New(cobj.y), v8::ReadOnly); 
	
		return obj;
	
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Vec2df JSVec2dfUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Vec2df cobj;
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
v8::Handle<v8::Value> JSVec2dfListWrap(Vec2dfList cobj) {
		v8::Handle<v8::Array> obj = v8::Array::New();
	
	for(int i = 0; i<cobj.length(); i++) {
		obj->Set(v8::Integer::New(i), JSVec2dfWrap(cobj.at(i)));
	}
		
	return obj;
	}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
Vec2dfList JSVec2dfListUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	Vec2dfList cobj;
	
	cobj.init(0, 0);
	if (value->IsArray()) {
		v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(value);
		if (arr->Length()) {
			cobj.init(new Vec2df[arr->Length()],arr->Length());
			for(int i = 0; i<cobj.count; i++) {
				cobj.items[i] = JSVec2dfUnwrap(arr->Get(v8::Integer::New(i)));
			}
		}
	}
	
	return cobj;
	}
