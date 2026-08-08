#include "all_your_base.h"
#include <stdint.h>
#include <stddef.h>
size_t rebase(int8_t digits[],int input_base,int output_base,int len){
    
    if (input_base < 2 || output_base < 2) {
    return 0;
}
    if(len==0){return 0;}
    int value=0;
    
    for(int i=0;i<len;i++){
        if (digits[i] < 0 || digits[i] >= input_base) {
        return 0;
    }
        value=value * input_base + digits[i]; 
    }
    int result[len];
    int count=0;
    int j=0;
    if (value == 0) {
    result[0] = 0;
    count=1;
}
    while(value>0){
    result[j]=value%output_base;
    value=value/output_base;
        j++;
        count++;
    }
   
    //REVERSING THE ARRAY
    for(int i=0;i<count;i++){
        digits[i]=result[count-1-i];
    }
    return count;
}