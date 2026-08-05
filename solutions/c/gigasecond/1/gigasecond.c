#include "gigasecond.h"
void gigasecond(time_t input, char *output, size_t size){
    struct tm* given;
     time_t after=input+1000000000;
    given=gmtime(&after);
    strftime(output,size,"%Y-%m-%d %H:%M:%S",given);
}