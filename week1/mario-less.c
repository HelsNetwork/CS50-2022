#include <cs50.h>
#include <stdio.h>

void pyramid(int n);

int main(void)
{
    int height = 0;
   
    do
    {
        height = get_int("Height: ");
    }
    while (!(height >= 1 && height <= 8));
    
    pyramid(height);
}

void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        
        for (int k = n - i - 2; k >= 0; k--)
        {
            printf(" ");
        }        
       
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }        
   
        printf("\n");
    }
}
