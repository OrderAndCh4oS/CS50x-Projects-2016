#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "hash.h"

void addWord(node* hash, char* word) {
    node* p;
    p = hash;

    for(int i = 0; !hasWordEnded(word[i]); i++) {
        if(p->alpha[indexChar(word[i])] == NULL) {
            node *next;
            next = (node*) malloc(sizeof(struct node));
            p->alpha[indexChar(word[i])] = next;
        }
        p = p->alpha[indexChar(word[i])];
    }
    p->isWord = 1;
}

int findWord(node* hash, const char* word) {
    node* p;
    p = hash;
    for(int i = 0; !hasWordEnded(word[i]); i++) {
        if(p->alpha[indexChar(word[i])] != NULL) {
            p = p->alpha[indexChar(word[i])];
        } else {
            return false;
        }
    }
    if(p->isWord == 1)
        return true;
    else
        return false;
}

int indexChar(char c) {
    if((int) c == 39) {
        return 26;
    }
    int i = tolower(c);
    return i-97;
}

int hasWordEnded(char c) {
    if(c == '\n' || c =='\0') {
        return true;
    }
    return false;
}

void freeHash(node* hash) {
    node* next;
    for(int i = 0; i < 27; i++) {
        next = hash->alpha[i];
        while(hash->alpha[i] != NULL) {
            free(hash);
            hash = next;
            next = hash->alpha[i];
        }
    }
    free(hash);
}