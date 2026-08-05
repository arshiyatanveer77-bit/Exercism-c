#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    float period;
    //if(planet >7 || planet <0){return -1;}
switch(planet){
    case MERCURY:
        period = 0.2408467;
        break;
    case VENUS:
        period =0.61519726;
        break;
    case EARTH:
        period=1.0;
        break;
    case MARS:
        period=	1.8808158;
        break;
    case JUPITER:
        period=11.862615;
        break;
    case SATURN:
        period=29.447498;
        break;
    case URANUS:
        period=84.016846;
        break;
    case NEPTUNE:
        period=	164.79132;
        break;
    default: return -1;
}

    float seconds_to_earthyears= seconds/31557600.0;
    float earthyears_to_planetyrs=seconds_to_earthyears/period;
    return earthyears_to_planetyrs;
}