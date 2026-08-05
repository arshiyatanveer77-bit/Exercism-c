#include "beer_song.h"
#include <string.h>
#include <stdio.h>
void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    int i=0;
     for(int bottles= start_bottles;bottles>start_bottles-take_down;bottles--){
         
         if(bottles>2){
         sprintf(song[i],"%d bottles of beer on the wall, %d bottles of beer.",bottles,bottles);
             i++;
             sprintf(song[i],"Take one down and pass it around, %d bottles of beer on the wall.",bottles-1);
             i++;
            song[i][0] = '\0';
            i++;
        }
         else if(bottles==2){
             sprintf(song[i], "2 bottles of beer on the wall, 2 bottles of beer.");
                i++;

            sprintf(song[i], "Take one down and pass it around, 1 bottle of beer on the wall.");
            i++;

            song[i][0] = '\0';
            i++;
         }        
         else if(bottles==1){
            sprintf(song[i], "1 bottle of beer on the wall, 1 bottle of beer.");
            i++;

            sprintf(song[i], "Take it down and pass it around, no more bottles of beer on the wall.");
            i++;

            song[i][0] = '\0';
            i++;
         }
         else if(bottles==0){
             sprintf(song[i], "No more bottles of beer on the wall, no more bottles of beer.");
            i++;

            sprintf(song[i], "Go to the store and buy some more, 99 bottles of beer on the wall.");
            i++;
         }
     }
     
}
                           