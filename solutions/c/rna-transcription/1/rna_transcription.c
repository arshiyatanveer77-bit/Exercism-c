#include "rna_transcription.h"
#include<string.h>
#include<stdlib.h>



char *to_rna(const char *dna){
    char *rna=malloc(strlen(dna) +1);
    char *result=rna;
while(*dna !='\0'){
    if(*dna == 'G'){*rna='C';}
    else if(*dna == 'C'){*rna='G';}
    else if(*dna == 'T'){*rna='A';}
    else if(*dna == 'A'){*rna='U';}
    rna++;
    dna++;
}
    *rna='\0';
    return result;
}