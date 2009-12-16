#include "../../src/physfs/love_physfs.h"
#include "../../src/physfs/file.h"

namespace love_physfs

class pFile { [className=File]
	int getSize()
}

static class love_physfs { [className=filesystem]
	pFile newFile( char* filename )   	 Constructs a File with the given filename.
	pFile newFile( char* filename, int mode ) 	Constructs a File with the given filename.
		
	char* getWorkingDirectory( ) 	Gets the current working directory.
	//char* getSaveDirectory( ) 	Gets the full path to the designated save directory.
		
	bool exists( char* filename ) 	Check whether a file exists.
	bool isDirectory( char* dirname ) 	Check whether something is a directory.
	bool isFile( char* filename ) 	Check whether something is a file.
		
	bool mkdir( char* dirname ) 	Creates a directory.
	bool remove( char* filename ) 	Removes a file <or directory>.
		
	bool open( pFile file ) 	Opens the file for reading/writing <depending on its mode>.
	bool close( pFile file ) 	Closes the file.
		
	//read( pFile file ) 	Reads bytes from an opened File.
	//read( pFile file, int bytes ) 	Reads bytes from an opened File.
	//char* read( char* filename ) 	Quick read using filename.
	//read( char* filename, int bytes ) 	Quick read using filename.
	//write( file, data ) 	Writes bytes to an opened File.
	//bool write( char* filename, char* data ) 	Quick write using filename.
		
	//lines( pFile file ) 	Iterate the lines in a File.
	//int lines( char* filename ) 	Iterate the lines in a File.
		
	bool eof( pFile file ) 	Check if end-of-file is reached.
	int tell( pFile file ) 	Gets the current position in a file.
	int seek( pFile file, int pos ) 	Seek to a position within a file.
	//enumerate( dir ) 	Gets a list of files in the given directory.
		
	//require( char* filename ) 	Includes and runs a Lua file <once>.
	//include( char* filename ) 	Includes and runs a Lua file.
	//load( char* filename ) 	Loads a Lua-file without running it. 
}