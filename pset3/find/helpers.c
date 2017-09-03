/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Should go in helpers.h
 * Unused functions are just for reference.
 */
bool linearSearch(int value, int values[], int n);
bool binarySearch(int value, int values[], int n);

void selectionSort(int values[], int n);
void bubbleSort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n < 0)
        return false;

    return binarySearch(value, values, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bubbleSort(values, n);
    return;
}

bool linearSearch(int value, int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
    }
    return false;
}

bool binarySearch(int value, int values[], int n)
{
    int min = 0, max = n, mid = n / 2;

    while (min <= max) {
        if (value > values[mid])
        {
            min = mid + 1;
            mid = (max - min) / 2 + min;
        }
        else if (value < values[mid])
        {
            max = mid - 1;
            mid = (max - min) / 2 + min;

        } else if (values[mid] == value)
        {
            return true;
        }
    }

    return false;
}

void selectionSort(int values[], int n)
{
    int counter = 1;
    for(int i = 0; i < n; i++)
    {
        int lowest = values[i],
            marker = 0;
        for(int j = counter; j < n; j++)
        {
            if(lowest > values[j])
            {
                lowest = values[j];
                marker = j;
            }
        }
        if(marker > 0) {
            values[marker] = values[i];
            values[i] = lowest;
        }
        counter++;
    }
    return;
}


void bubbleSort(int values[], int n)
{
    int counter, i = 0;
    do
    {
        counter = 0;
        i = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(values[i] > values[j])
            {
                int x = values[i];
                values[i] = values[j];
                values[j] = x;
                counter++;
            }
            i++;
        }
    } while(counter != 0);
    return;
}