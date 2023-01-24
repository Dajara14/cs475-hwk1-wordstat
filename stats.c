/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below
void  trySetNewMaxHistogramValue(int value,int *maxHistogram){
    //update the maximum histogram value if the new value is larger.
    if(value>*maxHistogram){
        *maxHistogram = value;
    }
}
//prints the histogram
void printHistogram(int histogram[], int maxHistogramValue){
    //goes by each row of stars, starting at the maximum defined value in the histogram array.
 for(int i = 0; i<maxHistogramValue;i++){
    //go through each letter in the alphabet
        for(int j = 0; j<ALPHABET_SIZE; j++){
            //if the histogram value is larger than the maximum-whatever row we are on, it means that a star will be there
            if(maxHistogramValue-i<=histogram[j]){
                printf("*\t");
            //else just empty space
            } else{
                printf(" \t");
            }
        }
        printf("\n");
    }
    //print out the alphabet underneath each part of the graph
    for(int j = 0; j<ALPHABET_SIZE; j++){
        printf("%c \t",65+j);
    }
    printf("\n");
    //and the numerical value of the frequency of each letter
   for(int j = 0; j<ALPHABET_SIZE; j++){
    printf("%d \t",histogram[j]);
   }
   //print a new line so that nothing gets weirdly concatinated.
   printf("\n");
}
void recordLetter(char letter, int histogram[], int* vowels,int* consonants,int*maxHistogramValue){
    //increment the histograms value for the inputted letter by 1 
    histogram[letter-65] = histogram[letter-65]+1;
    //check to see if this is the largest value in the histogram now
    trySetNewMaxHistogramValue( histogram[letter-65],maxHistogramValue);
                    //record if it is a vowel or a consonant
					if(letter=='A'||letter=='E'||letter=='I'||letter=='O'||letter=='U'){
						*vowels= *vowels +1;
					} else{
						*consonants= *consonants+1;
					}
}
