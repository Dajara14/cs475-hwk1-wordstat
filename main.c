/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	// TODO: start by getting strings from users until # is input
	//initialize all counters and necessary booleans
		int finished = 0; //tells us whether the program is finished or not
	int doneGettingWords = 0; //tells us if we are done collecting words for the histogram
	int vowels = 0; //number of vowels recorded
	int consonants = 0; //number of consonants recorded
	//initialize the histogram to have all letters have 0
	for(int i = 0; i<ALPHABET_SIZE; i++){
		histogram[i] = 0;
	}
	//initialize the most highest frequency of letters found for use in creating the histogram
	int maxHistogramValue = 0;
	//while we are not finished
	while(finished == 0){
		//while we are not done getting words
	while(doneGettingWords == 0){
		//prompt the user to enter strings
		printf("Enter Strings (# to stop):");
		//get the user inputted string into a usable state
		char str[MAX_INPUT_LEN];
		char *input;
		input = fgets(str, MAX_INPUT_LEN, stdin);
		//if it is a '#', end this part of the program
		if(str[0]=='#'){
			doneGettingWords = 1;
		//if it is not, we need to parse the string
		} else{
			//check to make sure the first character is a letter
			if((str[0]>='A'&&str[0]<='Z')||(str[0]>='a'&&str[0]<='z')){
			int i = 0;
			//go through each character, and add it to our histogram and vowel/consonant count, end when the input is the null value at the end of all strings.
			while(input[i]!='\0'){
				char currentChar = str[i];
				if(currentChar<='Z'&&currentChar>='A'){
					recordLetter(currentChar,histogram,&vowels,&consonants,&maxHistogramValue);
				} else if(currentChar<='z'&&currentChar>='a'){
					recordLetter(currentChar-32,histogram,&vowels,&consonants,&maxHistogramValue);
				}
				i++;
			}
			
			}
		}
	}
	// TODO: after # is input, print menu options
	//initializes whether we are done with the histogram menu to false
	int doneWithMenu = 0;
	//while the user is still getting information about the inputs...
	while(doneWithMenu == 0){
		//get a number from the user to determine the next function
	int menuOption = getMenuOption();
	//if the user chose 1, print out the number of vowels, consonants, and their percentages of the total.
	if(menuOption==1){
		int total = vowels+consonants;
		float vowelsPercent =((double)vowels/(double)total)*100;
		float consonantsPercent = ((double)consonants/(double)total)*100;
		printf("There are %d vowels( %.2f percent of total), %d consonants(%.2f percent of total), and a total of %d letters\n",vowels,vowelsPercent,consonants,consonantsPercent,total);
	//if the user chooses 2, print out the histogram
	}else if(menuOption==2){
		printHistogram(histogram,maxHistogramValue);
	//if the user chooses 3, we are done with this menu, and the user will go through the words adding again.
	}else if(menuOption==3){
		doneWithMenu = 1;
		doneGettingWords = 0;
	//if the user chooses 4, go through the main while loop, without doing anything and exit the program.
	}else if(menuOption==4){
		doneWithMenu = 1;
		finished = 1;
	//if the user chooses a number that is not 1-4, tell them that it is an unknown option and prompt them again
	}else{
		printf("Unknown Option %d", menuOption);
	}
	}
	}
	printf("Exiting...\n");
	return 0;
}
