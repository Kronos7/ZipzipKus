#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

void wall_coord()
{
			wall[0].x =650;			wall[1].x=800;
            wall[0].y =70;			wall[1].y=500;

            wall[2].x =1400;		wall[3].x=1800;
            wall[2].y =100;			wall[3].y=180;

            wall[4].x =2200;		wall[5].x=2700;
            wall[4].y =260;			wall[5].y=60;

			wall[6].x =2700;		wall[7].x=3200;
            wall[6].y =520;			wall[7].y=150;

			wall[8].x =3500;		wall[9].x=4000;
            wall[8].y =500;			wall[9].y=60;

			wall[10].x =4000;		wall[11].x=4300;
            wall[10].y =500;		wall[11].y=300;

			wall[12].x =4600;		wall[13].x=5300;
            wall[12].y =300;		wall[13].y=70;

			wall[14].x =5300;		wall[15].x=6200;
            wall[14].y =520;		wall[15].y=300;

            for(int i=0;i<16;++i)
            {
                wall[i].w = STEM_WIDTH;
                wall[i].h = STEM_HEIGHT;
            }
}

int play()
{
	int level = 1;
    wall_coord();

    bool quit = false;

    int bgX = 0, bgY = 0; //Arka plan offset degerleri
    Bird mybird;

    Timer fps;
    stem stm;

    Window myWindow;

    if( myWindow.error() == true )
    {
        return 1;
    }

    if( load_files() == false )
    {
        return 1;
    }

	Mix_PlayChannel(-1, music ,-1);

    fps.start();

    while( quit == false )
    {

        while( SDL_PollEvent( &event ) )
        {

            myWindow.handle_events();

            mybird.handle_input(level);

            if(event.type==SDL_KEYDOWN)
            {
                 if( event.key.keysym.sym==SDLK_ESCAPE)
                {
                        //Mix_FreeMusic( music );
                          quit=true;
                }

                else if( event.type == SDL_QUIT )
                {
                    quit = true;
                }

            }
        }
        
		if(level == 1)
        {
            bgX -= 10;
            
			for(int i=0;i<16;++i)
            {
                wall[i].x-=10;
            }

        }

        else if(level == 2)
        {
            bgX-=14;
            
			for(int i=0;i<16;++i)
            {
                wall[i].x-=14;
            }
        }

        else if(level == 3)
        {
            bgX-=18;
            
			for(int i=0;i<16;++i)
            {
                wall[i].x-=18;
            }
        }

        if( bgX <= -background->w ) //Oyun akýsýnda arka planýn yenilenmesi
        {
            bgX = 0;

			wall_coord();
        }

        //Arka planin gösterilmesi
        apply_surface( bgX, bgY, background, screen );
        apply_surface( bgX + background->w, bgY, background, screen );

        if( myWindow.error() == true )
        {
            return 1;
        }

        if ( mybird.move() == true ) // Ayni zamanda carpisma testi
		{
            bird=NULL;
            bird=load_image("images/birdgo1.png");
            game_over=load_image("images/go.png");

            apply_surface(mybird.box.x, mybird.box.y, bird, screen);
            
			SDL_Flip(screen);

			update_screen( fps , mybird.get_score(), level);
			apply_surface(0,0,game_over,screen);
            SDL_Flip(screen);

            SDL_Delay(4000);
            SDL_Flip(screen);

			break;
		}

        mybird.show();
        stm.show();

        update_screen( fps , mybird.get_score(), level);

		if(level == 1 && fps.get_ticks()>60000) // TUR SÜRESI
        {
			fps.pause();
			SDL_Delay(2000);
            SDL_Flip(screen);
			level++;
			bgX = 0;
			wall_coord();
			mybird.reset_offset();
			fps.unpause();
        }

		else if(level == 2 && fps.get_ticks()>120000) // TUR SÜRESI
        {
			fps.pause();
			SDL_Delay(2000);
            SDL_Flip(screen);
			level++;
			bgX = 0;
			wall_coord();
			mybird.reset_offset();
			fps.unpause();
        }
        
		else if(level == 3 && fps.get_ticks()>180000) // TUR SÜRESI
        {
			apply_surface(mybird.box.x, mybird.box.y, bird, screen);
            game_over=load_image("images/go.png");
            
			SDL_Flip(screen);

			update_screen( fps , mybird.get_score(), level);
			apply_surface(0,0,game_over,screen);
            SDL_Flip(screen);

            SDL_Delay(5000);
            SDL_Flip(screen);

			break;
        }

        if( SDL_Flip( screen ) == -1 ) //Ekranin yenilenmesi
        {
            return 1;
        }

        mybird.set_camera();

        apply_surface( 0, 0, background, screen, &camera );

        if( fps.get_ticks() < 1000 /FRAMES_PER_SECOND ) //Gecikme zamaninin düzenlenmesi
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    return 0;
}


#endif // PLAY_H_INCLUDED
