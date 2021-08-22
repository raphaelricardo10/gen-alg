#ifndef robot_h
#define robot_h

#include "genetic.h"

#define LIMIT 39999
#define ROBOT_QNT POP_SIZE
#define PIXEL_QNT (CHROMO_SIZE/2)+2
#define LAST_POINT (CHROMO_SIZE/2)

struct pixel
{
    int x;
    int y;
};

struct obstacles
{
    struct pixel p[3];

}obstacle[5];

struct door
{
    struct pixel p;
}door;

struct robot
{
    struct pixel p[PIXEL_QNT];
}robot[ROBOT_QNT];

struct distance
{   
    int best_robot;
    int minor_distance;
}winner;

void set_start_variables();
void encode();
void decode();
int verificate_collision();
void randomize_obstacles();

#endif