#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include"SDL.h"
#include "SDL_image.h"
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "stems.h"
#include "variables.h"

SDL_Surface *load_image( std::string filename,int n=0 )
{
    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );

        SDL_FreeSurface( loadedImage );

        if( optimizedImage != NULL )
        {
            if(n==0)
            {

			//Arka plana göre transparanlik saglanmasi.
			// (0, 0, 255) degerindeki pikseller arka plan görüntüsüne uygun renk degerine atanacak
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0, 255 );

            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }
            else if(n==1)
            {

            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 255, 128 );

            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }

        }
    }

    return optimizedImage;
}
bool load_files()
{
    background = load_image( "images/background1.png" );

    if( background == NULL )
    {
        return false;
    }

    font = TTF_OpenFont( "ArchitectsDaughter.ttf", 30 );
    if( font == NULL )
    {
        return false;
    }
    STEMS = load_image("images/stem1.png");
    if(STEMS==NULL)
    {
        return false;
    }

    bird = load_image( "images/bird1.png" );

    if( bird == NULL )
    {
        return false;
    }

    music = Mix_LoadWAV( "sound/gm.wav" );

    if( music == NULL )
    {
        return false;
    }

    return true;
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {

        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL )
    {
        return false;
    }

    if( TTF_Init() == -1 )
    {
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }


    SDL_WM_SetCaption( "..! ZIPZIP KUS !..", NULL );

    return true;
}

void clean_up()
{

    SDL_FreeSurface( bird );
    SDL_FreeSurface( STEMS );
    SDL_FreeSurface( background );


    TTF_CloseFont( font );

    Mix_FreeChunk( music );
    Mix_FreeChunk(boom);
    Mix_FreeChunk(loading);

    TTF_Quit();

    Mix_CloseAudio();

    SDL_Quit();
}
#endif // LOADER_H_INCLUDED

