#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "robot.h"
#include "genetic.h"

void set_start_variables()
{
    door.p.x = LIMIT+1;
    door.p.y = rand()%LIMIT;

    randomize_obstacles();
    
}

void decode()
{
    for(int i = 0; i < ROBOT_QNT; i++)
    {
        robot[i].p[0].x = 0;
        robot[i].p[0].y = 0;
        robot[i].p[PIXEL_QNT].x = door.p.x;
        robot[i].p[PIXEL_QNT].x = door.p.y;

        for(int j = 1; j < LAST_POINT; j++)
        {
            if(j%2 == 0)
                robot[i].p[j].x += population.member[i].chromossome[j];
            else
                robot[i].p[j].y += population.member[i].chromossome[j];
        }
    }

    winner.best_robot = population.best_member;
    winner.minor_distance = 1/population.absolute_fittest;
}

void randomize_obstacles()
{
    for(int i = 0; i < 5; i++)
    {
        int direction = rand()%3;

        obstacle[i].p[0].x = rand()%(LIMIT-1)+1;
        obstacle[i].p[0].y = rand()%(LIMIT-1)+1;

        obstacle[i].p[1].x = obstacle[i].p[0].x;
        obstacle[i].p[1].y = obstacle[i].p[0].y - 1;

        if(direction == 0)
        {
            obstacle[i].p[2].x = obstacle[i].p[0].x + 1;
            obstacle[i].p[2].y = obstacle[i].p[0].y - 1;
        }
        else if(direction == 1)
        {
            obstacle[i].p[2].x = obstacle[i].p[0].x + 1;
            obstacle[i].p[2].y = obstacle[i].p[0].y;
        }
        else if(direction == 2)
        {
            obstacle[i].p[2].x = obstacle[i].p[0].x - 1;
            obstacle[i].p[2].y = obstacle[i].p[0].y;
        }
        else if(direction == 1)
        {
            obstacle[i].p[2].x = obstacle[i].p[0].x - 1;
            obstacle[i].p[2].y = obstacle[i].p[0].y - 1;
        }
    }

}