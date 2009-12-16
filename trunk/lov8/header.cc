<?php foreach($this->objects as $object) : ?>
#include "<?php echo strtolower($object['name']);?>.h";
<?php endforeach; ?>

<?php foreach($this->objects as $object) : ?>
void JS<?php echo $object['name'];?>SetupClass(v8::Handle<v8::ObjectTemplate> js_obj);
v8::Handle<v8::FunctionTemplate> JS<?php echo $object['name'];?>CreateClass();
<?php endforeach; ?>