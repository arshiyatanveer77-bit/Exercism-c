#include "kindergarten_garden.h"
plants_t plants(const char *diagram,const char *student){
    int row_length = 0;
    char letter=student[0];
    //convert letter to num(value)
    int num=letter -'A';
    int start=num*2;
    while(diagram[row_length] !='\n'){row_length++;}
    plants_t result;
    for(int i=0;i<4;i++){
        char plant=diagram[(i/2)*(row_length+1)+start+(i%2)];
        switch(plant){
            case 'C':
                result.plants[i]=CLOVER;
                break;
            case 'G':
                result.plants[i]=GRASS;
                break;
            case 'V':
                result.plants[i]=VIOLETS;
                break;
           case 'R':
                result.plants[i]=RADISHES;
                break;
        }
    }
    return result;
}