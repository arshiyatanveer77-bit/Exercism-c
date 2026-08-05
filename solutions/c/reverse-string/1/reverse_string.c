#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>
char *reverse(const char *value){
    int len=strlen(value);
    char *rev=malloc((len+1)*sizeof(char));
    int j,i;
    for(i=len-1,j=0;i>=0;i--,j++){
        rev[j]=value[i];
    }
    rev[j]='\0';
    return rev;
}