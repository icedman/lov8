#include <v8.h>
#include "../v8Object.h"
#include "../../src/sdlmixer/love_sdlmixer.h"
#include "../../src/sdlmixer/sound.h"
#include "../../src/sdlmixer/music.h"

using namespace love_sdlmixer;

// extern

// forward declaractions


void JSpSoundSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpSoundCreateClass();
v8::Handle<v8::Value> JSpSoundWrap(pSound cppObject);
pSound JSpSoundUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pSound 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpSoundDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pSound> *p = static_cast<WrappedObject<pSound>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpSoundCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pSound *obj = 0;
		
	if (!obj)
		obj = new pSound;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pSound::setVolume 
 */
v8::Handle<v8::Value> JSpSoundSetVolume(const v8::Arguments& args) {
		pSound obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pSound>(JSpSoundUnwrap(self));		
	} else {
	return v8::Undefined();
	}
	
			
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int vol = args[0]->Int32Value();
	obj->setVolume(vol);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSpSoundSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("setVolume"), v8::FunctionTemplate::New(JSpSoundSetVolume));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpSoundCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpSoundCreateInstance);
		js_func->SetClassName(v8::String::New("Sound"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpSoundSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpSoundWrap(pSound cppObject) {
	WrappedObject<pSound> *p = new WrappedObject<pSound>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpSoundSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpSoundDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pSound JSpSoundUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pSound obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pSound> *p = static_cast<WrappedObject<pSound>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSpMusicSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpMusicCreateClass();
v8::Handle<v8::Value> JSpMusicWrap(pMusic cppObject);
pMusic JSpMusicUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pMusic 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpMusicDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pMusic> *p = static_cast<WrappedObject<pMusic>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpMusicCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pMusic *obj = 0;
		
	if (!obj)
		obj = new pMusic;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * SetupClass
 * Attach methods and properties
 */
void JSpMusicSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpMusicCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpMusicCreateInstance);
		js_func->SetClassName(v8::String::New("Music"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpMusicSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpMusicWrap(pMusic cppObject) {
	WrappedObject<pMusic> *p = new WrappedObject<pMusic>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpMusicSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpMusicDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pMusic JSpMusicUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pMusic obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pMusic> *p = static_cast<WrappedObject<pMusic>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSlove_sdlmixerSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_sdlmixerCreateClass();

 

/**
 * love_sdlmixer::newSound 
 */
v8::Handle<v8::Value> JSlove_sdlmixerNewSound(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	pSound ret = (pSound)love_sdlmixer::newSound(filename);
	return JSpSoundWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::newMusic 
 */
v8::Handle<v8::Value> JSlove_sdlmixerNewMusic(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	pMusic ret = (pMusic)love_sdlmixer::newMusic(filename);
	return JSpMusicWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::playSound 
 */
v8::Handle<v8::Value> JSlove_sdlmixerPlaySound(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pSound sound = JSpSoundUnwrap(args[0]->ToObject());
	love_sdlmixer::play(sound);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pSound sound = JSpSoundUnwrap(args[0]->ToObject());
			bool loop = args[1]->BooleanValue();
	love_sdlmixer::play(sound,loop);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::playMusic 
 */
v8::Handle<v8::Value> JSlove_sdlmixerPlayMusic(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pMusic music = JSpMusicUnwrap(args[0]->ToObject());
	love_sdlmixer::play(music);
		
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pMusic music = JSpMusicUnwrap(args[0]->ToObject());
			bool loop = args[1]->BooleanValue();
	love_sdlmixer::play(music,loop);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::pause 
 */
v8::Handle<v8::Value> JSlove_sdlmixerPause(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_sdlmixer::pause();
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::resume 
 */
v8::Handle<v8::Value> JSlove_sdlmixerResume(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_sdlmixer::resume();
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::stop 
 */
v8::Handle<v8::Value> JSlove_sdlmixerStop(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	love_sdlmixer::stop();
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::isPlaying 
 */
v8::Handle<v8::Value> JSlove_sdlmixerIsPlaying(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)love_sdlmixer::isPlaying();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::isPaused 
 */
v8::Handle<v8::Value> JSlove_sdlmixerIsPaused(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	bool ret = (bool)love_sdlmixer::isPaused();
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::setChannels 
 */
v8::Handle<v8::Value> JSlove_sdlmixerSetChannels(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int channels = args[0]->Int32Value();
	love_sdlmixer::setChannels(channels);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::setMode 
 */
v8::Handle<v8::Value> JSlove_sdlmixerSetMode(const v8::Arguments& args) {
					
	if (args.Length() == 3) {
	v8::HandleScope handle_scope;
			int frequency = args[0]->Int32Value();
			int mode = args[1]->Int32Value();
			int buffersize = args[2]->Int32Value();
	love_sdlmixer::setMode(frequency,mode,buffersize);
		
	}
	return v8::Undefined();
}


/**
 * love_sdlmixer::setVolume 
 */
v8::Handle<v8::Value> JSlove_sdlmixerSetVolume(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			int volume = args[0]->Int32Value();
	love_sdlmixer::setVolume(volume);
		
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_sdlmixerSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("newSound"), v8::FunctionTemplate::New(JSlove_sdlmixerNewSound));
	js_obj->Set(v8::String::New("newMusic"), v8::FunctionTemplate::New(JSlove_sdlmixerNewMusic));
	js_obj->Set(v8::String::New("playSound"), v8::FunctionTemplate::New(JSlove_sdlmixerPlaySound));
	js_obj->Set(v8::String::New("playMusic"), v8::FunctionTemplate::New(JSlove_sdlmixerPlayMusic));
	js_obj->Set(v8::String::New("pause"), v8::FunctionTemplate::New(JSlove_sdlmixerPause));
	js_obj->Set(v8::String::New("resume"), v8::FunctionTemplate::New(JSlove_sdlmixerResume));
	js_obj->Set(v8::String::New("stop"), v8::FunctionTemplate::New(JSlove_sdlmixerStop));
	js_obj->Set(v8::String::New("isPlaying"), v8::FunctionTemplate::New(JSlove_sdlmixerIsPlaying));
	js_obj->Set(v8::String::New("isPaused"), v8::FunctionTemplate::New(JSlove_sdlmixerIsPaused));
	js_obj->Set(v8::String::New("setChannels"), v8::FunctionTemplate::New(JSlove_sdlmixerSetChannels));
	js_obj->Set(v8::String::New("setMode"), v8::FunctionTemplate::New(JSlove_sdlmixerSetMode));
	js_obj->Set(v8::String::New("setVolume"), v8::FunctionTemplate::New(JSlove_sdlmixerSetVolume));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_sdlmixerCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("audio"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_sdlmixerSetupClass(js_obj);
	return js_obj;
}



