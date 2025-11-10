#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

//counts how many words in the words.txt file

int CountWords(FILE *file){
    char Buffer[100];
    int Counter = 0;

    while (fgets(Buffer, sizeof(Buffer), file)){
        Counter++;
    }
    
    rewind(file);
    return Counter;

}


//load the words into dynamic array

char **LoadWords(const char *filename , int *count){
    FILE *file = fopen(filename, "r");
    if(!file){
        printf("error while opening dictionary");
        exit(1);
    }

    
    *count = CountWords(file);

    char **words = malloc(*count * sizeof(char *));

    if(!words){
        printf("error while loading dictioanry");
        exit(1);
    }


    char buffer[100];
    int i=0;
    //read each word line by line

    while(fgets(buffer, sizeof(buffer), file)){
        buffer[strcspn(buffer, "\r\n")] = '\0'; //we remove new line indicator and replace with end of line

        words[i] = malloc(strlen(buffer) + 1); //allocate len of buffer + 1 for the end of line \0
        strcpy(words[i], buffer);
        i++;
    }
    fclose(file);
    return words;

}
// proc to free the allocated words after being done w em
void FreeWords(char **words, int count){
    for (int i = 0; i < count; i++){
        free(words[i]);
    }
    free(words);
}

int IsValid(char **wordlist, char *word, int WordCount){
    for (int i = 0; i < WordCount; i++){
        if(strcmp(wordlist[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

//to get the position of a char in a string (may use for solver)
int GetPos(char c, char str[]){
    for (int i=0; i<5; i++){
        if(strcmp(str[i],c) == 0){
            return i;
        }
    }
}

//proc green that eliminates all the words that don't contain the green letter in the right position
//mostly wrong for now will fix later          
void filter_green(char c, int pos, char **wordlist, int *len) {
    int j = 0;
    for (int i = 0; i < *len; i++) {
        if (wordlist[i][pos] == c) {
            wordlist[j++] = wordlist[i];
        }
    }
    *len = j;
}

void filter_yellow(char c, int pos, char **wordlist, int *len) {
    int j = 0;
    for (int i = 0; i < *len; i++) {
        int contains = 0;
        for (int k = 0; wordlist[i][k] != '\0'; k++) {
            if (wordlist[i][k] == c) contains = 1;
        }

        if (contains && wordlist[i][pos] != c) {
            wordlist[j++] = wordlist[i];
        }
    }
    *len = j;
}

    

void filter_gray(char c, char **wordlist, int *len) {
    int j = 0;
    for (int i = 0; i < *len; i++) {
        int found = 0;
        for (int k = 0; wordlist[i][k] != '\0'; k++) {
            if (wordlist[i][k] == c) {
                found = 1;
                break;
            }
        }
        if (!found) {
            wordlist[j++] = wordlist[i];
        }
    }
    *len = j;
}
