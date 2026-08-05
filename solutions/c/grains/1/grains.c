#include "grains.h"
uint64_t total(void){
    uint64_t no_grains = 1;
    uint64_t sum=1;
    for(uint8_t i=2;i<=64;i++){
        no_grains=no_grains*2;
        sum=sum+no_grains;
        }
    return sum;
}
uint64_t square(uint8_t index){
   uint64_t no_grains = 1;
    if(index==0 || index>64){
        return 0;
    }
    for(uint8_t i=2;i<=index;i++){
        no_grains=no_grains*2;
        }
    return no_grains;
}