#include "armstrong_numbers.h"
#include<math.h>
#include<stdlib.h>
bool is_armstrong_number(int candidate){
    int count=0;
    int num=candidate;
    int digit,res;
    int sum=0;
    while(candidate != 0){
        count++;
        candidate=candidate/10;
    }
    candidate=num;
   while(candidate> 0){
        digit=candidate % 10;
       res=digit;
       for(int i=1;i<count;i++){
        res=res * digit;
       }
       sum=sum+res;
         candidate=candidate/10;
    }
    
    if(sum == num){return true;}
   return false;
}