#include "binary.h"
#include<string.h>
#include <math.h>
int convert(const char *input){
    int sum=0;
    int digit,n;
     n=strlen(input);
    if(n==0){return INVALID;}
    
while(*input !='\0'){
    if(*input != '0' && *input != '1'){return INVALID;}
    digit=(*input - '0')*pow(2,n-1);
    sum=sum+digit;
    input++;
    n--;
    
}
    return sum;
}