#include "hamming.h"
int compute(const char *lhs, const char *rhs){
  
    int count=0;
    if(*lhs == 0 && *rhs ==0){
        return 0;
    }
    if(*lhs == 0 || *rhs ==0){
        return -1;
    }
     
    while(*lhs != '\0' && *rhs !='\0'){
       
        if(*lhs == *rhs){
            lhs++;
            rhs++;
        }
        else{
            count++;
             lhs++;
            rhs++;
        }
        
    }
    if(*lhs != '\0' || *rhs !='\0'){return -1;}
    return count;
}