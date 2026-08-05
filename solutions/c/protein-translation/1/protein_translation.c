#include "protein_translation.h"
#include<string.h>
protein_t protein(const char *const rna){
    protein_t strand;
    char codon[4];
     if(rna==NULL){
     strand.valid=false; 
                 strand.count=0;
                 return strand;
     }
    int len=strlen(rna);
    if (len == 0) {
    strand.valid = true;
    strand.count = 0;
    return strand;
    }
    bool stopped=false;
    int j=0;
    if(len<3){
        strand.valid=false;
        strand.count=0;
        return strand;
    }
    for(int i=0;i+2<len;i=i+3){
        codon[0]=rna[i];
        codon[1]=rna[i+1];
        codon[2]=rna[i+2];
        codon[3]='\0';
        
        if(strcmp(codon,"AUG")==0){
            strand.amino_acids[j]=Methionine;
            j++;
        }
        else if(strcmp(codon,"UUU")==0|| strcmp(codon,"UUC")==0){
            strand.amino_acids[j]=Phenylalanine;
            j++;
        }
        else if(strcmp(codon,"UUA")==0|| strcmp(codon,"UUG")==0){
            strand.amino_acids[j]=Leucine;
            j++;
        }
        else if(strcmp(codon,"UCU")==0|| strcmp(codon,"UCC")==0 ||strcmp(codon,"UCA")==0||             strcmp(codon,"UCG")==0){
            strand.amino_acids[j]=Serine;
            j++;
        }
        else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0) {
            strand.amino_acids[j] = Tyrosine;
            j++;
        }
        else if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0) {
            strand.amino_acids[j] = Cysteine;
            j++;
        }
        else if (strcmp(codon, "UGG") == 0) {
            strand.amino_acids[j] = Tryptophan;
            j++;
        }
        else if (strcmp(codon, "UAA") == 0 ||strcmp(codon, "UAG") == 0 || strcmp(codon,                 "UGA") == 0) {
            stopped=true;
            break;   
        }
        else{ 
            strand.valid=false;
            strand.count=j;
        return strand;}
        }
    if (!stopped && len % 3 != 0) {
        strand.valid = false;
        strand.count = 0;
        return strand;
    }
  
    strand.valid=true;
    strand.count=j;
    return strand;
}