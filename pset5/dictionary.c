/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include "hash.h"

unsigned int wordCount = 0;

node *hashDict;

char* newWord() {
    return malloc(sizeof(char)*46);
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    return findWord(hashDict, word);
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    char* word = NULL;
    hashDict = (node*) malloc(sizeof(struct node));
    FILE* fp;
    fp = fopen(dictionary, "r");
    int i = 0;
    do {
        if(word == NULL)
        {
            word = newWord();
        }
        char c = fgetc(fp);
        if(c != '\n') {
            word[i] = c;
            i++;
        } else {
            word[i] = '\0';
            addWord(hashDict, word);
            i = 0;
            free(word);
            word = NULL;
            wordCount++;
        }
    } while (!feof(fp));
    if(word != NULL) {
        free(word);
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    freeHash(hashDict);
    return true;
}
