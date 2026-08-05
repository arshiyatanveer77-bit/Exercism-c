#include "isogram.h"
#include<stddef.h>
#include<ctype.h>
bool is_isogram(const char phrase[]){
    int letters[26]={0};
    int i=0;
     if(phrase == NULL){return false;}
    while(phrase[i] != '\0'){
       
        if((phrase[i]>='a'&& phrase[i]<='z') || (phrase[i] >='A' && phrase[i] <= 'Z')){
            char ch=tolower(phrase[i]);
            letters[ch-'a']++;
            if(letters[ch-'a']>1){return false;}
        }     
            i++;  
    }
        return true;
}
    
   
