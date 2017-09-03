/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int byteBlock = 512; // Set block size

bool compare(BYTE buffer[]); // declare compare function for later use.

int main()
{

    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int count = 0; // Start counter for file names
    BYTE buffer[byteBlock]; // Set buffer size
    char outfile[8]; // Set output file name string length
    FILE* jpg = NULL; // Set JPG to NULL

    // Read 512 bytes until fead fails to read an bytes
    while (fread(buffer, 1, byteBlock, file)) {
        // Check first four bytes
        if (compare(buffer)) {
            // If jpg has been set close previous jpg file
            // If NULL it's the first occurence so ignore
            if (jpg != NULL)
                fclose(jpg);
            // Set out file title (outfile 8 char not 7 due to char to end string).
            sprintf(outfile, "%03d.jpg", count);
            // Open new file
            jpg = fopen(outfile, "w");
            // If can't open file return error.
            if (jpg == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 2;
            }
            // Increase count for next file name.
            count++;
        }
        // Start writing and continue writing once jpg has been found.
        if (jpg != NULL)
            fwrite(buffer, 1, sizeof(buffer), jpg);
    }
    // Close last jpg file.
    fclose(jpg);
    // Close read file.
    fclose(file);
    return 0;
}

bool compare(BYTE buffer[])
{
    // First 3 bytes of jpeg
    const BYTE startSeq[] = {0xff, 0xd8, 0xff};
    // Options for fourth byte of jpeg
    const BYTE lastSeq[] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};

    // Compare first 3 bytes against startSeq
    for (int i = 0; i < 3; i++)
        if (buffer[i] !=  startSeq[i])
            return false;

    // Compare fourth byte against all lastSeq options
    for (int i = 0; i < 16; i++) {
        if (buffer[3] == lastSeq[i]) {
            return true; // If fourth byte matches it's probably a jpeg.
        }
    }
    // No match
    return false;
}