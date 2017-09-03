/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    /** 
     * If 1 or 2 arguments aren't passed to program 
     * display usage instruction and return error 1. 
     */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    /**
     * Set number of random numbers to n
     * using first arguement passed (after program name)
     */
    int n = atoi(argv[1]);

    /**
     * if two arguments are passed use the second to seed random number
     * otherwise get the current time and use that to seed instead.
     * srand48 seeds the drand48 function to provide psuedo random numbers,
     * if the same seed is provided again the list returned will be the same.
     */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /**
     * drand48 returns a float between 0 and 1 
     * This is multiplied by limit to give us our range of numbers.
     * Print random numbers until n limit is reached.
     */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}