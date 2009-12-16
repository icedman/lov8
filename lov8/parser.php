<?php

class Parser {

	var $namespaces = array();
	var $includes = array();
	var $objects = array();
	var $structs = array();
	var $externs = array();
	var $map = array();

	function parseOverRide($l, $ret) {
		if (preg_match('/\[(.*)\]/', $l, $m)) {
			$overrides = explode(',',$m[1]);
			foreach($overrides as $over) {
				$params = explode(',',trim($over));
				foreach($params as $p) {
					$vv = explode('=',trim($p));
					if (count($vv) == 2)
						$ret[$vv[0]] = trim($vv[1]);
				}
			}
		}
		return $ret;
	}
	
	function parseLine($l) {
		if (empty($l))
			return null;
			
		$ret = array();
		
		for($i = 0; $i<4; $i++)
			$l = str_replace('  ', ' ', $l);
		
		// comment
		if (preg_match('/\/\//', $l))
			return null;
			
		// include
		if (preg_match('/include\s(.*)/', $l, $m)) {
			$ret['_t'] = 'include';
			$ret['file'] = trim($m[1]);
			return $ret;			
		}
		
		// namespace
		if (preg_match('/namespace\s(.*)/', $l, $m)) {
			$ret['_t'] = 'namespace';
			$ret['namespace'] = trim($m[1]);
			return $ret;			
		}
		
		// extern
		if (preg_match('/extern\s(.*)/', $l, $m)) {
			$ret['_t'] = 'extern';
			$ret['extern'] = trim($m[1]);
			return $ret;			
		}		
		
		// map
		if (preg_match('/map\s\((.*)\)/', $l, $m)) {
			$map = explode(',',$m[1]);
			$ret['_t'] = 'map';
			$ret['name'] = trim($map[0]);
			$ret['wrap'] = trim($map[1]);
			$ret['unwrap'] = trim($map[2]);
			$ret['prewrap'] = trim($map[3]);
			$ret['preunwrap'] = trim($map[4]);
			return $this->parseOverRide($l,$ret);
		}
		
		// method
		if (preg_match('/(.*)\((.*)\)/', $l, $m)) {
			$func = explode(' ',trim($m[1]));
			$params = explode(',',trim($m[2]));
			$ret['_t'] = 'method';
			$ret['static'] = ($func[0] == 'static');
			$ret['type'] = '';
			$ret['name'] = trim($func[count($func)-1]);
			if (count($func) > 1)
				$ret['type'] = trim($func[count($func)-2]);	
			$ret['params'] = array();
			foreach($params as $p) {
				if (empty($p))
					continue;
				$pp = explode(' ',trim($p));
				$ret['params'][] = array('type'=>trim($pp[0]),'name'=>trim($pp[1]));
			}
			return $this->parseOverRide($l,$ret);
		}
		
		// class
		if (preg_match('/class(.*)[\{]/', $l, $m)) {
			$classes = explode(':',$m[1]);
			$ret['_t'] = 'class';
			$ret['name'] = trim($classes[0]);
			$ret['className'] = trim($classes[0]);
			$ret['static'] = preg_match('/static\s/', $l);
			$ret['inherits'] = array();
			$ret['methods'] = array();
			if (count($classes)>1) {
				$in = explode(',',trim($classes[1]));
				//print_r($in);
				foreach($in as $i) {
					$ii = explode(' ', trim($i));
					$ret['inherits'][] = $ii[count($ii)-1];
				}
			}
			return $this->parseOverRide($l,$ret);
		}
		
		if (preg_match('/\}/', $l, $m)) {
			$ret['_t'] = '_class';
			return $this->parseOverRide($l,$ret);
		}
		
		// property
		if (preg_match('/(.*);/', $l, $m)) {
			$ii = explode(' ', trim($m[1]));
			if (count($ii) == 2) {
				$ret['_t'] = 'property';
				$ret['type'] = trim($ii[0]);
				$ret['name'] = trim($ii[1]);
				$ret['get'] = trim($ii[1]);
				$ret['set'] = trim($ii[1]);
				return $this->parseOverRide($l,$ret);
			}
		}
		
		return null;
	}
	
	function parse($file) {
		
		$objects = &$this->objects;
		$structs = &$this->structs;
		$map = &$this->map;
		$stack = array();
		
		$objects[] = array('name'=>'Global','inherits'=>array(),'static'=>false,'methods'=>array());
		$stack[] = &$objects[count($objects)-1];
		
		$fp = fopen($file, 'r');
		if (!$fp) {
			echo "Unable to open file\n";
			return;
		}
		while($l = fgets($fp)) {
			$r = $this->parseLine($l);
			if (!$r)
				continue;
			$target = &$stack[count($stack)-1];
			switch($r['_t']) {
			case 'include':
				$this->includes[] = $r;
				break;
			case 'namespace':
				$this->namespaces[] = $r;
				break;
			case 'extern':
				$this->externs[] = $r;
				break;				
			case 'class':
				if (!empty($r['struct'])) {
					$structs[] = $r;
					$stack[] = &$structs[count($structs)-1];
				} else {
					$objects[] = $r;
					$stack[] = &$objects[count($objects)-1];
				}
				break;
			case '_class':
				array_pop($stack);
				break;
			case 'method':
				if (empty($target['methods'][$r['name']]))
					$target['methods'][$r['name']] = array();
				if (empty($r['function']))
					$r['function'] = $r['name'];
				$target['methods'][$r['name']][] = $r;
				break;
			case 'property':
				if (empty($target['properties']))
					$target['properties'] = array();
				$target['properties'][$r['name']] = $r;
				break;	
			case 'map':
				$map[$r['name']] = $r;
				break;
			}
		}
		fclose($fp);
	}
	
	function isObject($type) {
		return (empty($this->map[$type]));
	}

	function wrap($type, $value, $act='wrap') {
		if (!empty($this->map[$type])) {
			$nv = str_replace('[','',$value);
			$nv = str_replace(']','',$nv);
			$t = $this->map[$type][$act];
			$t = str_replace('%v',$value,$t);
			$t = str_replace('%nv',$nv,$t);
			return $t;
		}
		// we're an object
		switch($act) {
		case 'wrap':
			return "JS{$type}Wrap({$value})";
		case 'unwrap':
			//return "JS{$type}Unwrap({$value}->ToObject()->GetInternalField(0))";
			return "JS{$type}Unwrap({$value}->ToObject())";
		}
		
		return '';
	}
	
	function unwrap($type, $value) {
		return $this->wrap($type, $value, 'unwrap');
	}
	
	function prewrap($type, $value) {
		return $this->wrap($type, $value, 'prewrap');
	}
	
	function preunwrap($type, $value) {
		return $this->wrap($type, $value, 'preunwrap');
	}
	
	function render($filename) {
		require $filename;
	}
}