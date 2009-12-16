#include "../../src/sdlmixer/love_sdlmixer.h"
#include "../../src/sdlmixer/sound.h"
#include "../../src/sdlmixer/music.h"

namespace love_sdlmixer

class pSound { [className=Sound]
	void setVolume( int vol )
}

class pMusic { [className=Music]
}

static class love_sdlmixer { [className=audio]
	pSound newSound( char* filename )   	 Loads a sound file.
	pMusic newMusic( char* filename ) 	Loads a music file.
		
	void playSound( pSound sound ) 	Plays a sound.	[function=play]
	void playSound( pSound sound , bool loop ) 	Plays a sound.	[function=play]
		
	void playMusic( pMusic music ) 	Plays a sound.	[function=play]
	void playMusic( pMusic music, bool loop ) 	Plays a sound.	[function=play]
		
	void pause( ) 	Pauses all audio playback.
	void resume( ) 	Resumes all audio playback.
	void stop( ) 	Stops all audio playback.
		
	bool isPlaying( ) 	Checks whether <any> audio is playing or not.
	bool isPaused( ) 	Checks whether audio playback is paused or not.
		
	void setChannels( int channels ) 	Sets the amount of channels for sounds.
	void setMode( int frequency, int mode, int buffersize ) 	Sets the mode for audio mixing and playback.
		
	void setVolume( int volume ) 	Changes the master volume. 
}