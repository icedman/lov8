#include "../../src/opengl/love_opengl.h"
#include "../../src/opengl/Image.h"
#include "../../src/opengl/Color.h"
#include "../../src/opengl/Font.h"
#include "../../src/opengl/Animation.h"

namespace love_opengl

class Pointf { [struct=1]
	double x;
	double y;
}

class PointfList { [struct=1,array=1]
	Pointf items;
	int count;
}

class Rectf { [struct=1]
	double x;
	double y;
	double w;
	double h;	
}

class LineStipple { [struct=1]
	int pattern;
	int factor;
}

class DisplayMode { [struct=1]
	int width;
	int height;
}

class DisplayModeList { [struct=1,array=1]
	DisplayMode items;
	int count;
}

class pImage { [className=Image]
}

class pAnimation { [className=Animation]
	void addFrame( double x, double y, double w, double h, int delay )   	 Adds a single frame to the Animation.
	void setMode( int mode ) 	Sets the animation mode.
	void play( ) 	Starts the Animation.
	void stop( ) 	Stops the Animation
	void reset( ) 	Sets the current frame to the first frame and resets timer.
	void seek( int frame ) 	Sets the current frame.
	int getCurrentFrame( ) 	Gets the current frame number
	int getSize( ) 	Gets the number of frames.
	void setDelay( int frame, int delay ) 	Sets the delay of a specific frame.
	void setSpeed( int speed ) 	Sets the overall speed of the Animation.
	double getSpeed( ) 	Returns the current speed of the Animation.
	double getWidth( ) 	Gets the width of the current frame.
	double getHeight( ) 	Gets the height of the current frame.
	void setCenter( double x, double y ) 	Changes the center of the Animation.
	void update( double dt ) 	Updates the Animation
}

class pFont { [className=Font]
	int getHeight( )   	 Returns the height of the font.
	int getWidth( char* line ) 	Returns the width of the line.
	void setLineHeight( double height ) 	Sets the line height of the font.
	int getLineHeight( ) 	Returns the line height. 
}

class pColor { [className=Color]
}

class pParticleSystem { [className=ParticleSystem]
	void setBufferSize( int size )   	 Sets the size of the buffer <the max allowed amount of particles in the system>.
	void setSprite( pImage sprite ) 	Sets the image which is to be emitted.
		
	void setEmissionRate( int rate ) 	Sets the amount of particles emitted per second.
	void setLifetime( int life ) 	Sets how long the particle system should emit particles <if -1 then it emits particles forever>.
	void setParticleLife( int life ) 	Sets the life of the particles.
	void setParticleLife( int min, int max ) 	Sets the life of the particles.
		
	void setPosition( double x, double y ) 	Sets the position of the emitter.
	void setDirection( double direction ) 	Sets the direction the particles will be emitted in <in degrees>.
	void setSpread( double spread ) 	Sets the amount of spread for the system.
		
	void setSpeed( double speed ) 	Sets the speed of the particles.
	void setSpeed( double min, double max ) 	Sets the speed of the particles.
		
	void setGravity( double gravity ) 	Sets the gravity affecting the particles <acceleration along the y-axis>.
	void setGravity( double min, double max ) 	Sets the gravity affecting the particles <acceleration along the y-axis>.
	void setRadialAcceleration( double acceleration ) 	Sets the radial acceleration <acceleration towards the emitter>.
	void setRadialAcceleration( double min, double max ) 	Sets the radial acceleration <acceleration towards the emitter>.
	void setTangentialAcceleration( double acceleration ) 	Sets the tangential acceleration <acceleration perpendicular to the particle's direction>.
	void setTangentialAcceleration( double min, double max ) 	Sets the tangential acceleration <acceleration perpendicular to the particle's direction>.
		
	void setSize( double size ) 	Sets the size of the image <1.0 being normal size>.
	void setSize( double start, double end ) 	Sets the size of the image <1.0 being normal size>.
	void setSize( double start, double end, double variation ) 	Sets the size of the image <1.0 being normal size>.
	void setSizeVariation( double variation ) 	Sets the degree of variation <0 meaning no variation and 1 meaning full variation between start and end>.
		
	void setRotation( double rotation ) 	Sets the rotation of the image upon particle creation <in degrees>.
	void setRotation( double min, double max ) 	Sets the rotation of the image upon particle creation <in degrees>.
	void setSpin( double size ) 	Sets the spin of the sprite.
	void setSpin( double start, double end ) 	Sets the spin of the sprite.
	void setSpin( double start, double end, double variation ) 	Sets the spin of the sprite.
	void setSpinVariation( double variation ) 	Sets the degree of variation <0 meaning no variation and 1 meaning full variation between start and end>.
		
	void setColor( pColor color ) 	Sets the color of the image <color modulation needs to be activated for it to have any effect>.
	void setColor( pColor start, pColor end ) 	Sets the color of the image <color modulation needs to be activated for it to have any effect>.
		
	double getX( ) 	Gets the x-coordinate of the particle emitter's position.
	double getY( ) 	Gets the y-coordinate of the particle emitter's position.
	double getDirection( ) 	Gets the direction of the particle emitter <in degrees>.
	double getSpread( ) 	Gets the amount of directional spread of the particle emitter <in degrees>.
		
	int count( ) 	Gets the amount of particles that are currently in the system.
		
	void start( ) 	Starts the particle emitter.
	void stop( ) 	Stops the particle emitter, resetting the lifetime counter.
	void pause( ) 	Pauses the particle emitter.
	void reset( ) 	Resets the particle emitter, removing any existing particles and resetting the lifetime counter.
		
	bool isActive( ) 	Checks whether the particle system is actively emitting particles.
	bool isEmpty( ) 	Checks whether the particle system is empty of particles.
	bool isFull( ) 	Checks whether the particle system is full of particles.
		
	void update( double dt ) 	Updates the particle system; moving, creating and killing particles. 
}


static class love_opengl { [className=graphics]
	pImage newImage( char* filename )   	 Creates an Image.
	pImage newImage( char* filename, int mode ) 	Creates an Image with a certain mode.
	pAnimation newAnimation( pImage image ) 	Creates an Animation.
	pAnimation newAnimation( pImage image, int fw, int fh, int  delay, int frames ) 	Creates an Animation.
	pColor newColor( int red, int green, int blue, int alpha ) 	Creates a color.
	pColor newColor( int red, int green, int blue ) 	Creates a color.
	pFont newFont( char* filename ) 	Creates a new Font with size 12.
	pFont newFont( char* filename, int size ) 	Creates a new font by loading the font file.
	pFont newImageFont( char* filename, char* glyphs ) 	Creates a new font by loading a specifically formatted image.
	pFont newImageFont( char* filename, char* glyphs, int spacing ) 	Creates a new font by loading a specifically formatted image.
	pParticleSystem newParticleSystem( pImage image, int buffer ) 	Creates a particle emitter.
		
	bool checkMode( int width , int height, bool fullscreen ) 	Checks if a display mode is supported.
	void setMode( int width, int height, bool fullscreen, bool vsync, bool fsaa ) 	Changes the display mode.
	void toggleFullscreen( ) 	Toggles fullscreen.
	bool isCreated( ) 	Checks if the display has been set.
	DisplayModeList getModes( ) 	Gets a list of supported fullscreen modes.
	void setCaption( char* caption ) 	Sets the window caption.
		
	void setColor( pColor color ) 	Sets the current color.
	void setColor( int red, int green, int blue ) 	Sets the current color.
	void setColor( int red, int green, int blue, int alpha ) 	Sets the current color.
	void setBackgroundColor( pColor color ) 	Sets the background color.
	void setBackgroundColor( int red, int green, int blue ) 	Sets the background color.
	void setFont( int font ) 	Sets the current font.
	//void setFont( char* filename ) 	Loads a font, and sets it as current.
	void setFont( char*  filename, double size ) 	Loads a font, and sets it as current.
		
	void setLineWidth( double width ) 	Sets the line width.
	void setLineStyle( double style ) 	Sets line anti-aliasing.
	void setLine( double width ) 	Sets the width of the line used when drawing outlined primitives.
	void setLine( double width, double type ) 	Sets the width of the line used when drawing outlined primitives.
	void setLineStipple( ) 	Disables line stipple.
	void setLineStipple( int pattern ) 	Sets a new stipple pattern.
	void setLineStipple( int pattern, double repeat ) 	Sets a new stipple pattern.
	int getLineWidth( ) 	Gets the current line width.
	int getLineStyle( ) 	Gets the current line style.
	LineStipple getLineStipple( ) 	Gets the current stipple pattern.
		
	void setPointSize( double size ) 	Sets the point size.
	void setPointStyle( double style ) 	Sets the point style.
	void setPoint( double size, double style ) 	Sets the point size and style.
	int getPointSize( ) 	Gets the current point size.
	int getPointStyle( ) 	Gets the current point style.
	int getMaxPointSize( ) 	Gets the max supported point size.
		
	void setBlendMode( double mode ) 	Sets the blending mode.
	void setColorMode( double mode ) 	Sets the color mode.
	int getBlendMode( ) 	Gets the current blend mode.
	int getColorMode( ) 	Gets the current color mode.
		
	pColor getColor( ) 	Gets the current color.
	pColor getBackgroundColor( ) 	Gets the current background color.
	pFont getFont( ) 	Gets the current font.
		
	int getWidth( ) 	Gets the width of the window.
	int getHeight( ) 	Gets the height of the window.
		
	void setScissor( double x, double y, double width, double height ) 	Scissor defines a box such that everything outside that box is discared and not drawn.
	void setScissor( ) 	Clears the scissor area.
	Rectf getScissor( ) 	Gets the current scissor box.
		
	void drawText( char* string, double x, double y ) 	Draws text on screen.	[function=draw]
	void drawText( char* string, double x, double y, double angle ) 	Draws rotated text on screen.	[function=draw]
	void drawText( char* string, double x, double y, double angle, double s ) 	Draws rotated/scaled text on screen.	[function=draw]
	void drawText( char* string, double x, double y, double angle, double sx, double sy ) 	Draws rotated/scaled text on screen.[function=draw]
	
	void drawImage( pImage sprite , double x, double y ) 	Draws an Image or Animation on screen.	[function=draw]
	void drawImage( pImage sprite , double x , double y, double angle ) 	Draws a rotated Image or Animation on screen.	[function=draw]
	void drawImage( pImage sprite , double x , double y, double angle, double s ) 	Draws a rotated/scaled Image or Animation on screen.	[function=draw]
	void drawImage( pImage sprite , double x , double y, double angle, double sx, double sy ) 	Draws a rotated/scaled Image or Animation on screen.	[function=draw]
	
	void drawParticleSystem( pParticleSystem particles, double x, double y ) 	Draws a particle system on screen. [function=draw]
		
	void drawFormattedText( char* string , double x , double y, int limit ) 	Draws formatted text on screen, with word wrap. [function=drawf]
	void drawFormattedText( char* string , double x , double y, int limit, int align ) 	Draws formatted text on screen, with word wrap. [function=drawf]
		
	void drawImage( pImage image , double x , double y , double cx , double cy , double w , double h ) 	Draws a subsprite of an Image.	[function=draws]
	void drawImage( pImage image , double x , double y , double cx , double cy , double w , double h, double angle ) 	Draws a rotated subsprite of an Image.	[function=draws]
	void drawImage( pImage image , double x , double y , double cx , double cy , double w , double h, double angle, double s ) 	Draws a rotated/scaled subsprite of an Image.	[function=draws]
	void drawImage( pImage image , double x , double y , double cx , double cy , double w , double h, double angle, double sx, double sy ) 	Draws a rotated/scaled subsprite of an Image.	[function=draws]
	void drawImage( pImage image , double x , double y , double cx , double cy , double w , double h, double angle, double sx, double sy, double ox, double oy ) 	Draws a rotated/scaled subsprite of an Image, rotating around a different center.	[function=draws]
		
	void point( double x, double y ) 	Draws a point at <x,y>.
	void line( double x1, double y1, double x2, double y2 ) 	Draws a line from <x1,y1> to <x2,y2>.
	void triangle( double type, double x1, double y1, double x2, double y2, double x3, double y3 ) 	Draws a triangle usign the passed coordinates.
	void rectangle( double type, double x, double y, double w, double h ) 	Draws a rectangle.
	void quad( double type, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4 ) 	Draws a quadrilateral usign the passed coordinates.
	void circle( double type, double x, double y, double radius ) 	Draws a circle usign the passed information.
	void circle( double type, double x, double y, double radius, double points ) 	Draws a circle usign the passed information.
	
	void polygon( int type, PointfList points ) 	Draws a polygon.
		
	void screenshot( char* filename ) 	Save a screenshot as BMP. 
}