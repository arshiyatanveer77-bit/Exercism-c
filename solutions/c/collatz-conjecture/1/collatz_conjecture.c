#include "collatz_conjecture.h"
int steps(int start){
    int count=0;
    if( start==0 || start<0){
        return -1;
    }
    
        
    while(start>1){
        if(start%2==0){
             start= start/2;
            count++;
        }
        else{
             start= start*3+1;
            count++;
        }
    }
    return count;
}