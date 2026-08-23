#include "scrabble_score.h"
#include <ctype.h>
unsigned int score(const char *word){
    unsigned int worth=0;
    
   while(*word!='\0'){
    char ch=toupper(*word);

    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='L'||ch=='N'||ch=='R'||ch=='S'||ch=='T'){
        worth=worth+1;
    }
    else if(ch=='D'||ch=='G'){
        worth=worth+2;
    }
    else if(ch=='B'||ch=='C'||ch=='M'||ch=='P'){
        worth=worth+3;
    }
    else if(ch=='F'||ch=='H'||ch=='V'||ch=='W'||ch=='Y'){
        worth=worth+4;
    }
    else if(ch=='K'){
        worth=worth+5;
    }
    else if(ch=='J'||ch=='X'){
        worth=worth+8;
    }
    else if(ch=='Q'||ch=='Z'){
        worth=worth+10;
    }
    else{
        return 0;
    }

    word++;
}
    return worth;
}