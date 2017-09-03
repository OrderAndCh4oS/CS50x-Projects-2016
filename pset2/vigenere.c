#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UC_OFFSET 65
#define LC_OFFSET 97

void Vigenere(char* k, char* p);
char EncryptChar(char k, char p);
char FindKey(char* k, int i);

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Please enter only letters as a key argument!\n");
                return 1;
            }
        }
        char* k = argv[1];
        char* p = GetString();
        Vigenere(k, p);
    } else {
        printf("Please enter a word as a key argument!\n");
        return 1;
    }

    return 0;
}

void Vigenere(char* k, char* p)
{
    char c[strlen(p)];
    int j = 0;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        char v = 0;
        if (isalpha(p[i]))
        {
             v = FindKey(k, j);
             j++;
        }
        c[i] = EncryptChar(v, p[i]);
        printf("%c", c[i]);
    }
    printf("\n");
}

char EncryptChar(char k, char p) {
    char c = p;
    int offset;
    if(isalpha(p))
    {
        if(isupper(p))
        {
            offset = UC_OFFSET;
        }
        else
        {
            offset = LC_OFFSET;
        }
        p -= offset;
        c = (p + k) % 26;
        c += offset;
    }
    return c;
}

char FindKey(char* k, int j)
{
    j = j % strlen(k);
    char v = toupper(k[j]) - UC_OFFSET;
    return v;
}