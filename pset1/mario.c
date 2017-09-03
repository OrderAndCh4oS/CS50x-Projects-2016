#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do {
        printf("Height: ");
        n = GetInt();
    } while (n < 0 || n > 23);
    if(n != 0) 
    {
        for(int i = 1; i <= n; i++)
        {
            int spaces = n-i;
            while(spaces)
            {
                printf(" ");
                spaces--;
            }
            int hashes = i;
            while(hashes)
            {
                printf("#");
                hashes--;
            }
            printf("#\n");
        }   
    }
}