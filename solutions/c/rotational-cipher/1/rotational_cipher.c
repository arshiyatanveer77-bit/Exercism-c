#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>
char *rotate(const char *text, int shift_key){
    char * str=malloc(strlen(text)+1);
    char * result=str;
    if (str == NULL)
    return NULL;
    shift_key %= 26;
    while(*text != '\0'){
        if(*text >='a' && *text <='z' ){
          *str = ((*text - 'a' + shift_key) % 26) + 'a';
            }
             
            else if(*text >='A' && *text <='Z'){
             *str = ((*text - 'A' + shift_key) % 26) + 'A';
            }
        
        else{
            *str=*text;
        }
        
        text++;
        str++;
    }
    *str='\0';
    return result;
}