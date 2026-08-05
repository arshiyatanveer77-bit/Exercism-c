#include "perfect_numbers.h"
kind classify_number(int num){
    if (num <= 0){
    return ERROR;
    }
    int sum=0;
    for(int i=1;i<num;i++){
    if(num%i==0 ){
        sum=sum+i;
    }
    }
    if(sum==num){
        return PERFECT_NUMBER;
    }  
    else if(num<sum){
        return ABUNDANT_NUMBER;
    }
    else if(num>sum){
        return DEFICIENT_NUMBER;
    }
    else{return ERROR;}
      
    
}