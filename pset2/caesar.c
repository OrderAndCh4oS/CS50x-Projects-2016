#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define UC_OFFSET 65
#define LC_OFFSET 97

void Caesar(int k, char* p);
char EncryptChar(int k, int p);

int main(int argc, char* argv[])
{
    if (argc == 2 && atoi(argv[1])) 
    {
        int k = atoi(argv[1]);
        char* p = GetString();
        Caesar(k, p);
    } else {
        printf("Please enter a digit as a key argument.\n");
        return 1;
    }
    
    return 0;
}

void Caesar(int k, char* p)
{
    char c[strlen(p)];
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        c[i] = EncryptChar(k, p[i]);
        printf("%c", c[i]);
    }
    printf("\n");
}

char EncryptChar(int k, int p) {
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