#include "nucleotide_count.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *count(const char *dna_strand){
    int a=0,c=0,g=0,t=0;
    char *counted=malloc(50); 
    while(*dna_strand !=0){
        if(*dna_strand == 'A'){a++;}
        else if(*dna_strand == 'C'){c++;}
        else if(*dna_strand == 'G'){g++;}
        else if(*dna_strand == 'T'){t++;}
        else{     
           counted[0] = '\0';
            return counted;
        }
        dna_strand++;
    }
    sprintf(counted, "A:%d C:%d G:%d T:%d", a, c, g, t);
    return counted;
}