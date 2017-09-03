#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    printf("Minutes: ");
    int mins = GetInt();
    printf("Bottles: %i\n", (mins * 12));
}
