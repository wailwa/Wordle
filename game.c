#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "utils.h"

//to load the words, start the game loop, pick a randfom word
void StartGame(){
    int WordCount;
    //load words
    char **words = LoadWords("words.txt", &WordCount);
 
    //pcik a random word
    srand(time(NULL));

    char *chosen = words[rand() % WordCount];
    printf("\nrandom word selected is %s", chosen);

    int attempts = 6;
    char guess[100] = ""; //to store players guess
    int win = 0; //mark if player won

    for(int i=0 ; i < attempts; i++){
        do {
        printf("\nAttempt %d/%d - Enter a 5-letter word: ", i + 1, attempts);
        scanf("%s", guess);

        if (strlen(guess) != 5){
            printf("Word must be 5 letters!\n");
        }
        else if (IsValid(words, guess, WordCount) == 0){
            printf("That word is invalid. Try again!");
        }
        } while (strlen(guess) != 5 || IsValid(words, guess, WordCount) == 0);

        char feedback[6]; //5 letters + end of line
        GetFeedback(guess, chosen, feedback);
        printf("\nthis is your feedback: %s", feedback);

        if(strcmp(feedback, "11111") == 0){ //basically 11111 means all the letters in the right position, 00000 means letters are right but in diff positions, XXXXX means both wrong
            win = 1;
            printf("\nYou guessed the word in %d attempts!", i+1);
            break;
        }

    }
}


void GetFeedback(const char *guess, const char *chosen, char *feedback){
    for (int i = 0; i <5; i++){
        if (guess[i] == chosen[i]){ //good pos and letter
            feedback[i] = '1';
        }
        else if (strchr(chosen, guess[i])){ //wrong pos
            feedback[i] = '0';
        }
        else{
            feedback[i] = 'X'; //wrong letter
            
        }
    }

    feedback[5]='\0';
}