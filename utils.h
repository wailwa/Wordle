#ifndef UTILS_H
#define UTILS_H


char **LoadWords(const char *filename, int *count);

void freeWords(char **words, int count);

int IsValid (char **wordlist, char *word, int WordCount);

int GetPos (char c, char str[]);

void green (char c, int pos, char **wordlist);

void yellow (char c, int pos, char **wordlist);

void gray (char c, int pos, char **wordlist);
#endif
