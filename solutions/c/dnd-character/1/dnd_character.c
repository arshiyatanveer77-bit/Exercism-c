#include "dnd_character.h"
#include <stdlib.h>

int ability(void){
   int rolls[4];
    for(int i=0;i<4;i++){
        rolls[i]=rand()%6 +1;
    }
    int lowest=rolls[0];
    int sum=0;
    for(int i=0;i<4;i++){
        if(rolls[i]<lowest){
            lowest=rolls[i];
        }
        
       sum=sum+rolls[i];
    }
    return sum-lowest;
   
}
int modifier(int score){
    int val=score-10;
    if(val<0 && val % 2 !=0){
        return (val/2) -1;
    }
    return val/2;
}
dnd_character_t make_dnd_character(void){
    dnd_character_t character;
    character.strength=ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints=10+modifier(character.constitution);
    return character;
}
