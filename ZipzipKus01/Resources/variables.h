#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
///SDL SURFACE POINTERS
SDL_Surface *game_over=NULL;
SDL_Surface *background = NULL;
SDL_Surface *STEMS= NULL;
SDL_Surface *screen = NULL;

SDL_Surface *bird=NULL;
TTF_Font    *font = NULL;
SDL_Surface *message=NULL;

Mix_Chunk   *music = NULL;
Mix_Chunk   *back_music=NULL;
Mix_Chunk   *selection = NULL;
Mix_Chunk   *boom=NULL;
Mix_Chunk   *loading=NULL;
Mix_Chunk   *proceed=NULL;

SDL_Surface* menu =NULL;
SDL_Surface* play_menu = NULL;
SDL_Surface* Instruc_menu = NULL;
SDL_Surface* Ins1 = NULL;
SDL_Surface* Ins2 = NULL;
SDL_Surface* quit_menu = NULL;

SDL_Event event;
SDL_Event mouse_event;

SDL_Color textColor = { 255, 0, 0};

#endif // VARIABLES_H_INCLUDED
