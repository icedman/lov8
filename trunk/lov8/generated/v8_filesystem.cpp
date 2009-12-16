#include <v8.h>
#include "../v8Object.h"
#include "../../src/physfs/love_physfs.h"
#include "../../src/physfs/file.h"

using namespace love_physfs;

// extern

// forward declaractions


void JSpFileSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSpFileCreateClass();
v8::Handle<v8::Value> JSpFileWrap(pFile cppObject);
pFile JSpFileUnwrap(v8::Handle<v8::Value> value);


/**
 *----------------------------------------
 * pFile 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JSpFileDestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<pFile> *p = static_cast<WrappedObject<pFile>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JSpFileCreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	pFile *obj = 0;
		
	if (!obj)
		obj = new pFile;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
 

/**
 * pFile::getSize 
 */
v8::Handle<v8::Value> JSpFileGetSize(const v8::Arguments& args) {
		pFile obj;
		
	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<pFile>(JSpFileUnwrap(self));		
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
 * SetupClass
 * Attach methods and properties
 */
void JSpFileSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("getSize"), v8::FunctionTemplate::New(JSpFileGetSize));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSpFileCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JSpFileCreateInstance);
		js_func->SetClassName(v8::String::New("File"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		js_obj->SetInternalFieldCount(1);
		JSpFileSetupClass(js_obj);
	return js_obj;
}

/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JSpFileWrap(pFile cppObject) {
	WrappedObject<pFile> *p = new WrappedObject<pFile>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JSpFileSetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JSpFileDestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
pFile JSpFileUnwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	pFile obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<pFile> *p = static_cast<WrappedObject<pFile>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}


void JSlove_physfsSetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JSlove_physfsCreateClass();

 

/**
 * love_physfs::newFile 
 */
v8::Handle<v8::Value> JSlove_physfsNewFile(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	pFile ret = (pFile)love_physfs::newFile(filename);
	return JSpFileWrap(ret);	
	}
	
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
			int mode = args[1]->Int32Value();
	pFile ret = (pFile)love_physfs::newFile(filename,mode);
	return JSpFileWrap(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::getWorkingDirectory 
 */
v8::Handle<v8::Value> JSlove_physfsGetWorkingDirectory(const v8::Arguments& args) {
					
	if (args.Length() == 0) {
	v8::HandleScope handle_scope;
	char* ret = (char*)love_physfs::getWorkingDirectory();
	return v8::String::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::exists 
 */
v8::Handle<v8::Value> JSlove_physfsExists(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	bool ret = (bool)love_physfs::exists(filename);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::isDirectory 
 */
v8::Handle<v8::Value> JSlove_physfsIsDirectory(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* dirname = *_args0;
	bool ret = (bool)love_physfs::isDirectory(dirname);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::isFile 
 */
v8::Handle<v8::Value> JSlove_physfsIsFile(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	bool ret = (bool)love_physfs::isFile(filename);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::mkdir 
 */
v8::Handle<v8::Value> JSlove_physfsMkdir(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* dirname = *_args0;
	bool ret = (bool)love_physfs::mkdir(dirname);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::remove 
 */
v8::Handle<v8::Value> JSlove_physfsRemove(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
		v8::String::Utf8Value _args0(args[0]);	char* filename = *_args0;
	bool ret = (bool)love_physfs::remove(filename);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::open 
 */
v8::Handle<v8::Value> JSlove_physfsOpen(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pFile file = JSpFileUnwrap(args[0]->ToObject());
	bool ret = (bool)love_physfs::open(file);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::close 
 */
v8::Handle<v8::Value> JSlove_physfsClose(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pFile file = JSpFileUnwrap(args[0]->ToObject());
	bool ret = (bool)love_physfs::close(file);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::eof 
 */
v8::Handle<v8::Value> JSlove_physfsEof(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pFile file = JSpFileUnwrap(args[0]->ToObject());
	bool ret = (bool)love_physfs::eof(file);
	return v8::Boolean::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::tell 
 */
v8::Handle<v8::Value> JSlove_physfsTell(const v8::Arguments& args) {
					
	if (args.Length() == 1) {
	v8::HandleScope handle_scope;
			pFile file = JSpFileUnwrap(args[0]->ToObject());
	int ret = (int)love_physfs::tell(file);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * love_physfs::seek 
 */
v8::Handle<v8::Value> JSlove_physfsSeek(const v8::Arguments& args) {
					
	if (args.Length() == 2) {
	v8::HandleScope handle_scope;
			pFile file = JSpFileUnwrap(args[0]->ToObject());
			int pos = args[1]->Int32Value();
	int ret = (int)love_physfs::seek(file,pos);
	return v8::Integer::New(ret);	
	}
	return v8::Undefined();
}


/**
 * SetupClass
 * Attach methods and properties
 */
void JSlove_physfsSetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
	js_obj->Set(v8::String::New("newFile"), v8::FunctionTemplate::New(JSlove_physfsNewFile));
	js_obj->Set(v8::String::New("getWorkingDirectory"), v8::FunctionTemplate::New(JSlove_physfsGetWorkingDirectory));
	js_obj->Set(v8::String::New("exists"), v8::FunctionTemplate::New(JSlove_physfsExists));
	js_obj->Set(v8::String::New("isDirectory"), v8::FunctionTemplate::New(JSlove_physfsIsDirectory));
	js_obj->Set(v8::String::New("isFile"), v8::FunctionTemplate::New(JSlove_physfsIsFile));
	js_obj->Set(v8::String::New("mkdir"), v8::FunctionTemplate::New(JSlove_physfsMkdir));
	js_obj->Set(v8::String::New("remove"), v8::FunctionTemplate::New(JSlove_physfsRemove));
	js_obj->Set(v8::String::New("open"), v8::FunctionTemplate::New(JSlove_physfsOpen));
	js_obj->Set(v8::String::New("close"), v8::FunctionTemplate::New(JSlove_physfsClose));
	js_obj->Set(v8::String::New("eof"), v8::FunctionTemplate::New(JSlove_physfsEof));
	js_obj->Set(v8::String::New("tell"), v8::FunctionTemplate::New(JSlove_physfsTell));
	js_obj->Set(v8::String::New("seek"), v8::FunctionTemplate::New(JSlove_physfsSeek));
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JSlove_physfsCreateClass() {
		v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
		js_func->SetClassName(v8::String::New("filesystem"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
		JSlove_physfsSetupClass(js_obj);
	return js_obj;
}



