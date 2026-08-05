#include "pangram.h"
#include <stddef.h>
#include <ctype.h>
bool is_pangram(const char *sentence){
    if(sentence == NULL){return false;}
    int letters[26]={0};
    while(*sentence != '\0'){
        if((*sentence >='A' && *sentence <='Z')||( *sentence >= 'a' && *sentence <='z')){
            char ch=tolower(*sentence);
            letters[ch-'a']=1;
            }
        sentence++;
        
    }
    for(int i=0;i<26;i++){
        if(letters[i] == 0){return false;}
    }
    return true;
}