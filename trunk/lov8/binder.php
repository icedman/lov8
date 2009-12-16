<?php

require_once 'parser.php';

if ($argc < 2) {
	echo "Usage: binder <source>\n       -g generate file\n";
	exit;
}

$source = $argv[$argc-1];
$savefile = false;

for($i = 0; $i<$argc; $i++) {
	if ($argv[$i] == '-g')
		$savefile = true;
}

function generate($source) {
	global $savefile;
	
	$p = new Parser;
	$p->parse('types.hh');
	$p->parse($source);
	ob_start();
	$p->render('implementation.cc');
	$contents = ob_get_contents();
	ob_clean();
	
	if (!$savefile)
		echo $contents;
	else
		file_put_contents('generated/' . str_replace('.i','.cpp',$source), $contents);
}

if ($source == 'all') {
	$handler = opendir(".");

    // keep going until all files in directory have been read
    while ($file = readdir($handler)) {
        if ($file != '.' && $file != '..') {
            if (preg_match('/\.i/', $file))
				generate($file);
		}
    }

    closedir($handler);

} else {
	generate($source);
}