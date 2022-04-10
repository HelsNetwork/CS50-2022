#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;

    if (argc == 2)
    {
        key = atoi(argv[1]);
    }

    if (key >= 26)
    {
        key %= 26;
    }

    if (argc != 2 || key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");


    if (argc == 2)
    {
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if (text[i] >= 65 && text[i] <= 90)
            {
                if (text[i] + key > 90)
                {
                    text[i] -= 26;
                }
                text[i] += key;
            }
            else if (text[i] >= 97 && text[i] <= 121)
            {
                if (text[i] + key > 121)
                {
                    text[i] -= 26;
                }
                text[i] += key;
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
