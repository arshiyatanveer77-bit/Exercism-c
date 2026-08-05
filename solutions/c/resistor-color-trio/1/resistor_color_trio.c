#include "resistor_color_trio.h"
#include<math.h>
#include<stdio.h>
#include <stdint.h>
resistor_value_t color_code(resistor_band_t colors[]){
    uint64_t value;
    uint64_t zeros;
    resistor_value_t result;
   value=colors[0] *10 + colors[1];
    zeros=value;
    for(resistor_band_t i=0;i<colors[2];i++){
        
        zeros=zeros * 10;
        
    }
  
   if(zeros<1000){
        result.value=zeros;
        result.unit=OHMS;
        return result;
   }
    

     else if (zeros<1000000){
        
         int resistance=zeros/1000;
      result.value=resistance;
        result.unit=KILOOHMS;
        return result;
    }
     else if (zeros<1000000000){
        
         int resistance=zeros/1000000;
      result.value=resistance;
        result.unit=MEGAOHMS;
        return result;
    }
     else {
        
         int resistance=zeros/1000000000;
      result.value=resistance;
        result.unit=GIGAOHMS;
        return result;
    }
    
}
