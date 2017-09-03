#include <stdio.h>
#include <cs50.h>
#include <math.h>

int deduce(int largest, int coins, int *pCents);
int main(void)
{
    printf("O hai! How much change is owed?\n");
    float change = GetFloat();

    while (change < 0) {
        printf("Retry: \n");
        change = GetFloat();
    }



    int cents = round(change*100);
    int coins = 0;

        coins = deduce(25, coins, &cents);
        coins = deduce(10, coins, &cents);
        coins = deduce(5, coins, &cents);
        coins = deduce(1, coins, &cents);

        printf("%i\n", coins);

}

int deduce(int largest, int coins, int *pCents)
{
    while(*pCents >= largest)
    {
        *pCents = *pCents - largest;
        coins++;
    }
    return coins;
}