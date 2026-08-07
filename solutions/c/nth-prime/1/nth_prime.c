#include "nth_prime.h"
#include <stdbool.h>
bool isprime(uint32_t num){
        if(num<2){return false;}
   for (uint32_t i = 2; i * i <= num; i++){
       if(num%i==0){return false;}
     }
      return true;
}
uint32_t nth(uint32_t n){
    if (n == 0) {
    return 0;
}
    uint32_t count=0;
    uint32_t num=2;
    while(count<n){
        if(isprime(num)){
        count++;
        }
         if(count==n){return num;}
        num++;
    }
   
   return 0;
}