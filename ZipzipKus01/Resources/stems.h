#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "constants.h"
#include "variables.h"
using namespace constants;

SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
bool check_collision( SDL_Rect A, SDL_Rect B )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if( bottomA - 30 <= topB )
    {
        return false;
    }

    if( topA >= bottomB - 30 )
    {
        return false;
    }

    if( rightA - 18 <= leftB )
    {
        return false;
    }

    if( leftA >= rightB - 18 )
    {
        return false;
    }

    return true;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

class stem
{
    public:
    SDL_Rect box[16]; //Dallar icin carpisma kutusu

    stem();

    void show();

};
stem::stem()
{
            box[0].x =650;		box[1].x=800;
            box[0].y =70;		box[1].y=500;

            box[2].x =1400;		box[3].x=1800;
            box[2].y =100;		box[3].y=180;

            box[4].x =2200;		box[5].x=2700;
            box[4].y =260;		box[5].y=60;

			box[6].x =2700;		box[7].x=3200;
            box[6].y =520;		box[7].y=150;

			box[8].x =3500;		box[9].x=4000;
            box[8].y =500;		box[9].y=60;

			box[10].x =4000;	box[11].x=4300;
            box[10].y =500;		box[11].y=300;

			box[12].x =4600;	box[13].x=5300;
            box[12].y =300;		box[13].y=70;

			box[14].x =5300;	box[15].x=6200;
            box[14].y =520;		box[15].y=300;

            for(int i=0;i<16;++i)
            {
                box[i].w = STEM_WIDTH;
                box[i].h = STEM_HEIGHT;
            }

}
void stem::show()
{
    for(int i=0;i<16;++i)
    apply_surface( box[i].x, box[i].y, STEMS, background );

}

#endif // COLLISION_H_INCLUDED
