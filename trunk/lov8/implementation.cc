#include <v8.h>
#include "../v8Object.h"
<?php foreach($this->includes as $inc) : ?>
#include <?php echo strtolower($inc['file']);?>

<?php endforeach; ?>

<?php foreach($this->namespaces as $nm) : ?>
using namespace <?php echo $nm['namespace'];?>;
<?php endforeach; ?>

// extern
<?php foreach($this->externs as $ex) : ?>
extern v8::Handle<v8::Value>  JS<?php echo $ex['extern'];?>Wrap(<?php echo $ex['extern'];?> cppObject);
extern <?php echo $ex['extern'];?> JS<?php echo $ex['extern'];?>Unwrap(v8::Handle<v8::Value> value);
<?php endforeach; ?>

// forward declaractions
<?php foreach($this->structs as $object) : ?>
v8::Handle<v8::Value> JS<?php echo $object['name'];?>Wrap(<?php echo $object['name'];?> cppObject);
<?php echo $object['name'];?> JS<?php echo $object['name'];?>Unwrap(v8::Handle<v8::Value> value);
<?php endforeach; ?>

<?php foreach($this->objects as $object) : ?><?php if ($object['name'] == 'Global') continue;?>

void JS<?php echo $object['name'];?>SetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::ObjectTemplate> JS<?php echo $object['name'];?>CreateClass();
<?php if (!$object['static']) :?>
v8::Handle<v8::Value> JS<?php echo $object['name'];?>Wrap(<?php echo $object['name'];?> cppObject);
<?php echo $object['name'];?> JS<?php echo $object['name'];?>Unwrap(v8::Handle<v8::Value> value);
<?php endif; ?>

<?php if (!$object['static']) :?>

/**
 *----------------------------------------
 * <?php echo $object['name']; ?>
 
 *----------------------------------------
 */
 
/**
 * DestroyInstance
 * Called when weak object is destroyed
 */
void JS<?php echo $object['name']; ?>DestroyInstance(v8::Persistent<v8::Value> object, void* parameter) {
	WrappedObject<<?php echo $object['name'];?>> *p = static_cast<WrappedObject<<?php echo $object['name'];?>>*>(parameter);
	delete p;
	object.Dispose();
}

/**
 * CreateInstance
 * Called when an object is created
 */
v8::Handle<v8::Value> JS<?php echo $object['name']; ?>CreateInstance(const v8::Arguments& args) {
	/*
	// todo
	
	<?php echo $object['name']; ?> *obj = 0;
	<?php
	if (!empty($object['methods'][$object['name']]))
	foreach($object['methods'][$object['name']] as $method) :
	?>	
	if (args.Length() == <?php echo count($method['params']); ?>) {
	<?php $params = array(); foreach($method['params'] as $n=>$param) : ?>
	<?php echo $param['type'];?> <?php echo $param['name'];?> = <?php echo $this->wrap($param['type'],"args[{$n}]");?>;
	<?php $params[] = $param['name']; endforeach; ?>
	obj = new <?php echo $object['name'];?>(<?php echo implode(',', $params);?>);
	}
	<?php endforeach; ?>
	
	if (!obj)
		obj = new <?php echo $object['name']; ?>;
	
	// call wrapper
	*/
	
	return v8::Undefined(); 
}
<?php endif; ?>
 
<?php foreach($object['methods'] as $name => $methods) : ?>
<?php if ($object['name'] == $name) continue;?>

/**
 * <?php echo $object['name'] . '::' . $name; ?>
 
 */
v8::Handle<v8::Value> JS<?php echo $object['name']; ?><?php echo ucwords($name);?>(const v8::Arguments& args) {
	<?php if (!$object['static']) :?>
	<?php echo $object['name']; ?> obj;
	<?php endif; ?>
	<?php if ($object['static']) : ?>
	<?php else: ?>

	v8::Local<v8::Object> self = args.Holder();
	if (self->InternalFieldCount()) {
    obj = static_cast<<?php echo $object['name']; ?>>(JS<?php echo $object['name']; ?>Unwrap(self));		
	} else {
	return v8::Undefined();
	}
	
	<?php endif; ?>
	<?php
	foreach($methods as $method) :
	?>	
	if (args.Length() == <?php echo count($method['params']); ?>) {
	v8::HandleScope handle_scope;
	<?php $params = array(); foreach($method['params'] as $n=>$param) : ?>
	<?php echo $this->preunwrap($param['type'],"args[{$n}]");?>
	<?php echo $param['type'];?> <?php echo $param['name'];?> = <?php echo $this->unwrap($param['type'],"args[{$n}]");?>;
	<?php $params[] = $param['name']; endforeach; ?>
<?php if ($object['static'] || $method['static']) : ?>
<?php if ($method['type'] != 'void') echo "{$method['type']} ret = ({$method['type']})";?><?php echo "{$object['name']}";?>::<?php echo $method['function'];?>(<?php echo implode(',', $params);?>);
	<?php if ($method['type'] != 'void') echo "return " . $this->wrap($method['type'],'ret') . ";";?>
<?php else :?>
<?php if ($method['type'] != 'void') echo "{$method['type']} ret = ({$method['type']})";?>obj-><?php echo $method['function'];?>(<?php echo implode(',', $params);?>);
	<?php if ($method['type'] != 'void') echo "return " . $this->wrap($method['type'],'ret') . ";";?>
<?php endif;?>
	
	}
<?php endforeach; ?>
	return v8::Undefined();
}

<?php endforeach; ?>

/**
 * SetupClass
 * Attach methods and properties
 */
void JS<?php echo $object['name'];?>SetupClass(v8::Handle<v8::ObjectTemplate> js_obj) {
<?php foreach($object['methods'] as $name => $methods) : if ($name == $object['name']) continue; ?>
	js_obj->Set(v8::String::New("<?php echo $name;?>"), v8::FunctionTemplate::New(JS<?php echo $object['name'] . ucwords($name);?>));
<?php endforeach; ?>
<?php foreach($object['inherits'] as $parent) : ;?>
	JS<?php echo $parent;?>SetupClass(js_obj);
<?php endforeach; ?>
}

/**
 * CreateClass
 * Creates a JS object
 */
v8::Handle<v8::ObjectTemplate> JS<?php echo $object['name'];?>CreateClass() {
	<?php if ($object['static']) :?>
	v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New();
	<?php else : ?>
	v8::Handle<v8::FunctionTemplate> js_func = v8::FunctionTemplate::New(JS<?php echo $object['name'];?>CreateInstance);
	<?php endif; ?>
	js_func->SetClassName(v8::String::New("<?php echo $object['className'];?>"));
	v8::Handle<v8::ObjectTemplate> js_obj = js_func->InstanceTemplate();
	<?php if (!$object['static']) :?>
	js_obj->SetInternalFieldCount(1);
	<?php endif; ?>
	JS<?php echo $object['name'];?>SetupClass(js_obj);
	return js_obj;
}

<?php if (!$object['static']) :?>
/**
 * Wrap
 * Wraps a cpp class into a JS object
 */
v8::Handle<v8::Value> JS<?php echo $object['name'];?>Wrap(<?php echo $object['name'];?> cppObject) {
	WrappedObject<<?php echo $object['name'];?>> *p = new WrappedObject<<?php echo $object['name'];?>>(cppObject);
	v8::Handle<v8::ObjectTemplate> objT = v8::ObjectTemplate::New();
	JS<?php echo $object['name'];?>SetupClass(objT);
	objT->SetInternalFieldCount(1);
	v8::Handle<v8::Object> obj = objT->NewInstance();
	obj->SetInternalField(0, v8::External::New((void*)p));
	
	// make weak
	v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(obj);
	self.MakeWeak((void*)p, &JS<?php echo $object['name'];?>DestroyInstance);
	
	return obj;
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
<?php echo $object['name'];?> JS<?php echo $object['name'];?>Unwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	<?php echo $object['name'];?> obj;
	v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(value->ToObject());
	WrappedObject<<?php echo $object['name'];?>> *p = static_cast<WrappedObject<<?php echo $object['name'];?>>*>(wrap->Value());
	obj = p->unwrap();
	return obj;
}
<?php endif; ?>

<?php endforeach; ?>

<?php foreach($this->structs as $object) : ?>
/**
 * Wrap
 * Wraps a c struct into a JS object
 */
v8::Handle<v8::Value> JS<?php echo $object['name'];?>Wrap(<?php echo $object['name'];?> cobj) {
	<?php if (empty($object['array'])) : ?>
	v8::Handle<v8::Object> obj = v8::Object::New();

	<?php foreach($object['properties'] as $prop) : ?>
	
	obj->Set(v8::String::New("<?php echo $prop['name'];?>"),<?php echo $this->wrap($prop['type'],'cobj.' . $prop['get']);?>, v8::ReadOnly); 
	
	<?php endforeach; ?>
	return obj;
	
	<?php else : ?>
	v8::Handle<v8::Array> obj = v8::Array::New();
	
	for(int i = 0; i<cobj.length(); i++) {
		obj->Set(v8::Integer::New(i), JS<?php echo $object['properties']['items']['type'];?>Wrap(cobj.at(i)));
	}
		
	return obj;
	<?php endif; ?>
}

/**
 * Unwrap
 * Unwrap a JS object int a cpp class
 */
<?php echo $object['name'];?> JS<?php echo $object['name'];?>Unwrap(v8::Handle<v8::Value> value) {
	if (value->ToObject()->InternalFieldCount())
		value = value->ToObject()->GetInternalField(0);
	<?php echo $object['name'];?> cobj;
	<?php if (empty($object['array'])) : ?>
	if (value->IsObject()) {
	v8::Handle<v8::Object> obj = value->ToObject();
	<?php foreach($object['properties'] as $prop) : ?>
	
		cobj.<?php echo $prop['name'];?> = <?php echo $this->unwrap($prop['type'], "obj->Get(v8::String::New(\"{$prop['name']}\"))");?>;
	<?php endforeach;?>
	
	}
	return cobj;
	<?php else : ?>

	cobj.init(0, 0);
	if (value->IsArray()) {
		v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(value);
		if (arr->Length()) {
			cobj.init(new <?php echo $object['properties']['items']['type'];?>[arr->Length()],arr->Length());
			for(int i = 0; i<cobj.count; i++) {
				cobj.items[i] = JS<?php echo $object['properties']['items']['type'];?>Unwrap(arr->Get(v8::Integer::New(i)));
			}
		}
	}
	
	return cobj;
	<?php endif; ?>
}
<?php endforeach; ?>