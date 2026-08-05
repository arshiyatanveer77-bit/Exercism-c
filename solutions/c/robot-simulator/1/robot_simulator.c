#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y){
     robot_status_t robot;
    if (direction < DIRECTION_NORTH || direction >= DIRECTION_MAX){
        robot.direction=DIRECTION_DEFAULT ;
    }
   else{
    robot.direction=direction;
   }
    robot.position.x=x;
    robot.position.y=y;
    return robot;
}
void robot_move(robot_status_t *robot, const char *commands){    
    while(*commands != '\0'){
        if(*commands == 'R'){
           robot->direction = (robot->direction + 1) % 4;
        }
        else if(*commands == 'L'){
           robot->direction = (robot->direction + 3) % 4;
        }
        else if(*commands == 'A'){
            if(robot->direction == DIRECTION_NORTH){ robot->position.y++;}
            else if(robot->direction == DIRECTION_EAST){ robot->position.x++;}
            else if(robot->direction == DIRECTION_WEST){ robot->position.x--;}
            else if(robot->direction == DIRECTION_SOUTH){ robot->position.y--;}
        }
        else{return; }        
        commands++;        
    }
}
