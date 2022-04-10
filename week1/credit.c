#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // List of possible first digits for Mastercard, Visa and American Express
    int AE1 = 34;
    int AE2 = 37;
    int MC1 = 51;
    int MC2 = 52;
    int MC3 = 53;
    int MC4 = 54;
    int MC5 = 55;
    int Visa = 4;
    int count;
    long card = 0;
    int brand = 0;

    card = get_long("Number: ");
    long temp = card;
    count = 0;
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }
    if (count == 13)
    {
        int temp13 = card / 1000000000000;
        if (temp13 == Visa)
        {
            brand = 1;
        }
    }
    else if (count == 15)
    {
        int temp15 = card / 10000000000000;
        if (temp15 == AE1 || temp15 == AE2)
        {
            brand = 2;
        }
    }
    else if (count == 16)
    {
        int temp16MC = card / 100000000000000;
        int temp16V = card / 1000000000000000;
        if (temp16MC == MC1 || temp16MC == MC2 || temp16MC == MC3 || temp16MC == MC4 || temp16MC == MC5)
        {
            brand = 3;
        }
        else if (temp16V == Visa)
        {
            brand = 1;
        }
    }

    if (brand != 0)
    {
        int tempx;
        int last = 0;
        int secToLast = 0;

        while (card > 0)
        {
            last += card % 10;

            card /= 10;

            tempx = (card % 10) * 2;

            if (tempx > 9)
            {
                secToLast += tempx % 10 + tempx / 10;
            }
            else
            {
                secToLast += tempx;
            }

            card /= 10;
        }
        if ((last + secToLast) % 10 == 0)
        {
            if (brand == 1)
            {
                printf("VISA\n");
            }
            if (brand == 2)
            {
                printf("AMEX\n");
            }
            if (brand == 3)
            {
                printf("MASTERCARD\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
