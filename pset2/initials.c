#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int checkSpace(char c);

int main(void) {

    char* name = GetString();
    
    if (name != NULL) {
        bool skip = 1;
        for(int i = 0, n = strlen(name); i < n; i++) 
        {
            if(!checkSpace(name[i]) && skip)
            {
                printf("%c", toupper(name[i]));
                skip = 0;
            } 
            else if (checkSpace(name[i])) 
            {
                skip = 1;
            }
        }
        printf("\n");
        return 0;
    }
    return 1;
}

int checkSpace(char c) 
{
    if((int) c == 32) 
    {
        return 1;
    }
    return 0;
}