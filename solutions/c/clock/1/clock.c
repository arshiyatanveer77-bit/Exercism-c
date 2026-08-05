#include "clock.h"
clock_t clock_create(int hour, int minute){
    clock_t str;
    int total_min=hour * 60 + minute;
    total_min %= 1440;
    if(total_min <0){
        total_min += 1440;
    }
    int hourr=total_min /60;
    int min=total_min % 60;
    str.text[0]=hourr /10 + '0';
    str.text[1]=hourr %10 +'0';
    str.text[2]=':';
    str.text[3]=min /10 + '0';
    str.text[4]=min %10 +'0';
    str.text[5] = '\0';
    return str;
}

clock_t clock_add(clock_t clock, int minute_add){
    
     int min= (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
     int hour= (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
    
    int total_min = hour * 60 + min;
    int result=total_min + minute_add;
    
     result =result %1440;
    
    if (result < 0){
    result = result + 1440;
    }
    
    int hour_after_adding=result /60;
    int min_after_adding=result % 60;
    clock.text[0]= (hour_after_adding /10 ) + '0';
    clock.text[1]= (hour_after_adding % 10 ) + '0';
    clock.text[3]=( min_after_adding /10 ) + '0';
     clock.text[4]= ( min_after_adding % 10 ) + '0';
    clock.text[2] = ':';
clock.text[5] = '\0';
    
    return clock;
}


clock_t clock_subtract(clock_t clock, int minute_subtract){
    minute_subtract= -minute_subtract;
     return clock_add(clock, minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b){
   for (int i = 0; a.text[i] != '\0'; i++){
        if(a.text[i]!=b.text[i]){
            return false;
        }
    }
    return true;
}