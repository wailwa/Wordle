#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"
#include "utils.h"
#include "game.h"

extern char *chosen;

void starSolver(){
    
    int wordCount;
    char **wordlist = LoadWords("words.txt", &wordCount);

    int attempts = 6;
    char *guess = "";
    int win =0;

    for (int i=0; i<6 ; i++){
        guess = makeGuess(i, wordlist , wordCount);

        char feedback[6];
        
    }


    
}

char *makeGuess(int n, char **wordlist, int len){
    switch (n){
        case 1 : return "AUDIO";

        case 2 : return "CRANE";

        default :
                srand(time(NULL));
                return wordlist[rand() % len];
    }
}