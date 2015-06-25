#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED

#include "loader.h"
#include "stems.h"
#include "timer.h"

class Bird:
	public Timer
{
    private:

    int xVel, yVel; //Kusun hiz degerleri
    static int score;

    public:

    SDL_Rect box; //Kusun carpisma kutusu
    Bird();

    void handle_input(int);

    bool move();

    void show();

	void reset_offset();

    void set_camera();

    static int get_score();
};

int Bird::score=0;

Bird::Bird()
{
    box.x =350; //Offset degerleri
    box.y =350;

    box.w = BIRD_WIDTH;
    box.h = BIRD_HEIGHT;

    xVel = 0;
    yVel = 5;

	score = 0;
}

void Bird::reset_offset()
{
	box.x =350;
    box.y =250;
}

int Bird:: get_score()
{
    return score;
}

void Bird::handle_input(int level)
{

    if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= BIRD_HEIGHT / 2;
                break;
            case SDLK_DOWN: yVel += BIRD_HEIGHT / 5;
				if( level == 1)
					score+=1;
				else if (level == 2)
					score+=2;
				else if (level == 3)
					score+=3;
				break;
            default:
                break;

        }

    }

    else if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += BIRD_HEIGHT / 2;
				if( level == 1)
					score+=1;
				else if (level == 2)
					score+=2;
				else if (level == 3)
					score+=3;
				break;
            case SDLK_DOWN: yVel -= BIRD_HEIGHT / 5;
				break;

            default:
                break;
        }
    }
}

bool Bird::move()
{
    box.y += yVel;

    for(int i=0;i<16;++i) // Kus icin carpisma testi
    {
        if( ( box.y < -10 ) || ( box.y + BIRD_HEIGHT > SCREEN_HEIGHT + 10 ) || check_collision(box, wall[i]))
        {
            box.y -= yVel; //Geri hareket
			return true;
        }
    }
	return false;
}

void Bird::show()
{
    apply_surface( box.x - camera.x, box.y - camera.y, bird, screen );
}

void Bird::set_camera()
{
    camera.x = ( box.x + BIRD_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.y = (box.y + BIRD_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > LEVEL_HEIGHT - camera.h )
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
}

#endif // BIRD_H_INCLUDED
