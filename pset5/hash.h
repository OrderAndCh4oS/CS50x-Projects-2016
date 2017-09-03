#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    struct node* alpha[27];
    int isWord;
} node;


void addWord(node* hash, char* word);
int findWord(node* hash, const char* word);
int indexChar(char c);
int hasWordEnded(char c);
void freeHash(node* hash);

#endif