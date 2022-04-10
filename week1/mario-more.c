#include <cs50.h>
#include <stdio.h>

void pyramid(int n);

int main(void)
{
    int height = 0;
    // asks for height
    do
    {
        height = get_int("Height: ");
    }
    while (!(height >= 1 && height <= 8));

    pyramid(height);
}


void space(int l)
{
    for (int k = 0; k < l; k++)
    {
        printf(" ");
    }
}

void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        space(n - i - 1);

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        space(2);

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
