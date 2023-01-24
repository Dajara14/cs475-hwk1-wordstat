/*
 * histo.h
 */

#ifndef STATS_H_
#define STATS_H_

// constants
#define ALPHABET_SIZE 26

// TODO: functions declarations go below

void  trySetNewMaxHistogramValue(int value,int* maxHistogramValue);
void printHistogram(int histogram[], int maxHistogramValue);
void recordLetter(char letter,int histogram[],int* vowels,int* consonants, int*maxHistogramValue);
#endif /* STATS_H_ */
