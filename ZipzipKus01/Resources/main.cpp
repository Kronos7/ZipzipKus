#include "SDL.h"
#include "SDL_image.h"
#include <SDL_mixer.h>
#include <string>

#include "bird.h"
#include "loader.h"
#include "timer.h"
#include "window.h"
#include "stems.h"
#include "game_functions.h"
#include "play.h"

int main(int argc, char* args[])
{
    bool cont=true;

    if( init() == false )
    {
        return 1;
    }

    Window my;
    my.toggle_fullscreen(); //Tam ekran moduna gecilmesi

    int opt;

    while(cont)
    {
        opt = game_menu(); //Menü cagrisi
        
		switch(opt)
        {
            case 1:
                play(); //Oyun döngüsü
				Mix_FreeChunk(music);
                break;

            case 2:
				//Nasil Oynanir?
                break;

            case 3:
                //Cikis
				cont=false;
                break;

            default:
                break;
        }
    }

    //clean_up();
    return 0;
}
