#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <sstream>
#include "bird.h"

void sound_off();
void sound_on();
void clean_menu_surfaces();
void update_screen(Timer& time,int score);

int game_menu()
{

    int choice;
    int x,y;

    menu = load_image("images/menu/menuo.png");
    play_menu = load_image("images/menu/start.png");
    Instruc_menu = load_image("images/menu/instructions.png");
    quit_menu = load_image("images/menu/quit.png");

    bool session=true;

    apply_surface(0,0,menu,screen);

    back_music=Mix_LoadWAV("sound/birds.wav");
    Mix_PlayChannel(-1,back_music,-1);

    while(session)
    while(SDL_PollEvent(&mouse_event))
        {
            if(mouse_event.type==SDL_MOUSEMOTION)
            {
                    x = mouse_event.motion.x;
                    y = mouse_event.motion.y;

                    if((x>51)&&(x<444)&&(y>435)&&(y<512))     // 'BAÞLA' secenegi
                    {
                        apply_surface(0,0,play_menu,screen);
                    }

                    else if((x>290)&&(x<1024)&&(y>550)&&(y<627))    // 'Nasil Oynanir?' secenegi
                    {
                        apply_surface(0,0,Instruc_menu,screen);
                    }

                    else if((x>939)&&(x<1281)&&(y>652)&&(y<755))    // 'CIKIS' secenegi
                    {
                        apply_surface(0,0,quit_menu,screen);
                    }
                    
					else
                    {
                        apply_surface(0,0,menu,screen);
                    }
                    
					SDL_Flip(screen); // Ekran yenileniyor
            }

            if(mouse_event.type == SDL_MOUSEBUTTONDOWN)
            {
                    x = mouse_event.motion.x;
                    y = mouse_event.motion.y;

                    if((x>51)&&(x<444)&&(y>435)&&(y<512))
                    {
						choice = 1;
						session = false;
                    }

					else if((x>290)&&(x<1024)&&(y>550)&&(y<627))
					{
						choice = 2;

						Ins1 = load_image("images/menu/ins/ins1.png");
						Ins2 = load_image("images/menu/ins/ins2.png");

						apply_surface(0,0,Ins1,screen);
                        SDL_Flip(screen);

                        int ax,ay;
                        bool bye = false;

						while(!bye)
                        {

                            while(SDL_PollEvent(&mouse_event))
                            {
                                if(mouse_event.type==SDL_MOUSEMOTION)
                                    {
                                        ax = mouse_event.motion.x;
                                        ay = mouse_event.motion.y;

                                        if((ax>1050)&&(ax<1280)&&(ay>670)&&(ay<750))
                                        {
                                            apply_surface(0,0,Ins2,screen);
                                        }
                                        else
                                        {
                                            apply_surface(0,0,Ins1,screen);
                                        }
                                    }

                                if(mouse_event.type == SDL_MOUSEBUTTONDOWN)
                                    {
                                         ax = mouse_event.motion.x;
                                         ay = mouse_event.motion.y;
                                         
										 if( (ax>1050)&&(ax<1280)&&(ay>670)&&(ay<750) )
                                         {
											bye = true;
                                         }
                                    }
                                SDL_Flip(screen);
                            }
                            SDL_Flip(screen);
                        }
                        apply_surface(0,0,menu,screen);
						session = false;
                    }

                    else if((x>939)&&(x<1281)&&(y>652)&&(y<755))
                    {
						choice = 3;
						session = false;
                    }
            }

            switch( mouse_event.type )
            {
            case SDL_KEYDOWN:
				if( mouse_event.key.keysym.sym == SDLK_ESCAPE )
				{
					choice = 3;
					session = false;
				}
            break;

            case SDL_QUIT:
                 choice = 3;
                 session = false;
                 break;
            }
        }

    clean_menu_surfaces();
    return choice;
}

void update_screen(Timer& TimE,int score, int level)
{
    std::stringstream samaya;
    int a=TimE.get_ticks();
    if(a<60000)
        {
           samaya<< "Seviye-" << level << " / Puan: "<<score
           <<" / Zaman: " << a/60000<<" : "<<a / 1000;
        }
        else
        {
            int sec=a/1000;
            int min=0;
            min=sec/60;
            sec-=min*60;
            samaya<< "Seviye-" << level << " / Puan: "<<score
            << " / Zaman: " << min<<" : "<<sec;

        }
    message = TTF_RenderText_Solid( font , samaya.str().c_str() , textColor ) ;
    apply_surface((SCREEN_WIDTH-message->w)/2,0,message,screen);
    SDL_FreeSurface(message);
}

void clean_menu_surfaces()
{
    SDL_FreeSurface(menu);
    SDL_FreeSurface(play_menu);
    SDL_FreeSurface(Instruc_menu);
    SDL_FreeSurface(quit_menu);

    Mix_FreeChunk(back_music);
}
#endif // FUNCTIONS_H_INCLUDED
